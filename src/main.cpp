#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>

using namespace std;

int TIME_TO_WARM_UP = 900;
int time;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void warmUp();

void setup() {
    lcd.begin(16, 2);
    lcd.print("PaulekLab");
    lcd.setCursor(0, 1);
    lcd.print("Alcohol Reader");
    delay(10000);
}

void loop() {

    delay(1000);

    time++;

    if(time <= TIME_TO_WARM_UP) {
        warmUp();
        return;
    }

    //Read sensor data
    int value1 = analogRead(0);
    delay(10);
    int value2 = analogRead(0);
    delay(10);
    int value3 = analogRead(0);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Wykryty Alkochol");
    lcd.setCursor(0, 1);
    lcd.print(String(value1/3) + " gm/L");
}

void warmUp() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Rozgrzewanie...");
    lcd.setCursor(0, 1);
    int timeLeft = TIME_TO_WARM_UP - time;
    if(timeLeft <= 60) {
        lcd.print("Pozostalo: " + String(timeLeft) + "sec");
        return;
    }
    lcd.print("Pozostalo: " + String(timeLeft / 60) + "min");
}