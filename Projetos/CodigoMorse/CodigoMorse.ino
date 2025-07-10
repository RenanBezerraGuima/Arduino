#define PIN_BUZZER 11
// Tom do buzzer (Maior mais agudo, menor mais grave)
#define FREQUENCIA_BUZZER 600  
// ms
#define DURACAO_PONTO 100 

#define DURACAO_LINHA (3 * DURACAO_PONTO)
// Pausa entre pontos e traços da mesma letra
#define PAUSA_ELEMENTOS DURACAO_PONTO       
#define PAUSA_LETRAS (3 * DURACAO_PONTO) 
#define PAUSA_PALAVRAS (7 * DURACAO_PONTO)
            

struct CodigoMorse {
  const char caracter;
  const char* sequencia;
};

const CodigoMorse tabelaMorse[] = {
  // Letras (A-Z)
  {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
  {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
  {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
  {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
  {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
  {'Z', "--.."},
  
  // Números (0-9)
  {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"},
  {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."},
  
  // Pontuação comum
  {'.', ".-.-.-"}, {',', "--..--"}, {'?', "..--.."}, {'!', "-.-.--"},
  {'/', "-..-."}, {'(', "-.--."}, {')', "-.--.-"}, {'&', ".-..."},
  {':', "---..."}, {';', "-.-.-."}, {'=', "-...-"}, {'+', ".-.-."},
  {'-', "-....-"}, {'_', "..--.-"}, {'"', ".-..-."}, {'$', "...-..-"},
  {'@', ".--.-."}
};

const int TAMANHO_TABELA = sizeof(tabelaMorse) / sizeof(tabelaMorse[0]);

// ===== FUNÇÕES DE ÁUDIO =====
void tocarTom(unsigned int duracao){
  tone(PIN_BUZZER, FREQUENCIA_BUZZER);
  delay(duracao);
  noTone(PIN_BUZZER);
}

void tocarPonto() {
  tocarTom(DURACAO_PONTO);
  delay(PAUSA_ELEMENTOS);
}

void tocarLinha() {
  tocarTom(DURACAO_LINHA);
  delay(PAUSA_ELEMENTOS);
}

// ===== FUNÇÕES DE BUSCA E CONVERSÃO =====
const char* buscarSequenciaMorse(char caracter) {
  char maiusculo = toupper(caracter);

  for (unsigned int i = 0; i < TAMANHO_TABELA; i++) {
    char caracterTabela = tabelaMorse[i].caracter;
    if (caracterTabela == maiusculo) {
      return (tabelaMorse[i].sequencia);
    }
  }
  return nullptr; // Caracter não encontrado
}

void tocarSequenciaMorse(const char* sequencia) {
  if (sequencia == nullptr) return; // Caracter não encontrado

  for (unsigned int i = 0; sequencia[i] != '\0'; i++) {
    switch (sequencia[i]) {
      case '.':
        tocarPonto();
        break;
      case '-':
        tocarLinha();
        break;
      default:
        // Não faz nada para caracteres inválidos
        break;
    }
  }
}

void tocarCaracter(char caracter) {
  const char* sequencia = buscarSequenciaMorse(caracter);

  if (sequencia != nullptr) {
    Serial.print(caracter);
    Serial.print(" -> ");
    Serial.println(sequencia);

    tocarSequenciaMorse(sequencia);
    delay(PAUSA_LETRAS);
  } else {
    Serial.print(caracter);
    Serial.println(" -> [CARACTER NAO SUPORTADO]");
  }
}

void processarTexto(const String& texto) {
  if (texto.length() == 0) {
    Serial.println("Texto vazio!");
    return;
  }

  Serial.println("===== INICIANDO TRANSMISSAO =====");

  bool palavraAnterior = false;

  for (unsigned int i = 0; i < texto.length(); i++) {
    char caracter = texto[i];

    if (caracter == ' ') {
      if (palavraAnterior) {
        Serial.println("[PAUSA ENTRE PALAVRAS]");
        delay(PAUSA_PALAVRAS);
        palavraAnterior = false;
      }
    } else {
      tocarCaracter(caracter);
      palavraAnterior = true;
    }
  }

  Serial.println("===== TRANSMISSAO CONCLUIDA =====");
  Serial.println();
}

// ===== CONFIGURACAO INICIAL =====
void setup() {
  pinMode(PIN_BUZZER, OUTPUT);
  Serial.begin(9600);

  // Aguarda a inicialização do Serial
  while (!Serial) {
    delay(10);
  }

  Serial.println("===== TRANSMISSOR CODIGO MORSE ======");
  Serial.println();
  Serial.println("Digite o texto e pressione Enter");
  Serial.println("Caracateres suportados: A-Z, 0-9, pontuacao basica");
  Serial.println();
}

void loop() {
  if (Serial.available() > 0) {
    String textoEntrada = Serial.readStringUntil('\n'); // Lê a linha até a quebra de linha
    textoEntrada.trim(); // Remove espaços em branco extras do início/fim

    if (textoEntrada.length() == 0) {
      Serial.println("\nAJUDA:");
      Serial.println("- Digite qualquer texto para converter em Morse");
      Serial.println("- Use espacos para separar palavras");
      Serial.println("- Caracteres nao suportados serao ignorados");
      Serial.println();
      return;
    }

    Serial.print("Texto recebido: \"");
    Serial.print(textoEntrada);
    Serial.println("\"");
    Serial.println();
    
    processarTexto(textoEntrada);
  }
}
