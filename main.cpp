#include <ArduinoJson.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define PIN            D1
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(16, 16, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);

#define TEXT_COLOR      matrix.Color(255, 255, 255)
#define BG_COLOR        matrix.Color(0, 0, 0)

byte letterA[] = {
  B00111100,
  B01000010,
  B10000001,
  B11111111,
  B10000001,
  B10000001,
  B10000001,
  B00000000
};

byte letterB[] = {
  B11111110,
  B10000010,
  B10000010,
  B11111100,
  B10000010,
  B10000010,
  B11111110,
  B00000000
};

byte letterC[] = {
  B01111100,
  B10000010,
  B10000000,
  B10000000,
  B10000000,
  B10000010,
  B01111100,
  B00000000
};

byte letterD[] = {
  B11111100,
  B10000010,
  B10000010,
  B10000010,
  B10000010,
  B10000000,
  B10000000,
  B11111100
};

byte letterE[] = {
  B11111110,
  B10000000,
  B10000000,
  B11111100,
  B10000000,
  B10000000,
  B11111110,
  B00000000
};

byte letterF[] = {
  B11111110,
  B10000010,
  B10000010,
  B11111100,
  B10000010,
  B10000010,
  B10000010,
  B00000000
};

byte letterG[] = {
  B01111110,
  B10000010,
  B10000000,
  B10001110,
  B10000010,
  B10000010,
  B01111100,
  B00000000
};

byte letterH[] = {
  B10000010,
  B10000010,
  B10000010,
  B11111110,
  B10000010,
  B10000010,
  B10000010,
  B10000010
};

byte letterI[] = {
  B11111110,
  B00110000,
  B00110000,
  B00110000,
  B00110000,
  B00110000,
  B00110000,
  B11111110
};

byte letterJ[] = {
  B00011110,
  B00001100,
  B00001100,
  B00001100,
  B10001100,
  B10001100,
  B01111000,
  B00000000
};

byte letterK[] = {
  B10000010,
  B10000100,
  B10001000,
  B11110000,
  B10001000,
  B10000100,
  B10000010,
  B10000000
};

byte letterL[] = {
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B11111110,
  B00000000
};

byte letterM[] = {
  B10000001,
  B11000011,
  B10100101,
  B10011001,
  B10000001,
  B10000001,
  B10000001,
  B10000001
};

byte letterN[] = {
  B10000011,
  B11000011,
  B10100011,
  B10010011,
  B10001111,
  B10000111,
  B10000011,
  B10000011
};

byte letterO[] = {
  B01111100,
  B10000010,
  B10000010,
  B10000010,
  B10000010,
  B10000010,
  B01111100,
  B00000000
};

byte letterP[] = {
  B11111110,
  B10000010,
  B10000010,
  B11111100,
  B10000000,
  B10000000,
  B10000000,
  B10000000
};

byte letterQ[] = {
  B01111100,
  B10000010,
  B10000010,
  B10000010,
  B10011010,
  B10001010,
  B01110100,
  B00000000
};

byte letterR[] = {
  B11111110,
  B10000010,
  B10000010,
  B11111100,
  B10001000,
  B10000100,
  B10000010,
  B10000011
};

byte letterS[] = {
  B01111100,
  B10000010,
  B10000000,
  B01111100,
  B00000010,
  B10000010,
  B01111100,
  B00000000
};

byte letterT[] = {
  B11111110,
  B00110000,
  B00110000,
  B00110000,
  B00110000,
  B00110000,
  B00110000,
  B00000000
};

byte letterU[] = {
  B10000010,
  B10000010,
  B10000010,
  B10000010,
  B10000010,
  B01111100,
  B00111000,
  B00010000
};

byte letterV[] = {
  B10000010,
  B10000010,
  B10000010,
  B10000010,
  B01111100,
  B00111000,
  B00010000,
  B00000000
};

byte letterW[] = {
  B10000001,
  B10000001,
  B10011001,
  B10100101,
  B11000011,
  B10000001,
  B10000001,
  B10000001
};

byte letterX[] = {
  B10000010,
  B01111100,
  B00111000,
  B00010000,
  B00111000,
  B01111100,
  B10000010,
  B00000000
};

byte letterY[] = {
  B10000010,
  B10000010,
  B01111100,
  B00111000,
  B00110000,
  B00110000,
  B00110000,
  B00000000
};

byte letterZ[] = {
  B11111110,
  B00000110,
  B00001100,
  B00011000,
  B00110000,
  B01100000,
  B11111110,
  B00000000
};



// Function declarations
void scrollTextFromJSON(const char* jsonTextTop, const char* jsonTextBottom, double topSpeedMultiplier, double bottomSpeedMultiplier);
void drawChar(int16_t x, int16_t y, char c, uint16_t color);
byte* getLetterBytes(char c);

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(50);
}

void loop() {
  const char* jsonTextTop = "{\"letters\":\"MY NAME IS AB\"}";
  const char* jsonTextBottom = "{\"letters\":\"MY LAST NAME IS ABKC\"}";

  double topSpeedMultiplier = 1.5;
  double bottomSpeedMultiplier = 2.0;

  scrollTextFromJSON(jsonTextTop, jsonTextBottom, topSpeedMultiplier, bottomSpeedMultiplier);
  delay(1000); // Delay before transitioning to the next text
}


void scrollTextFromJSON(const char* jsonTextTop, const char* jsonTextBottom, double topSpeedMultiplier, double bottomSpeedMultiplier) {
    DynamicJsonDocument docTop(128);
    DynamicJsonDocument docBottom(128);

    deserializeJson(docTop, jsonTextTop);
    deserializeJson(docBottom, jsonTextBottom);

    const char* textTop = docTop["letters"];
    const char* textBottom = docBottom["letters"];

    int textTopLength = strlen(textTop) * 8;
    int textBottomLength = strlen(textBottom) * 8;

    int16_t upperScrollPosition = matrix.width(); // Initial position for the top part
    int16_t lowerScrollPosition = matrix.width(); // Initial position for the bottom part

    while (upperScrollPosition > -(max(textTopLength, textBottomLength) + matrix.width()) || lowerScrollPosition > -(max(textTopLength, textBottomLength) + matrix.width())) {
        matrix.fillScreen(BG_COLOR);

        // Display text on the top half
        for (int8_t i = 0; i < strlen(textTop); i++) {
            drawChar(upperScrollPosition + i * 8, 0, textTop[i], TEXT_COLOR);
        }

        // Display text on the bottom half
        for (int8_t i = 0; i < strlen(textBottom); i++) {
            drawChar(lowerScrollPosition + i * 8, 8, textBottom[i], TEXT_COLOR);
        }

        matrix.show();

        // Update scroll positions based on speed multipliers
        upperScrollPosition -= topSpeedMultiplier;
        lowerScrollPosition -= bottomSpeedMultiplier;

        delay(100); // Adjust the delay based on your desired speed
    }
}



void drawChar(int16_t x, int16_t y, char c, uint16_t color) {
  if (x >= matrix.width() || y >= matrix.height()) return;

  byte* letterBytes = getLetterBytes(c);

  if (letterBytes != NULL) {
    for (int8_t i = 0; i < 8; i++) {
      if (y + i >= 0 && y + i < matrix.height()) {
        for (int8_t j = 7; j >= 0; j--) {  // Iterate in reverse order
          if (letterBytes[i] & (1 << j)) {
            matrix.drawPixel(x + (7 - j), y + i, color);  // Adjust the x-coordinate
          }
        }
      }
    }
  }
}



byte* getLetterBytes(char c) {
  switch (c) {
    case 'A':
        return letterA;
    case 'B':
        return letterB;
    case 'C':
        return letterC;
    case 'D':
        return letterD;
    case 'E':
        return letterE;
    case 'F':
        return letterF;
    case 'G':
        return letterG;
    case 'H':
        return letterH;
    case 'I':
        return letterI;
    case 'J':
        return letterJ;
    case 'K':
        return letterK;
    case 'L':
        return letterL;
    case 'M':
        return letterM;
    case 'N':
        return letterN;
    case 'O':
        return letterO;
    case 'P':
        return letterP;
    case 'Q':
        return letterQ;
    case 'R':
        return letterR;
    case 'S':
        return letterS;
    case 'T':
        return letterT;
    case 'U':
        return letterU;
    case 'V':
        return letterV;
    case 'W':
        return letterW;
    case 'X':
        return letterX;
    case 'Y':
        return letterY;
    case 'Z':
        return letterZ;
    default:
        return NULL;
  }
}



