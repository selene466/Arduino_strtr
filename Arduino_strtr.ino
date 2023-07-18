void setup() {
  // Set serial baudrate
  Serial.begin(9600);
  // Define originalChar & translateChar
  String originalChar = "abcdefghijklmnopqrstuvwxyz",
         translateChar = "zyxwvutsrqponmlkjihgfedcba",
         // example string
    originalString = "the quick brown fox jumps over the lazy dog",
         // create var to save the result
    translatedString1 = "",
         translatedString2 = "";

  // Wipe serial screen
  Serial.println("\n");
  Serial.println("\n");
  Serial.println("Example implementing php strtr() in Arduino C:\n");

  // Example translating char
  // Output:
  // Original String #1: the quick brown fox jumps over the lazy dog
  // Translated String #1: gsv jfrxp yildm ulc qfnkh levi gsv ozab wlt
  translatedString1 = strtr(originalString, originalChar, translateChar);
  Serial.print("Original String #1: ");
  Serial.println(originalString);
  Serial.print("Translated String #1: ");
  Serial.println(translatedString1);
  Serial.println("\n");

  // Example revert back translated char
  // Output:
  // Original String #2: gsv jfrxp yildm ulc qfnkh levi gsv ozab wlt
  // Translated String #2: the quick brown fox jumps over the lazy dog
  translatedString2 = strtr(translatedString1, translateChar, originalChar);
  Serial.print("Original String #2: ");
  Serial.println(translatedString1);
  Serial.print("Translated String #2: ");
  Serial.println(translatedString2);
}

void loop() {}

// function strtr()
String strtr(String inputString, String inputFrom, String inputTo) {
  String result = "";
  for (int i = 0; i < inputString.length(); i++) {
    String tmp = String(inputString[i]);
    for (int j = 0; j < inputFrom.length(); j++) {
      if (inputString[i] == inputFrom[j]) {
        tmp.replace(inputFrom[j], inputTo[j]);
      }
    }
    result += tmp;
  }
  return result;
}
