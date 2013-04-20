// Controlling a turret position and orientation using EOG

#include <Servo.h>
 
Servo h_servo;            // create servo object to control a pivot servo

int sidepin = 0;           // analog pin 0 used to connect the horizontal EOG


//--------------------------------
const int numReadings = 10;
int h_readings[numReadings];      // the readings from the horizontal EOG
int h_index = 0;                  // the index of the current reading
int h_total = 0;                  // the running total

//--------------------------------
int pivot = 0;                    // variable to read the value from the horizontal EOG analog pin

//--------------------------------
int temp_time = 0;      //variable to suppress blinks in veritcal EOG
int pitch_hold = 0;       //variable to hold pitch position until new data arrives


void setup()
{
  h_servo.attach(9);         // attaches the pivot servo on pin 9 to the servo object

  pinMode(sidepin, INPUT);
 
  // initialize all the analog readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
  {
    h_readings[thisReading] = 0;
   
  }
}

void loop()
{
    //pivot = analogRead(sidepin);              //test reads
    
    //running average to smooth horizontal EOG data into pivot controls
    h_total= h_total - h_readings[h_index];        
    h_readings[h_index] = analogRead(sidepin);    // reads the value of the horizontal EOG (value between 0 and 1023)
    h_total= h_total + h_readings[h_index];          // add the reading to the total
    h_index = h_index + 1;                       // advance to the next position in the array
    if (h_index >= numReadings)                // if we're at the end of the array...
    {
      h_index = 0;                             // ...wrap around to the beginning
    }  
    pivot = h_total / numReadings;              // calculate the average

  
    pivot = map(pivot, 0, 1023, 0, 180);      // scale it to use it with the servo (value between 0 and 180 degrees)
    h_servo.write(pivot);                     // sets the pitch servo position according to the scaled value
    delay(10);
  
  
}



