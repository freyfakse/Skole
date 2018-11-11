import paho.mqtt.publish as publish
import paho.mqtt.subscribe as subscribe
import sys
import paho.mqtt.client as mqtt

smc = "Simple MQTT Calculator App\n"

host= "localhost"

num=5

print(smc)

def load(num : int):
    publish.single("dat235/calc/oper/load",num, hostname="localhost")
    msg = subscribe.simple("dat235/calc/eval/#", hostname="localhost")
    print("Accum: %s" % (msg.payload))  

def on_connect(client,userdata,flags,rc):
    print("connected with rc:",rc)
    #mqttc.publish("dat235/calc/eval",10)
    mqttc.subscribe("dat235/calc/eval/#")

def on_message(client,userdata,message):
    print(message.topic,str(message.payload))


# You write the rest


if __name__ == "__main__":
    mqttc = mqtt.Client()

    mqttc.on_connect = on_connect

    mqttc.on_message = on_message

    mqttc.connect(host)

    

    mqttc.loop_forever()
    
    mqttc.publish("dat235/calc/oper/load",num)
