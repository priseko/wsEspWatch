#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <ESP8266httpUpdate.h> 
#include "wordClock.h"

#define PIN (4)

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(11, 10, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);

void setup() {
  int pixel;
  Serial.begin(115200);
  
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(40);
  matrix.fillScreen(0);
  
  //ES_IST(matrix, matrix.Color(255, 0, 0))

  int color = matrix.Color(255, 0, 0);

  matrix.drawPixel(0, 0, color);  
  matrix.drawPixel(1, 0, color);  
  matrix.drawPixel(3, 0, color); 
  matrix.drawPixel(4, 0, color); 
  matrix.drawPixel(5, 0, color);

  matrix.show();
}

void loop() {
  // put your main code here, to run repeatedly:

}

int coordToPixel(int x, int y) {
  int pixel = (((x+1)/2) * 20) - (x % 2);

  pixel = pixel + ((y+1) * ((-1)^x));

  Serial.printf("X: %d Y: %d Pixel: %d \n",x, y, pixel);
  
  return pixel;
}

