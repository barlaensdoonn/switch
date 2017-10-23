// utility code to test relay
// 10/22/17

// using Power Switch Tail (PST) as relay http://www.powerswitchtail.com/
// pin 7 connected to PST + input
// ground connected to PST - input

int relay = 7;  // pin used to communicate with relay
int delayTime = 3000;  // time to wait between switches


void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);
  Serial.println("Setup has ended, entering loop()");
}

void loop() {
  digitalWrite(relay, HIGH);
  Serial.println("wrote relay pin HIGH");
  delay(delayTime);

  digitalWrite(relay, LOW);
  Serial.println("wrote relay pin LOW");
  delay(delayTime);
}

