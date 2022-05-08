#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

//#define MASK_DETECT_TH                80 //in percent %
//#define START_SCAN_COUNT              15
//#define DISTANCE_ERROR_COUNT          10
//#define ERROR_COUNT                   5
//#define TEMP_MAX_ALLOWABLE            39
//#define TEMP_THRESHOLD                35
//
//#define MINIMUM_DISTANCE              35
//#define MAXIMUM_DISTANCE              60


int const trigPin = 2;
int const echoPin = 3;
int const buzzPin = 6;
int input_cam=7;
int ledpin = 9;

void setup(){
    Serial.begin(9600);
    pinMode(ledpin, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(buzzPin, OUTPUT);
    pinMode(input_cam,INPUT);
    digitalWrite(input_cam,LOW);
    digitalWrite(buzzPin,LOW);
    Serial.println("Setup Comp");
    Serial.println("Adafruit MLX90614 test");  
    mlx.begin(); 
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
      int objtemp = mlx.readObjectTempC();
      
      Serial.println(distance);  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC()); 
     Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
     Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF()); 
//     Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");
     Serial.println();
      delay(500);
  	    Serial.println(digitalRead(input_cam));
        if(digitalRead(input_cam) == HIGH){
          Serial.println("Before Temperature");
          if(objtemp>=34 && objtemp<=39){
            Serial.println("ESP32 working");
            digitalWrite(buzzPin, HIGH);
            Serial.println("Mask Dd");
            delay(500);
            digitalWrite(buzzPin,LOW);
          }
        }
        else{
          digitalWrite(buzzPin, LOW);
          digitalWrite(ledpin, HIGH);
          delay(200);
          digitalWrite(ledpin, LOW);
          delay(200);
        }
    } 
    else {
        digitalWrite(buzzPin, LOW);
    }
    delay(60);
}
