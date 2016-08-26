#include <stdbool.h>
#include "wordClock.h"
#include <Adafruit_NeoMatrix.h>

clockWord_t es;
clockWord_t ist;
clockWord_t m_fuenf;
clockWord_t m_zehn;
clockWord_t m_zwanzig;
clockWord_t m_dreiviertel;
clockWord_t vor;
clockWord_t nach;
clockWord_t halb;
clockWord_t h_elf;
clockWord_t h_fuenf;
clockWord_t h_eins;
clockWord_t h_zwei;
clockWord_t h_drei;
clockWord_t h_vier;
clockWord_t h_sechs;
clockWord_t h_acht;
clockWord_t h_sieben;
clockWord_t h_zwoelf;
clockWord_t h_zehn;
clockWord_t h_neun;
clockWord_t uhr;

void initWords() {  
  es.row = 0;
  es.startPixel = 0;
  es.endPixel = 1;

  ist.row = 0;
  ist.startPixel = 3;
  ist.endPixel = 5;

  m_fuenf.row = 0;
  m_fuenf.startPixel = 7;
  m_fuenf.endPixel = 10;

  m_zehn.row = 1;
  m_zehn.startPixel = 0;
  m_zehn.endPixel = 3;

  m_zwanzig.row = 1 ;
  m_zwanzig.startPixel = 4 ;
  m_zwanzig.endPixel = 10 ;

  m_dreiviertel.row = 2 ;
  m_dreiviertel.startPixel = 0 ;
  m_dreiviertel.endPixel = 10 ;

  vor.row = 3 ;
  vor.startPixel = 0 ;
  vor.endPixel = 2 ;

  nach.row = 3 ;
  nach.startPixel = 7 ;
  nach.endPixel = 10 ;

  halb.row = 4 ;
  halb.startPixel = 0 ;
  halb.endPixel = 3 ;

  h_elf.row = 4 ;
  h_elf.startPixel = 5 ;
  h_elf.endPixel = 7 ;

  h_fuenf.row = 4 ;
  h_fuenf.startPixel = 7 ;
  h_fuenf.endPixel = 10 ;

  h_eins.row = 5 ;
  h_eins.startPixel = 0 ;
  h_eins.endPixel = 3 ;

  h_zwei.row = 5 ;
  h_zwei.startPixel = 7 ;
  h_zwei.endPixel = 10 ;

  h_drei.row = 6 ;
  h_drei.startPixel = 0 ;
  h_drei.endPixel = 3 ;

  h_vier.row = 6 ;
  h_vier.startPixel = 7 ;
  h_vier.endPixel = 10 ;

  h_sechs.row = 7 ;
  h_sechs.startPixel = 0 ;
  h_sechs.endPixel = 4 ;

  h_acht.row = 7 ;
  h_acht.startPixel = 7 ;
  h_acht.endPixel = 10 ;

  h_sieben.row = 8 ;
  h_sieben.startPixel = 0 ;
  h_sieben.endPixel = 5 ;

  h_zwoelf.row = 8 ;
  h_zwoelf.startPixel = 6 ;
  h_zwoelf.endPixel = 10 ;

  h_zehn.row = 9 ;
  h_zehn.startPixel = 0 ;
  h_zehn.endPixel = 3 ;

  h_neun.row = 9 ;
  h_neun.startPixel = 3 ;
  h_neun.endPixel = 6 ;

  uhr.row = 9 ;
  uhr.row =8 ;
  uhr.row =10;
}


void displayWord(Adafruit_NeoMatrix matrix, clockWord_t cw, int color) {
  for (int x=cw.startPixel; x<=cw.endPixel; x++) {
   matrix.drawPixel(x, cw.row, color);
   Serial.printf("x: %d, y: %d, color: %d \n", x, cw.row, color);
  }
}


bool updateClockDisplay(Adafruit_NeoMatrix matrix, int color, int hh, int mm) {
  static bool initial = false;
  static bool updated = false;
  bool retVal = false;

  if ((!initial) || (((mm % 5) == 0) && !updated)) {
    updateClockDisplay_int(matrix, color,  hh,  mm);
    updated = true;
    initial = true;
    retVal = true;
  }

  if ((mm % 5) == 1) {
    updated = false;
  }

  return retVal;
}

void updateClockDisplay_int(Adafruit_NeoMatrix matrix, int color, int hh, int mm) {
  int dispH = hh;

  displayWord(matrix, es, color);
  displayWord(matrix, ist, color);
  
  Serial.print("Es ist ");

}

