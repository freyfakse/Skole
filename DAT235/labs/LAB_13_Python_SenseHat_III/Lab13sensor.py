import paho.mqtt.client as mqtt
from sense_hat import SenseHat
import json
import time
import sys
import EventTimer
from Lab13common import *


host = "localhost"   #  MQTT broker host address
connected = False           #  Connected to MQTT broker
CMD_Activate = False        #  Command: Activate sensor reporting
CMD_Terminate = False       #  Command: Terminate program

verbose = True              #  Extra printout

# definitions and intial data config
hello = "Lab13sensor - publishing sensor data to "+maintopic+" tree\n"
goodbye = "Lab13sensor -- terminating now\n"


#  global objects
sense = None
client = None
timer = None


# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, flags, rc):
    global connected
    
    if not connected:
        print("Connected with result code "+str(rc))
        sys.stdout.flush()
    if rc!=0:
        print("Cannot connect properly. Shutting down.")
        sys.exit(1)
    else:
        connected = True
    

# The callback for when a PUBLISH message is received from the server.
def on_message(client, userdata, msg):
    global CMD_Activate, CMD_Terminate
    global timer
    global PERIOD_Temperature, PERIOD_Pressure, PERIOD_Humidity, PERIOD_Compass
    
    warn = "Warning: "
    payls = str(msg.payload)
    if msg.topic == starttopic:
        try:
            # Python 3.5.x: must "decode" first (3.6/3.7 don't need this)
            start = json.loads(msg.payload.decode("utf-8"))
        except ValueError:
            print(warn+"Topic start, unexpected input:",payls," -- ignored!")
            sys.stdout.flush()

        if isinstance(start,bool):
            CMD_Activate = start
            return

        if isinstance(start,str):
            CMD_Terminate = start==EXITcommand
            return
        else:
            print(warn+"Topic start, unexpected string:",payls," -- ignored")
            return
                
        print(warn+"Topic start, unexpected input (neither 'EXIT' nor bool):", \
                payls," -- ignored")
        
    # Handle config command - Publish & reschedule as appropriate
    if msg.topic == configtopic:
        # Don't bother with checking here -- you fix it :-)
        cmd = json.loads(msg.payload.decode("utf-8"))
        
        if cmd[0] == EV_Temperature:
            if not isinstance(cmd[1], int):
                print(warn+"period must be int, --  ignored")
            else:
                PERIOD_Temperature = cmd[1]
                if  CMD_Activate: 
                    Reschedule(PERIOD_Temperature, EV_Temperature)                    
                    publish_Temperature()
                print("\n==>  Config: period for Temperature set to ",cmd[1],"\n") 
                    
        if cmd[0] == EV_Pressure:
            if not isinstance(cmd[1], int):
                print(warn+"period must be int, --  ignored")
            else:
                PERIOD_Pressure = cmd[1]
                if  CMD_Activate:
                    Reschedule(PERIOD_Pressure, EV_Pressure)
                    publish_Pressure()
                print("\n==>  Config: period for Pressure set to ",cmd[1],"\n")

        if cmd[0] == EV_Humidity:
            if not isinstance(cmd[1], int):
                print(warn+"period must be int, -- ignored")
            else:
                PERIOD_Humidity = cmd[1]
                if CMD_Activate:
                    Reschedule(PERIOD_Humidity, EV_Humidity)
                    publish_Humidity()
                print("\n==>  Config: period for Humidity set to ",cmd[1],"\n")
                    
        if cmd[0] == EV_Compass:
            if not isinstance(cmd[1], int):
                print(warn+"period must be int, -- ignored")
            else:
                PERIOD_Compass = cmd[1]
                if  CMD_Activate:
                    Reschedule(PERIOD_Compass, EV_Compass)    
                    publish_Compass()
                print("\n==>  Config: period for Compass set to ",cmd[1],"\n")


def publish_Temperature():
    global sense, client
    
    temperature = sense.get_temperature()
    if verbose:
        print("Publishing temperature:",temperature)
    client.publish(temperaturetopic, json.dumps(temperature))


def publish_Pressure():
    global sense, client
    
    pressure = sense.get_pressure()
    if verbose:
        print("Publishing pressure:",pressure)
    client.publish(pressuretopic, json.dumps(pressure))


def publish_Humidity():
    global sense, client
    
    humidity = sense.get_humidity()
    if verbose:
        print("Publishing humidity:",humidity)
    client.publish(humiditytopic, json.dumps(humidity))

    
def publish_Compass():
    global sense, client
    
    compass = sense.get_compass()
    if verbose:
        print("Publishing compass:",compass)
    client.publish(compasstopic, json.dumps(compass))
    
    
def Reschedule(period, Event):
    global timer
    timer.CancelEvent(Event)        # not always necessary, but never dangerous 
    if period > 0:
        timer.SetTimer(period*100, [Event])  
        

def initially():
    global client, sense
    
    sense = SenseHat()
    sense.set_imu_config(True, False, False) # enabling the compass
    
    try:
        client = mqtt.Client(client_id=devicename+"_sensor", clean_session=False)
        client.username_pw_set("ctrl13", password="123")
        client.on_connect = on_connect
        client.on_message = on_message
        client.connect(host)
        client.loop()
    except:
        print("Tried to connect, but it failed. Exiting now.\n", file=sys.stderr)
        sys.stderr.flush()
        sys.exit(1)
        
    wt = 0
    while not connected:
        client.loop()
        time.sleep(0.2)
        wt += 1
        if wt>20:
            print("Error: Cannot connect to "+host, file=sys.stderr)
            sys.stderr.flush()
            sys.exit(1)
            
    print("Reporting periods:")
    print("  Temperature: ",PERIOD_Temperature)
    print("  Pressure   : ",PERIOD_Pressure)
    print("  Humidity   : ",PERIOD_Humidity)
    print("  Compass    : ",PERIOD_Compass)
    print()
    
    return(client)
    

if __name__ == "__main__":
    print(hello)  
    sys.stdout.flush()
    client = initially()

    client.subscribe(starttopic, qos=1)
    client.subscribe(configtopic, qos=1)
    client.loop()
    
    timer = EventTimer.EvTimer()
 
    # The main event-loop
    activestate = False
    
    print("Ready to report.")
    while True:
        client.loop()
        time.sleep(0.01)
        
        # if we are in an activestate, then we check if there are any timeouts
        # If there are timeout, then we handle them (easy peasy)
        if activestate:
            if timer.timeout():
                event = timer.GetEvent()
                tag = event[1][0]
                if tag == EV_Temperature:
                    publish_Temperature()
                    Reschedule(PERIOD_Temperature, tag)
                if tag == EV_Pressure:
                    publish_Pressure()
                    Reschedule(PERIOD_Pressure, tag)
                if tag == EV_Humidity:
                    publish_Humidity()
                    Reschedule(PERIOD_Humidity, tag)
                if tag == EV_Compass:
                    publish_Compass()
                    Reschedule(PERIOD_Compass, tag)

            
        #  The variable CMD_Activate is False initially
        #  It is set for False/True according to payload in ../start topic
        #  ../start messages are retained  --- set by Lab13ctrl.py utility
        #  The current state (activestate) is updated to be True 
        if CMD_Activate:
            if  not activestate:
                #  Return to a active state - publish sensor data and set timers
                #  If the PERIOD is zero, then sensor reporting is disabled
                print("\n***  Reporting is Activated.\n")
                activestate = CMD_Activate
                if PERIOD_Temperature > 0:
                    publish_Temperature()
                    Reschedule(PERIOD_Temperature, 'temperature')
                if PERIOD_Pressure > 0:
                    publish_Pressure()
                    Reschedule(PERIOD_Pressure, 'pressure')
                if PERIOD_Humidity > 0:
                    publish_Humidity()
                    Reschedule(PERIOD_Humidity, 'humidity')
                if PERIOD_Compass > 0:
                    publish_Compass()
                    Reschedule(PERIOD_Compass, 'compass')
        else:
            # Go to passive state
            if activestate:
                print("\n***  Reporting is Deactivated.\n")
                timer.Reset() 
                activestate = False
                
        # Exit command may be received from ../start,
        if CMD_Terminate:
            print("\n***  EXIT command received.")
            break

    # Terminating
    print("\nReporting periods:")
    print("  Temperature: ",PERIOD_Temperature)
    print("  Pressure   : ",PERIOD_Pressure)
    print("  Humidity   : ",PERIOD_Humidity)
    print("  Compass    : ",PERIOD_Compass)
    print()
    print(goodbye)
    client.disconnect()
