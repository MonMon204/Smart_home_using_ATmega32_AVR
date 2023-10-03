# Smart_home_using_ATmega32_AVR

Components:
          1. Temperature Sensor.
          2. DC Motor.
          3. KeyPad
          4. LCD
          5. LEDs
          6. ATmega 32

Operation :
1. When user tries to Enter system should ask for password by displaying this message on LCD “Please Enter Password”
2. User Enters password through keypad .
3. If user enters a correct password , system will display a successful login message Ex :“welcome Ahmed”.
4. If user Enters a wrong password , the system should display this message , “wrong password , please Try again”.
5. The user has a maximum of 3 times to try to enter a correct password after that the system will lock for 2 minutes .
6. After a successful login , the system display
    this message :
    1- Leds ON
    2- Leds OFF
user can choose to control leds using keypad.
• System should monitor the temperature Sensor at all times
• if : temp <= 25  DC motor is off
• if : temp > 25 & temp < 30  DC motor is ON with half speed
• if : temp >= 30  DC motor is ON with full speed





https://github.com/MonMon204/Smart_home_using_ATmega32_AVR/assets/143510444/fa24c501-28ad-4ba5-86f6-299dc1371ede

