Estou utilizando uma placa [Black Board](https://www.robocore.net/loja/produtos/arduino-blackboard.html), mas é um Arduino UNO
![[Pasted image 20250706092651.png]]
# Alimentação (1,2) (Energia/USB/Conector P4)
O Arduino UNO pode ser alimentado a partir de um cabo USB conectado a um computador, ou a partir de uma fonte de alimentação com um conector P4.
**OBS: A tensão recomendada da fonte para a maioria dos modelos Arduino é de 6V a 12V**
**OBS: O terminal positivo (+) da fonte deve ser o terminal interno do conector P4**
Abaixo um conector P4:
![[Pasted image 20250706092929.png| 100]]
No diagrama da placa, a conexão USB é (1) e a entrada P4 é (2).

A conexão USB também é a maneira de carregar o código na placa Arduino.
# Pinos
Os pinos da placa Arduino são os pontos de conexão da placa com um circuito por meio de fios (normalmente jumpers), a seguir os diferentes tipos de pinos:
- **GND (3):** *Ground*, qualquer um dos fios terra da placa podem ser utilizados para aterrar o circuito;
- **5V (4) e 3V3 (5):** Fornecem respectivamente 5 volts e 3,3 volts de energia ao circuito. A maioria dos componentes utilizam 5 V ou 3,3 V;
- **Analógico (6):** Pinos rotulados *Analog IN* ($A0$ a $A5$ no UNO). Estes pinos conseguem ler sinais de sensores analógicos (como um sensor de luminosidade) e convertê-los para um valor digital (codificá-los para binário) para utilização no código;
- **Digital (7):** Pinos rotulados *Digital* (0 a 13 no UNO). Utilizados tanto para input (e.g. um botão pressionado) como para output (e.g. alimentar um LED);
- **PWM (8):** Ao lado de alguns pinos digitais tem um til (~) (3,5,6,9,10 e 11 no UNO). Estes pinos além de serem pinos digitais comuns, também podem enviar uma saída analógica (e.g. controlar a intensidade de um LED);
- **AREF:** Este pino pode ser utilizado para alterar a tensão de referência para as leituras analógicas da placa;
- **OBS:** Os pinos analógicos do Arduino UNO podem também serem utilizados como entrada ou saída digital ($A0$ a $A5$ do UNO).
# Botão Reset (9)
Ao pressionar este botão, o Arduino conectará o pino de reset (RST) ao GND e reiniciará o programa carregado no Arduino.
# LED indicador de energia (10)
Localizado ao centro da placa UNO, rotulado ON (10).
# LEDs TX e RX (11)
TX é abreviação para transmitir e RX para receber. Indicam pinos responsáveis pela comunicação serial. No UNO estão presentes nos pinos 0 e 1 e os LEDs que indicam se a comunicação de dados está acontecendo.
# Circuito Integrado (CI) principal (12)
\