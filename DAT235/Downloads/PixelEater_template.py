from sense_hat import SenseHat
from time import sleep
import sys

sense = SenseHat()

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

visited = None
vis = set()


def allEaten():
    accum = 0
    for x in range(0,8):
        for y in range(0,8):
            if visited[x][y]: accum += 1
    return (accum==64)


def matrix_init():
    global x_pos, y_pos, visited, vis

    visited = [[False for i in range(0,8)] for j in range(0,8)]
    
    x_pos = 0
    y_pos = 0
    sense.clear(white)
    sense.set_pixel(x_pos,y_pos,eater)
    vis.add((x_pos, y_pos))

    visited[x_pos][y_pos] = True


def event_loop():
    global x_pos, y_pos
    prev_pos = None
    # ***  your code here  ***
    
    
    while True:
        if len(vis) == 64:
            done()
            sleep(0.3)
        event = sense.stick.wait_for_event(emptybuffer = True)
        if not event.action == "released":
            print(event.action,event.direction)
            if event.direction=="left":
                prev_pos = (x_pos, y_pos)
                x_pos=(x_pos+1) % 8
                redraw(x_pos, y_pos, prev_pos)
                
            elif event.direction=="right":
                prev_pos = (x_pos, y_pos)
                x_pos=(x_pos-1) % 8
                redraw(x_pos, y_pos, prev_pos)
                
            elif event.direction=="down":
                prev_pos = (x_pos, y_pos)
                y_pos=(y_pos-1) % 8
                redraw(x_pos, y_pos, prev_pos)
                
            elif event.direction=="up":
                prev_pos = (x_pos, y_pos)
                y_pos=(y_pos+1) % 8
                redraw(x_pos, y_pos, prev_pos)
            else:
                sense.clear()
                done()
            
        #print(type(event.action))

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


if  __name__ == "__main__":
    sense.set_rotation(180)
    
    matrix_init()
    event_loop()
     
    #sense.show_message("PixelEater template")

    sense.clear()
