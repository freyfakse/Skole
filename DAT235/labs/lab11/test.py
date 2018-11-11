import sys

import paho.mqtt.publish as publish
import paho.mqtt.subscribe as subscribe


smc = "Simple MQTT Calculator App\n"

print(smc)


while True:
    msg = subscribe.simple("dat235/calc/eval", hostname="localhost")
    print(msg)
    
if __name__ == "__main__":
    main()


