#TestTimer
import EventTimer
import time
import random


def BasicTest1():
    t = EventTimer.EvTimer()

    dat235 = list("DAT235")
    delay = 5000

    while len(dat235)>0:
        ch = dat235.pop()
        t.SetTimer(delay*len(dat235), [ch,"A message"])
    
    while t.EventCnt()>0:
        if t.timeout():
            print("This happened now: ",t.GetEvent())
        else:
            print("Nothing ever happens.... --- ....taking a short nap")
            time.sleep(1)

            
    t.Dump()
    print("Nothing more to do...!")
            
    
def BasicTest2():
    t = EventTimer.EvTimer()

    dat235 = list("DAT235 Security and IoT")
    delay = 1000

    while len(dat235)>0:
        ch = dat235.pop()
        t.SetTimer(delay*len(dat235), [ch,len(dat235)])
    
    while t.EventCnt()>0:
        print("Waiting for something to happen!")
        event = t.waitTimeout()
        print("Eventually, this happened: ",event,"\n")
        
        # insert another event?  -- a 1/3 chance of that happening here
        if random.choice([True,False,False]):
            t.SetTimer(random.randint(1000, 5000), ["A random event was inserted."])
            
    print("Nothing more to do...!")
    
    
def BasicTest3():
    t = EventTimer.EvTimer()

    dat235 = list("DAT235 Security and IoT")
    dat235 = dat235*10
    delay = 100

    while len(dat235)>0:
        ch = dat235.pop()
        t.SetTimer(delay*len(dat235), [ch,len(dat235)])
    
    t.Dump()
    #return None

    while t.EventCnt()>0:
        print("Waiting for something to happen!")
        event =t.waitTimeout()
        print("Eventually, this happened: ",event,"\n")
        
        # delete all events  -- a 1/10 chance of that happening here
        if random.randint(1,10)==10:
            print("Still ",t.EventCnt()," events coming up, but I'm done!")
            t.Reset()
            print("Reset(). New events? : ",t.EventCnt())
            
    print("Nothing more to do...!")
    
    
def BasicTest4():
    t = EventTimer.EvTimer()

    dat235 = list("DAT235 Security and IoT")
    dat235g = list("DAT235 Security and IoT")

    delay = 100

    while len(dat235)>0:
        ch = dat235.pop()
        t.SetTimer(delay*len(dat235), [ch,t.EventCnt()])
        
    while t.EventCnt()>0:
        print("Waiting for something to happen!")
        event = t.waitTimeout()
        print("Eventually, this happened: ",event,"\n")
        
        # cancel an event 
        tag = random.choice(list(dat235g))
        print("Cancelling and event with tag=",tag)
        event = t.CancelEvent(tag)
        if event==None:
            print("Nothing to cancel (?)")
        else:
            print("Cancelled this event: ",event)
        
            
    print("Nothing more to do...!")
