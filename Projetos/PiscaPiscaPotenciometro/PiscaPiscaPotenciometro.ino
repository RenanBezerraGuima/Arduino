#define POTENCIOMETRO_PIN A0
#define LED_PIN 12
#define PERIODO 1023
int tempoLigado, tempoDesligado;

void setup() {
  pinMode(POTENCIOMETRO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
  Serial.begin(115200);
}

void loop() {
  tempoLigado = analogRead(POTENCIOMETRO_PIN);
  tempoDesligado = PERIODO - tempoLigado;
  digitalWrite(LED_PIN, HIGH);
  delay(tempoLigado);
  
  digitalWrite(LED_PIN, LOW);
  delay(tempoDesligado);

  Serial.print(tempoLigado);
  Serial.print("\t");
  Serial.println(tempoDesligado);
}
