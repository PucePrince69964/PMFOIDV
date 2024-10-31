//IMPORTAÇÃO e DEFINIÇÃO
#include <NewPing.h>  //Biblioteca do sensor HC-SR04

//CONFIGURAÇÃO
//Eixo X, Z
#define TRIGGER_PIN (10)
#define ECHO_PIN (8)

//Eixo Y
#define TRIGGER_PIN1 (12) 
#define ECHO_PIN1 (13)

#define DISTANCIA_MAXIMA (103)

NewPing sonar(TRIGGER_PIN, ECHO_PIN, DISTANCIA_MAXIMA);
NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, DISTANCIA_MAXIMA);

void setup() {
  Serial.begin(9600);  //Inicializa a comunicação serial, isto é, fazer com que o código rode no sensor
}

void loop() {
  int x = sonar.ping_cm();
  int y = sonar1.ping_cm();

  Serial.print("Eixo X: ");
  Serial.println(x);
  Serial.print("Eixo Y: ");
  Serial.println(y);
  Serial.print("Eixo Z: ");
  Serial.println(x);
  Serial.println("----------------------");

  x = (DISTANCIA_MAXIMA - x);
  y = (DISTANCIA_MAXIMA - y);

  Serial.print("Eixo X: ");
  Serial.println(x);
  Serial.print("Eixo Y: ");
  Serial.println(y);
  Serial.println("*----------------------*");

  int volume = x * x * y;
  Serial.print("Volume: ");
  Serial.println(volume);

  // Espera um certo tempo para reiniciar o loop (em milissegundos)*/
  delay(800);
}