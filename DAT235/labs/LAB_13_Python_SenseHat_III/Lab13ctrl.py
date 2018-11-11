import paho.mqtt.client as mqtt
import json
import sys
from Lab13common import *


host = "localhost"          #  MQTT broker host address
connected = False           #  Connected to MQTT broker
CMD_Terminate = False       #  Command: Terminate program


# definitions and intial data config
hello = "Lab13ctrl - controlling sensor data reporting "+maintopic+"#\n"
goodbye = "\nLab13ctrl -- terminating now\n"


#  global objects
client = None


# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, flags, rc):
    global connected
    
    if not connected:
        print("Connected with result code "+str(rc))
        sys.stdout.flush()
    if rc!=0:
        print("Cannot connect properly",file=sys.stderr)
        sys.stderr.flush()
        sys.exit(1)
    else:
        connected = True
    

# The "initially" client setup & connect
def initially():
    try:
        client = mqtt.Client(client_id=devicename+"_ctrl")
        client.username_pw_set("ctrl13", password="123")
        client.on_connect = on_connect
        client.connect(host,keepalive=600)  # Very long, but useful here
        client.loop()
    except:
        print("Tried to connect, but it failed. Exiting now.\n", file=sys.stderr)
        sys.stderr.flush()
        sys.exit(1)

    wt = 0
    while not connected:
        client.loop()
        wt += 1
        if wt>10:
            print("Error: Cannot connect to "+host,file=sys.stderr)
            sys.stderr.flush()
            sys.exit(1)
    return(client)


if __name__ == "__main__":  
    print(hello) 
    sys.stdout.flush()    
    client = initially()

    # The main event-loop
    CMD_Terminate = False
    while not CMD_Terminate:
        client.loop()
        print("Controlling sensor periods, activation/deactivation and termination.\n") 
        print("A - Activate sensors")
        print("D - Deactivate sensors")        
        print("T - Set period for Temperature sensor")
        print("P - Set period for Pressure sensor")
        print("H - Set period for Humidity sensor")
        print("C - Set period for Compass sensor")        
        print("X - Terminate measurements")
        print("! - Terminate this program")
        
        answer = input("\nEnter command: ").upper()
        if answer == "A":
            print("==> Sending activation command\n")
            client.publish(starttopic, json.dumps(True), qos=1, retain=True)
        if answer == "D":
            print("==> Sending deactivation command\n")                
            client.publish(starttopic, json.dumps(False), qos=1, retain=True)
            
        if answer in ["T","P","H","C"]:
            periods = input("Give period (in 1/10 seconds): ")
            try:
                period = int(periods)
            except ValueError:
                print("Not an integer")
                
            if answer == "T":
                print("==> Sending command to alter Temperature period to", period,"\n")                    
                client.publish(configtopic, json.dumps([EV_Temperature, period]), qos=1,)
            if answer == "P":
                print("==> Sending command to alter Pressure period to", period, "\n")                    
                client.publish(configtopic, json.dumps([EV_Pressure, period]), qos=1)
            if answer == "H":
                print("==> Sending command to alter Humidity period to", period, "\n")                
                client.publish(configtopic, json.dumps([EV_Humidity, period]), qos=1)
            if answer == "C":
                print("==> Sending command to alter Compass period to", period, "\n")                    
                client.publish(configtopic, json.dumps([EV_Compass, period]), qos=1)
        
        if answer == "X":
            print("==> Sending command to terminate measurements\n")
            client.publish(starttopic, json.dumps(EXITcommand), qos=1, retain=True)
            client.loop()
            CMD_Terminate = True
        
        if answer == "!":
            print("Termination accepted.\n")
            CMD_Terminate = True            
            
    print(goodbye)
    client.disconnect()
