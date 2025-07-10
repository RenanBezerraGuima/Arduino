/* Semáforo
*/

void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT); // LED Verde
  pinMode(12, OUTPUT); // LED Amarelo
  pinMode(13, OUTPUT); // LED Vermelho
}

void loop() {
  // put your main code here, to run repeatedly:
  // Sinal Fechado (Vermelho)
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  delay(3000); // 3s

  // Sinal Transição (Amarelo)
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  delay(1000); // 3s

  // Sinal Aberto (Verde)
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  delay(3000); // 3s
}
