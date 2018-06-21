#include "SinglePageInputMenu.hpp"

SinglePageInputMenu* mSinglePageInputMenu;

void setup() {
  mSinglePageInputMenu = new SinglePageInputMenu();
}

void loop() {
  // The menu runs the show - this will never exit
  SerialDisplayMenu::userInputLoop(mSinglePageInputMenu);
}
