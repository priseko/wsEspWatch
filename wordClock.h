#include <Adafruit_NeoMatrix.h>

typedef struct clockWord_t {
  int row;
  int startPixel;
  int endPixel;
} clockWord_t;

void initWords();
bool updateClockDisplay(Adafruit_NeoMatrix matrix,int color, int hh, int mm);

static void updateClockDisplay_int(Adafruit_NeoMatrix matrix, int color, int hh, int mm);


