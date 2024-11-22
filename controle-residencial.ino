// Variáveis para pinos
const int micPin = A0;         // Microfone no pino analógico A0
const int ledPin = 9;          // LED conectado ao pino digital 9
const int motorPin = 10;       // Motor vibratório no pino digital 10
int soundThreshold = 500;      // Limite para detectar sons (ajustável)

void setup() {
  pinMode(ledPin, OUTPUT);     // Configura LED como saída
  pinMode(motorPin, OUTPUT);   // Configura motor como saída
  Serial.begin(9600);          // Inicializa monitor serial
}

void loop() {
  int soundLevel = analogRead(micPin); // Lê o nível de som
  Serial.println(soundLevel);         // Mostra o nível de som no monitor serial

  if (soundLevel > soundThreshold) {  // Se o som ultrapassar o limite:
    digitalWrite(ledPin, HIGH);       // Acende o LED
    digitalWrite(motorPin, HIGH);     // Liga o motor
    delay(500);                       // Alerta dura 500 ms
    digitalWrite(ledPin, LOW);        // Desliga o LED
    digitalWrite(motorPin, LOW);      // Desliga o motor
  }

  delay(100); // Pequeno atraso para evitar leituras excessivas
}
