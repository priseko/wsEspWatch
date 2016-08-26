#include <stdbool.h>
#include <NTPClient.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <ESP8266httpUpdate.h> 
#include "wordClock.h"

#define PIN (4)

const char *ssid     = "netz";
const char *password = "#netz4all!";

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(11, 10, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);

int color;
int lastDispSec = 0;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "de.pool.ntp.org", 7200 /* 2h offset */, 60000 /* Update once per minute*/);

void setup() {
  int pixel;
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();
  
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(40);
  matrix.fillScreen(0);
  color = matrix.Color(255, 0, 0);
  matrix.show();

  Serial.printf("Matrix: %X \n", &matrix);

  initWords();
}

void loop() {
  timeClient.update();

  int seconds = timeClient.getSeconds();
  if (lastDispSec != seconds) {
    lastDispSec = seconds;
    Serial.println(timeClient.getFormattedTime());
  }

  if (updateClockDisplay(color, timeClient.getHours(), timeClient.getMinutes())) {
    matrix.show();
  }
}



