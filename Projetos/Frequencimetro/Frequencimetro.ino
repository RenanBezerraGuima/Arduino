// Não são utilizados resistores pull down 
// juntos aos botões, porque a placa pode utilizar
// um resistor interno para este papel 

// INPUT_PULLUP atribui um pino como entrada e 
// com um resistor pullup. 
// Ao pressionar o botao o valor lido é LOW 

// Frequencímetro: 
// Aumenta ou diminui a frequência do Buzzer
// com dois botões

unsigned int frequencia = 600; // Frequencia inicial
#define BUZZER_PIN 10
#define BOTAO_AUMENTA_PIN 9
#define BOTAO_DIMINUI_PIN 11

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BOTAO_AUMENTA_PIN, INPUT_PULLUP);
  pinMode(BOTAO_DIMINUI_PIN, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BOTAO_AUMENTA_PIN) == LOW) {
    frequencia = frequencia + 50;
  }

  if (digitalRead(BOTAO_DIMINUI_PIN) == LOW) {
    frequencia = frequencia - 50;
  }

  tone(BUZZER_PIN, frequencia);
  delay(100);
}
