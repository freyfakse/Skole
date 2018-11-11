from sense_hat import SenseHat
import time

hat = SenseHat()
humidity = hat.get_humidity()

temp = hat.get_temperature()
print("Luftfuktighet: {:5.2f}".format(humidity))
print("Temperatur på RPI: {:5.2f}".format(temp))

print()

# alternatives
print("Luftfuktighet:",humidity)
print("Temperatur på RPI:",temp)

hat.set_rotation(180)

hat.show_message(str(temp), scroll_speed=0.1, text_colour=[255, 255, 255], back_colour=[0, 0, 0])
time.sleep(2)
