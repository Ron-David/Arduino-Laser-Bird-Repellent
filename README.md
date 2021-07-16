

# Arduino-Laser-Bird-Repellent
Laser-Bird-Repellent is an IOT device that detects with the help of an ultrasonic sensor whether the pigeon is on the window and then activates a laser in its direction - the pigeon interprets the laser as an object moving toward its direction and therefore its natural reflex is to flee in panic, which will cause all pigeons near by to flee as well.

/-------------------------/

Requirements:
- Arduino Uno
- Ultrasonic sensor
- Laser
- 2 Servos
- Wifi module (optional) // I used NodeMCU as a wifi module
- Wires
- Servo bracket

/-------------------------/

Connection table:

NodeMCU: 					
- 3.3V to 3.3V 			
- GND to GND				
- GPI05 to TX			
- GPI04 to RX

Servo #1:
- 5V to 5V
- GND to GND
- Signal to 3

Servo #2:
- 5V to 5V
- GND to GND
- Signal to 4

Ultrasonic:		
- 5V to 5V		
- GND to GND	
- Echo to 10
- Trig to 9

LASER:
- 5V to 11
- GND to GND


<img width="560" alt="Screen Shot 2021-07-16 at 18 39 00" src="https://user-images.githubusercontent.com/77014885/125975282-3c510146-eeaf-4df0-b81c-7d9a5d95e180.png">

<img width="812" alt="Screen Shot 2021-07-16 at 17 51 27" src="https://user-images.githubusercontent.com/77014885/125966999-f1d18b1b-1b0d-4dbf-80a4-8255f21efb36.png">



https://user-images.githubusercontent.com/77014885/125963787-c62c672d-6704-40d5-9aba-82deb52571a2.mov
