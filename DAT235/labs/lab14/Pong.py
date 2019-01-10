import paho.mqtt.client as mqtt
import sys
import time


host = "localhost"          #  MQTT broker host address


# definitions and intial data config
hello = "Pong started"
goodbye = "Pong ended"
pingpongtopic = "dat235/pingpong"

#  global objects
client = None
payload = None


# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, flags, rc):  
    if rc!=0:
        print("Cannot connect properly")
        sys.exit(1)
        
    print("Connected with result code "+str(rc))
    sys.stdout.flush()

    
# The callback for when a PUBLISH message is received from the server.
def on_message(client, userdata, msg):  
    global payload
    payload = msg.payload


def initially():
    try:
        client = mqtt.Client(client_id="pong")
        client.on_connect = on_connect
        client.on_message = on_message
        client.username_pw_set("pong", "123")
        client.connect(host)
        client.loop()
    except:
        print("Tried to connect, but it failed. Exiting now.\n", file=sys.stderr)
        sys.stderr.flush()
        sys.exit(1)
        
    return(client)


if __name__ == "__main__":
    print(hello)   
    sys.stdout.flush()    
    client = initially()
    client.subscribe(pingpongtopic)
    client.loop()
    
    client.publish(pingpongtopic,0)  
    client.loop()
    
    # The main event-loop
    while True:
        client.loop()
        if payload!=None:
            if int(payload)%2 == 1:
                print("Pong: ponged with ",int(payload),", pinging back.")         
                sys.stdout.flush()
                client.publish(pingpongtopic,int(payload)+1)
            payload = None
        time.sleep(1)

    print(goodbye)
    client.disconnect()
