#!/usr/bin/env python3
#coding=utf-8

#import sys; sys.path.append('mylibs')
from mylibs import my as pf

class B(pf.B):
    def __init__(self):
        super(B, self).__init__()
        pass

    def added_fcn(self):
        print("added_fcn run")
        return 3

b = B()
pf.call_parallel(b)

print("end")
