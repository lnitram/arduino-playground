int cam_pin = 13;
int photodiode = 0;
int threshold = 10;

int light_val;

void setup()
{
  pinMode(cam_pin, OUTPUT);
  digitalWrite(cam_pin, LOW);
  //Serial.begin(9600);

  light_val = analogRead(photodiode);
}

void loop()
{
  int newLightVal = analogRead(photodiode);

  if (abs(newLightVal - light_val) > threshold)
  {
    digitalWrite(cam_pin, HIGH);
    delay(500);
  }
  light_val = newLightVal;
}int cam_pin = 13;
