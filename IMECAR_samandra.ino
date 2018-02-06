void store();
void up();
void down();
void resetPot();
void maxPot();
void minPot();

const int INC = 4;
const int UD = 3;
const int CS = 2;

int controlPotvalue = 0; 

void setup() {

  pinMode(INC,OUTPUT);
  pinMode(UD,OUTPUT);
  pinMode(CS,OUTPUT);

  Serial.begin(9600);

  resetPot();

}

void store(){
  digitalWrite(INC,HIGH);
  digitalWrite(CS,HIGH);
  delay(50);
  digitalWrite(CS,LOW);
  delay(50);
}

void up(){
  if(controlPotvalue <250){
      digitalWrite(CS,LOW);
      digitalWrite(INC,HIGH);
      digitalWrite(UD,HIGH);
      delay(1);
      digitalWrite(INC,LOW);
      delay(1);
      store();
      controlPotvalue++;
  }//else do not increase

}

void down(){
  if(controlPotvalue > 20){
    digitalWrite(CS,LOW);
    digitalWrite(INC,HIGH);
    digitalWrite(UD,LOW);
    delay(1);
    digitalWrite(INC,LOW);
    delay(1);
    store();
    controlPotvalue--;
  }//else do not decrease
  
}

void maxPot(){
//250
  //for(int i=0;i<25;i++){
    up();
  //}
  
}

void minPot(){
  //20
  //for(int i=0;i<25;i++){
    down();
  //}
}

void resetPot(){
  controlPotvalue = 120;
  for(int i=0;i<100;i++){
    down();
  }
  for(int i=0;i<=20;i++){
    up();
  }
  controlPotvalue = 20;
  Serial.println("Pot is reseted!");
}

void loop() {
  if (Serial.available() > 0) {
      int inByte = Serial.read();
      Serial.print("pot value is:");
      Serial.println(controlPotvalue);
      switch (inByte) {
        case 'u':
          maxPot();
          break;
        case 'd':
          minPot();
          break;
        default:break;
      }
  }
}










