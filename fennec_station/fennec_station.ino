#include <DHT.h>               // https://github.com/adafruit/DHT-sensor-library
#include <Wire.h>         
#include <LiquidCrystal_I2C.h> // https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library
 
#define DHTPIN 2
#define DHTTYPE DHT11
#define LCDADDR 0x27

LiquidCrystal_I2C lcd(LCDADDR, 16, 2);
DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
  dht.begin();
  lcd.begin();

  printWelcomeMessage();
  printTemplate();
}
 
void loop() {
  float temperature = dht.readTemperature();
  int humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    printDHTError();
  } else {
    printReadings(temperature, humidity);
  }

  delay(2000);
}
