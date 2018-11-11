#  Module SenseLogger  
#
#  --> Rename the file to "SenseLogger.py", and write the missing functions
#

import time
import json


EV_Joystick     = "Joystick"
EV_Time         = "Time"
EV_Clear        = "Clear"
EV_Pixel        = "Pixel"
EV_Pixelmap     = "Pixelmap"
EV_Message      = "Message"
EV_Letter       = "Letter"
EV_Temperature  = "Temperature"
EV_Humidity     = "Humidity"
EV_Pressure     = "Pressure"
EV_Compass      = "Compass"
EV_Rotation     = "Rotation"


class Logger:
    f = None
    
    def __init__(self, filename = "SenseHAT_event.log", message=""):
        self.f = open(filename,"w")
        self.f.write("#\n")
        self.f.write("#  Sense HAT logging started: "+time.asctime()+" "+message+"\n")
        self.f.write("#\n")


    def _write(self, event : str):
        self.f.write("@"+event+"\n")

        
    def log_joystick(self,event):
        """Logging a Sense HAT Joystick event"""
        #
        #   Lab_08 
        #
        #print(type(eventlist.timestamp))
        
        
            
        self._write(json.dumps([EV_Joystick, event.timestamp,event.direction,event.action]))
       
        
    
    def log_time(self, timestamp=None,message=""):
        """Logging a Sense HAT time event"""
        if timestamp==None:
            timestamp = time.time()
        event = [EV_Time, timestamp]
        if message!="":
            event.append(message)
        self._write(json.dumps(event))
    
    
    def log_clear(self, rgb=[0,0,0]):
        """Log a call to clear()"""
        event = [EV_Clear, rgb]
        self._write(json.dumps(event))


    def log_pixel(self, x,y,rgb):
        """Log a pixel setting"""
        event = [EV_Pixel, x, y, rgb]
        self._write(json.dumps(event))


    def log_pixelmap(self, pixelmap):
        """Log a pixel map"""
        #
        #   Lab_07
        #
        event = [EV_Pixelmap,pixelmap]
        self._write(json.dumps(event))
    
    
    def log_message(self, message, scroll_speed, text_colour, back_colour):
        """Log show_message"""
        #
        #   Lab_07
        #
        event = [EV_Message,message,scroll_speed, text_colour, back_colour]
        self._write(json.dumps(event))
        
    
    def log_letter(self, char, text_colour, back_colour):
        """Log show_message"""
        #
        #  Lab_07
        #
        event = [EV_Letter,char,text_colour,back_colour]
        self._write(json.dumps(event))
    
    
    def log_temperature(self, temperature):
        """Log temperature"""
        #
        #  Lab_07
        #
        event = [EV_Temperature,temperature]
        self._write(json.dumps(event))
    
    
    def log_humidity(self, humidity):
        """Log humidity"""
        #
        #  Lab_07
        #
        event = [EV_Humidity,humidity]
        self._write(json.dumps(event))


    def log_pressure(self, pressure):
        """Log pressure"""
        #
        #  Lab_07
        #
        event = [EV_Pressure,pressure]
        self._write(json.dumps(event))


    def log_compass(self, north):
        """Log compass"""
        #
        #  Lab_07
        #
        event = [EV_Compass,north]
        self._write(json.dumps(event))


    def log_rotation(self, rotation):
        """Log rotation"""
        #
        #  Lab_07
        #
        event = [EV_Rotation,rotation]
        self._write(json.dumps(event))


    def StopLog(self, message=""):
        """Close the log"""
        self.f.write("#\n")
        self.f.write("#  Sense HAT logging stopped: "+time.asctime()+" "+message+"\n")
        self.f.write("#\n")
        self.f.close()
    
        
