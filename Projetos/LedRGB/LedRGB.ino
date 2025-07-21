/*
  LED RGB:
    Junção de 3 LEDs (Red Green Blue)
    que em conjunto conseguem mostrar todas as cores.
    Seu módulo (se for cátodo) com o maior pino é 
    aquele que deve ser conectado o GROUND e o resto 
    é a alimentação das 3 cores.
*/

#define LEDR_PIN 9
#define LEDG_PIN 10
#define LEDB_PIN 11

#define BOTAOR_PIN 5
#define BOTAOG_PIN 6
#define BOTAOB_PIN 7

unsigned int leituraBotaoR;
unsigned int leituraBotaoG;
unsigned int leituraBotaoB;

void setup() {
  pinMode(LEDR_PIN, OUTPUT);
  pinMode(LEDG_PIN, OUTPUT);
  pinMode(LEDB_PIN, OUTPUT);

  pinMode(BOTAOR_PIN, INPUT_PULLUP);
  pinMode(BOTAOG_PIN, INPUT_PULLUP);
  pinMode(BOTAOB_PIN, INPUT_PULLUP);
}

void loop() {
  leituraBotaoR = digitalRead(BOTAOR_PIN);
  leituraBotaoG = digitalRead(BOTAOG_PIN);
  leituraBotaoB = digitalRead(BOTAOB_PIN);

  if(leituraBotaoR == LOW) {
    analogWrite(LEDR_PIN, 255);
  } else {
    analogWrite(LEDR_PIN, 0);
  }

  if(leituraBotaoG == LOW) {
    analogWrite(LEDG_PIN, 255);
  } else {
    analogWrite(LEDG_PIN, 0);
  }

  if(leituraBotaoB == LOW) {
    analogWrite(LEDB_PIN, 255);
  } else {
    analogWrite(LEDB_PIN, 0);
  }

  delay(100);
}
