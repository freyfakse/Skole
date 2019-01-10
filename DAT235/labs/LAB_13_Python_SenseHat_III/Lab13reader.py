import paho.mqtt.client as mqtt
import json
import sys
import time
from Lab13common import *


host = "localhost"          #  MQTT broker host address
connected = False           #  Connected to MQTT broker
CMD_Terminate = False       #  Command: Terminate program


# definitions and intial data config
hello = "Lab13reader - controlling sensor data reporting "+maintopic+"#\n"
goodbye = "\nLab13reader -- terminating now\n"

#  global objects
client = None


# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, flags, rc):
    global connected
    
    if rc!=0:
        print("Cannot connect properly")
        sys.exit(1)
        
    if not connected:
        print("Connected with result code "+str(rc))
        sys.stdout.flush()
        connected = True
        return

    
# The callback for when a PUBLISH message is received from the server.
def on_message(client, userdata, msg):  
    global CMD_Terminate
    
    if msg.topic == starttopic:
        CMD_Terminate = json.loads(msg.payload.decode("utf-8")) == EXITcommand
        return
    
    print(time.ctime()+":  ", end="")
    if msg.topic == temperaturetopic:
        print("Temperature: ",json.loads(msg.payload.decode("utf-8")))     
    if msg.topic == pressuretopic:
        print("Pressure: ",json.loads(msg.payload.decode("utf-8")))
    if msg.topic == humiditytopic:
        print("Humidity: ",json.loads(msg.payload.decode("utf-8")))
    if msg.topic == compasstopic:
        print("Compass: ",json.loads(msg.payload.decode("utf-8"))) 
    sys.stdout.flush()           


def initially():
    try:
        client = mqtt.Client(client_id=devicename+"_reader")
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
            
    print("Starting subscriptions\n")
    sys.stdout.flush()
    client.subscribe(starttopic,qos=1)    
    client.subscribe(temperaturetopic)
    client.subscribe(pressuretopic)
    client.subscribe(humiditytopic)
    client.subscribe(compasstopic)  
    client.loop()
    
    return(client)


if __name__ == "__main__":
    print(hello)   
    sys.stdout.flush()    
    client = initially()

    # The main event-loop
    CMD_Terminate = False
    while not CMD_Terminate:
        client.loop()

    print(goodbye)
    client.disconnect()
