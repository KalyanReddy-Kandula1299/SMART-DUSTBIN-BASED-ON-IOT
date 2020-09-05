#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(1,2); // RX, TX
void setup() {
  pinMode(10,OUTPUT);//trig
  pinMode(11,INPUT);
  Serial.begin(9600);

}
void loop() {
   //if (Bluetooth.available()>0) {
   //char status=Bluetooth.read();
   //if(status=='S')
  //{     
        while(1){
                digitalWrite(10,HIGH);
                delayMicroseconds(2);
                digitalWrite(10,LOW);
                delayMicroseconds(10);
                digitalWrite(10,HIGH);
                delayMicroseconds(2);
                long duration=pulseIn(11,HIGH);
                float distance=duration*0.034/2;
                float garbage=100-((distance/15.0)*100);
                Serial.print("Garbage percentage:");
                Serial.println(garbage);
                Bluetooth.print("Garbage percentage:");
                Bluetooth.println(garbage);
                delay(1000);
                break;
           }
    // }
 //}
}
