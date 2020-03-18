int lm35Pin = A0;
int led = 8;
#define buzzer 9
int zaman = 1000;
int okunan_deger = 0;
float sicaklik_gerilim = 0;
float sicaklik = 0;

void setup()
{
  pinMode(lm35Pin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  okunan_deger = analogRead(lm35Pin);
  sicaklik_gerilim = (okunan_deger / 1023.0) * 5000;
  sicaklik = sicaklik_gerilim / 10.0;
  //  Serial.print("SICAKLIK=  ");
  //  Serial.println(sicaklik);


  if (sicaklik >= 25) {
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(zaman);
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    delay(zaman);
    Serial.print("SICAKLIK ");
    Serial.println(sicaklik);
    Serial.print(" derece");
  }
  else {
    Serial.println("ODA SICAKLIĞI ALTINDA ");
    Serial.print(sicaklik);
    Serial.print(" derece");

    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);


  }
}
