void printWelcomeMessage() {
  lcd.home();
  
  char* string = "Fennec";
  lcd.setCursor(3, 0); 
  for (int i = 0, cursorPos = 3; i < (int)strlen(string); i++, cursorPos++) {
    lcd.print(string[i]);
    delay(300);
  }

  for (int i = 0; i < 5; i++) {
    lcd.setCursor(6, 1);
    i % 2 == 0 ? lcd.print("station") : lcd.print("       ");
    delay(1000);
  } 

  delay(1000);
}

void printTemplate() {
  lcd.clear();
  lcd.print("Temperatura");
  lcd.setCursor(0, 1);
  lcd.print("Wilgotnosc");
}

void printDHTError() {
  lcd.setCursor(12, 1);
  lcd.print("xxxx");
  lcd.setCursor(13, 1);
  lcd.print("xxx");
}

void printReadings(float temperature, int humidity) {
  lcd.setCursor(12, 0);
  lcd.print(temperature, 1);
  lcd.setCursor(13, 1);
  lcd.print(humidity);
  lcd.setCursor(15, 1);
  lcd.print("%");
}
