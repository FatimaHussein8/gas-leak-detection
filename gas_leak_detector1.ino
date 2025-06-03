int red_LED_PIN = 11;
int green_LED_PIN = 9;
int buzzer = 6;
int smoke_detector = A0;

int warning_limit = 150;
int danger_limit = 250;

void setup()
{
  pinMode(red_LED_PIN, OUTPUT);
  pinMode(green_LED_PIN, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smoke_detector, INPUT);
  Serial.begin(9600); 
}

void loop()
{
  int sensor_read = analogRead(smoke_detector); 

  Serial.print("Smoke Density: ");
  Serial.println(sensor_read);

  if (sensor_read >= danger_limit)
  {
    digitalWrite(red_LED_PIN, HIGH);
    digitalWrite(green_LED_PIN, LOW);
    tone(buzzer, 1000); 
  }
  else if (sensor_read >= warning_limit)
  {
    digitalWrite(red_LED_PIN, HIGH);
    digitalWrite(green_LED_PIN, LOW);
    tone(buzzer, 500); 
  }
  else
  {
    digitalWrite(green_LED_PIN, HIGH);
    digitalWrite(red_LED_PIN, LOW);
    noTone(buzzer); 
  }

  delay(200);
}
