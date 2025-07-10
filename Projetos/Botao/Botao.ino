# define INPUT_BUTTON1 9
# define INPUT_BUTTON2 10
# define LED_OFF 12 // LED fica desligado até que o botao seja pressionado
# define LED_ON 13 // LED fica ligado até que o botao seja pressionado

void setup() {
  pinMode(INPUT_BUTTON1, INPUT); 
  pinMode(INPUT_BUTTON2, INPUT);
  pinMode(LED_OFF, OUTPUT); 
  pinMode(LED_ON, OUTPUT); 
}

void loop() {
  switch (digitalRead(INPUT_BUTTON1)) {
    case LOW: // Botao desligado
    digitalWrite(LED_ON, HIGH);
    break;

    case HIGH: // Botao pressionado
    digitalWrite(LED_ON, LOW);
    break;
  }
  switch (digitalRead(INPUT_BUTTON2)) {
    case LOW: // Botao desligado
      digitalWrite(LED_OFF, LOW);
      break;

    case HIGH: // Botao pressionado
      digitalWrite(LED_OFF, HIGH);
      break;
  }
}
