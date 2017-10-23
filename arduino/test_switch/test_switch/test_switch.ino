// utility code to test light switch input
// 10/22/17

// top of light switch connected to pin 2
// bottom connected to arduino 5V
// light switch ground connected to arduino ground via 10K resistor

int lightSwitch = 2;  // pin used to communicate with light switch
int input;  // hold reading from lightSwitch pin


void setup() {
  Serial.begin(9600);
  pinMode(lightSwitch, INPUT);
  delay(100); // small pause for stability
  Serial.println("setup has ended, entering loop()");
}

void loop() {
  input = digitalRead(lightSwitch);
  Serial.print("input: ");
  Serial.println(input);
  delay(10);
}
