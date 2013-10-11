int CAMERA = 10; //Pin an dem die Kamera angeschlossen ist

void setup() {
  pinMode(CAMERA,OUTPUT);    //Pin 10 als output initialisieren
  delay(5000);               //5 Sekunden warten
  digitalWrite(CAMERA,HIGH); //Kamera auslösen
  delay(500);                //kurz warten
  digitalWrite(CAMERA,LOW);  
}

void loop() {
  //Nichts mehr zu tun...
}
