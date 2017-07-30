#include <SoftwareSerial.h>// import the serial library

SoftwareSerial Genotronex(10, 11); // RX, TX
int ledpin=13; // led on D13 will show blink on / off
int BluetoothData; // the data given from Computer

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Bluetooth On please press 1 or 0 blink LED ..");
  pinMode(ledpin,OUTPUT);
  digitalWrite(ledpin,HIGH);
  Genotronex.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
   //Serial.println("Test0");
   if (Serial.available()){
    //Serial.println("Test1");
   BluetoothData=Serial.read();
   //Serial.println("Test1.5");
   if(BluetoothData=='1'){   // if number 1 pressed ....
   //Serial.println("Test2");
   digitalWrite(ledpin,1);
   delay(1000);
   Serial.println("LED  On D13 ON ! ");
   }
  if (BluetoothData=='0'){// if number 0 pressed ....
  digitalWrite(ledpin,0);
  delay(1000);
   Serial.println("LED  On D13 Off ! ");
  }
}
delay(100);// prepare for next data ...
}
