int temp = 0;      // variable to store the read value

void setup() {
  Serial.begin(9600); // open the serial port at 9600 bps:
  pinMode(2, INPUT);    // sets the digital pin 2 as input
  pinMode(3, INPUT);    // sets the digital pin 3 as input
  pinMode(4, INPUT);    // sets the digital pin 4 as input
  pinMode(5, INPUT);    // sets the digital pin 5 as input
  pinMode(6, INPUT);    // sets the digital pin 6 as input
  pinMode(7, INPUT);    // sets the digital pin 7 as input
  pinMode(8, INPUT);    // sets the digital pin 8 as input
  pinMode(9, INPUT);    // sets the digital pin 9 as input
  pinMode(13, OUTPUT);    // sets the digital pin 13 as output
}

void loop() {

  digitalWrite(13, LOW);  // sets the digital pin 13 off
  delay(1);            // waits for a second
  digitalWrite(13, HIGH);
  temp = digitalRead(2)+digitalRead(3)*2+digitalRead(4)*4+digitalRead(5)*8+digitalRead(6)*16+digitalRead(7)*32+digitalRead(8)*64+digitalRead(9)*128;   // read the input pin
  Serial.print(temp,DEC);  // show read value in ºC
   Serial.print("\n");
  Serial.print(temp+273,DEC); // show read value in K
   Serial.print("\n");
  Serial.print(((9*temp)/5)+32, DEC) // show read value in ºF
  Serial.print("\n");
  delay(2000);
