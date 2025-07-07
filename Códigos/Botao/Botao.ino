void setup() {
  pinMode(9, INPUT); 
  pinMode(10, INPUT);
  pinMode(12, OUTPUT); // LED fica desligado até que o botao seja pressionado
  pinMode(13, OUTPUT); // LED fica ligado até que o botao seja pressionado
}

void loop() {
  if (digitalRead(9) == LOW){
    digitalWrite(13, HIGH);
  }
  if (digitalRead(10) == LOW){
    digitalWrite(12, LOW);
  }
  if (digitalRead(9) == HIGH) {
    digitalWrite(13, LOW);
  }
  if (digitalRead(10) == HIGH){
    digitalWrite(12, HIGH);
  }
}
