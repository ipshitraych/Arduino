#define rled 13
#define gled 12
#define yled 11
#define button 10

int ledstate = 0;
int cstate;
int lstate;

void setup() {

  pinMode(button, INPUT);
  pinMode(rled, OUTPUT);
  pinMode(gled, OUTPUT);
  pinMode(yled, OUTPUT);

  cstate = digitalRead(button);
  
}

void loop() {

  lstate = cstate;
  cstate = digitalRead(button);

  if (cstate == LOW && lstate == HIGH) {

    if (ledstate == 1) {
      digitalWrite(rled, HIGH);
      digitalWrite(gled, HIGH);
      digitalWrite(yled, HIGH);
      ledstate = 0;
    }
    else {
      digitalWrite(rled, LOW);
      digitalWrite(gled, LOW);
      digitalWrite(yled, LOW);
      ledstate = 1;
    }
  }
}
