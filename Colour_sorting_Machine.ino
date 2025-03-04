#include <Servo.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
const char * myWriteAPIKey = "******"; // Type your API Key
unsigned long myChannelNumber = 12345678; // Type your ThingSpeak Channel number
const char *ssid =  "******";     // Enter your WiFi Name
const char *pass =  "*******"; // Enter your WiFi Password
WiFiClient client;
Servo pickServo;
Servo dropServo;
const int s0 = D4;  
const int s1 = D5;  
const int s2 = D6;  
const int s3 = D7;  
const int out = D8;   
int red = 0;  
int green = 0;  
int blue = 0; 
int color=0;
int orangecolor = 0;
int greencolor = 0;
int yellowcolor = 0;
int CLOSE_ANGLE = 90;  // The closing angle of the servo motor arm
int OPEN_ANGLE = 10;  // The opening angle of the servo motor arm
void setup()   
{  
  Serial.begin(9600); 
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);  
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);  
  pickServo.attach(D2);
  dropServo.attach(D3);
  pickServo.write(30);
  dropServo.write(73);
  ThingSpeak.begin(client);
  Serial.println("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) 
     {
            delay(550);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
}  
void loop() 
{  
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
  Serial.print("R Intensity:");  
  Serial.print(red, DEC);  
  Serial.print(" G Intensity: ");  
  Serial.print(green, DEC);  
  Serial.print(" B Intensity : ");  
  Serial.print(blue, DEC);  
  if(red<21 & red>11 & green<46 & green>36&blue<41 & blue>31
  ){
    dropServo.write(10);
    delay(200);
    orangecolor++;
    Serial.print("orrange");
   pickServo.write(OPEN_ANGLE); 
    delay(150);
    pickServo.write(CLOSE_ANGLE);
    ThingSpeak.writeField(myChannelNumber, 1,orangecolor, myWriteAPIKey);
  }

  if(red<36 & red>26 & green<29 & green>19 & blue<39 & blue>29){
    dropServo.write(50);
    delay(200);
    greencolor++;
    Serial.print("green");
  pickServo.write(OPEN_ANGLE); 
    delay(150);
   pickServo.write(CLOSE_ANGLE);
    ThingSpeak.writeField(myChannelNumber, 2,greencolor, myWriteAPIKey);
  } 
  Serial.println();  
 // delay(1000); 
} 
void open1(){ 
  pickServo.write(OPEN_ANGLE);   // Send the command to the servo motor to open the trap door
}
void close1(){ 
  pickServo.write(CLOSE_ANGLE);   // Send te command to the servo motor to close the trap door
}
