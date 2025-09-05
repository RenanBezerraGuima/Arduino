/*
  Ao invés de manualmente controlar cada segmento do display
  via as voltagens dos pinos, com a utilização de um circuito
  integrado 4511 conversor de BCD para Display 7 Segmentos 
  (BCD = Binary Coded Decimal) é possível reduzir o número de 
  pinos que devem ser controlados de 7 para 4, sendo cada um 
  deles responsável por um dígito de um decimal codificado em 
  4bits (0 até 9).
*/

#define PIN_A 12
#define PIN_B 9
#define PIN_C 10
#define PIN_D 11

void setup() {
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
}

void loop() {
  // Contador 0 a 1
  displayNumero(0);
  delay(1000);

  displayNumero(1);
  delay(1000);
  
  displayNumero(2);
  delay(1000);

  displayNumero(3);
  delay(1000);

  displayNumero(4);
  delay(1000);

  displayNumero(5);
  delay(1000);

  displayNumero(6);
  delay(1000);

  displayNumero(7);
  delay(1000);

  displayNumero(8);
  delay(1000);

  displayNumero(9);
  delay(1000);
}

void displayNumero(int numero) {
  switch (numero) {
    case 0: // 0000
      digitalWrite(PIN_A, LOW);
      digitalWrite(PIN_B, LOW);
      digitalWrite(PIN_C, LOW);
      digitalWrite(PIN_D, LOW);
      break;
    case 1: // 0001
      digitalWrite(PIN_A, HIGH);
      digitalWrite(PIN_B, LOW);
      digitalWrite(PIN_C, LOW);
      digitalWrite(PIN_D, LOW);
      break;
    case 2: // 0010
      digitalWrite(PIN_A, LOW);
      digitalWrite(PIN_B, HIGH);
      digitalWrite(PIN_C, LOW);
      digitalWrite(PIN_D, LOW);
      break;
    case 3: // 0011
      digitalWrite(PIN_A, HIGH);
      digitalWrite(PIN_B, HIGH);
      digitalWrite(PIN_C, LOW);
      digitalWrite(PIN_D, LOW);
      break;
    case 4: // 0100
      digitalWrite(PIN_A, LOW);
      digitalWrite(PIN_B, LOW);
      digitalWrite(PIN_C, HIGH);
      digitalWrite(PIN_D, LOW);
      break;
    case 5: // 0101
      digitalWrite(PIN_A, HIGH);
      digitalWrite(PIN_B, LOW);
      digitalWrite(PIN_C, HIGH);
      digitalWrite(PIN_D, LOW);
      break;
    case 6: // 0110
      digitalWrite(PIN_A, LOW);
      digitalWrite(PIN_B, HIGH);
      digitalWrite(PIN_C, HIGH);
      digitalWrite(PIN_D, LOW);
      break;
    case 7: // 0111
      digitalWrite(PIN_A, HIGH);
      digitalWrite(PIN_B, HIGH);
      digitalWrite(PIN_C, HIGH);
      digitalWrite(PIN_D, LOW);
      break;
    case 8: // 1000
      digitalWrite(PIN_A, LOW);
      digitalWrite(PIN_B, LOW);
      digitalWrite(PIN_C, LOW);
      digitalWrite(PIN_D, HIGH);
      break;
    case 9: // 1001
      digitalWrite(PIN_A, HIGH);
      digitalWrite(PIN_B, LOW);
      digitalWrite(PIN_C, LOW);
      digitalWrite(PIN_D, HIGH);
      break;
    default: // 0000
      digitalWrite(PIN_A, LOW);
      digitalWrite(PIN_B, LOW);
      digitalWrite(PIN_C, LOW);
      digitalWrite(PIN_D, LOW);
  }
}
