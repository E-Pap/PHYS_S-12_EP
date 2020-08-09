#include <Stepper.h>

const int stepsPerRevolution = 200;  //200 for our steppers.

// initialize the stepper library for two steppers:
Stepper Stepper1(stepsPerRevolution, 11, 10, 9, 8);
Stepper Stepper2(stepsPerRevolution, 7, 6, 5, 4);

int step_count = 0;

void setup() {
    Serial.begin(0);              //This is the USB serial.
    Serial.setTimeout(20);        //Set wait time for serial data to 20ms (default 1 sec).
    while (!Serial) {;}             //Wait until Serial wakes up
    Serial.println("ready");
}

void loop() {

  while (!Serial.available() ){;}            //Loop and do nothing until there is a serial character received.
  while(Serial.available()){                //Receive bytes and parse them into an integer.
  int target = Serial.parseInt();             //this function finds the integer in the bytes, ignoring commas, spaces, returns, etc....
  int step_dir = 1;                 //step_dir determines whether to step +,-, or 0.
  
    while(!(step_dir == 0 )){         //This loop continues until the target is reached.
    if (target - step_count > 0) step_dir = 1;
    else if (target - step_count < 0 ) step_dir = -1;
    else step_dir = 0;
    step_count += step_dir;               //modify accumulated steps according to step direction.
    Stepper1.step(step_dir);
    Stepper2.step(-step_dir);
    delay(10);
    }
    
    Serial.println(step_count); 
  }
  
}
