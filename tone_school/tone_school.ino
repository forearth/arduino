#include "notes.h"

int melody[] = {
  NOTE_G5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_E5,
  NOTE_G5, NOTE_G5, NOTE_E5, NOTE_E5, NOTE_D5, 0,
  NOTE_G5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_E5,
  NOTE_G5, NOTE_E5, NOTE_D5, NOTE_E5, NOTE_C5, 0
};

int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 2, 2,
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 2, 2,
};

void setup() {
  for (int thisNote = 0; thisNote < 26; thisNote++) {

    // 음의 길이 따른 시간을 계산한다.
    //e.g. 4분음표 = 1000 / 4, 8분음표 = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // 음 출력이 유지될 수 있도록 delay time을 설정한다. 30%정도로 설정한다.
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {

}
