#include <Wire.h>
//#include <Adafruit_MLX90614.h>
//Adafruit_MLX90614 mlx = Adafruit_MLX90614();

int const trigPin = 2;
int const echoPin = 3;
int const buzzPin = 6;
int input_cam=7;

void setup(){
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(buzzPin, OUTPUT);
    pinMode(input_cam,INPUT);
    digitalWrite(input_cam,LOW);
    digitalWrite(buzzPin,LOW);
    Serial.println("Setup Comp");
//    Serial.println("Adafruit MLX90614 test");  
//    mlx.begin(); 
}
void loop(){
    int duration, distance=100;
    digitalWrite(trigPin, HIGH);
    delay(1);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    //Serial.println("duration : "+duration);
    distance = (duration/2) / 29.1;
    if (distance < 10) {    
      Serial.println(distance);  
        if(digitalRead(input_cam) == HIGH){
            digitalWrite(buzzPin, HIGH);
            Serial.println("Mask Dd");
            delay(500);
            digitalWrite(buzzPin,LOW);
        }
    } 
    else {
        digitalWrite(buzzPin, LOW);
    }
    delay(60);
}
