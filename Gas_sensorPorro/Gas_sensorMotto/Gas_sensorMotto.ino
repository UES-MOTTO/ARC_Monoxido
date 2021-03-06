//Declaraciones Iniciales 
int ledAlarma = 8;    //LedRojo
int ledAlerta1 = 12;  //Led Verde 
int ledAlerta2 = 7;   //Led Amarillo
int buzzer = 9;       //Buzzer 
// Pin Analogo para el Sensor en 'A0'
int sensor = A0;
// Inicializar valor de sensor
float sensorValue;
float vProc;
float motto=0;

//
/*
//Reales
int PRIMERO = 100;
int SEGUNDO = 200;
int TERCERO = 300;
*/
//----------------

//Para Prueba
int PRIMERO = 30;
int SEGUNDO = 60;
int TERCERO = 100;

// Preparar Arduino
void setup() {
  // Inicializa OUTPUT
  pinMode(ledAlarma, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledAlerta1, OUTPUT);
  pinMode(ledAlerta2, OUTPUT);
  // Inicializa COmunicacion serial a 9600 bit/s
  Serial.begin(9600);
}

// Comienza Loop
void loop() {
  //Lee sensor
  sensorValue= analogRead(sensor);
  
  Serial.println(sensorValue);


  ///////////////////////////////////////////////////////////////////////////////
  // Si el sensor pasa IF enciende Alerta 1
  if (sensorValue < PRIMERO ) {
    // Niveles Normales
    //Serial.println("AMBIENTE LIBRE DE MONOXIDO DE CARBONO");
  }
  ///////////////////////////////////////////////////////////////////////////////
  // Si el sensor pasa IF enciende Alerta 1
  if (sensorValue >= PRIMERO && sensorValue < SEGUNDO) {
    // Activa Alarma
   // Serial.println("SE DETECTA MONOXIDO DE CARBONO EN EL AMBIENTE");
    digitalWrite(ledAlerta1, HIGH); //Led Verde activo

  }
  else {
    // Activa led de Alerta
    digitalWrite(ledAlerta1, LOW); //Led Verde apagado
  }
  ///////////////////////////////////////////////////////////////////////////////
  // Si el sensor pasa IF enciende Alerta 2
  if (sensorValue >= SEGUNDO && sensorValue < TERCERO) {
    // Activa Alarma
   // Serial.println("LOS NIVELES DE MONOXIDO DE CARBONO SON ANORMALES");
    digitalWrite(ledAlerta2, HIGH); //Led Amarillo activo

    //Activa BUZZER
     analogWrite(buzzer,100); //emite sonido bajo
     delay(500); //espera medio segundo
     digitalWrite(buzzer, LOW); //deja de emitir
     delay(500);//espera medio segundo
     //BUZZER
  }
  else {
    // Activa led de Alerta
    digitalWrite(ledAlerta2, LOW); //Led amarillo apagado
  }
  
  ///////////////////////////////////////////////////////////////////////////////
  // Si el sensor pasa IF enciende ALARMA
  if (sensorValue >= TERCERO) {
    // Activa Alarma
   // Serial.println("EL NIVEL DE MONOXIDO DE CARBONO ES ALTAMENTE TOXICO");
   // Serial.println("TOME LAS PRECAUSIONES DEBIDAS INMEDIATAMENTE...");
    digitalWrite(ledAlarma, HIGH); //Led Rojo activo

    //Activa BUZZER
     analogWrite(buzzer,200); //emite sonido alto
     delay(1000); //espera medio segundo
     digitalWrite(buzzer, LOW); //deja de emitir
     delay(1000);//espera medio segundo
     //BUZZER
  }
  else {
    // Activa led de Alerta
    digitalWrite(ledAlarma, LOW); //Led rojo apagado
  }


  
  delay(1000);
  
}
