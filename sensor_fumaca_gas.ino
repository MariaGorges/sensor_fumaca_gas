/* Programa: Detector de gás e fumaça */

/* Definição dos pinos */
#define MQ_analogico A0
#define MQ_digital 4
#define Buzzer 5
#define Led_Verde 12
#define Led_Vermelho 13

/* Variáveis */
int valor_analogico;
int valor_digital;

void setup() {
  /* Inicia a comunicação serial com velocidade de 9600 bauds */
  Serial.begin(9600);

  /* Configura os pinos de entrada e saída */
  pinMode(MQ_analogico, INPUT);
  pinMode(MQ_digital, INPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Led_Verde, OUTPUT);
  pinMode(Led_Vermelho, OUTPUT);
}


void loop() {

  valor_analogico = analogRead(MQ_analogico);
  valor_digital = digitalRead(MQ_digital);
  Serial.print("Nível detectado: ");
  Serial.print(valor_analogico);
  Serial.print(" || ");

  // alterar o valor conforme a leitura do monitor serial.
  // verificar o valor da leitura no limpo e na fumaça
  if (valor_analogico >= 275) {
    Serial.println("GÁS DETECTADO !!!");
    digitalWrite(Led_Verde, LOW);
    digitalWrite(Led_Vermelho, HIGH);
    tone(Buzzer, 262, 250);
  } /* end if */
  else {
    Serial.println("GAS AUSENTE !!!");
    digitalWrite(Led_Verde, HIGH);
    digitalWrite(Led_Vermelho, LOW);
    noTone(Buzzer);
  }

  delay(500);
}