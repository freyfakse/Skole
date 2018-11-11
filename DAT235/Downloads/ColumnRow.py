from sense_hat import SenseHat
from time import sleep
import sys


sense = SenseHat()


# Basic colors - Rapidtables definitions
Black = [0,0,0]
White = [255,255,255]
Red = [255,0,0]
Lime = [0,255,0]
Blue = [0,0,255]
Yellow =[255,255,0]
Cyan = [0,255,255]
Aqua = Cyan
Magenta = [255,0,255]
Fuchsia = Magenta
Silver = [192,192,192]
Gray = [128,128,128]
Maroon = [128,0,0]
Olive = [128,128,0]
Green = [0,128,0]
Purple = [128,0,128]
Teal = [0,128,128]
Navy = [0,0,128]


# set_column -- either rgb is a list (len=3) or it is a list of lists (len=3)
def set_column(x, rgb):
    assert(isinstance(x,int))
    assert(x>=0 and x<8)    
    assert(isinstance(rgb,list))
    assert(len(rgb)==3 or len(rgb)==8)
    if len(rgb)==3:
        for y in range(0,8): sense.set_pixel(x,y,rgb)        
    if len(rgb)==8:
        for y in range(0,8): 
            assert(isinstance(rgb[y],list))
            assert(len(rgb[y])==3)
            sense.set_pixel(x,y,rgb[y])        
       

# set_row -- either rgb is a list (len=3) or it is a list of lists (len=3)
def set_row(y,rgb):
    assert(isinstance(y,int))
    assert(y>=0 and y<8)
    assert(isinstance(rgb,list))
    assert(len(rgb)==3)
    if len(rgb)==3:
        for x in range(0,8): sense.set_pixel(x,y,rgb)
    
    


# get_column -- returns a list of rgb tuples
def get_column(x):
    assert(isinstance(x,int))
    assert(x>=0 and x<8)
    pixmap = sense.get_pixels()
    
    '''
    column = pixmap[x:x+1]
    column = pixmap[x+8:x+8+1]
    '''
    return(pixmap[x-1::8])

        
# get_row -- returns a list of rgb tuples
def get_row(y):
    assert(isinstance(y,int)) 
    assert(y>=0 and y<8)
    pixmap = sense.get_pixels()
    return(pixmap[y*8:y*8+8])


if  __name__ == "__main__":
    print("Ready")
    sense.set_rotation(180)
    sense.clear()
    # minimal test -- and very bad taste in colours (!)
    '''for i in range(0,8,2):
        set_column(i,Red)
    for i in range(0,8,2):
        set_row(i,Green)
    
    row = 0
    while True:
        sense.clear()
        set_row(row,Red)
        row = (row + 1) % 8
        sleep(0.03)
    #set_row(3,Red)
    '''
    set_row(3,Red)
    set_row(7,Blue)
    sense.set_pixel(2,2,Yellow)
    
    print(get_column(3))
