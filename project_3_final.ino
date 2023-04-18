long zero;

#define LED 5
#define IR 18

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IR, INPUT);
  pinMode(LED, OUTPUT);
  
  zero = 0;
  for (int i = 0; i < 100; i++) {
    zero += analogRead(IR);
  }
  zero /= 100;  
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(IR);
  // makes sure that the value doesnt exceed 1023
  val = constrain(val, 0, 1023);
  // changes the value from 0 - 1023 to 0 - 255
  val = map(val, 0, 1023, 0, 255);
  // Changes brightness based off of how much light is recieved
  analogWrite(LED, val);
}
