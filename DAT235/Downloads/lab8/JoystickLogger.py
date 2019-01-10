# JoyStickLogger
from sense_hat import SenseHat
import time 
import SenseLogger


black = (0,0,0)
trail = black  # the eater trail
eater = (255,255,0)   # the eater position (bright yellow)
white = (127,127,127)


log = SenseLogger.Logger("Joystick_events.log","Logging a PixelEater run")


def pixelEater():
    sense = SenseHat()    
    sense.clear(white)
    log.log_clear(white)
    
    x = 0
    y = 7
    eaten = set()
    eaten.add((x,y))
    sense.set_pixel(x,y,eater)
    log.log_pixel(x,y,eater)
    
    
    print("A PixelEater to collect Joystick events - complete the LED matrix")             
    
    last = len(eaten)
    now = last
    print("Eaten ",now)
    
    while now<64:
        
        for event in sense.stick.get_events():            
            log.log_joystick(event)
            action = event.action
            direction = event.direction     
            combined = action+direction
            if combined in ["heldup","pressedup"]:
                sense.set_pixel(x,y,trail)
                y = (y - 1) % 8
                sense.set_pixel(x,y,eater)
                eaten.add((x,y))
                
            if combined in ["helddown","presseddown"]:
                sense.set_pixel(x,y,trail)
                y = (y + 1) % 8
                sense.set_pixel(x,y,eater)               
                eaten.add((x,y))                
           
            if combined in ["pressedleft","heldleft"]:
                sense.set_pixel(x,y,trail)
                x = (x - 1) % 8
                sense.set_pixel(x,y,eater)                 
                eaten.add((x,y))                
            
            if combined in ["pressedright","heldright"]:
                sense.set_pixel(x,y,trail)
                x = (x + 1) % 8
                sense.set_pixel(x,y,eater)           
                eaten.add((x,y))   
                
            now = len(eaten)
            if now>last:
                last = now
                print("Eaten ",now)


    print("What a meal!")
    sense.clear(black)
    log.log_clear(black)


if  __name__ == "__main__":
    log.log_time(time.time(),"Starting the show")   
    pixelEater()
    log.StopLog("End of game")  
