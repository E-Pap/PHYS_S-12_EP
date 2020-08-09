/*
  Input Pull-up Serial

  This example demonstrates the use of pinMode(INPUT_PULLUP). It reads a digital
  input on pin 2 and prints the results to the Serial Monitor.

  The circuit:
  - momentary switch attached from pin 2 to ground
  - built-in LED on pin 13

  Unlike pinMode(INPUT), there is no pull-down resistor necessary. An internal
  20K-ohm resistor is pulled to 5V. This configuration causes the input to read
  HIGH when the switch is open, and LOW when it is closed.

  created 14 Mar 2012
  by Scott Fitzgerald

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/InputPullupSerial
*/

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);

}

void loop() {
  //read the pushbutton value into a variable
  int Bon = digitalRead(2);
  int Buw = digitalRead(3);
  int Bee = digitalRead(4);
  //print out the value of the pushbutton
  Serial.println(Bon);

  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if (Bon == LOW && Buw == HIGH && Bee == HIGH) {
    digitalWrite(12, HIGH);
    digitalWrite(12, LOW);
  } else if (Bon == HIGH && Buw == LOW && Bee == HIGH) {
    digitalWrite(11, HIGH);
    digitalWrite(11, LOW);
  } else if (Bon == HIGH && Buw == HIGH && Bee == LOW) {
    digitalWrite(10, HIGH);
    digitalWrite(10, LOW);
  } else if (Bon == LOW && Buw == LOW && Bee == HIGH) {
    digitalWrite(12, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(11, LOW);
  } else if (Bon == HIGH && Buw == LOW && Bee == LOW) {
    digitalWrite(10, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(11, LOW);
  } else if (Bon == LOW && Buw == HIGH && Bee == LOW) {
    digitalWrite(12, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(10, LOW);
  } else if (Bon == LOW && Buw == LOW && Bee == LOW) {
    digitalWrite(12, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(11, LOW);
  } else{
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(12, LOW);
  }
}
