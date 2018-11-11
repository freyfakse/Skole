import paho.mqtt.client as mqtt
import sys
import time
import ssl
import os.path

host = "192.168.0.103"          #  MQTT broker host address

capath = ""                     #  Make sure the ca cert is there! 
cafile = "dat235ca.crt"         #


# definitions and intial data config
hello = "Secured Pong started"
goodbye = "Pongs ended"
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
        client = mqtt.Client(client_id="pong")
        client.username_pw_set("pong", password="Random_02") 
        
        # explicitly set the certificate context -- there are more options!
        certctx = ssl.SSLContext(protocol=ssl.PROTOCOL_TLSv1_2)
        certctx.verify_mode = ssl.CERT_REQUIRED
        certctx.load_verify_locations(fqcafile)  
        client.tls_set_context(certctx)
        
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
    
    client.publish(pingpongtopic,0)  
    client.loop()
    
    cnt = 0
    # The main event-loop
    while True:
        client.loop()
        if payload!=None:
            if int(payload)%2 == 1:
                print("Pong: ponged with "+str(int(payload))+", pinging back.")         
                sys.stdout.flush()
                client.publish(pingpongtopic,int(payload)+1)
            payload = None
        time.sleep(1)

        cnt += 1
        if cnt>30:
            # publishing a text string -- Ping will not expect that!
            client.publish(pingpongtopic,"The end.") 
            break
        
    print(goodbye)
    client.disconnect()
