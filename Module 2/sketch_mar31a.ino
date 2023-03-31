const int buttonPin = 17;
const int xPin = 25;
const int yPin = 26;


int buttonState;       // current state of the button
int lastButtonState = HIGH;     // previous state of the button


int buttonVal;
int xVal;
int yVal;
int count = 0;


void setup() {
  // put your setup code here, to run once:
  //debouncer.attach(switchPin, INPUT);
  //debouncer.interval(25);

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(xPin, INPUT_PULLUP);
  pinMode(yPin, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {

  buttonState = digitalRead(buttonPin);
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);

  // We display our data separated by a comma

    if (lastButtonState == LOW && buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      // music should play
      Serial.print(1);
      count += 1; //increment button push count - ensures music plays until next button push

    } else if (count % 2 == 0){
      // if the current state is LOW then the button went from on to off:
      //pause music
      Serial.print(0);
    }

     else {
      Serial.print(1);
     }

  // Print new line for easy trimming in Processing code
  Serial.print("\n");
  lastButtonState = buttonState;
  delay(100);
}
