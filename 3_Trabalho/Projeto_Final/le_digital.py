#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
PyFingerprint
Copyright (C) 2015 Bastian Raschke <bastian.raschke@posteo.de>
All rights reserved.

"""
from Adafruit_CharLCD import Adafruit_CharLCD
import time
import tempfile
import os
import sys
import hashlib
from pyfingerprint.pyfingerprint import PyFingerprint
import RPi.GPIO as GPIO

##Inicializacao do LCD


lcd = Adafruit_CharLCD(rs = 26, en = 19, d4 = 13, d5 = 6, d6 = 5, d7 = 11, cols = 16, lines = 2)

lcd.message(" Acesso ao LEI\n")
lcd.message("   UnB - FGA")

sys.stdout.flush()
sys.stdout.close()

sys.stderr.flush()
sys.stderr.close()

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(18, GPIO.OUT)
GPIO.setup(17, GPIO.OUT)
GPIO.output(17, GPIO.HIGH)
## Search for a finger
##

## Tries to initialize the sensor
try:
    f = PyFingerprint('/dev/ttyUSB0', 57600, 0xFFFFFFFF, 0x00000000)

    if ( f.verifyPassword() == False ):
        raise ValueError('The given fingerprint sensor password is wrong!')

except Exception as e:
    print('The fingerprint sensor could not be initialized!')
    print('Exception message: ' + str(e))
    exit(1)
    


## Gets some sensor information
#print('Currently used templates: ' + str(f.getTemplateCount()) +'/'+ str(f.getStorageCapacity()))

## Tries to search the finger and calculate hash
try:
    #print('Waiting for finger...')

    ## Wait that finger is read
    while ( f.readImage() == False ):
        pass

    
    
    
    
    ## Converts read image to characteristics and stores it in charbuffer 1
    f.convertImage(0x01)

    ## Searchs template
    result = f.searchTemplate()


    positionNumber = result[0]
    accuracyScore = result[1]
    GPIO.output(18, GPIO.HIGH)
    time.sleep(0.1)
    GPIO.output(18, GPIO.LOW)
    time.sleep(0.1)
    time.sleep(0.5)
    if ( positionNumber == -1 ):
        lcd.clear()
        lcd.message("   Usuario\n")
        lcd.message(" nao cadastrado")
        lcd.clear()
        GPIO.output(18, GPIO.HIGH)
        time.sleep(0.1)
        GPIO.output(18, GPIO.LOW)
        time.sleep(0.1)
        GPIO.output(18, GPIO.HIGH)
        time.sleep(0.1)
        GPIO.output(18, GPIO.LOW)
        time.sleep(0.1)
        GPIO.output(18, GPIO.HIGH)
        time.sleep(0.1)
        GPIO.output(18, GPIO.LOW)
        time.sleep(0.1)
        os.system("sleep 2")
        exit(0)
    else:
        lcd.clear()
        lcd.message(" Usuario, Seja\n")
        lcd.message("   Bem-Vindo")
        GPIO.output(18, GPIO.HIGH)
        time.sleep(0.4)
        GPIO.output(18, GPIO.LOW)
        GPIO.output(17, GPIO.LOW)
        os.system("sleep 2")
        time.sleep(0.5)
        GPIO.output(17, GPIO.HIGH)
        lcd.clear()
     #   print('Found template at position #' + str(positionNumber))
     #   print('The accuracy score is: ' + str(accuracyScore))
    a = 0
    ## OPTIONAL stuff
    ##
    
    ## Loads the found template to charbuffer 1
    #f.loadTemplate(positionNumber, 0x01)

    ## Downloads the characteristics of template loaded in charbuffer 1
    #characterics = str(f.downloadCharacteristics(0x01)).encode('utf-8')

    ## Hashes characteristics of template
    #print('SHA-2 hash of template: ' + hashlib.sha256(characterics).hexdigest())

except Exception as e:
    print('Operation failed!')
    print('Exception message: ' + str(e))
    exit(1)
