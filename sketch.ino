// Definição dos pinos e variáveis
#define pino_LDR 34          // Pino do sensor LDR no ESP32
#define pino_botao 5 // Pino para o botão
#define pino_vermelho 27          // Pino do LED vermelho
#define pino_amarelo 32       // Pino do LED amarelo
#define pino_verde 33        // Pino do LED verde
#define limite 500       // Limite de luminosidade para ativar o modo noturno

int estado_LED = 0;  // Estado atual da sequência dos LEDs
unsigned long intervalo = 5000; // Intervalo de 5s para o LED vermelho ficar ligado
unsigned long antigoMillis = 0;

unsigned long tempoDeDebounce = 50;

bool estadoBotao = digitalRead(pino_botao);

// Função de configuração
void setup() {
  Serial.begin(115200);

  // Define os pinos dos LEDs e do LDR
  pinMode(pino_LDR, INPUT); // Define o pino do sensor de luminosidade como uma ENTRADA
  pinMode(pino_botao, INPUT_PULLDOWN); // Define o pino do botão
  pinMode(pino_vermelho, OUTPUT); // Define o pino do LED vermelho como uma SAÍDA
  pinMode(pino_amarelo, OUTPUT); // Define o pino do LED amarelo como uma SAÍDA
  pinMode(pino_verde, OUTPUT); // Define o pino do LED verde como uma SAÍDA
}

void controlarLEDs(int valor_LDR) {
    if (valor_LDR < limite) {
    Serial.println("Modo automático: LED amarelo piscando devido à baixa luminosidade.");
    digitalWrite(pino_vermelho, LOW);
    digitalWrite(pino_amarelo, HIGH); // Acende o LED amarelo
    digitalWrite(pino_verde, LOW);
    delay(1000);
    digitalWrite(pino_amarelo, LOW); // Desliga o LED amarelo
    delay(1000);
  }
  else{
    switch (estado_LED) {
      case 0: // LED verde aceso e os outros apagados
        digitalWrite(pino_vermelho, LOW);
        digitalWrite(pino_amarelo, LOW);
        digitalWrite(pino_verde, HIGH);
        delay(3000); // Intervalo de 3s para o led verde ficar aceso
        estado_LED = 1;
        break;
      case 1: // LED amarelo aceso e os outros apagados
        digitalWrite(pino_vermelho, LOW);
        digitalWrite(pino_amarelo, HIGH);
        digitalWrite(pino_verde, LOW);
        delay(2000); // Intervalo de 2s para o led amarelo ficar aceso
        estado_LED = 2;
        break;
      case 2: // LED vermelho aceso e os outros apagados
        // Alterna entre os LEDs em sequência
        //unsigned long millisAtual = millis();
        digitalWrite(pino_vermelho, HIGH);
        digitalWrite(pino_amarelo, LOW);
        digitalWrite(pino_verde, LOW);   
        delay(5000);     
        //if (millisAtual - antigoMillis >= intervalo){
          //antigoMillis = millisAtual;// Intervalo de 5s para o led vermelho ficar aceso
          //if((millis() - antigoMillis) > tempoDeDebounce){
            //if(estadoBotao == 1){
              //delay(1000); //Espera um segundo para ligar o sinal verde
              //digitalWrite(pino_vermelho, LOW); //Desliga sinal vermelho
              //digitalWrite(pino_amarelo, LOW);
              //digitalWrite(pino_verde, HIGH); // Liga sinal verde
            //} else{
              //digitalWrite(pino_vermelho, HIGH); //Mantém o sinal vermelho ligado
              //digitalWrite(pino_amarelo, LOW); 
              //digitalWrite(pino_verde, LOW); // 
              //delay(5000);
            //}
            //antigoMillis = millis();
          //}  
        //}
        estado_LED = 0;
        break;
    }
  }
}

// Função principal de execução contínua
void loop() {
  // Lê o valor do LDR
  int valor_LDR = analogRead(pino_LDR);
  estadoBotao = digitalRead(pino_botao);
  Serial.println(valor_LDR);
  Serial.println(estadoBotao);

  // Controla os LEDs
  controlarLEDs(valor_LDR);
}
