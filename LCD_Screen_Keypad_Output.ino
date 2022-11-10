#include <LiquidCrystal.h> 
#include <Keypad.h>

const byte ROWS = 2; 
const byte COLS = 3; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'}
};

byte rowPins[ROWS] = {13, 12}; 
byte colPins[COLS] = {11, 10, 9}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
int x = 0;
int y = 0;
int Contrast = 75;
LiquidCrystal lcd(8, 7, 5, 4, 3, 2);  

void setup()
 {
    analogWrite(6,Contrast);
    lcd.begin(16, 2);
    Serial.begin(9600);
    
 } 
  
void loop()
 { 

    char inputNum = customKeypad.getKey();
    lcd.setCursor(x, y);
    
    if (inputNum){
      Serial.println(inputNum);
      lcd.print(inputNum);
      x++;  
    }
    
    if (x == 16 && y == 1){
      lcd.clear();
      x = 0;  
      y = 0;
    }
   
    if (x == 16){
      x = 0;  
      y = 1;
    }     

   
 }
