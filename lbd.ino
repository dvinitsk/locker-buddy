#include <LiquidCrystal.h>
#include <Key.h>
#include <Keypad.h>

//Setting up the keypad...
const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {5, 6, 7, 8};
byte colPins[COLS] = {2, 3, 4};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int sensorState = 0, lastState = 0; // variable for reading the pushbutton status
//Setting up the LCD...
LiquidCrystal lcd (1, 9, 13, 12, 11, 10);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  pinMode(14, OUTPUT);//solenoid
  // initialize the sensor pin as an input:
  pinMode(15, INPUT);//IR sensor
  digitalWrite(15, HIGH); // turn on the pullup
  pinMode(16, OUTPUT);//buzzer

}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Enter pin...");
  delay (3000);
  lcd.clear();


  String actualpwd = "1234";
  char enteredpwd[4];
  int count = 0;
  while (count < 4)
  {
    char key = keypad.getKey();
    if (key)
    {
      if (key != '*')
      {
        lcd.print("*");
        enteredpwd[count] = key;
        count++;
      }
      else
      {
        count = 0;
        lcd.clear();
      }
    }
  }

  enteredpwd[4] = '\0';
  String conversion = String(enteredpwd);

  if (conversion == actualpwd)
  {
    lcd.clear();
    digitalWrite(16, HIGH);
    delay(300);
    digitalWrite(16, LOW);
    sensorState = digitalRead(15);
    do
    {
      digitalWrite(14, HIGH);
      sensorState = digitalRead(15);
    } while (sensorState == HIGH);
    do
    {
      sensorState = digitalRead(15);
    } while (sensorState == LOW);

    conversion = "";
    digitalWrite(14, LOW);
  }
  else
  {
    conversion = "";
    digitalWrite(14, LOW);
  }
}
