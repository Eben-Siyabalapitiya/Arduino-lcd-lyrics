#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void typeText(int row, String text, int charDelayMs) {
  lcd.setCursor(0, row);
  for (int i = 0; i < text.length(); i++) {
    lcd.print(text[i]);
    delay(charDelayMs);
  }
}

void showLyric(String text, int displayMs, int typingSpeed) {
  String words[30];
  int wordCount = 0;
  String current = "";

  for (int i = 0; i <= text.length(); i++) {
    char c = (i < text.length()) ? text[i] : ' ';
    if (c == ' ') {
      if (current.length() > 0) { words[wordCount++] = current; current = ""; }
    } else { current += c; }
  }

  String pages[20];
  int pageCount = 0;
  String line = "";

  for (int i = 0; i < wordCount; i++) {
    String word = words[i];
    if (line.length() == 0) line = word;
    else if (line.length() + 1 + word.length() <= 16) line += " " + word;
    else { pages[pageCount++] = line; line = word; }
  }
  if (line.length() > 0) pages[pageCount++] = line;

  int screenCount = (pageCount + 1) / 2;
  int msPerScreen = displayMs / max(screenCount, 1);

  for (int s = 0; s < screenCount; s++) {
    lcd.clear();

    String row0 = pages[s * 2];
    String row1 = (s * 2 + 1 < pageCount) ? pages[s * 2 + 1] : "";

    typeText(0, row0, typingSpeed);
    delay(120);
    if (row1.length() > 0) typeText(1, row1, typingSpeed);

    int typingTime = (row0.length() + row1.length()) * typingSpeed + 120;
    int holdTime = msPerScreen - typingTime;
    if (holdTime > 0) delay(holdTime);
  }
}

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  showLyric("Wake up in the morning everything's alright", 4500, 60);
  showLyric("At the end of the story you're holdin' me tight", 4000, 60);
  showLyric("I don't need to worry am I out of my mind?", 3000, 60);
  showLyric("And oh it's hard to see you but I wish you were right here", 4500, 60);
  showLyric("Oh, it's hard to leave you when I get you everywhere", 4000, 60);
  showLyric("All this time I'm thinking, I'm strong enough to sink it", 4000, 60);
  showLyric("Oh, no, I don't need you, but I miss you, come here", 4000, 60);
}