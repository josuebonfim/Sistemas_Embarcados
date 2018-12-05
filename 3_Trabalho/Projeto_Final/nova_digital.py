from Adafruit_CharLCD import Adafruit_CharLCD
import time
import tempfile
import os
from pyfingerprint.pyfingerprint import PyFingerprint
import RPi.GPIO as GPIO

##Inicializacao do LCD


lcd = Adafruit_CharLCD(rs = 26, en = 19, d4 = 13, d5 = 6, d6 = 5, d7 = 11, cols = 16, lines = 2)
## Enrolls new finger
##

## Tries to initialize the sensor
try:
    f = PyFingerprint('/dev/ttyUSB0', 57600, 0xFFFFFFFF, 0x00000000)

    if ( f.verifyPassword() == False ):
        raise ValueError('The given fingerprint sensor password is wrong!')
        
        
except Exception as e:
    print('O sensor de impressao digital nao pode ser inicializado')
    print('Exception message: ' + str(e))
    exit(1)

## Gets some sensor information
#print('Templates Usados: ' + str(f.getTemplateCount()) +'/'+ str(f.getStorageCapacity()))

## Tries to enroll new finger
try:
    print('Coloque o dedo no sensor ...')
    lcd.clear()
    lcd.message("Coloque o dedo \n")
    lcd.message("no sensor (1/3)")

    ## Wait that finger is read
    while ( f.readImage() == False ):
        pass
        
    GPIO.setmode(GPIO.BCM)
    GPIO.setwarnings(False)
    GPIO.setup(18, GPIO.OUT)
    
    GPIO.output(18, GPIO.HIGH)
    time.sleep(0.1)
    GPIO.output(18, GPIO.LOW)
    time.sleep(0.1)
    time.sleep(0.5)

    ## Converts read image to characteristics and stores it in charbuffer 1
    f.convertImage(0x01)

    ## Checks if finger is already enrolled
    result = f.searchTemplate()
    positionNumber = result[0]

    if ( positionNumber >= 0 ):
        print('A digital ja esta cadastrada na posicao #' + str(positionNumber))
        exit(1)

    print('Retire o dedo do sensor ...')
    lcd.clear()
    lcd.message("Retire o dedo\n")
    lcd.message("do sensor 1/3")
    time.sleep(2)

    print('Coloque o mesmo dedo no sensor ...')
    lcd.clear()
    lcd.message("Coloque o dedo\n")
    lcd.message("no sensor 2/3")


    ## Wait that finger is read again
    while ( f.readImage() == False ):
        pass
        
    GPIO.output(18, GPIO.HIGH)
    time.sleep(0.1)
    GPIO.output(18, GPIO.LOW)
    time.sleep(0.1)
    time.sleep(0.5)

    ## Converts read image to characteristics and stores it in charbuffer 2
    f.convertImage(0x02)

    ## Compares the charbuffers
    if ( f.compareCharacteristics() == 0 ):
        raise Exception('Dedos nao sao os mesmos.')
    print('Retire o dedo do sensor ...')
    lcd.clear()
    lcd.message("Retire o dedo\n")
    lcd.message("do sensor 2/3")
    time.sleep(2)

    ## Creates a template
    f.createTemplate()

    ## Saves template at new position number
    positionNumber = f.storeTemplate()
####################################################################
################## Download da imagem ##############################
####################################################################
    print('Coloque o mesmo dedo no sensor mais uma vez...')
    lcd.clear()
    lcd.message("Coloque o dedo\n")
    lcd.message("no sensor 3/3")

## Wait that finger is read
    while ( f.readImage() == False ):
        pass
        
    GPIO.output(18, GPIO.HIGH)
    time.sleep(0.1)
    GPIO.output(18, GPIO.LOW)
    time.sleep(0.1)
    time.sleep(0.5)
    #lcd.clear()
    #lcd.message("Retire o dedo\n")
    #lcd.message("do sensor 3/3")
    print("Retire o dedo do sensor ...")
    lcd.clear()
    lcd.message("Retire o dedo\n")
    lcd.message("do sensor 3/3")
    time.sleep(2)

    print('Aguarde o final da operacao...')
    lcd.clear()
    lcd.message("Aguarde ...")

    imageDestination =  tempfile.gettempdir() + '/fingerprint.bmp'
    f.downloadImage(imageDestination)

    #print('The image was saved to "' + imageDestination + '".')

####################################################################

    print('Digital cadastrada com sucesso.')
    print('Nova digital cadastrada na posicao #' + str(positionNumber))
    lcd.clear()
    lcd.message("Digital Salva\n")
    lcd.message("na posicao " + str(positionNumber))

    f = open("position.txt", "w")
    f.write(str(positionNumber))
    f.close()

except Exception as e:
    print('Operation failed!')
    print('Exception message: ' + str(e))
    exit(1)

