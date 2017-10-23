// utility code to test light switch input
// 10/22/17

// top of light switch connected to pin 2
// bottom connected to arduino ground

const int lightSwitch = 2;  // input pin from light switch
const long pause = 50;  // ms to wait between readings [50ms will be about 20x/second]

int input;  // hold reading from switch_pin
unsigned long timer;


void setup() {
  Serial.begin(9600);
  pinMode(lightSwitch, INPUT_PULLUP);
  timer = millis() + pause;  // initialize the timer for 50ms from now
  Serial.println("setup has ended, entering loop()");
}

void loop() {
  if (millis() > timer) {
    timer += pause;
    input = digitalRead(lightSwitch);
    Serial.print("input: ");
    Serial.println(input);
  }
}
