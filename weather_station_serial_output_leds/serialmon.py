#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  serialmon.py
#  
#  Copyright 2016 Paul Sutton <psutton@CoreDuo>
#  
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#  
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA 02110-1301, USA.
#  
#  

#http://shallowsky.com/blog/hardware/ardmonitor.html
import serial

ser = serial.Serial("/dev/ttyUSB0", 9600)
while True:
    print ser.readline()
    
while True :
    # Check whether the user has typed anything (timeout of .2 sec):
    inp, outp, err = select.select([sys.stdin, self.ser], [], [], .2)

    # If the user has typed anything, send it to the Arduino:
if sys.stdin in inp :
	line = sys.stdin.readline()
	self.ser.write(line)

    # If the Arduino has printed anything, display it:
if self.ser in inp :
	line = self.ser.readline().strip()
	print "Arduino:", line

