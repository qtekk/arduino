#define BUTTON_PIN   2
#define RED_PIN      11
#define BLUE_PIN     10
#define GREEN_PIN    9

int counter = 0;
int prevButtonState = LOW;
int currentButtonState = prevButtonState;

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  currentButtonState = digitalRead(BUTTON_PIN);
  
  if (currentButtonState != prevButtonState && currentButtonState == HIGH) {
    counter = ++counter % 4;
  }

  switch (counter) {
    case 1:
      setColor(HIGH, LOW, LOW);
      break;
    case 2:
      setColor(LOW, HIGH, LOW);
      break;
    case 3:
      setColor(LOW, LOW, HIGH);
      break;
    default:
      setColor(LOW, LOW, LOW);
  }
  
  delay(10);
  prevButtonState = currentButtonState;
}

void setColor(int redState, int greenState, int blueState) {
  digitalWrite(RED_PIN, redState);
  digitalWrite(GREEN_PIN, greenState);
  digitalWrite(BLUE_PIN, blueState);
}
