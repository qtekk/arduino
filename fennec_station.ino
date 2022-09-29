#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
#define DHTPIN 2
#define DHTTYPE DHT11
#define LCDADDR 0x27

//                      ADDR, EN,RW,RS,D4,D5,D6,D7,BL,POLARITY
LiquidCrystal_I2C lcd(LCDADDR, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  
DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
  dht.begin();
  lcd.begin(16, 2);

  lcd.home();
  lcd.setCursor(3, 0); 
  lcd.print("Fennec");
  lcd.setCursor(6, 1); 
  lcd.print("station");

  delay(6000);

  lcd.clear();
  lcd.print("Temperatura");
  lcd.setCursor(0, 1);
  lcd.print("Wilgotnosc");
}
 
void loop() {
  float temperature = dht.readTemperature();
  int humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    lcd.setCursor(12, 1);
    lcd.print("xxxx");
    lcd.setCursor(13, 1);
    lcd.print("xxx");
  } else {
    lcd.setCursor(12, 0);
    lcd.print(temperature, 1);
    lcd.setCursor(13, 1);
    lcd.print(humidity);
    lcd.setCursor(15, 1);
    lcd.print("%");
  }

  delay(2000);
}
