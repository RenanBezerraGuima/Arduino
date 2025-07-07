https://en.wikipedia.org/wiki/Push-button
# Resistor de _pull-down_
Se você simplesmente conectar um dos pares de terminais ao VCC e o outro ao pino do Arduino, quando você pressionar o botão o pino terá 5 V. 
Mas qual sinal chegará ao pino do Arduino quando o botão não estiver pressionado? Nada? 
Na verdade a melhor resposta seria "qualquer coisa", pois como não tem nenhum sinal válido (5 V ou 0 V) conectado a ele, o caminho fica livre para os ruídos existentes no circuito. 
O pino do Arduino então poderá assumir um valor lógico verdadeiro ou falso a qualquer momento.  
Para retirar essas flutuações que prejudicam a interpretação dos sinais, nós utilizamos normalmente um **resistor de pull-down**. 
Ele atua garantindo que o sinal de GND chegue até o pino enquanto o botão não for pressionado, e protege o circuito contra um curto circuito quando você aperta o botão.
![[Pasted image 20250707180002.png]]
# Hardware do botão
![[Pasted image 20250707180019.png]]
