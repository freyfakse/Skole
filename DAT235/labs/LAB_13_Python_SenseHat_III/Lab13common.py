#
#  Lab13common
#
#    Common definitions for LAb13 programs
#


#  Topic
devicename  = "NilDev00"   #  Modify the device name
maintopic   = "dat235/lab13/"+devicename+"/sensor/"      
starttopic  = maintopic+"start"
configtopic = maintopic+"config"


#  Defines a leaf-topic/event name
EV_Temperature = "temperature"     
EV_Pressure    = "pressure"
EV_Humidity    = "humidity"
EV_Compass     = "compass"


# Event topics
temperaturetopic = maintopic+EV_Temperature
pressuretopic    = maintopic+EV_Pressure
humiditytopic    = maintopic+EV_Humidity
compasstopic     = maintopic+EV_Compass


# Event periods -- all numbers in 1/10 second
PERIOD_Temperature =   50
PERIOD_Pressure    =  100
PERIOD_Humidity    =   70
PERIOD_Compass     =  120


# The exit command (will be json encoded)
EXITcommand = "EXIT"


