#include "DHT.h"
#include <Wire.h> // библиотека для управления устройствами по I2C 
#include <LiquidCrystal_I2C.h> // подключаем библиотеку для LCD 1602

LiquidCrystal_I2C lcd(0x3F, 16, 2); // присваиваем имя lcd для дисплея// подключаем библиотеку для датчика
DHT dht(2, DHT11); // сообщаем на каком порту будет датчик

void setup() // процедура setup
{
  dht.begin(); // запускаем датчик влажности DHT11
  Serial.begin(9600); // подключаем монитор порта
  Serial.println("DHT TEST"); // пишем один раз
  lcd.init(); // инициализация LCD дисплея
  lcd.backlight(); // включение подсветки дисплея
  lcd.clear();
  lcd.setCursor(0, 0); // ставим курсор на 1 символ первой строки
  lcd.print("I LOVE"); // печатаем сообщение на первой строке
  lcd.setCursor(0, 1); // ставим курсор на 1 символ второй строки
  lcd.print("ARDUINO"); // печатаем сообщение на второй строке
  lcd.noBacklight();

}

void loop() // процедура loop
{
  delay(1000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C");
  lcd.backlight();
  lcd.home();
  lcd.clear();
  lcd.setCursor(0, 0); // ставим курсор на 1 символ второй строки
  lcd.print("Vlazhnost': ");
  lcd.print(h);;
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(t);
  delay(3000);
  lcd.noBacklight();

}
