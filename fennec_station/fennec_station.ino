#include <DHT.h>               // https://github.com/adafruit/DHT-sensor-library
#include <Wire.h>         
#include <LiquidCrystal_I2C.h> // https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library
 
#define DHTPIN 2
#define DHTTYPE DHT11
#define LCDADDR 0x27
#define LCD_WIDTH 16
#define LCD_HEIGHT 2
#define SERIAL_BAUDRATE 9600
#define SERIAL_MESSAGE_DELIMITER_CHAR '|'

LiquidCrystal_I2C lcd(LCDADDR, LCD_WIDTH, LCD_HEIGHT);
DHT dht(DHTPIN, DHTTYPE);

int passedTime = 0;
 
void setup() {
  dht.begin();
  lcd.begin();

  printWelcomeMessage();
  printTemplate();

  Serial.begin(SERIAL_BAUDRATE);
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
  passedTime += 2;

  if (passedTime == 10) {
    passedTime = 0;
    if (Serial.available()) {    
      lcd.clear();
      for(int i = 0; Serial.available(); i++) {
        lcd.setCursor(0, i);
        String messagePart = Serial.readStringUntil(SERIAL_MESSAGE_DELIMITER_CHAR);
        lcd.print(messagePart);
      }
      delay(10000);
      printTemplate();   
    }
  }
}