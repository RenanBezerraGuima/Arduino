/*
  Display de 7 Segmentos:
    Um circuito encapsulado, composto por 7 ou 8 segmentos
    (com o oitavo sendo o ponto e os segmentos sendo um led).

  O display cátodo comum não contém resistor dentro de seu
  circuito, sendo assim necessário um externo. (300 ohms)

  Somente com o display é preciso utilizar 8 portas + GRD
  para poder utilizá-lo e programar o comportamento de cada
  LED de cada segmento por meio de sinais digitais dos pinos.
*/

#define DOT_PIN 6

#define A_PIN 7
#define B_PIN 8
#define C_PIN 9
#define D_PIN 10
#define E_PIN 11
#define F_PIN 12
#define G_PIN 13

void setup() {
  pinMode(DOT_PIN, OUTPUT);

  pinMode(A_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
  pinMode(C_PIN, OUTPUT);
  pinMode(D_PIN, OUTPUT);
  pinMode(E_PIN, OUTPUT);
  pinMode(F_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
}

void loop() {
  // Contador

  // 0
  digitalWrite(A_PIN, HIGH);
  digitalWrite(B_PIN, HIGH);
  digitalWrite(C_PIN, HIGH);
  digitalWrite(D_PIN, HIGH);
  digitalWrite(E_PIN, HIGH);
  digitalWrite(F_PIN, HIGH);
  digitalWrite(G_PIN, LOW);
  delay(1000);

  // 1
  digitalWrite(A_PIN, LOW);
  digitalWrite(B_PIN, HIGH);
  digitalWrite(C_PIN, HIGH);
  digitalWrite(D_PIN, LOW);
  digitalWrite(E_PIN, LOW);
  digitalWrite(F_PIN, LOW);
  digitalWrite(G_PIN, LOW);
  delay(1000);

  // 2
  digitalWrite(A_PIN, HIGH);
  digitalWrite(B_PIN, HIGH);
  digitalWrite(C_PIN, LOW);
  digitalWrite(D_PIN, HIGH);
  digitalWrite(E_PIN, HIGH);
  digitalWrite(F_PIN, LOW);
  digitalWrite(G_PIN, HIGH);
  delay(1000);


  // 3
  digitalWrite(A_PIN, HIGH);
  digitalWrite(B_PIN, HIGH);
  digitalWrite(C_PIN, HIGH);
  digitalWrite(D_PIN, HIGH);
  digitalWrite(E_PIN, LOW);
  digitalWrite(F_PIN, LOW);
  digitalWrite(G_PIN, HIGH);
  delay(1000);


  // 4
  digitalWrite(A_PIN, LOW);
  digitalWrite(B_PIN, HIGH);
  digitalWrite(C_PIN, HIGH);
  digitalWrite(D_PIN, LOW);
  digitalWrite(E_PIN, LOW);
  digitalWrite(F_PIN, HIGH);
  digitalWrite(G_PIN, HIGH);
  delay(1000);

  // 5
  digitalWrite(A_PIN, HIGH);
  digitalWrite(B_PIN, LOW);
  digitalWrite(C_PIN, HIGH);
  digitalWrite(D_PIN, HIGH);
  digitalWrite(E_PIN, LOW);
  digitalWrite(F_PIN, HIGH);
  digitalWrite(G_PIN, HIGH);
  delay(1000);

  // 6
  digitalWrite(A_PIN, HIGH);
  digitalWrite(B_PIN, LOW);
  digitalWrite(C_PIN, HIGH);
  digitalWrite(D_PIN, HIGH);
  digitalWrite(E_PIN, HIGH);
  digitalWrite(F_PIN, HIGH);
  digitalWrite(G_PIN, HIGH);
  delay(1000);

  // 7
  digitalWrite(A_PIN, HIGH);
  digitalWrite(B_PIN, HIGH);
  digitalWrite(C_PIN, HIGH);
  digitalWrite(D_PIN, LOW);
  digitalWrite(E_PIN, LOW);
  digitalWrite(F_PIN, LOW);
  digitalWrite(G_PIN, HIGH);
  delay(1000);

  // 8
  digitalWrite(A_PIN, HIGH);
  digitalWrite(B_PIN, HIGH);
  digitalWrite(C_PIN, HIGH);
  digitalWrite(D_PIN, HIGH);
  digitalWrite(E_PIN, HIGH);
  digitalWrite(F_PIN, HIGH);
  digitalWrite(G_PIN, HIGH);
  delay(1000);

  // 9
  digitalWrite(A_PIN, HIGH);
  digitalWrite(B_PIN, HIGH);
  digitalWrite(C_PIN, HIGH);
  digitalWrite(D_PIN, HIGH);
  digitalWrite(E_PIN, LOW);
  digitalWrite(F_PIN, HIGH);
  digitalWrite(G_PIN, HIGH);
  delay(1000);
}
