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

  h_feunf.row = 4 ;
  h_feunf.startPixel = 7 ;
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

void displayWord(clockWord_t cw, int color) {
  
}

