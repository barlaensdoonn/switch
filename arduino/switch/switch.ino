// use light switch as trigger for relay
// 10/22/17
// updated 10/23/17

// top of light switch connected to pin 2
// bottom connected to arduino ground

// using Power Switch Tail (PST) as relay http://www.powerswitchtail.com/
// pin 7 connected to PST + input
// ground connected to PST - input

const int relay = 7;  // pin used to communicate with relay
const int lightSwitch = 2;  // input pin from light switch
const long pause = 50;  // ms to wait between readings [50ms will be about 20x/second]

int input;  // hold reading from lightSwitch pin
int prevInput;  // hold previous reading from lightSwitch pin
unsigned long timer;  // use a timer instead of delay()
bool state;  // track state of relay

int checkSwitch() {
  int reading;
  reading = digitalRead(lightSwitch);
  return reading;
}

void setup() {
  pinMode(relay, OUTPUT);
  pinMode(lightSwitch, INPUT_PULLUP);
  input = checkSwitch();

  if (input == 1) {
    state = false;
  }
  else {
    state = true;
  }

  digitalWrite(relay, state);
  prevInput = input;
  timer = millis() + pause;
}

void loop() {
  if (millis() > timer) {
    timer += pause;
    input = checkSwitch();

    if (input != prevInput) {
      state = !state;
      digitalWrite(relay, state);
      prevInput = input;
    }
  }
}

