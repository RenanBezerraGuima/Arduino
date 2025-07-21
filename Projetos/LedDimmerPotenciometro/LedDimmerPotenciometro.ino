/*
  Lâmpada dimerizável
  (Lâmpada com brilho ajustável)

  A placa de arduino só capaz de gerar pulsos de 0V ou 5V
  Para criar saídas analógicas, a placa utiliza PWM
  PWM: Pulse Width Modulation
    Controla a proporção do tempo no qual o sinal é 
    ligado e desligado em um período fixo.
    A proporção é conhecida como duty cycle.
    Os períodos fixos são muito curtos, e portanto
    não são visíveis à olho nu. 
*/

#define pinoPotenciometro A0
#define pinoLED 11

unsigned int leitura = 0; 
unsigned int pwm = 0;

void setup() {
  pinMode(pinoPotenciometro, INPUT); 
  pinMode(pinoLED, OUTPUT); 
}

void loop() {
  leitura = analogRead(pinoPotenciometro);
  
  // converte o valor do potenciômetro, de 0 a 1023, em um valor de 0 a 255
  // O led só aceita de 0 (LOW) a 255 (HIGH)
  pwm = map(leitura, 0, 1023, 0, 255); 
  
  // Dá a tensão correta ao led, sendo o dimmer
  analogWrite(pinoLED, pwm);
}