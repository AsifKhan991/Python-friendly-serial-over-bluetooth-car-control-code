import serial
import keyboard
import time

COM='COM7'
baud=57600

port=1
Ardu_stat=1


if Ardu_stat==1:
    try:
        arduino = serial.Serial(COM, baud)
        print(' Port found! ')
    except serial.serialutil.SerialException:
        print(' Port not found! ')
        port=0

    
max_angle=60 #40 to 160
currentspeed=80

    
    

while True:
    speed=0
    steer_angle=100
    try:
            if keyboard.is_pressed('up'):
                speed=currentspeed
            if keyboard.is_pressed('down'):
                speed=-currentspeed
            if keyboard.is_pressed('left'):
                steer_angle=100-max_angle
            if keyboard.is_pressed('right'):
                steer_angle=100+max_angle


    except:
            pass        
    if Ardu_stat==1 and port==1:    
        data=str(steer_angle)+","+str(speed)+";\n"
        arduino.write(data.encode())
    print(speed)
    
    try:
            if keyboard.is_pressed('q'):
                    break# if key 'q' is pressed 

    except:
            pass
          


print('Closing..')
    
if Ardu_stat==1 and port==1:	
    arduino.write('100,0;\n'.encode())
    time.sleep(0.2)
    arduino.close()
    
