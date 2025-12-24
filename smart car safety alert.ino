#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2  // DS18B20 data pin on D2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

int pirPin    = 3;
int ledGreen  = 8;
int ledYellow = 9;
int ledRed    = 10;
int buzzer    = 11;

float warnTemp   = 30.0;  // warning start
float dangerTemp = 40.0;  // danger level

void setup() {
  Serial.begin(9600);
  sensors.begin();

  pinMode(pirPin, INPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, LOW);
  digitalWrite(buzzer, LOW);
}

void loop() {
  int pirState = digitalRead(pirPin);

  sensors.requestTemperatures();
  float temp = sensors.getTempCByIndex(0);  // DS18B20 temperature

  Serial.print("PIR: ");
  Serial.print(pirState);
  Serial.print("  Temp: ");
  Serial.println(temp);

  // All OFF default
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, LOW);
  noTone(buzzer);

  if (pirState == LOW) {
    // No person inside → only safe indication
    digitalWrite(ledGreen, HIGH);
  } else {
    // Person detected inside
    if (temp < warnTemp) {
      // Safe zone
      digitalWrite(ledGreen, HIGH);
    } else if (temp >= warnTemp && temp < dangerTemp) {
      // Warning zone
      digitalWrite(ledYellow, HIGH);
      tone(buzzer, 1000);
      delay(300);
      noTone(buzzer);
    } else if (temp >= dangerTemp) {
      // Danger zone
      digitalWrite(ledRed, HIGH);
      tone(buzzer, 1500);
      delay(800);
    }
  }

  delay(500);
}
