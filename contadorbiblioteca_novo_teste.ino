//IMPORTAÇÃO e DEFINIÇÃO
#include <NewPing.h>  //Biblioteca do sensor HC-SR04

#define TRIGGER_PIN (10)  // Indica o pino que está conectado o sinal de emissão do sensor na placa Arduino
#define ECHO_PIN (8)      // Indica o pino que está conectado o sinal de recepção do sensor na placa Arduino

#define TRIGGER_PIN1 (6)  // Indica o pino que está conectado o sinal de emissão do sensor na placa Arduino
#define ECHO_PIN1 (4)     // Indica o pino que está conectado o sinal de recepção do sensor na placa Arduino

#define DISTANCIA_MAXIMA (103)  //Definição da distância máxima

NewPing sonar(TRIGGER_PIN, ECHO_PIN, DISTANCIA_MAXIMA);     //Encontra valores de distância de emissão e recepção do sensor (até onde ele vai)
NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, DISTANCIA_MAXIMA);  //Encontra valores de distância de emissão e recepção do sensor (até onde ele vai)

//VÁRIAVEIS
int contador = 0;
int indicador = 0;
int padawan[2][2] = {
  {0, 0}, 
  {0, 0}
};

void setup() {
  Serial.begin(9600);  //Inicializa a comunicação serial, isto é, fazer com que o código rode no sensor
}

void loop() {
  int distancias[2] = {sonar.ping_cm(), sonar1.ping_cm()};

  Serial.println("---------------------");
  // SENSORES
  if (distancias[0] < 10 && padawan[0][0] != 1){
    padawan[indicador][0] = 1;
    padawan[indicador][1] = 0;
    indicador++;
  } else if (distancias[1] < 10 && padawan[0][1] != 1){
    padawan[indicador][0] = 1;
    padawan[indicador][1] = 0;
    indicador++;
  } else if (distancias[0] == 10 && padawan[0][0] != 1){
    padawan[indicador][0] = 0;
    padawan[indicador][1] = 0;
  } else if (distancias[1] == 10 && padawan[0][1] != 1){
    padawan[indicador][0] = 0;
    padawan[indicador][1] = 0;
  }

  for (int i = 0; i < 2; i++){
    for (int j = 0; i < 2; i++){
      Serial.print(padawan[i][j]);
    }
  }

  Serial.print(padawan[1][0]);
  Serial.println(padawan[1][1]);

// Espera um certo tempo para reiniciar o loop (em milissegundos)*/
delay(400);
}