import time
import tempfile
import os
from pyfingerprint.pyfingerprint import PyFingerprint


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

    ## Wait that finger is read
    while ( f.readImage() == False ):
        pass

    ## Converts read image to characteristics and stores it in charbuffer 1
    f.convertImage(0x01)

    ## Checks if finger is already enrolled
    result = f.searchTemplate()
    positionNumber = result[0]

    if ( positionNumber >= 0 ):
        print('A digital ja esta cadastrada na posicao #' + str(positionNumber))
        exit(0)

    print('Retire o dedo do sensor ...')
    time.sleep(2)

    print('Coloque o mesmo dedo no sensor ...')

    ## Wait that finger is read again
    while ( f.readImage() == False ):
        pass

    ## Converts read image to characteristics and stores it in charbuffer 2
    f.convertImage(0x02)

    ## Compares the charbuffers
    if ( f.compareCharacteristics() == 0 ):
        raise Exception('Dedos nao sao os mesmos.')

    ## Creates a template
    f.createTemplate()

    ## Saves template at new position number
    positionNumber = f.storeTemplate()
####################################################################
################## Download da imagem ##############################
####################################################################
    print('Coloque o mesmo dedo no sensor mais uma vez...')

## Wait that finger is read
    while ( f.readImage() == False ):
        pass

    print('Aguarde o final da operacao...')

    imageDestination =  tempfile.gettempdir() + '/fingerprint.bmp'
    f.downloadImage(imageDestination)

    #print('The image was saved to "' + imageDestination + '".')

    f = open("destination.txt", "w")
    f.write(imageDestination)
    f.close()

####################################################################

    print('Digital cadastrada com sucesso.')
    print('Nova digital cadastrada na posicao #' + str(positionNumber))

    f = open("test.txt", "a")
    f.write("Posicao: " + str(positionNumber) + "\n\n")
    f.close()

except Exception as e:
    print('Operation failed!')
    print('Exception message: ' + str(e))
    exit(1)

