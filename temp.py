#!/usr/bin/env python3

import serial
import subprocess

ser = serial.Serial("/dev/ttyUSB0", baudrate=115200)

while (True):
    status = ser.readline()
    status += ser.readline()
#   print(status)
    subprocess.Popen(["notify-send", status])
