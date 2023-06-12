// Pines del driver para el motor A
const int driver_ENB = 6;  // Pin PWM que controla la velocidad
const int driver_IN3 = 7;  // Pin que controla el sentido de giro

// Pines del driver para el motor B
const int driver_ENA = 5;  // Pin PWM que controla la velocidad
const int driver_IN1 = 4;  // Pin que controla el sentido de giro del motor

// Variables enteras que almacenan la velocidad del motor A y B
int velocidad_motor_B = 0;
int velocidad_motor_A = 0;

void setup() {
  // Configuramos los pines del driver como salida
  pinMode(driver_ENA, OUTPUT);
  pinMode(driver_IN1, OUTPUT);
  pinMode(driver_ENB, OUTPUT);
  pinMode(driver_IN3, OUTPUT);
  
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
    } else if (t == 'w') {
      apagarLed();
    } else if (t == 'S') {
      detenerMotores();
    }
  }
}

void moverAdelante() {
  digitalWrite(driver_IN1, HIGH);
  digitalWrite(driver_IN3, HIGH);
  analogWrite(driver_ENA, 255);
  analogWrite(driver_ENB, 255);
}

void moverAtras() {
  digitalWrite(driver_IN1, LOW);
  digitalWrite(driver_IN3, LOW);
  analogWrite(driver_ENA, 0);
  analogWrite(driver_ENB, 0);
}

void girarIzquierda() {
  digitalWrite(driver_IN1, LOW);
  digitalWrite(driver_IN3, HIGH);
  analogWrite(driver_ENA, 255);
  analogWrite(driver_ENB, 255);
}

void girarDerecha() {
  digitalWrite(driver_IN1, HIGH);
  digitalWrite(driver_IN3, LOW);
  analogWrite(driver_ENA, 255);
  analogWrite(driver_ENB, 255);
}

void encenderLed() {
  digitalWrite(9, HIGH);
}

void apagarLed() {
  digitalWrite(9, LOW);
}

void detenerMotores() {
  digitalWrite(driver_IN1, LOW);
  digitalWrite(driver_IN3, LOW);
  analogWrite(driver_ENA, 0);
  analogWrite(driver_ENB, 0);
}
