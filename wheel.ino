const int lw=11;
const int rw=12;
int option = 52;
void setup() {
  pinMode(lw, OUTPUT);      
  pinMode(rw, OUTPUT);
  Serial.begin(9600);
}
void loop(){
if (Serial.available() > 0) 
{option = Serial.read();
Serial.println(option);}
switch (option){
case 49 :
digitalWrite(lw, HIGH);
digitalWrite(rw, HIGH);
break;
case 50 :
digitalWrite(lw, HIGH);
digitalWrite(rw, LOW);
break;
case 51 :
digitalWrite(lw, LOW);
digitalWrite(rw, HIGH);
break;
default :
digitalWrite(lw, LOW);
digitalWrite(rw, LOW);
break;}}


