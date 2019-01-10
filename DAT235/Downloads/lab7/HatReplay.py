#
#    HatReplay -- replay most action, but not the joystick events (they are merely noted)
#
#    -- Rename the file to HatReplay.py
#    -- Feel free to improve the code :-)
#

from sense_hat import SenseHat
import time 
import sys
import json
import SenseLogger


sense = SenseHat()

if len(sys.argv)==1:
    log_name = input("Which log file to read? ")
else:
    log_name = sys.argv[1]
    

try:
    f = open("HatLogger.log", "r")
except:
    sys.stderr.write("Well, that didn't go so well. Just couldn't open the file '"+log_name+"'")
    sys.exit(1)
    

simtime = None

for line in f:
    if line[0]=="@":
        event = json.loads(line[1:])
        print("Event: ",event[0],end=" - ")  
        
        if event[0] == SenseLogger.EV_Joystick:
            timestamp = event[1]
            if simtime == None: simtime = timestamp
            time.sleep(timestamp-simtime)
            simtime = timestamp
            print("Joystick event: ",event[2], event[3], " (we are ignoring it)")
            
        if event[0] == SenseLogger.EV_Time:
            timestamp = event[1]
            if simtime == None: simtime = timestamp
            timediff = timestamp-simtime
            print("Waiting {:5.2f} seconds".format(timediff))
            time.sleep(timestamp-simtime)
            simtime = timestamp
            
        if event[0] == SenseLogger.EV_Clear:
            rgb = event[1]
            print("Colour: ",rgb)
            sense.clear(rgb)
            
        if event[0] == SenseLogger.EV_Pixel:
            #
            #  You write this code
            #
            x=event[1]
            y=event[2]
            rgb = event[3]
            print("Pixel: ",x,y,rgb)
            #sense.clear(x,y,rgb)
        
        if event[0] == SenseLogger.EV_Pixelmap:
            #
            # You write this code
            #
            pixelmap = event[1]
            print("Pixelmap: ",pixelmap)
            #sense.clear(pixelmap)
            
        if event[0] == SenseLogger.EV_Message:
            #
            # You write this code
            #
            message, scroll_speed, text_colour, back_colour = event[1:]
            print("Message: ",message, scroll_speed, text_colour, back_colour)

        if event[0] == SenseLogger.EV_Letter:
            #
            # You write this code
            #
            char, text_colour, back_colour = event[1:]
            print("Letter: ",char, text_colour, back_colour)

        if event[0] == SenseLogger.EV_Temperature:
            print("Temperature: ",event[1])
        
        if event[0] == SenseLogger.EV_Humidity:
            print("Humidity: ",event[1]) 
            
        if event[0] == SenseLogger.EV_Pressure:
            print("Pressure: ",event[1])    
            
        if event[0] == SenseLogger.EV_Compass:
            print("North: ",event[1])
        
        if event[0] == SenseLogger.EV_Rotation:
            print("Rotation: ",event[1])  
            sense.set_rotation(event[1])
        
    
