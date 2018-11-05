#include <LiquidCrystal.h>

#define V_PIN A0

const float multp = 5.0f * 2.0f / 1024.0f;
const float percent = 100.0f / 1023.0f;
const char full_blanck = 255;

float volts = 0.0f;
float fuel_percentage = 0.0f;
int value_read = 0;
int progress = 0;
int i = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  //Serial.begin(9600);
  lcd.begin(16, 2);
  //lcd.print("Hello Word!");
  //lcd.setCursor(0, 1);
  //lcd.print("8===D");
}

void loop() {
  value_read = analogRead(V_PIN);
  volts = value_read * multp;
  progress = map(value_read, 0, 1023, 0, 16);
  fuel_percentage = value_read * percent;
  
  //Serial.println(value_read);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(volts);
  lcd.print(" V  ");
  lcd.print(fuel_percentage);
  lcd.print(" %");
  lcd.setCursor(0, 1);

  if (value_read) {
    for (i = progress; i > 0; i--) {
      lcd.print(full_blanck);    
    }
  } else {
    lcd.print("     EMPTY!     ");
  }
  
  delay(300);
}
