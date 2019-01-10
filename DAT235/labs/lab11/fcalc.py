import sys

import paho.mqtt.publish as publish
import paho.mqtt.subscribe as subscribe


smc = "Simple MQTT Calculator App\n"

print(smc)


def load(num: int):
    publish.single("dat235/calc/oper/load", num, hostname="localhost")
    msg = subscribe.simple("dat235/calc/eval/#", hostname="localhost")
    print("Accum: %s" % (msg.payload))


# You write the rest
def add_val(num: int):
    publish.single("dat235/calc/oper/add", num, hostname="localhost")
    msg = subscribe.simple("dat235/calc/eval/#", hostname="localhost")
    print("Ny sum: %s" % (msg.payload))
    

def sub_val(num):
    publish.single("dat235/calc/oper/sub", num, hostname="localhost")
    msg = subscribe.simple("dat235/calc/eval/#", hostname="localhost")
    print("Ny sum: %s" % (msg.payload))


def mul_val(num):
    publish.single("dat235/calc/oper/mul", num, hostname="localhost")
    msg = subscribe.simple("dat235/calc/eval/#", hostname="localhost")
    print("Ny sum: %s" % (msg.payload))


def div_val(num):
    publish.single("dat235/calc/oper/div", num, hostname="localhost")
    msg = subscribe.simple("dat235/calc/eval/#", hostname="localhost")
    print("Ny sum: %s" % (msg.payload))


if __name__ == "__main__":
    main()

