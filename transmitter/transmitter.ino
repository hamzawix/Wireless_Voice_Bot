
  int m1_f = 3;
  int m1_b = 4;
  int m2_f = 5;
  int m2_b = 6;
  
void setup() {
  
  Serial.begin(9600);
 
  pinMode(m1_f, OUTPUT);
  pinMode(m1_b, OUTPUT);
  pinMode(m2_f, OUTPUT);
  pinMode(m2_b, OUTPUT);

  
}

void loop() {

char v = ' ';

if(Serial.available()){
  v = Serial.read();
  Serial.println(v);
  if(v == 's'){
    digitalWrite(m1_f, 0);
    digitalWrite(m1_b, 0);
    digitalWrite(m2_f, 0);
    digitalWrite(m2_b, 0);
  }
  
 else if(v == 'f'){
  digitalWrite(m1_f, 1);
  digitalWrite(m1_b, 0);
  digitalWrite(m2_f, 1);
  digitalWrite(m2_b, 0);
 }
 else if(v == 'b'){
  digitalWrite(m1_f, 0);
  digitalWrite(m1_b, 1);
  digitalWrite(m2_f, 0);
  digitalWrite(m2_b, 1);
 }

 else if(v == 'r'){
  digitalWrite(m1_f, 1);
  digitalWrite(m1_b, 0);
  digitalWrite(m2_f, 0);
  digitalWrite(m2_b, 1);
 }

 else if(v == 'l'){
  digitalWrite(m1_f, 0);
  digitalWrite(m1_b, 1);
  digitalWrite(m2_f, 1);
  digitalWrite(m2_b, 0);
 }

 else{
    digitalWrite(m1_f, 0);
    digitalWrite(m1_b, 0);
    digitalWrite(m2_f, 0);
    digitalWrite(m2_b, 0);
 }
 

}
}



