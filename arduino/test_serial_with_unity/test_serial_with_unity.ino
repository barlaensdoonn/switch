// test sending data over Serial to Unity
// 11/18/17

void setup() {
  Serial.begin(9600);
  while (!Serial);
}

void loop() {
  Serial.println('1');
  delay(1000);
}

