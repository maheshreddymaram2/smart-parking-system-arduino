#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>
#include <Servo.h>

// Ultrasonic Sensor Pins - Slot 1
#define TRIG_PIN1 10
#define ECHO_PIN1 11
#define RED_LED1 4
#define GREEN_LED1 5

// Ultrasonic Sensor Pins - Slot 2
#define TRIG_PIN2 12
#define ECHO_PIN2 13
#define RED_LED2 6
#define GREEN_LED2 7

// Ultrasonic Sensor Pins - Slot 3
#define TRIG_PIN3 A0
#define ECHO_PIN3 A1
#define RED_LED3 A2
#define GREEN_LED3 A3

// Servo Pins
#define ENTRY_GATE_PIN 2
#define EXIT_GATE_PIN 3

Servo entryGate;
Servo exitGate;
Adafruit_LiquidCrystal lcd(0);

void setup() {
  pinMode(TRIG_PIN1, OUTPUT);
  pinMode(ECHO_PIN1, INPUT);
  pinMode(RED_LED1, OUTPUT);
  pinMode(GREEN_LED1, OUTPUT);

  pinMode(TRIG_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);
  pinMode(RED_LED2, OUTPUT);
  pinMode(GREEN_LED2, OUTPUT);

  pinMode(TRIG_PIN3, OUTPUT);
  pinMode(ECHO_PIN3, INPUT);
  pinMode(RED_LED3, OUTPUT);
  pinMode(GREEN_LED3, OUTPUT);

  entryGate.attach(ENTRY_GATE_PIN);
  exitGate.attach(EXIT_GATE_PIN);

  lcd.begin(16, 2);
  lcd.setBacklight(1);
  lcd.setCursor(0, 0);
  lcd.print("Smart Parking");
  delay(2000);
}

long getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

void scrollMessage(String message) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(message);
  for (int i = 0; i < message.length() - 16; i++) {
    lcd.scrollDisplayLeft();
    delay(300);  // Delay for scrolling effect
  }
}

void loop() {
  int distance1 = getDistance(TRIG_PIN1, ECHO_PIN1);
  int distance2 = getDistance(TRIG_PIN2, ECHO_PIN2);
  int distance3 = getDistance(TRIG_PIN3, ECHO_PIN3);

  lcd.clear();
  
  // ---- SLOT 1 ----
  if (distance1 <= 10) {
    digitalWrite(RED_LED1, HIGH);
    digitalWrite(GREEN_LED1, LOW);
    entryGate.write(0);   // Entry gate closed
    exitGate.write(90);   // Exit gate open
    lcd.setCursor(0, 0);
    lcd.print("Slot 1 Full");
    lcd.setCursor(0, 1);
    lcd.print("Car 1 Ready to Leave");

    // Call scrollMessage function for a sliding display
    scrollMessage("Car 1 Ready to Leave");
  } else {
    digitalWrite(RED_LED1, LOW);
    digitalWrite(GREEN_LED1, HIGH);
    entryGate.write(90);  // Entry gate open
    exitGate.write(0);    // Exit gate closed
    lcd.setCursor(0, 0);
    lcd.print("Slot 1 Empty");
    lcd.setCursor(0, 1);
    lcd.print("Car 1 coming");
  }

  delay(3000);
  lcd.clear();

  // ---- SLOT 2 ----
  if (distance2 <= 10) {
    digitalWrite(RED_LED2, HIGH);
    digitalWrite(GREEN_LED2, LOW);
    entryGate.write(0);   // Entry gate closed
    exitGate.write(90);   // Exit gate open
    lcd.setCursor(0, 0);
    lcd.print("Slot 2 Full");
    lcd.setCursor(0, 1);
    lcd.print("Car 2 Ready to Leave");

    // Call scrollMessage function for a sliding display
    scrollMessage("Car 2 Ready to Leave");
  } else {
    digitalWrite(RED_LED2, LOW);
    digitalWrite(GREEN_LED2, HIGH);
    entryGate.write(90);  // Entry gate open
    exitGate.write(0);    // Exit gate closed
    lcd.setCursor(0, 0);
    lcd.print("Slot 2 Empty");
    lcd.setCursor(0, 1);
    lcd.print("Car 2 coming");
  }

  delay(3000);
  lcd.clear();

  // ---- SLOT 3 ----
  if (distance3 <= 10) {
    digitalWrite(RED_LED3, HIGH);
    digitalWrite(GREEN_LED3, LOW);
    entryGate.write(0);   // Entry gate closed
    exitGate.write(90);   // Exit gate open
    lcd.setCursor(0, 0);
    lcd.print("Slot 3 Full");
    lcd.setCursor(0, 1);
    lcd.print("Car 3 Ready to Leave");

    // Call scrollMessage function for a sliding display
    scrollMessage("Car 3 Ready to Leave");
  } else {
    digitalWrite(RED_LED3, LOW);
    digitalWrite(GREEN_LED3, HIGH);
    entryGate.write(90);  // Entry gate open
    exitGate.write(0);    // Exit gate closed
    lcd.setCursor(0, 0);
    lcd.print("Slot 3 Empty");
    lcd.setCursor(0, 1);
    lcd.print("Car 3 coming");
  }

  delay(3000);  // Wait before next cycle
}