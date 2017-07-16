const int motionSensor1Pin = 2;
const int motionSensor2Pin = 3;
const int relayPin = 5;
unsigned long lastOnTime;
int lightState = 0;

void setup() {
  pinMode(motionSensor1Pin, INPUT);
  pinMode(motionSensor2Pin, INPUT);
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
  digitalWrite(relayPin, 1);
}

void loop() {
  int motionSensor1State = digitalRead(motionSensor1Pin);
  int motionSensor2State = digitalRead(motionSensor2Pin);
  if(motionSensor1State == 1 || motionSensor2State == 1){
    turnOnLight();    
  } else {
   if (lightState == 1 && (millis() - lastOnTime >= 8000)) {
      turnOffLight();
    } 
  }  
}

void turnOnLight() { 
  digitalWrite(relayPin, 0);
  lightState = 1;
  lastOnTime = millis();
}

void turnOffLight() {  
  digitalWrite(relayPin, 1);
  lightState = 0;
}

