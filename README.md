# WokTimeVisualizer

I made this device to help me track and reduce the number of hours I spend working every day. Working over multiple time zones means that I can’t really rely on the time of the day. And software tools didn’t work for me, I needed something visual.

****This is a tool for all my workaholic friends out there.****

12 lights for 12 hours. Large enough to be visible but not distracting.

IT people make jokes that one 24h day has 3 MDs of work. If I still end up working more than 12 hours then this device is not working.

## Light configuration:

1-6 – Green lights – keep working

7-8 – Orange – time is running out, finish things and plan for tomorrow

9-10 – Red – stop working

11-12 – flashing RED – seriously, stop working

12+ All lights are flashing red. Self-destruction in progress.

## Other functionality:
-	Every hour is saved to EEPROM and retrieved when turned back on.
-	Progress can be manually adjusted with a push button on the back.
-   After 13 hours is reached, automatic counting will not continue and it will end there.


## Recommendations for time tracking:

The idea is to track real time spent working, not just time of the day. Connect device to a cable with a switch, or even better to a smart plug. Then you can integrate it in your routines or control with voice or SmartDeck.

### Here is my setup:
-	Connected to a smart plug.
-	I have a routine to start working that I activate with the voice/Smart Deck. I added this plug to the routine and it will be turned on.
-	I have IFTTT integration and a toggle button on my Smart Deck so I can turn it off and back on with a button whenever I’m taking a break from work.
-	I have a routine to end work in the evening, this will turn it off.


## 3D Printing:
No supports needed, infill as you wish.

Front white diffuser can be replaced with a sheet of paper for very clean look. Or thin black acrylic diffuser for stealth look.

Back LED Cover has holders to fit prototype  PCB board of 10cm length (this one: https://amzn.to/3XEdoul). You can print a version without PCB holder and figure out a different way to mount your electronic (hot-glue?) 

Back box cover is provided in versions with and without hole for the push button. Since the part is very thin, you can easily drill the hole to fit your button location.


Files are also uploaded to Printables: HERE

## Other hardware:
Apart from the 3d printed parts, the following is needed:
-	Smaller Arduino board with EEPROM. Some boards such as Seeeduino Xiao don’t have EEPROM and you will need to use emulator instead. I used ATTINY85 - https://amzn.to/3K7cdAL

-	12 pixels of individually addressable 5V LED strip or individual NeoPixel LEDs. Files fit NeoPixel strip WS2812B with 60 pixel/meter - https://amzn.to/3YAC5Jw

-	5V power adapter and a cable. You can use 5V USB port on your Arduino, or you can cut USB cable and solder + and - directly, or use 5mm female connector as I did.
-	10K resistor - https://amzn.to/40Z81Jd
-	Push Button. For example this one: https://amzn.to/3IoVOX8


## Electronic Circuit:

![Circuit][https://github.com/vukasinterzic/WokTimeVisualizer/blob/main/IMG/WorkTimeVisualizerCircuit.png]
 
# Known issues:
* ISS1: button sometiems register multiple clicks. This can probably be fixed by software debounce.
* ISS2: if turned off, time since last full hour will be lost. One hour timer will start from 0 after turned off.
* ISS3: no reset function, need to go up to 13 to reset (using button)
* ISS4: This is not a bug it's a feature! I did not add EEPROM write after making changes with button. Therefore if button is pressed to set lights, and then turned off, that state will not be saved. Last saved change will be from when one hour passed. This is because EEPROM memory has a limited number of rewrites and holding button (or removing it completely) will generate a lot of fast changes. Therefore I did not add EEPROM write there to protect the accidental memory demaging.



# Version 2 Ideas:

* Use Real Time Clock to improve accuracy, fix issues with loosing time. Also to automatic reset next day. A lot of space left on the PCB for RTC to fit.
* Use better button and place it on top of the case, this is not optimal location and it can be hard to reach
* Use Arduino board with USB-C port or a famale USB-C connector inside the case
* Use black acrylic as diffuser, so it is black and less visible when not in lit
* Connect to the Internet and keep daily history on GitHub, Calendar etc.