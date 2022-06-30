#include <Keypad.h>

bool fst = false;
bool scd = false;
int count = 0;

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);

}
  
void loop(){
  
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(customKey);
  }
  
  if (customKey == '1') {
    fst = true;
    customKey == '0';
    }
    
  if (customKey == '2') {
    if (fst == true) {
    scd = true;
    customKey == '0';
    }
  }
  
  if (customKey == '3') {
    if (scd == true) {
    Serial.println("Unlocked");
    fst = false;
    scd = false;
    count = -1;
    customKey == '0';
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    }
  }

  if (customKey != '\0'){ 
    count++;
    }

  if (count == 3) {
    fst = false;
    scd = false;
    count = 0;
    customKey = 0;
    Serial.println("Incorrect");
    digitalWrite(12, HIGH);
    delay(1000);
    digitalWrite(12, LOW);
    } 
    
  }  
