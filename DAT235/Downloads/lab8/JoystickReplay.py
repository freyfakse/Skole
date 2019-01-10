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
#import JoystickLogger

sense = SenseHat()

'''
if len(sys.argv)==1:
    log_name = input("Which log file to read? ")
else:
    log_name = sys.argv[1]
    
'''
try:
    f = open("Joystick_events.log", "r")
except:
    sys.stderr.write("Well, that didn't go so well. Just couldn't open the file '"+log_name+"'")
    sys.exit(1)
    
x_pos = 0
y_pos = 7
red = (127,0,0)
green = (0,127,0)
blue = (0,0,127)
white = (127,127,127)
yellow = (127,127,0)
black = (0,0,0)

trail = black  # the eater trail
eater = (255,255,0)   # the eater position (bright yellow)

#visited = None
vis = set()

x_pos = 0
y_pos = 0
sense.clear(white)
sense.set_pixel(x_pos,y_pos,eater)
vis.add((x_pos, y_pos))
#visited[x_pos][y_pos] = True
    
def redraw(x_pos, y_pos, prev_pos):
    #sense.clear()
    sense.set_pixel(prev_pos[0],prev_pos[1], trail)
    sense.set_pixel(x_pos, y_pos, eater)
    #visited[x_pos][y_pos]=True
    vis.add((x_pos, y_pos))
    print(len(vis))


def done():
    sense.show_message("Victory")
    sense.clear()  

    
def pixelEater(action, direction):
    global x_pos, y_pos
    if not action == "released":
        print(action,direction)
        if direction=="right":
            prev_pos = (x_pos, y_pos)
            x_pos=(x_pos+1) % 8
            redraw(x_pos, y_pos, prev_pos)
                
        elif direction=="left":
            prev_pos = (x_pos, y_pos)
            x_pos=(x_pos-1) % 8
            redraw(x_pos, y_pos, prev_pos)
                
        elif direction=="up":
            prev_pos = (x_pos, y_pos)
            y_pos=(y_pos-1) % 8
            redraw(x_pos, y_pos, prev_pos)
                
        elif direction=="down":
            prev_pos = (x_pos, y_pos)
            y_pos=(y_pos+1) % 8
            redraw(x_pos, y_pos, prev_pos)
            
        else:
            sense.clear()
            #done()


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
            #print("Joystick event: ",event[2], event[3], " (we are ignoring it)")
            pixelEater(event[3],event[2])
            
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


    

