/*
 * Arduino Hot Wheels Speedometer
 * 
 * Ronaldo Rezende Junior
 * ronaldo.rrj at gmail
 * 02/2019
 * https://github.com/naldin
 * 
 * For math was used:
 * 100mm = 0.1m (or 100/1000)
 * 1ms = 0.001sec (or 1/1000)
 * 1m/s = 3.6km/h
 * 1km/h = 0.621mi/h
 * 
 */

#include <LiquidCrystal.h>

// Using for setting LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const float tHold = 1000; //threshold

float ldr1 = 0; // LDR 1
float ldr2 = 0; // LDR 2
float t1 = 0;   // Time 1
float t2 = 0;   // Time 2
float res = 0;  // Result

void setup() {
  // Starting LCD
  lcd.begin(16, 2);
  lcd.clear();

  // Label
  lcd.setCursor(0, 0);
  lcd.print("Speed km/h:");
  lcd.setCursor(0, 1);
  lcd.print("Speed mi/h:");

  // Pins setup
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}
void loop() {
  //Reading LDRs
  ldr1 = analogRead(A0);
  ldr2 = analogRead(A1);

  // Setting time 1
  if (ldr1 > tHold) {
    t1 = millis();
  }
  //Setting time 2
  if (ldr2 > tHold) {
    t2 = millis();

    // Doing the math and print
    res = (100 / (t2 - t1)) * 3.6;
    lcd.setCursor(11, 0);
    lcd.print(res); // km/h
    lcd.setCursor(11, 1);
    lcd.print(res * 0.621); // mi/h
  }
}
