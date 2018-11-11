#
#   EventTimer- EvTimer
#
#   A very simple event timer
#   - EvTimer() -- Create a timer
#   - Reset() -- Cancel all events
#   - EventCnt() -- Returns the number of outstanding events
#   - SetTimer(ms : int, event) - Insert an event with timeout ms milliseconds in the future
#   - timeout() -- Returns True if there is an event ready. non-blocking
#   - GetEvent() -- Return the first event in the eventlist (irrespective of timeouts). May be None.
#   - waitTimeout() -- Waits until there is a timeout, but only if there is at least one event waiting. blocking
#   - CancelEvent(tag) -- resets one event at max (identified by the tag)
#
#   - event -- list. Shall always have a string tag as the zero'th element. Minimu length is 1
#              [0]  - tag : str
#              [n]  - parameters (n in [1..MAXINT]
#

import time
import bisect


class EvTimer():
    _eventlist = []
    
    
    def __init__(self):
        self.Reset()
        
        
    def Reset(self):
        """ Resets the eventlist """
        self._eventlist = []
            
            
    def EventCnt(self):
        return(len(self._eventlist))
    
    
    def SetTimer(self, ms : int, event : list):
        """ Inserts the event in the eventlist """
        bisect.insort(self._eventlist,[time.time()+ms/1000, event])
        
        
    def timeout(self):
        """ Returns True if there was a timeout """
        if len(self._eventlist)<=0:
            # empty list
            return(False)
        else:
            return(time.time()>=self._eventlist[0][0])
        
        
    def GetEvent(self):
        """ Returns first event in the list - if any """
        if len(self._eventlist)<=0:
            return(None)
        else:
            return(self._eventlist.pop(0))
    
    
    def waitTimeout(self):
        """ Wait until there is a timeout -- returns the event (or None) """
        if  len(self._eventlist)<=0:
            return(None)
        else:
            if self.timeout():
                return(self.GetEvent())
            else:
                # no timeout yet -- need to wait
                # This code will ignore events (if any) that is inserted while waiting
                time.sleep(self._eventlist[0][0]-time.time())
                return(self.GetEvent())
            
            
    def CancelEvent(self, tag : str):
        """ Removes (and returns) at most one instance of the tagged event """
        if self.EventCnt()<=0:
            # No events
            return(None)
        else:
            # Return first event that matches -- if any
            for i in range(len(self._eventlist)):
                if self._eventlist[i][1][0] == tag:
                    return(self._eventlist.pop(i))
            # No match
            return(None)
        
        