#include <LiquidCrystal.h>

#define LDR_PIN A0
#define AMP_PIN A1
#define RS_DISP 7
#define EN_DISP 6
#define D4_DISP 5
#define D5_DISP 4
#define D6_DISP 3
#define D7_DISP 2

float AD_RESO = (5.0/1024.0);

LiquidCrystal lcd(RS_DISP, EN_DISP, D4_DISP, D5_DISP, D6_DISP, D7_DISP);

void setup() {
  DDRB = 0b111;
  lcd.begin(16, 2);
  Serial.begin(115200);
}

void loop() {
  uint16_t luminacia = analogRead(LDR_PIN);
  uint8_t x = luminacia / (1024 / 8);
  PORTB = x;
  float tensao = analogRead(AMP_PIN);
  Serial.print("Tensao: ");
  Serial.println(tensao);
  Serial.print("Luminancia: ");
  Serial.println(luminacia);
  Serial.print("Binario: ");
  Serial.println(x, BIN);
  Serial.print("Tensao: ");
  Serial.println(tensao);
  Serial.print("Tensao: ");
  Serial.println(tensao * AD_RESO);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Lum:");
  lcd.setCursor(4, 0);
  lcd.print(luminacia);

  lcd.setCursor(0, 1);
  lcd.print("Bin:");
  lcd.setCursor(4, 1);
  lcd.print(x, BIN);

  lcd.setCursor(9, 1);
  lcd.print("V:");
  lcd.setCursor(11, 1);
  lcd.print(tensao * AD_RESO);
  delay(20);
}