/*
Version: 1.2
Author: Vukasin Terzic
Description:


Requirements:
this is for chip with eeprom
Seeeduino doesn't have it so this can't be used!


*/

  
  
  #include <Adafruit_NeoPixel.h>
  #include <EEPROM.h>

  #ifdef __AVR__
   #include <avr/power.h>
  #endif
  
  
    // Read value from EEPROM
    int EEPROMaddress = 1; // address - total 256 bytes
    int WorkHours = EEPROM.read(EEPROMaddress); //retrieves value for address
  
  // Which pin on the Arduino is connected to the NeoPixels?
  #define LED_PIN     2

  // How many NeoPixels are attached to the Arduino?
  #define LED_COUNT   16

  // Button configuration
  #define BUTTON_PIN  0
  byte currentState;     // the current reading from the input pin
  
  // Declare our NeoPixel strip object:
  Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);


  //Millis for counting hours:
  unsigned long startMillis;
  unsigned long currentMillis;
  const unsigned long period = 3600000; //1h = 3600 000 ms, 1 minute is 60000 ms, 1s = 1000 ms

void setup() {
  // put your setup code here, to run once:
  
  //start counting ms
  startMillis = millis(); //initial start time


  //Set WorkHours value and save it to EEPROM:
  if ( WorkHours >= 12 ) {
    
    WorkHours = 0;
    delay(200);
    EEPROM.update(EEPROMaddress, WorkHours);
    delay(1000);
    
  }

    #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
      clock_prescale_set(clock_div_1);
    #endif

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
//  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)

//button config:
  pinMode(BUTTON_PIN, INPUT);
}


void loop() {

  currentMillis = millis();  //get the current time passed
  
  if (currentMillis - startMillis >= period) { //test whether the period has elapsed

    WorkHours++;
    delay(200);

    if (WorkHours >= 13) {

        WorkHours = 13;

    } else {

      //This part will run only once when <period value reached> AND <if WorkHours less than 13 >. In theory this runs only once every hour. In theory :D
      
      EEPROM.update(EEPROMaddress, WorkHours);
      delay(1000);

    }
    
    startMillis = millis(); //start again
  }

  // read the state of the switch/button:
  currentState = digitalRead(BUTTON_PIN);

if (currentState == HIGH) {
      WorkHours++;
      startMillis = millis(); //start again

      if (WorkHours > 13) {
        WorkHours = 0;
      } //FIXME: it is not writing WorkHours value to EEPROM. This can be added here as another Else if needed.
}

delay(100);

// set lights depending on WorkHours value:

  if (WorkHours == 1) {

    strip.setPixelColor(0,0,255,0,250);
    strip.show();
    
  } else if (WorkHours == 2) {
    
    strip.setPixelColor(0,0,255,0,250);
    strip.setPixelColor(1,0,255,0,250);
    strip.show();
  
  } else if (WorkHours == 3) {

    strip.setPixelColor(0,0,255,0,250);
    strip.setPixelColor(1,0,255,0,250);
    strip.setPixelColor(2,0,255,0,250);
    strip.show();
  
  } else if (WorkHours == 4) {

    strip.setPixelColor(0,0,255,0,250);
    strip.setPixelColor(1,0,255,0,250);
    strip.setPixelColor(2,0,255,0,250);
    strip.setPixelColor(3,0,255,0,250);
    strip.show();
  
  } else if (WorkHours == 5) {

    strip.setPixelColor(0,0,255,0,250);
    strip.setPixelColor(1,0,255,0,250);
    strip.setPixelColor(2,0,255,0,250);
    strip.setPixelColor(3,0,255,0,250);
    strip.setPixelColor(4,0,255,0,250);
    strip.show();
  
  } else if (WorkHours == 6) {

    strip.setPixelColor(0,0,255,0,250);
    strip.setPixelColor(1,0,255,0,250);
    strip.setPixelColor(2,0,255,0,250);
    strip.setPixelColor(3,0,255,0,250);
    strip.setPixelColor(4,0,255,0,250);
    strip.setPixelColor(5,0,255,0,250);
    strip.show();
  
  } else if (WorkHours == 7) {

    strip.setPixelColor(0,0,255,0,250);
    strip.setPixelColor(1,0,255,0,250);
    strip.setPixelColor(2,0,255,0,250);
    strip.setPixelColor(3,0,255,0,250);
    strip.setPixelColor(4,0,255,0,250);
    strip.setPixelColor(5,0,255,0,250);
    strip.setPixelColor(6,255,165,0,250);
    strip.show();
  
  } else if (WorkHours == 8) {

    strip.setPixelColor(0,0,255,0,250);
    strip.setPixelColor(1,0,255,0,250);
    strip.setPixelColor(2,0,255,0,250);
    strip.setPixelColor(3,0,255,0,250);
    strip.setPixelColor(4,0,255,0,250);
    strip.setPixelColor(5,0,255,0,250);
    strip.setPixelColor(6,255,165,0,250);
    strip.setPixelColor(7,255,165,0,250);
    strip.show();
  
  } else if (WorkHours == 9) {

    strip.setPixelColor(0,0,255,0,250);
    strip.setPixelColor(1,0,255,0,250);
    strip.setPixelColor(2,0,255,0,250);
    strip.setPixelColor(3,0,255,0,250);
    strip.setPixelColor(4,0,255,0,250);
    strip.setPixelColor(5,0,255,0,250);
    strip.setPixelColor(6,255,165,0,250);
    strip.setPixelColor(7,255,165,0,250);
    strip.setPixelColor(8,255,0,0,250);
    strip.show();
  
  } else if (WorkHours == 10) {

    strip.setPixelColor(0,0,255,0,250);
    strip.setPixelColor(1,0,255,0,250);
    strip.setPixelColor(2,0,255,0,250);
    strip.setPixelColor(3,0,255,0,250);
    strip.setPixelColor(4,0,255,0,250);
    strip.setPixelColor(5,0,255,0,250);
    strip.setPixelColor(6,255,165,0,250);
    strip.setPixelColor(7,255,165,0,250);
    strip.setPixelColor(8,255,0,0,250);
    strip.setPixelColor(9,255,0,0,250);
    strip.show();
  
  } else if (WorkHours == 11) {

    strip.setPixelColor(0,0,255,0,250);
    strip.setPixelColor(1,0,255,0,250);
    strip.setPixelColor(2,0,255,0,250);
    strip.setPixelColor(3,0,255,0,250);
    strip.setPixelColor(4,0,255,0,250);
    strip.setPixelColor(5,0,255,0,250);
    strip.setPixelColor(6,255,165,0,250);
    strip.setPixelColor(7,255,165,0,250);
    strip.setPixelColor(8,255,0,0,250);
    strip.setPixelColor(9,255,0,0,250);
    strip.show();
    
    strip.setPixelColor(10,139,0,0,250);
    strip.show();
    delay(600);
    strip.setPixelColor(10,0,0,0,250);
    strip.show();
    delay(600);
  
  } else if (WorkHours == 12) {

    strip.setPixelColor(0,0,255,0,250);
    strip.setPixelColor(1,0,255,0,250);
    strip.setPixelColor(2,0,255,0,250);
    strip.setPixelColor(3,0,255,0,250);
    strip.setPixelColor(4,0,255,0,250);
    strip.setPixelColor(5,0,255,0,250);
    strip.setPixelColor(6,255,165,0,250);
    strip.setPixelColor(7,255,165,0,250);
    strip.setPixelColor(8,255,0,0,250);
    strip.setPixelColor(9,255,0,0,250);
    strip.show();
    
    strip.setPixelColor(10,139,0,0,250);
    strip.setPixelColor(11,139,0,0,250);
    strip.show();
    delay(600);
    strip.setPixelColor(10,0,0,0,250);
    strip.setPixelColor(11,0,0,0,250);
    strip.show();
    delay(600);
  
  } else if (WorkHours == 13) {

    for(int i=0; i<12; i++) {
    strip.setPixelColor(i,250,0,0,250);
    strip.show();
    delay(30);
    }

    for(int i=0; i<12; i++) {
    strip.setPixelColor(i,0,0,0,0);
    strip.show();
    delay(30);
    }

/* circle with blue light

    for(int i=0; i<12; i++) {
    strip.setPixelColor(i,0,0,250,250);
    strip.show();
    delay(30);
    }

    for(int i=0; i<12; i++) {
    strip.setPixelColor(i,0,0,0,0);
    strip.show();
    delay(30);
    }
*/

  } else {

    colorWipe(strip.Color(0, 0, 0), 0); // off
  
  }
  
} //end of loop


//individual functions:

void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}