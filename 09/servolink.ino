#include <WiFi.h>                                 // esp32 library
#include <FirebaseESP32.h>                        // firebase library
#include <ESP32Servo.h>

Servo myservo;

#define FIREBASE_HOST "esp32-led-2b2t.firebaseio.com"  // the project name address from firebase id
#define FIREBASE_AUTH "yHBxDN26bAw9GQp1DmM1PnbLAjAlBr4wKVyTWQa9"                          // the secret key generated from firebase
#define WIFI_SSID "RIVERSIDE"                                // input your home or public wifi name
#define WIFI_PASSWORD "harbor1397cheer"                            // password of wifi ssid

String fireString = "";                                          // led status received from firebase
int redpin = 5;
int greenpin = 14;
int servopos = 0;

//Define FirebaseESP32 data object
FirebaseData firebaseData;

void setup() {
  Serial.begin(9600);
  delay(1000);
  myservo.attach(21);
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                          // try to connect with wifi

  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                // print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                  // connect to firebase
  Firebase.reconnectWiFi(true);
  Firebase.set(firebaseData, "/LED_STATUS", "ON");              // set initial string of "OFF"
}

void loop() {

  Firebase.get(firebaseData, "/LED_STATUS");                     // get led status input from firebase
  fireString = firebaseData.stringData();                        // change to e.g. intData() or boolData()
  Serial.println(fireString);
  
  if (fireString == "ON") {                    // compare the input of led status received from firebase
    Serial.println("Led Turned ON");
    digitalWrite(redpin, HIGH);                // make output led ON
    digitalWrite(greenpin, LOW); 
    myservo.write(0);
  }

  else if (fireString == "OFF") {              // compare the input of led status received from firebase
    Serial.println("Led Turned OFF");
    digitalWrite(redpin, LOW);                 // make output led OFF
    digitalWrite(greenpin, HIGH); 
    myservo.write(90);
  }

  else {
    Serial.println("Please send ON/OFF");
  }

  delay(1000);                                 // not strictly necessary
}
