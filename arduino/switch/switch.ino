// use light switch as trigger for relay
// 10/22/17

// using Power Switch Tail (PST) as relay http://www.powerswitchtail.com/
// pin 7 connected to PST + input
// ground connected to PST - input

const int relay = 7;  // pin used to communicate with relay
const int lightSwitch = 2;  // input pin from light switch
const long pause = 50;  // ms to wait between readings [50ms will be about 20x/second]

int input;  // hold reading from lightSwitch pin
unsigned long timer;


void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  pinMode(lightSwitch, INPUT_PULLUP);

  Serial.println("initializing relay as off");
  digitalWrite(relay, LOW);

  timer = millis() + 1000;  // pause to prevent flickering
  Serial.println("setup has ended, entering loop()");
}

void loop() {
  if (millis() > timer) {
    timer += pause;
    input = digitalRead(lightSwitch);
    Serial.print("input: ");
    Serial.println(input);

    if (input == 1) {
      digitalWrite(relay, LOW);
    }
    else {
      digitalWrite(relay, HIGH);
    }
  }
}

