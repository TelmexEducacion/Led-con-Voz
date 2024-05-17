const int ledPin = 13; // Pin del LED
String command = "";  // Variable para almacenar el comando recibido

void setup() {
  Serial.begin(9600); // Inicializamos la comunicación serial a 9600 baudios
  pinMode(ledPin, OUTPUT); // Configuramos el pin del LED como salida
  Serial.println("Ready"); // Mensaje de inicio para el monitor serial
}

void loop() {
  // Verificamos si hay datos disponibles en el puerto serie
  if (Serial.available() > 0) {
    // Leemos la línea de datos recibida
    command = Serial.readStringUntil('\n');
    // Eliminamos cualquier espacio en blanco del comando
    command.trim();
    
    // Verificamos si el comando es "ON"
    if (command == "ON") {
      digitalWrite(ledPin, HIGH);  // Encendemos el LED
      Serial.println("LED is ON"); // Enviamos confirmación de que el LED está encendido
    }
    // Verificamos si el comando es "OFF"
    else if (command == "OFF") {
      digitalWrite(ledPin, LOW);  // Apagamos el LED
      Serial.println("LED is OFF"); // Enviamos confirmación de que el LED está apagado
    }
    else {
      Serial.println("Unknown command"); // Enviamos mensaje de comando desconocido
    }
  }
}
