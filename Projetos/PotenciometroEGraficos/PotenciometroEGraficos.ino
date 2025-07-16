/*
  Leitura do potênciometro por meio de gráficos
*/
#define POTENCIOMETRO_PIN A0
unsigned int leitura = 0; 
float tensao = 0.0;

void setup() {
  Serial.begin(9600);
  pinMode(POTENCIOMETRO_PIN, INPUT);
}

void loop() {
  leitura = analogRead(POTENCIOMETRO_PIN);

  // converte e imprime o valor em tensão elétrica
  tensao = leitura * 5.0 / 1024.0;

  // imprime valor no plotter serial
  Serial.print(leitura);
  Serial.print(" "); // separa as váriaveis
  Serial.print(tensao); //exibe o valor de tensão vezes 100.
  Serial.println(" "); // separa as váriaveis
  
  delay(100); // aguarda 100 milissegundos para uma nova leitura
}