#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 30

enum {CELL_OFF, CELL_ON};
enum {black=30, red=31, green=32, yellow=33, blue=34, purple=35, cyan=36, white=37, next=38, next2=39, reset=40};
int current_color = black;

void change_colour() {
    current_color++;
    if (current_color == reset) {
      current_color = black;
    }
    printf("\033[1;%im", current_color);
}

int determine_cell_110(int left, int centre, int right) {
  if (left==CELL_OFF && centre == CELL_OFF && right == CELL_OFF) {
    return CELL_OFF;
  }
  if (left==CELL_ON && centre == CELL_ON && right == CELL_ON) {
    return CELL_OFF;
  }
  if (left==CELL_ON && centre == CELL_OFF && right == CELL_ON) {
    return CELL_ON;
  }
  if (left==CELL_ON && centre == CELL_ON && right == CELL_OFF) {
    return CELL_ON;
  }
  if (left==CELL_ON && centre == CELL_OFF && right == CELL_OFF) {
    return CELL_OFF;
  }
  if (left==CELL_OFF && centre == CELL_ON && right == CELL_ON) {
    return CELL_ON;
  }
  if (left==CELL_OFF && centre == CELL_ON && right == CELL_OFF) {
    return CELL_ON;
  }
  if (left==CELL_OFF && centre == CELL_OFF && right == CELL_ON) {
    return CELL_ON;
  }
}

int determine_cell_30(int left, int centre, int right) {
  if (left==CELL_OFF && centre == CELL_OFF && right == CELL_OFF) {
    return CELL_OFF;
  }
  if (left==CELL_ON && centre == CELL_ON && right == CELL_ON) {
    return CELL_OFF;
  }
  if (left==CELL_ON && centre == CELL_OFF && right == CELL_ON) {
    return CELL_OFF;
  }
  if (left==CELL_ON && centre == CELL_ON && right == CELL_OFF) {
    return CELL_ON;
  }
  if (left==CELL_ON && centre == CELL_OFF && right == CELL_OFF) {
    return CELL_ON;
  }
  if (left==CELL_OFF && centre == CELL_ON && right == CELL_ON) {
    return CELL_ON;
  }
  if (left==CELL_OFF && centre == CELL_ON && right == CELL_OFF) {
    return CELL_ON;
  }
  if (left==CELL_OFF && centre == CELL_OFF && right == CELL_ON) {
    return CELL_ON;
  }
}

int determine_cell_90(int left, int centre, int right) {
  if (left==CELL_OFF && centre == CELL_OFF && right == CELL_OFF) {
    return CELL_OFF;
  }
  if (left==CELL_ON && centre == CELL_ON && right == CELL_ON) {
    return CELL_OFF;
  }
  if (left==CELL_ON && centre == CELL_OFF && right == CELL_ON) {
    return CELL_OFF;
  }
  if (left==CELL_ON && centre == CELL_ON && right == CELL_OFF) {
    return CELL_ON;
  }
  if (left==CELL_ON && centre == CELL_OFF && right == CELL_OFF) {
    return CELL_ON;
  }
  if (left==CELL_OFF && centre == CELL_ON && right == CELL_ON) {
    return CELL_ON;
  }
  if (left==CELL_OFF && centre == CELL_ON && right == CELL_OFF) {
    return CELL_OFF;
  }
  if (left==CELL_OFF && centre == CELL_OFF && right == CELL_ON) {
    return CELL_ON;
  }
}

int main() {
  
  int initial_row[MAX_SIZE];
  srand(time(NULL));

  for (int i=0; i<MAX_SIZE; i++) {
    int r = rand() % 20;
    if (r < 10) {
      initial_row[i] = CELL_ON;
    }
    else {
      initial_row[i] = CELL_OFF;
    };
  };

  int last_row[MAX_SIZE];

  for (int i=0;i<MAX_SIZE; i++) {
      last_row[i] = initial_row[i];
    }
  
  int next_row[MAX_SIZE];

  int j = 0;
  while (1) {
    printf("\n");

    change_colour();    

    printf("|");
    for (int i=0;i<MAX_SIZE; i++) {
      int left = last_row[i-1];
      int right = last_row[i+1];
      int centre = last_row[i];
      if (i==0) {
        left = last_row[MAX_SIZE-1];
      }
      if (i==MAX_SIZE-1) {
        right = last_row[0];
      }

      change_colour();

      next_row[i] = determine_cell_90(left, centre, right); /* Change rules here */
      (next_row[i]==CELL_ON) ? printf("*") : printf(" ");
    };
    
    for (int i=0;i<MAX_SIZE; i++) {
      last_row[i] = next_row[i];
    };
    
    j++;
    
    change_colour();
    
    printf("|");
    
  }; 
  return 0;
}
