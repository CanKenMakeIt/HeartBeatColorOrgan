const int onBoardLed = 13;      // onboard LED
const int led = 3;              // the pin that the LED is attached to

// sound value contraints
const int centeringValue = 512; 
const int soundValueContraintLow = 0;
const int soundValueContraintHigh = 70;

// input to output mapping values
const int soundValueLow = 0;
const int soundValueHigh = 70;
const int ledValueLow = 0;
const int ledValueHigh = 255;

void setup() 
{
  pinMode(led, OUTPUT);
  pinMode(onBoardLed, OUTPUT);
  
  //turn off the on board led
  digitalWrite(onBoardLed, LOW);
}

void loop() 
{
  // read the input on analog pin 0 and convert it to a positive number offset from the middle of the sensor values with a upper limit of 70
  int soundValue = constrain(abs(analogRead(A0) - centeringValue), soundValueContraintLow, soundValueContraintHigh); 

  // Map sound value to digital value range 
  int ledValue = map(soundValue, soundValueLow, soundValueHigh, ledValueLow, ledValueHigh);

  // Put the PWM to the led
  analogWrite(led, ledValue);
}
