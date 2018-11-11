import paho.mqtt.client as mqtt
import sys
import time
import ssl
import os.path


host = "192.168.0.103"          #  MQTT broker host address

capath = ""                     #  Make sure the ca cert is there! 
cafile = "dat235ca.crt"         #


# definitions and intial data config
hello = "Secured Ping started, with pw and acl"
goodbye = "Pings ended"
pingpongtopic = "dat235/pingpong"

#  global objects
client = None
payload = None


# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, flags, rc):  
    if rc!=0:
        print("Cannot connect properly, rc=",rc)
        if rc==5:
            print("Not authorized!")
        sys.exit(1)
        
    print("Connected with result code "+str(rc))
    sys.stdout.flush()

    
# The callback for when a PUBLISH message is received from the server.
def on_message(client, userdata, msg):  
    global payload
    payload = msg.payload


# set up CA cert and make a TLS secured connect
def initially():
    fqcafile = os.path.join(capath,cafile)
    if not os.path.exists(fqcafile):
        print("CA cert cannot be found: ",fqcafile)
    else:
        print("CA cert file: ",fqcafile)
        
    try:
        client = mqtt.Client(client_id="ping")        
        client.username_pw_set("ping", password="Random_01")  
        
        # tls_set(): the certificate context, etc. -- there are more options!
        client.tls_set(ca_certs=fqcafile, tls_version=ssl.PROTOCOL_TLSv1_2)
        
        client.on_connect = on_connect
        client.on_message = on_message
        client.connect(host, port=8883)
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

    # The main event-loop
    while True:
        client.loop()
        if payload!=None:
            # best to be sceptical of Pong -- need input validation
            try:
                payint = int(payload)
            except ValueError:
                print("That was not a valid int: ",str(payload))
                print("Don't want any dirty play. Exiting now.")
                break
                
            if payint%2 == 0:
                print("Ping: pinged with "+str(payint)+", ponging back.")
                sys.stdout.flush()
                client.publish(pingpongtopic,payint+1)
            payload = None

        time.sleep(1)

    print(goodbye)
    client.disconnect()
