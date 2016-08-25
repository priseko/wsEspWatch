
typedef struct clockWord_t {
  int row;
  int startPixel;
  int endPixel;
} clockWord_t;






// Clock words
#define ES_IST(matrix, color)      matrix.drawPixel(0, 0, color);  matrix.drawPixel(0, 1, color);  matrix.drawPixel(0, 3, color); matrix.drawPixel(0, 4, color); matrix.drawPixel(0, 5, color);
#define MFUENF      timeBuffer[0] |= 0b0000000111100000

#define MZEHN      timeBuffer[1] |= 0b1111000000000000
#define ZWANZIG     timeBuffer[1] |= 0b0000111111100000

#define DREIVIERTEL timeBuffer[2] |= 0b1111111111100000
#define VIERTEL     timeBuffer[2] |= 0b0000111111100000

#define VOR     timeBuffer[3] |= 0b1110000000000000
#define UM      timeBuffer[3] |= 0b0000110000000000
#define NACH      timeBuffer[3] |= 0b0000000111100000

#define HALB      timeBuffer[4] |= 0b1111000000000000
#define ELF     timeBuffer[4] |= 0b0000011100000000
#define FUENF     timeBuffer[4] |= 0b0000000111100000

#define EINS      timeBuffer[5] |= 0b1111000000000000
#define ZWEI      timeBuffer[5] |= 0b0000000111100000

#define DREI      timeBuffer[6] |= 0b1111000000000000
#define VIER      timeBuffer[6] |= 0b0000000111100000

#define SECHS       timeBuffer[7] |= 0b1111100000000000
#define ACHT      timeBuffer[7] |= 0b0000000111100000

#define SIEBEN      timeBuffer[8] |= 0b1111110000000000
#define ZWOELF      timeBuffer[8] |= 0b0000001111100000

#define ZEHN      timeBuffer[9] |= 0b1111000000000000
#define NEUN      timeBuffer[9] |= 0b0001111000000000
#define UHR         timeBuffer[9] |= 0b0000000011100000

