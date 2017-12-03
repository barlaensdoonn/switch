// use light switch as trigger for relay
// 10/22/17
// updated 12/02/17

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

int checkSwitch() {
  int reading;
  reading = digitalRead(lightSwitch);
  return reading;
}

void setState(int in) {
  bool state;  // track state of relay

  if (in == 1) {
    state = false;
    Serial.println('0');
  }
  else {
    state = true;
    Serial.println('1');
  }

  digitalWrite(relay, state);
}

void setup() {
  Serial.begin(9600);
  while (!Serial);
 
  pinMode(relay, OUTPUT);
  pinMode(lightSwitch, INPUT_PULLUP);

  input = checkSwitch();
  setState(input);

  prevInput = input;
  timer = millis() + pause;
}

void loop() {
  if (millis() > timer) {
    timer += pause;
    input = checkSwitch();

    if (input != prevInput) {
      setState(input);
      prevInput = input;
    }
  }
}

