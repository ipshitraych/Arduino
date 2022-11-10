#include <LiquidCrystal.h> 
#include <Keypad.h>

int x = 0;
int y = 0;
const byte ROWS = 2; 
const byte COLS = 3; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'}
};

byte rowPins[ROWS] = {13, 12}; 
byte colPins[COLS] = {11, 10, 9}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

LiquidCrystal lcd(8, 7, 5, 4, 3, 2);  

void setup(){
    
    analogWrite(6, 75);
    lcd.begin(16, 2);
    
 } 
  
void loop(){ 
  
    char inputNum = customKeypad.getKey();
    lcd.setCursor(x, y);
    
    if (inputNum){

      lcd.print(inputNum);
      x++;  
    }
    
    if (x == 17 && y == 1){
      lcd.clear();
      x = 0;  
      y = 0;
      lcd.setCursor(x, y);
      lcd.print(inputNum);
    }
   
    if (x == 17){
      x = 0;  
      y = 1;
      lcd.setCursor(x, y);
      lcd.print(inputNum);
    }     
 }
