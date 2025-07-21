/*
  Selecionando as cores do RGB com potenciometro
*/

#define POTECIOMETRO_PIN A0

#define RED_PIN         9
#define GREEN_PIN       10
#define BLUE_PIN        11

#define BOTAO_RED_PIN   7
#define BOTAO_GREEN_PIN 6
#define BOTAO_BLUE_PIN  5

unsigned int red    = 0;
unsigned int green  = 0;
unsigned int blue   = 0;

void setup() {
  pinMode(POTECIOMETRO_PIN, INPUT);

  pinMode(BOTAO_RED_PIN, INPUT_PULLUP);
  pinMode(BOTAO_GREEN_PIN, INPUT_PULLUP);
  pinMode(BOTAO_BLUE_PIN, INPUT_PULLUP);

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);

  Serial.print("red: "); Serial.print(red);
  Serial.print(" | green: "); Serial.print(green);
  Serial.print(" | blue: "); Serial.println(blue);

  if (digitalRead(BOTAO_RED_PIN) == LOW) {
    red = analogRead(POTECIOMETRO_PIN);
    red = map(red, 0, 1023, 0, 255);
    analogWrite(RED_PIN, red);
  }
  if (digitalRead(BOTAO_GREEN_PIN) == LOW) {
    green = analogRead(POTECIOMETRO_PIN);
    green = map(green, 0, 1023, 0, 255);
    analogWrite(GREEN_PIN, green);
  }
  if (digitalRead(BOTAO_BLUE_PIN) == LOW) {
    blue = analogRead(POTECIOMETRO_PIN);
    blue = map(blue, 0, 1023, 0, 255);
    analogWrite(BLUE_PIN, blue);
  }

  delay(50);
}
