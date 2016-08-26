#include <Adafruit_NeoMatrix.h>

typedef struct clockWord_t {
  int row;
  int startPixel;
  int endPixel;
} clockWord_t;

void initWords();
bool updateClockDisplay(int color, int hh, int mm);

static void updateClockDisplay_int(int color, int hh, int mm);


