import random


birthdays = set()

def newrun():
    global birthdays
    random.seed()
    birthdays = set()
    print("\n\n")
    
def BirthdayDate(bd):
    if (bd <= 31): return ("%02d.01" % bd)
    bd -= 31
    
    if (bd <= 28): return ("%02d.02" % bd)
    bd -= 28
    
    if (bd <= 31): return ("%02d.03" % bd)
    bd -= 31
    
    if (bd <= 30): return ("%02d.04" % bd)
    bd -= 30
    
    if (bd <= 31): return ("%02d.05" % bd)
    bd -= 31
    
    if (bd <= 30): return ("%02d.06" % bd)
    bd -= 30
    
    if (bd <= 31): return ("%02d.07" % bd)
    bd -= 31
    
    if (bd <= 31): return ("%02d.08" % bd)
    bd -= 31
    
    if (bd <= 30): return ("%02d.09" % bd)
    bd -= 30
    
    if (bd <= 31): return ("%02d.10" % bd)
    bd -= 31
    
    if (bd <= 30): return ("%02d.11" % bd)
    bd -= 30
    
    if (bd <= 31): return ("%02d.12" % bd)

    return (" ??? ")
    
    
    
def BirthdayDraw():
    global birthdays
    bd = random.randrange(1,365)
    print("Birthday on "+BirthdayDate(bd))
    if (bd in birthdays):
        print("*** Another paradox after %d draws" % (len(birthdays)+1))
        return True
    else:
        birthdays.add(bd)
        return False
    return 


def BDrun():
    newrun()
    while True:
        if BirthdayDraw(): break 



if __name__ == "__main__":
    BDrun()