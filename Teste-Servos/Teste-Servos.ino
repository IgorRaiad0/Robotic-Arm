#include <VarSpeedServo.h>

VarSpeedServo servo;
const int pinServo = 8;

void setup() {
  Serial.begin(9600);   // Inicializa comunicação serial
  servo.attach(pinServo);
}

void loop() {
  for (int ang = 0; ang <= 180; ang += 10) {
    servo.write(ang, 255, true); // move devagar
    Serial.print("Testando angulo: ");
    Serial.println(ang);
    delay(500);
  }

  delay(2000);

  for (int ang = 180; ang >= 0; ang -= 10) {
    servo.write(ang, 255, true);
    Serial.print("Testando angulo: ");
    Serial.println(ang);
    delay(500);
  }

  delay(2000);
}
