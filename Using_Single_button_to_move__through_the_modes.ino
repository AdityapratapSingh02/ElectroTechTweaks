const PROGMEM int Mode1Select = 2;                   //Button to increment the mode


int ChPushCounter = 0;   // counter for the number of button presses
int ChIncState = 0;         // current state of the button
int lastChIncState = 1;     // previous state of the button

void setup() {
  pinMode(Mode1Select, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  ChannelSelectFunction();
}



//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^Channel Select Function
void ChannelSelectFunction() {
  ChIncState = digitalRead(Mode1Select);

  // compare the buttonState to its previous state
  if (ChIncState != lastChIncState) {
    // if the state has changed, increment the counter
    if (ChIncState == LOW && ChPushCounter <= 3) {
      // if the current state is HIGH then the button went from off to on:
      ChPushCounter++;
    }
    else if (ChIncState == LOW && ChPushCounter == 4) {
      // if the current state is HIGH then the button went from off to on:
      ChPushCounter = 1;
    }
    // save the current state as the last state, for next time through the loop
    lastChIncState = ChIncState;
    if (ChPushCounter == 1 && ChIncState == LOW) {
      Serial.println("Mode increment 1");
      delay(100);
    }
    else if (ChPushCounter == 2 && ChIncState == LOW) {
      Serial.println("Mode increment 2");
      delay(100);
    }

    else if (ChPushCounter == 3 && ChIncState == LOW) {
      Serial.println("Mode increment 3");
      delay(100);
    }
    else if (ChPushCounter == 4 && ChIncState == LOW) {
      Serial.println("Mode increment 4");
      delay(100);
    }
  }




}
