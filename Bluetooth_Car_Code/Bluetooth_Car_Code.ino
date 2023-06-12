// Pines del driver para el motor A
const int driver_ENB = 6;  // Pin PWM que controla la velocidad
const int driver_IN3 = 7;  // Pin que controla el sentido de giro

// Pines del driver para el motor B
const int driver_ENA = 5;  // Pin PWM que controla la velocidad
const int driver_IN1 = 4;  // Pin que controla el sentido de giro del motor

const int led = 13;
const int ledRED = 11;
const int buzz = 12;

// Variable entera que almacena la velocidad de los motores
int velocidad_motor = 0;

void setup() {
  // Configuramos los pines del driver como salida
  pinMode(driver_ENA, OUTPUT);
  pinMode(driver_IN1, OUTPUT);
  pinMode(driver_ENB, OUTPUT);
  pinMode(driver_IN3, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(buzz, OUTPUT);

  // Inicializamos el estado del motor en parada
  detenerMotores();

  // Iniciamos el puerto serial
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char t = Serial.read();

    if (t == 'F') {
      moverAdelante();
    } else if (t == 'B') {
      moverAtras();
    } else if (t == 'L') {
      girarIzquierda();
    } else if (t == 'R') {
      girarDerecha();
    } else if (t == 'W') {
      encenderLed();
    } else if (t == 'U') {
      encenderLedRed();
    } else if (t == 'u') {
      apagarLedRed();
    } else if (t == 'w') {
      apagarLed();
    } else if (t == 'V') {
      bocinaON();
    } else if (t == 'v') {
      bocinaOFF();
    } else if (t >= '1' && t <= '9') {
      // Ajustar la velocidad del motor basado en el valor recibido
      velocidad_motor = map(t - '0', 1, 9, 26, 255);
    } else if (t == '0') {
      // Detener los motores
      detenerMotores();
    }
  }
}

void moverAdelante() {
  digitalWrite(driver_IN1, HIGH);
  digitalWrite(driver_IN3, HIGH);
  analogWrite(driver_ENA, velocidad_motor);
  analogWrite(driver_ENB, velocidad_motor);
}

void moverAtras() {
  digitalWrite(driver_IN1, LOW);
  digitalWrite(driver_IN3, LOW);
  analogWrite(driver_ENA, velocidad_motor);
  analogWrite(driver_ENB, velocidad_motor);
}

void girarIzquierda() {
  digitalWrite(driver_IN1, LOW);
  digitalWrite(driver_IN3, HIGH);
  analogWrite(driver_ENA, velocidad_motor);
  analogWrite(driver_ENB, velocidad_motor);
}

void girarDerecha() {
  digitalWrite(driver_IN1, HIGH);
  digitalWrite(driver_IN3, LOW);
  analogWrite(driver_ENA, velocidad_motor);
  analogWrite(driver_ENB, velocidad_motor);
}

void encenderLed() {
  digitalWrite(led, HIGH);
}

void apagarLed() {
  digitalWrite(led, LOW);
}
void encenderLedRed() {
  digitalWrite(ledRED, HIGH);
}

void apagarLedRed() {
  digitalWrite(ledRED, LOW);
}

void bocinaON() {
  digitalWrite(buzz, HIGH);
}

void bocinaOFF() {
  digitalWrite(buzz, LOW);
}

void detenerMotores() {
  digitalWrite(driver_IN1, LOW);
  digitalWrite(driver_IN3, LOW);
  analogWrite(driver_ENA, 0);
  analogWrite(driver_ENB, 0);
}
