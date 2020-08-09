int IR = 3;
int LED = A0;
int i = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(IR, OUTPUT);
  pinMode(LED, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(IR, HIGH);
 int sensorValue = analogRead(LED);    
 if (sensorValue > 40) {
  i = i + 1;
  Serial.println(i/3);
}
}
