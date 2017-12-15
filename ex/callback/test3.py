#!/usr/bin/env python3
#coding-utf-8
from mylibs.my import Callback
from mylibs.my import emit
import asyncio

class MyCallback( Callback ):
    def __init__(self, value):
        Callback.__init__(self, self, value)
        print("init")
    
    def callback(self, value1 , value2):
        print("got it callback:%i %i"%(value1, value2))    


async def do_some_work(x):
    callback = MyCallback(x)
    emit(callback, 4)

print("end")

loop = asyncio.get_event_loop()
loop.run_until_complete( asyncio.gather(
    do_some_work(3),
    do_some_work(1),
))

loop.run_forever()