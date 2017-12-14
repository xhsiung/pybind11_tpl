#!/usr/bin/env python3
#coding-utf-8
from mylibs.my import Callback
from mylibs.my import emit
import  threading,time

class MyCallback( Callback ):
    def __init__(self, value):
        Callback.__init__(self, self, value)
        print("init")
    
    def callback(self, value1 , value2):
        print("got it callback:%i %i"%(value1, value2))    

def doWaiting():
    callback = MyCallback(3)
    emit(callback, 4)

thread1 = threading.Thread(target = doWaiting)    
thread1.start() 

print("end")
