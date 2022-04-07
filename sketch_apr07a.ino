int input_cam=7;
int buzz = 6;


void setup() {  
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(input_cam,INPUT);
  pinMode(buzz,OUTPUT);
  digitalWrite(input_cam,LOW);
  digitalWrite(buzz,LOW);
  Serial.println("Setup Comp");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(input_cam) == HIGH)
    {
      digitalWrite(buzz,HIGH);
      Serial.println("Mask Dd");
      delay(1000);
      digitalWrite(buzz,LOW);
    }
    delay(1000);
    
}
