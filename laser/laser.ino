const int ledPin = 11;

const int ldrPin = A0;
int lez=4;
int lezz=8;
int led=12;
#include <SoftwareSerial.h>

//Alarm reciever's phone number with country code
const String PHONE = "+201117441885";

//GSM Module RX pin to Arduino 3
//GSM Module TX pin to Arduino 2
#define rxPin 2
#define txPin 3
SoftwareSerial sim800(rxPin,txPin);
void setup() {

Serial.begin(9600);

pinMode(ledPin, OUTPUT);
pinMode(lez, OUTPUT);
pinMode(lezz,OUTPUT);
pinMode(led,OUTPUT);
pinMode(ldrPin, INPUT);
  Serial.begin(115200);          // initialize serial

  sim800.begin(9600);
  Serial.println("SIM800L software serial initialize");

  sim800.println("AT");
  delay(1000);

}

void loop() {

while(sim800.available()){
  Serial.println(sim800.readString());
}
//////////////////////////////////////////////////
while(Serial.available())  {
  sim800.println(Serial.readString());
}

int ldrStatus = analogRead(ldrPin);

if (ldrStatus <= 900
) {

digitalWrite(ledPin, LOW);
 digitalWrite(lez, LOW);
    digitalWrite(lezz, LOW);
   digitalWrite(led,LOW);

Serial.print("Its DARK, Turn on the LED : ");

Serial.println(ldrStatus);

} else {
   digitalWrite(lezz, HIGH);
      digitalWrite(ledPin, HIGH);
       digitalWrite(lez, HIGH);
   digitalWrite(led,HIGH);
      delay(1000);
      digitalWrite(ledPin, LOW);
        digitalWrite(lez, LOW);
   digitalWrite(led,LOW);
      delay(1000);
      digitalWrite(ledPin, HIGH);
   digitalWrite(lez, HIGH);
   digitalWrite(led,HIGH);
delay(350);
    sim800.println("ATD"+PHONE+";");
    delay(8000); //20 sec delay

    

Serial.print("Its BRIGHT, Turn off the LED : ");

Serial.println(ldrStatus);

}

}
