/*
  Medidor de Temperatura DHT11:
    Composto por um componente medidor de umidade e
    um termistor NTC para temperatura, ambos conectados
    a um controloador de 8-bits.
    As leituras dos sensores são enviadas utilizando um
    único fio de barramento.

    Temperatura:
      O termistor é um semicondutor sensível à temperatura.
      Ele funciona como um resistor cuja resistência varia
      em função da temperatura.
      Pode ser NTC (Negative Temperature Coefficient) ou
      PTC (Positive Temperature Coefficient).
      
      NTC -> Resistência diminui com o aumento da temperatura.
      PTC -> Resistência aumenta com o aumento da temperatura.
    
    Umidade:
      Detecta vapor de água medindo a resistência elétrica
      entre dois eletrodos.

      Umidade relativa é a relação entre a quantidade de água
      existente no ar (umidade absoluta) e a quantidade máxima
      que poderia haver na mesma temperatura (ponto de saturação)

      No ponto de saturação, o vapor de água começa a condensar
      e se acumular sobre as superfícies.
      O ponto de saturação muda com a temperatura do ar.
      Ar frio pode conter menos vapor de água antes de saturar,
      enquando o Ar quente pode conter mais vapor de água.

      Uma umidade relativa mais elevada diminui a resistência
      entre os eletrodos, enquanto uma menor umidade relativa
      aumenta a resistência entre os eletrodos.

      O microcontrolador converte as medições de resistência
      em umidade relativa e unidades de temperatura.

    Hardware:
      A ordem dos terminais deve ser seguida 
      sob a perspectiva da parte do componente com "buracos".
      Os terminais nesta ordem são:
        1. Energia (+) entre 3.5V - 5.5V
        2. Dados (Input para o Arduino)
        3. NC (Não Conectado) terminal não tem função, serve
        para fabricação padrão e/ou rigidez mecânica
        4. GROUND (GND) (-)

    Especificações:
      O sensor DHT11 tem um resolução baixa.

      Alimentação: 3.5 a 5.5 VDC
      Corrente: 200uA a 500mA
      Faixa de medição de umidade: 20 a 80% ± 5% UR
      Faixa de medição de temperatura: 0° a 50°C ± 2°C         
*/

// https://github.com/adafruit/DHT-sensor-library
#include <DHT.h>

#define DHT_PIN 9

float temperatura;
float umidade;

DHT dht(DHT_PIN, DHT11); // Define o pino e o tipo de DHT

void setup() {
  Serial.begin(9600);

  dht.begin();
}

void loop() {
  delay(2000); // Atraso do sensor

  temperatura = dht.readTemperature();
  umidade = dht.readHumidity();

  if (isnan(umidade) || isnan(temperatura)) {
    Serial.println("Falha na leiutura do sensor DHT.");
  } else {
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.print(" °C ");

    Serial.print("\t");

    Serial.print("Umidade: ");
    Serial.print(umidade);
    Serial.print(" %\t");

    Serial.println();
  }

}
