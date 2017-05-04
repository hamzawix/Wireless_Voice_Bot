
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

char v = ' ';

if(Serial.available()){
  v = Serial.read();
Serial.println(v);
}
}



