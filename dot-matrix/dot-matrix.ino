//We always have to include the library
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc = LedControl(12, 11, 10, 1);

/* we always wait a bit between updates of the display */
unsigned long delaytime = 300;
unsigned long delaytime2 = 30;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0, false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0, 8);
  /* and clear the display */
  lc.clearDisplay(0);
}

/*
 This method will display the characters for the
 word "Arduino" one after the other on the matrix. 
 (you need at least 5x7 leds to see the whole chars)
 */
void writeArduinoOnMatrix() {
  /* here is the data for the characters */
  byte a[5] = { B01111110, B10001000, B10001000, B10001000, B01111110 };
  byte r[5] = { B00111110, B00010000, B00100000, B00100000, B00010000 };
  byte d[5] = { B00011100, B00100010, B00100010, B00010010, B11111110 };
  byte u[5] = { B00111100, B00000010, B00000010, B00000100, B00111110 };
  byte i[5] = { B00000000, B00100010, B10111110, B00000010, B00000000 };
  byte n[5] = { B00111110, B00010000, B00100000, B00100000, B00011110 };
  byte o[5] = { B00011100, B00100010, B00100010, B00100010, B00011100 };

  /* now display them one by one with a small delay */
  lc.setRow(0, 0, a[0]);
  lc.setRow(0, 1, a[1]);
  lc.setRow(0, 2, a[2]);
  lc.setRow(0, 3, a[3]);
  lc.setRow(0, 4, a[4]);
  delay(delaytime);
  lc.setRow(0, 0, r[0]);
  lc.setRow(0, 1, r[1]);
  lc.setRow(0, 2, r[2]);
  lc.setRow(0, 3, r[3]);
  lc.setRow(0, 4, r[4]);
  delay(delaytime);
  lc.setRow(0, 0, d[0]);
  lc.setRow(0, 1, d[1]);
  lc.setRow(0, 2, d[2]);
  lc.setRow(0, 3, d[3]);
  lc.setRow(0, 4, d[4]);
  delay(delaytime);
  lc.setRow(0, 0, u[0]);
  lc.setRow(0, 1, u[1]);
  lc.setRow(0, 2, u[2]);
  lc.setRow(0, 3, u[3]);
  lc.setRow(0, 4, u[4]);
  delay(delaytime);
  lc.setRow(0, 0, i[0]);
  lc.setRow(0, 1, i[1]);
  lc.setRow(0, 2, i[2]);
  lc.setRow(0, 3, i[3]);
  lc.setRow(0, 4, i[4]);
  delay(delaytime);
  lc.setRow(0, 0, n[0]);
  lc.setRow(0, 1, n[1]);
  lc.setRow(0, 2, n[2]);
  lc.setRow(0, 3, n[3]);
  lc.setRow(0, 4, n[4]);
  delay(delaytime);
  lc.setRow(0, 0, o[0]);
  lc.setRow(0, 1, o[1]);
  lc.setRow(0, 2, o[2]);
  lc.setRow(0, 3, o[3]);
  lc.setRow(0, 4, o[4]);
  delay(delaytime);
  lc.setRow(0, 0, 0);
  lc.setRow(0, 1, 0);
  lc.setRow(0, 2, 0);
  lc.setRow(0, 3, 0);
  lc.setRow(0, 4, 0);
  delay(delaytime);
}

/*
  This function lights up a some Leds in a row.
 The pattern will be repeated on every row.
 The pattern will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
 */
void rows() {
  for (int row = 0; row < 8; row++) {
    delay(delaytime2);
    lc.setRow(0, row, B10100000);
    delay(delaytime2);
    lc.setRow(0, row, (byte)0);
    for (int i = 0; i < row; i++) {
      delay(delaytime2);
      lc.setRow(0, row, B10100000);
      delay(delaytime2);
      lc.setRow(0, row, (byte)0);
    }
  }
}

/*
  This function lights up a some Leds in a column.
 The pattern will be repeated on every column.
 The pattern will blink along with the column-number.
 column number 4 (index==3) will blink 4 times etc.
 */
void columns() {
  for (int col = 0; col < 8; col++) {
    delay(delaytime2);
    lc.setColumn(0, col, B10100000);
    delay(delaytime2);
    lc.setColumn(0, col, (byte)0);
    for (int i = 0; i < col; i++) {
      delay(delaytime2);
      lc.setColumn(0, col, B10100000);
      delay(delaytime2);
      lc.setColumn(0, col, (byte)0);
    }
  }
}

/* 
 This function will light up every Led on the matrix.
 The led will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
 */
void single() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      delay(delaytime2);
      lc.setLed(0, row, col, true);
      delay(delaytime2);
      for (int i = 0; i < col; i++) {
        lc.setLed(0, row, col, false);
        delay(delaytime2);
        lc.setLed(0, row, col, true);
        delay(delaytime2);
      }
    }
  }
}


/*
 This method is draws a pacman
 */
void drawPacman() {
  /* here is the data for the characters */
  byte a[8] = { B00111000, B01010100, B10000010, B10001110, B10000010, B01000100, B00111000, B00000000 };
  byte r[8] = { B00111100, B01010010, B10000100, B10001000, B10000100, B01000010, B00111100, B00000000 };
  // TODO - correct the comments below to include an ending comment
  /*byte d[8]={B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
  byte u[8]={B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
  byte i[8]={B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
  byte n[8]={B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
  byte o[8]={B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
  byte s[8]={B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};*/

  /* now display them one by one with a small delay */
  lc.setRow(0, 0, a[0]);
  lc.setRow(0, 1, a[1]);
  lc.setRow(0, 2, a[2]);
  lc.setRow(0, 3, a[3]);
  lc.setRow(0, 4, a[4]);
  lc.setRow(0, 5, a[5]);
  lc.setRow(0, 6, a[6]);
  lc.setRow(0, 7, a[7]);
  delay(delaytime);
  lc.setRow(0, 0, r[0]);
  lc.setRow(0, 1, r[1]);
  lc.setRow(0, 2, r[2]);
  lc.setRow(0, 3, r[3]);
  lc.setRow(0, 4, r[4]);
  lc.setRow(0, 5, r[5]);
  lc.setRow(0, 6, r[6]);
  lc.setRow(0, 7, r[7]);
  delay(delaytime);
  /*lc.setRow(0,0,d[0]);
  lc.setRow(0,1,d[1]);
  lc.setRow(0,2,d[2]);
  lc.setRow(0,3,d[3]);
  lc.setRow(0,4,d[4]);
  lc.setRow(0,5,d[5]);
  lc.setRow(0,6,d[6]);
  lc.setRow(0,7,d[7]);
  delay(delaytime);
  lc.setRow(0,0,u[0]);
  lc.setRow(0,1,u[1]);
  lc.setRow(0,2,u[2]);
  lc.setRow(0,3,u[3]);
  lc.setRow(0,4,u[4]);
  lc.setRow(0,5,u[5]);
  lc.setRow(0,6,u[6]);
  lc.setRow(0,7,u[7]);
  delay(delaytime);
  lc.setRow(0,0,i[0]);
  lc.setRow(0,1,i[1]);
  lc.setRow(0,2,i[2]);
  lc.setRow(0,3,i[3]);
  lc.setRow(0,4,i[4]);
  lc.setRow(0,5,i[5]);
  lc.setRow(0,6,i[6]);
  lc.setRow(0,7,i[7]);
  delay(delaytime);
  lc.setRow(0,0,n[0]);
  lc.setRow(0,1,n[1]);
  lc.setRow(0,2,n[2]);
  lc.setRow(0,3,n[3]);
  lc.setRow(0,4,n[4]);
  lc.setRow(0,5,n[5]);
  lc.setRow(0,6,n[6]);
  lc.setRow(0,7,n[7]);
  delay(delaytime);
  lc.setRow(0,0,o[0]);
  lc.setRow(0,1,o[1]);
  lc.setRow(0,2,o[2]);
  lc.setRow(0,3,o[3]);
  lc.setRow(0,4,o[4]);
  lc.setRow(0,5,o[5]);
  lc.setRow(0,6,o[6]);
  lc.setRow(0,7,o[7]);
  delay(delaytime);
  lc.setRow(0,0,s[0]);
  lc.setRow(0,1,s[1]);
  lc.setRow(0,2,s[2]);
  lc.setRow(0,3,s[3]);
  lc.setRow(0,4,s[4]);
  lc.setRow(0,5,s[5]);
  lc.setRow(0,6,s[6]);
  lc.setRow(0,7,s[7]);
  delay(delaytime);*/
}


/*
 This renders one orizontal line
 */
void renderOneLine(int line) {

  byte oneRow = B11111111;
  /* here is the data for the characters */
  byte rows[8] = { B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000001 };

  rows[line] = oneRow;

  // now display the row
  lc.setRow(0, 0, rows[0]);
  lc.setRow(0, 1, rows[1]);
  lc.setRow(0, 2, rows[2]);
  lc.setRow(0, 3, rows[3]);
  lc.setRow(0, 4, rows[4]);
  lc.setRow(0, 5, rows[5]);
  lc.setRow(0, 6, rows[6]);
  lc.setRow(0, 7, rows[7]);
}

void loopLines() {
  int localDelay = 100;
  for (int j = 0; j < 5; j++) {
    for (int i = 7; i >= 0; i--) {
      renderOneLine(i);
      delay(localDelay);
    }
    localDelay = localDelay - 20;
  }
}

void drawPacmanTimes(int times) {
  for (int i = 0; i < times; i++) {
    drawPacman();
  }
}

void loop() {
  writeArduinoOnMatrix();
  rows();
  columns();
  single();

  drawPacmanTimes(5);
  delay(delaytime);
  loopLines();
}
