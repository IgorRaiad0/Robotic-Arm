#include <VarSpeedServo.h>

// Objetos do Servo
VarSpeedServo garra;
VarSpeedServo base;
VarSpeedServo cotovelo;
VarSpeedServo braco;

// Pinos dos servos
const int pinGarra = 11;
const int pinBase = 10;
const int pinCotovelo = 9;
const int pinBraco = 8;

// Velocidade de movimento (1 a 255)
const int velocidade = 100;

// Ângulos da garra 
const int garraFechada = 90;
const int garraAberta  = 20;

// ângulos do base 
const int baseParada = 90;
const int baseDireita = 0;
const int baseEsquerda = 180;


// ângulos do cotovelo
const int cotoveloBaixo = 20;
const int cotoveloAlto = 180;

// ângulos do braço
const int bracoRetraido = 0;
const int bracoEsticado = 170;
const int bracoRepouso = 90;

void setup() {
  Serial.begin(9600);

  // Conecta os servos
  garra.attach(pinGarra);
  base.attach(pinBase);
  cotovelo.attach(pinCotovelo);
  braco.attach(pinBraco);

  // Posição inicial (fechada)
  garra.write(garraFechada);
  base.write(baseParada);
  cotovelo.write(cotoveloBaixo);
  braco.write(bracoRepouso);
  delay(1000);
}

void move();

void loop() {

  move();

  
}

void move(){
  base.write(baseParada, velocidade, true);
  delay(1000);

  braco.write(bracoRepouso, velocidade, true);
  delay(1000);

  cotovelo.write(cotoveloAlto, velocidade, true);
  delay(1000);

  garra.write(garraAberta, velocidade, true);
  delay(1000);

  cotovelo.write(cotoveloBaixo, velocidade, true);
  delay(1000);

  braco.write(bracoEsticado, velocidade, true);
  delay(1000);

  cotovelo.write(cotoveloAlto, velocidade, true);
  delay(1000);

  garra.write(garraFechada, velocidade, true);
  delay(1000);

  braco.write(bracoRepouso, velocidade, true);
  delay(1000);

  base.write(baseEsquerda, velocidade, true);
  delay(1000);

  garra.write(garraAberta, velocidade, true);
  delay(1000);

}

