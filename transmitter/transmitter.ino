
  int m1_f = 3;
  int m1_b = 4;
  int m2_f = 5;
  int m2_b = 6;
  int t = 9;
  int e = 10;
  long duration, distance;


void setup() {
  
  Serial.begin(9600);
 
  pinMode(m1_f, OUTPUT);
  pinMode(m1_b, OUTPUT);
  pinMode(m2_f, OUTPUT);
  pinMode(m2_b, OUTPUT);
  pinMode(t, OUTPUT);
  pinMode(e, INPUT);

  
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
  if( checkDistance(t, e) > 15){
  digitalWrite(m1_f, 1);
  digitalWrite(m1_b, 0);
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
 
 else if(v == 'b'){
 
  digitalWrite(m1_f, 0);
  digitalWrite(m1_b, 1);
  digitalWrite(m2_f, 0);
  digitalWrite(m2_b, 1);
 }
 
 else if(v == 'l'){
  if( checkDistance(t, e) > 15){
  digitalWrite(m1_f, 1);
  digitalWrite(m1_b, 0);
  digitalWrite(m2_f, 0);
  digitalWrite(m2_b, 1);
 }
 else{
  digitalWrite(m1_f, 0);
    digitalWrite(m1_b, 0);
    digitalWrite(m2_f, 0);
    digitalWrite(m2_b, 0);
 }}

 else if(v == 'r'){
  if( checkDistance(t, e) > 15){
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
 }}

 else{
    digitalWrite(m1_f, 0);
    digitalWrite(m1_b, 0);
    digitalWrite(m2_f, 0);
    digitalWrite(m2_b, 0);
 }
 

}

if (checkDistance(t, e) <= 15){
    digitalWrite(m1_f, 0);
    digitalWrite(m1_b, 0);
    digitalWrite(m2_f, 0);
    digitalWrite(m2_b, 0);
}
  
}
  
 long checkDistance(int trig, int echo){
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH);
    distance = (duration/2)/29.1;
    return distance;
  }



