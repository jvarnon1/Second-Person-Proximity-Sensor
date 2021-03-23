
import RPi.GPIO as GPIO # RPi.GPI0 is a python package 
import time #python module

GPIO.setwarnings(False) #suppress warning messages
GPIO.cleanup() 
GPIO.setmode(GPIO.BCM)

#positions on board
TRIG = 4
ECHO = 18
GREEN = 17
YELLOW = 27
RED = 22

#set components as input or outputs
GPIO.setup(TRIG,GPIO.OUT)
GPIO.setup(ECHO,GPIO.IN)
GPIO.setup(GREEN,GPIO.OUT)
GPIO.setup(YELLOW,GPIO.OUT)
GPIO.setup(RED,GPIO.OUT)

#setup the lights colors
def green_light():
	GPIO.output(GREEN, GPIO.HIGH)
	GPIO.output(YELLOW, GPIO.LOW)
	GPIO.output(RED, GPIO.LOW)

def yellow_light():
	GPIO.output(GREEN, GPIO.LOW)
	GPIO.output(YELLOW, GPIO.HIGH)
	GPIO.output(RED, GPIO.LOW)

def red_light():
	GPIO.output(GREEN, GPIO.LOW)
	GPIO.output(YELLOW, GPIO.LOW)
	GPIO.output(RED, GPIO.HIGH)

#get the distance(cm) from the sensor
def get_distance():
	GPIO.output(TRIG, True)
	time.sleep(0.00001)
	GPIO.output(TRIG, False)
	while GPIO.input(ECHO) == False: start = time.time()

	while GPIO.input(ECHO) == True: end = time.time()

	signal_time = end-start
	distance = signal_time / 0.000058

	return distance

#using distance, determine which light to turn on
while True:
	distance = get_distance()
	time.sleep(0.05)

	print(distance)

	if distance >= 25:
		green_light()

	elif 25 > distance > 10:
		yellow_light()

	elif distance <= 5:
		red_light()
