#include "wordClock.h"

clockWord_t es;
clockWord_t ist;
clockWord_t m_fuenf;
clockWord_t m_zehn;
clockWord_t m_zwanzig;

void initWords() {
  es.row = 0;
  es.startPixel = 0;
  es.endPixel = 1;

  ist.row = 0;
  ist.startPixel = 3;
  tst.endPixel = 5;

  m_fuenf.row = 0;
  m_fuenf.startPixel = 7;
  m_fuenf.endPixel = 10;
}

void displayWord(clockWord_t cw, int color) {
  
}

