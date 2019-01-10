import paho.mqtt.publish as publish
import paho.mqtt.subscribe as subscribe
import sys
from sense_hat import SenseHat

red = [255,0,0]

sense = SenseHat()
sense.set_rotation(180)



smc = "Simple MQTT Calculator\n"

print(smc)

publish.single("dat235/calc",smc, hostname="localhost")

accum = 0
#publish.single("dat235/calc/eval",payload=None, retain=True, hostname="localhost")
publish.single("dat235/calc/eval",accum, hostname="localhost")    

while True:
    if(accum < 0):
        accum = 0

    elif(accum > 63):
        accum = 63

    emptylist = []

    #alternativ 1
    emptylist=[red]*accum

    #alternativ 2
    #for i in range(accum):
    #    emptylist.append(red)

    for i in range(64-accum):
        emptylist.append([0,0,0])
    
        
    sense.set_pixels(emptylist)
    
    #print(len(emptylist))
    
    msg = subscribe.simple("dat235/calc/oper/#",hostname="localhost")
    print("%s %s" % (msg.topic, msg.payload))     
    if msg.topic == "dat235/calc/oper/load": accum = int(msg.payload)    
    if msg.topic == "dat235/calc/oper/add": accum += int(msg.payload)
    if msg.topic == "dat235/calc/oper/sub": accum -= int(msg.payload)  
    if msg.topic == "dat235/calc/oper/mul": accum = accum * int(msg.payload)
    if msg.topic == "dat235/calc/oper/div": 
        if int(msg.payload) == 0:
            publish.single("dat235/calc/eval","***  Invalid operation: Divide by zero", hostname="localhost")
            publish.single("dat235/calc/eval","***  Resetting the calculator", hostname="localhost") 
            print("***  Invalid operation: Divide by zero"+"\n"+"***  Resetting the calculator"+"\n")
            sys.stdout.flush()            
            accum = 0
        else:
            accum = accum // int(msg.payload)   
    
    publish.single("dat235/calc/eval",accum, hostname="localhost")
    print("===>  Accum: ",accum)
    sys.stdout.flush()        

