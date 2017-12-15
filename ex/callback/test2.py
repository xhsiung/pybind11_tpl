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
    callback = MyCallback(3)
    emit(callback, 4)

coroutine1 = do_some_work(1)
coroutine2 = do_some_work(1)
tasks=[ asyncio.ensure_future( coroutine1) ,
        asyncio.ensure_future( coroutine2) ,
    ]


print("end")

loop = asyncio.get_event_loop()
loop.run_until_complete( asyncio.wait(tasks) )

try:
    loop.run_forever()
finally:
    loop.run_until_complete(loop.shutdown_asyncgens())
    loop.close()
