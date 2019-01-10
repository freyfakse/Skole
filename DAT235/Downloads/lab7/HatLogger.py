# -*- coding: utf-8 -*-

#
#  HatLogger
#
#  - Feel free to improve on the code :-)
#

from sense_hat import SenseHat
import time 
import SenseLogger
import sys


black = (0,0,0)
yellow = (255,255,0)
white = (127,127,127)
trail = black    # the eater trail
eater = yellow   # the eater position (bright yellow)


if  __name__ == "__main__":
    """We basically want to log all events except the "event" events."""
    hat = SenseHat()
    
    hat.set_rotation(180)
    
    log_name = "HatLogger.log"
    log = SenseLogger.Logger(log_name, " *** Logging various events.")
    log.log_time(time.time(),"The HatLogger log trial.")   
    
    print("Clearing the LED matrix")
    hat.clear(white)
    log.log_clear(white)
    
    time.sleep(1)
    print("Setting pixels")
    for i in range(8):
        hat.set_pixel(i,i,[0,0,255])                # Blue
        log.log_pixel(i,i,hat.get_pixel(i,i))
    for i in range(8):
        hat.set_pixel(7-i, i, [0,255,0])            # Green
        log.log_pixel(7-i,i,hat.get_pixel(7-i,i))  
    
    time.sleep(1)
    print("Loading a pixelmap")
    X = [255, 0, 0]  # Red
    O = white
    
    question_mark = [
    O, O, O, X, X, O, O, O,
    O, O, X, O, O, X, O, O,
    O, O, O, O, O, X, O, O,
    O, O, O, O, X, O, O, O,
    O, O, O, X, O, O, O, O,
    O, O, O, X, O, O, O, O,
    O, O, O, O, O, O, O, O,
    O, O, O, X, O, O, O, O]    
    
    hat.set_pixels(question_mark)  
    log.log_pixelmap(question_mark) 
    log.log_time()
    time.sleep(1)
    print("Logging a message and a letter")
    noneshallpass = "None Shall Pass"
    hat.show_message(noneshallpass, 0.05, white, black)
    log.log_message(noneshallpass, 0.05, white, black)
    time.sleep(1)
    log.log_time()
    hat.show_letter("0",yellow,black)
    log.log_letter("0",yellow, black)
    hat.show_letter(" ")
    log.log_time()
    
    print(noneshallpass)
    sys.stdout.flush()
    
    time.sleep(1)
    print("Temperature, Humidity and Pressure")
    log.log_temperature(hat.get_temperature())
    log.log_humidity(hat.get_humidity())
    log.log_pressure(hat.get_pressure())
    
    time.sleep(1)
    print("Compass: degrees to north: ", end="")
    hat.set_imu_config(True, False, False)  # compass only
    north = hat.get_compass()
    print("{:5.2f}".format(north))
    log.log_compass(north)
    
    time.sleep(1)
    log.log_rotation(hat.rotation)  # the current rotation 
    print("Sense HAT rotation: "+str(hat.rotation))
    log.log_time(message="Ready for some rotations -- starting from "+str(hat.rotation))
    
    hat.set_rotation(0)
    log.log_rotation(0)
    hat.show_letter("?",white,black)
    log.log_letter("?",white,black)
    time.sleep(1)
    log.log_time()    
    hat.set_rotation(90)
    log.log_rotation(90)
    hat.show_letter("?",white,black)
    log.log_letter("?",white,black)    
    time.sleep(1)
    log.log_time()        
    hat.set_rotation(180)
    log.log_rotation(180)
    hat.show_letter("?",white,black)
    log.log_letter("?",white,black)
    time.sleep(1)
    log.log_time()        
    hat.set_rotation(270)
    log.log_rotation(270)
    hat.show_letter("?",white,black)
    log.log_letter("?",white,black)   
    time.sleep(1)
    log.log_time()     
    hat.set_rotation(0)
    log.log_rotation(0)
    hat.show_letter("?",black,white)
    log.log_letter("?",black,white) 
    
    input("use joystick")
    event = hat.stick.get_events()
    log.log_joystick(event)
    
    time.sleep(1)
    log.log_time()
    print("That's it for now.")
    hat.clear()       
    log.log_clear()
    log.StopLog(log_name+" *** finished logging.")
    
