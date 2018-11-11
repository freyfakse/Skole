import paho.mqtt.publish as publish
from sense_hat import SenseHat
import time

goodbye = "\nThat's all folks -- take care.\n"
print("A very simple publisher - publishing to dat235/test/gmk\n")
i = 0

sense = SenseHat()
host = "localhost"

while True:
    publish.single("dat235/test/gmk ",str(i), hostname=host)
    i += 1
    time.sleep(1)
    if (100 == i): break
    
publish.single("dat235/test/gmk ",goodbye, hostname=host)

print(goodbye)