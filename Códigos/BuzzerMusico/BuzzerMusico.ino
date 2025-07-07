# define OUTPUT_PIN 11 // Pin conectado ao buzzer
// Não precisa ser um pin digital com saída analógica

void setup() {
  pinMode(OUTPUT_PIN, OUTPUT);
  randomSeed(analogRead(A0));
}

void loop() {
  tone(OUTPUT_PIN, random(1, 30)); // Frequências superiores muito altas são ruins
  //delay(10); // Intervalo constante e curto -> ruído
  delay(200); // Intervalo constante BPM maior -> música
  //delay(300);// Intervalo constante BPM menor-> música
  //delay(random(300, 500)); // Intervalo incosistente e longo -> música
  //delay(random(1, 20)); // Intervalo inconsistente e curto -> ruído
  //delay(random(1, 500)); // Intervalo inconsistente -> ruído mais parecido com música
}
