//Projeto: Medidor de distancia com sensor ultrassonico
//autor: Azzi

#include <Ultrasonic.h>

#define pino_trigger 4
#define pino_echo 5

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup() {
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor... ");
}

void loop() {

  //Le as informacoes do sensor, em cm e pol
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  Serial.print("Distancia em Polegadas: ");
  Serial.print(inMsec);
  delay(1000);
}
