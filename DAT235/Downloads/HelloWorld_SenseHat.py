# -*- coding: utf-8 -*-
from sense_hat import SenseHat
import time

hat = SenseHat()

hat.show_message("D A T 2 3 5 ", scroll_speed=0.1, text_colour=[255, 255, 255], back_colour=[0, 0, 0])
time.sleep(2)

s = "DAT235 - Sikkerhet og IoT "
a = 0
while len(s)>0:
    letter = s[0]
    hat.show_letter(letter, text_colour=[a,0,127])    
    a = (a + 64) % 255
    s = s[1:]
    time.sleep(1)

    
hat.show_letter("!", text_colour=[255,0,0])
input("Enter for å ta farvel ")
hat.clear()