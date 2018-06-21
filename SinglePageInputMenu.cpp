#include "SinglePageInputMenu.hpp"

// define pins
static const uint8_t CONTROL_PIN = 4;

bool mCurrentState;

/*******************************
 * Constructors
 *******************************/

SinglePageInputMenu::SinglePageInputMenu() 
  : SerialDisplayMenu(new SerialDisplayMenuConfiguration(SerialDisplayType::ansi_vt100, true, 20000, 100000), nullptr, (int8_t) 5, (int8_t) 7) {
    Serial.begin(115200);
    pinMode(CONTROL_PIN, OUTPUT);
    mCurrentState = false;
}

/*******************************
 * Actions
 *******************************/

void SinglePageInputMenu::controllerUpdate() {}

String SinglePageInputMenu::constructStatusLine() {
  return "Bulb is currently " + (mCurrentState ? String("On") : String("Off"));
}

void SinglePageInputMenu::printMenu() {
  Serial.println(" [1] Turn bulb on");
  Serial.println(" [2] Turn bulb off");
  Serial.println();
  Serial.print("Choose 1 or 2: ");
}

SerialDisplayMenu* SinglePageInputMenu::processUserInput(String userInput) {
  if (userInput.equals("1")) {
    digitalWrite(CONTROL_PIN, HIGH);
    mCurrentState = true;
  } else if (userInput.equals("2")) {
    digitalWrite(CONTROL_PIN, LOW);
    mCurrentState = false;
  } else {
    displayError("Only 1 or 2 are accepted, rec: " + String(userInput));
  }
  return this;
}
