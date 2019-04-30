//this code is used to use the digital sound detectors and an led
int light=12;
int testlight=11;
int Sensor=A0;
int threshold = 530;
int state = LOW;
void setup() {
  // put your setup code here, to run once:
pinMode(light, OUTPUT);
pinMode(testlight, OUTPUT);
pinMode(Sensor, INPUT);
Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:

int reading = analogRead(Sensor);
Serial.print(reading);
Serial.print('\n');

if (reading > threshold) {
  delay(300);
  for (int i=0; i<3000; i++) {
    reading=analogRead(Sensor);
    if (reading > threshold) {
      if (state == LOW){
        state = HIGH;
        digitalWrite(light, state);
        digitalWrite(testlight, state);
        break;}
      else {
        state = LOW;
        digitalWrite(light, state);
        digitalWrite(testlight, state);
      break;}
    }
  }
}

}
