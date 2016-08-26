#include <stdbool.h>
#include "wordClock.h"

int (*fp_drawPixel)(int,int,int);

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

void initWords(void *fptr) {
  fp_drawPixel = fptr;
  
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


void displayWord(clockWord_t cw, int color) {
  for (int x=cw.startPixel; x<=cw.endPixel; x++) {
    (*fp_drawPixel)(x, cw.row, color);
  }
}


void updateClockDisplay(int color, int hh, int mm) {
  static bool updated = false;

  if (((mm % 5) == 0) && !updated) {
    updateClockDisplay_int( color,  hh,  mm);
    updated = true;
  }

  if ((mm % 5) == 1) {
    updated = false;
  }
}

void updateClockDisplay_int(int color, int hh, int mm) {
  int dispH = hh;

  displayWord(es, color);
  displayWord(ist, color);
  
  Serial.print("Es ist ");
  if ((mm>4) && (mm<10)) {
    MFUENF;
    NACH;
    Serial.print("fuenf nach ");
  }
  if ((mm>9) && (mm<15)) {
    MZEHN;
    NACH;
    Serial.print("zehn nach ");
  }
  if ((mm>14) && (mm<20)) {
    VIERTEL;
    Serial.print("viertel ");
  }
  if ((mm>19) && (mm<25)) {
    MZEHN;
    VOR;
    HALB;
    Serial.print("zehn vor halb ");
  }
  if ((mm>24) && (mm<30)) {
    MFUENF;
    VOR;
    HALB;
    Serial.print("fuenf vor halb ");
  }
  if ((mm>29) && (mm<35)) {
    HALB;
    Serial.print("halb ");
  }
  if ((mm>34) && (mm<40)) {
    MFUENF;
    NACH;
    HALB;
    Serial.print("fuenf nach halb ");
  }
  if ((mm>39) && (mm<45)) {
    MZEHN;
    NACH;
    HALB;
    Serial.print("zehn nach halb ");
  }
  if ((mm>44) && (mm<50)) {
    DREIVIERTEL;
    Serial.print("dreiviertel ");
  }
  if ((mm>49) && (mm<55)) {
    MZEHN;
    VOR;
    Serial.print("zehn vor ");
  }
  if (mm>54) {
    MFUENF;
    VOR;
    Serial.print("fuenf vor ");
  }  
  if (mm>14) {
    dispH++;
  }
  dispH = dispH % 12;
  switch (dispH) {
  case 1: 
    EINS;
    Serial.print("Eins ");
    break;
  case 2: 
    ZWEI;
    Serial.print("Zwei ");
    break;
  case 3:
    DREI;
    Serial.print("Drei ");
    break;
  case 4:
    VIER;
    Serial.print("Vier ");
    break;
  case 5:
    FUENF;
    Serial.print("Fuenf ");
    break;
  case 6:
    SECHS;
    Serial.print("Sechs ");
    break;
  case 7:
    SIEBEN;
    Serial.print("Sieben ");
    break;
  case 8:
    ACHT;
    Serial.print("Acht ");
    break;
  case 9:
    NEUN;
    Serial.print("Neun ");
    break;
  case 10:
    ZEHN;
    Serial.print("Zehn ");
    break;
  case 11:
    ELF;
    Serial.print("Elf ");
    break;
  case 0:
    ZWOELF;
    Serial.print("Zwoelf ");
    break;
  }
  if (mm<5) {
    UM;
    Serial.print("Uhr ");
  }  
  Serial.print("\n");


}

