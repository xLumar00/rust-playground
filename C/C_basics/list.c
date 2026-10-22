#include "types.h"
#include <stdio.h>

#define ARRAY_LENGTH 5
#define MERGED_ARRAY_LENGTH 2 * ARRAY_LENGTH

void read_print_array_reverse(void) {
  //TODO 1. Read an array of numbers of length ARRAY_LENGTH from stdin.
  int arr[ARRAY_LENGTH];

  for (int i = 0; i < ARRAY_LENGTH; i++) {
      scanf("%i", &arr[i]);
  }

  //TODO 2. Print read array in reversed order to stdout.

  for (int i = ARRAY_LENGTH-1 ; i >= 0; i--) {
      printf("%i \n", arr[i]);
  }
  return;
}

void read_print_array_max(void) {
  //TODO 1. Read an array of numbers of length ARRAY_LENGTH from stdin.
  int arr[ARRAY_LENGTH];
  for (int i = 0; i < ARRAY_LENGTH; i++) {
      scanf("%i", &arr[i]);
  }

  //TODO 2. Find maximum value and print it to stdout.
  int max = 0;
  for (int i = 0 ; i< ARRAY_LENGTH;i++ ){
    if (arr[i] > max) {
    max = arr[i];
    }
  }
  printf("%i", max);

  return;
}

void read_print_array_avg(void) {
  //TODO 1. Read an array of numbers of length ARRAY_LENGTH from stdin.
  int arr[ARRAY_LENGTH];
  for (int i = 0; i < ARRAY_LENGTH; i++) {
      scanf("%i", &arr[i]);
  }

  //TODO 2. Calculate average value and print it to stdout.
  float sum = 0;
  for (int i =0; i < ARRAY_LENGTH; i++) {
    sum += arr[i];
  }
  float avg = sum/ARRAY_LENGTH;
  printf("%f",avg);

  return;
}


void read_print_array_merge(void) {
  //TODO 1. Read 2 arrays of numbers, each of length ARRAY_LENGTH from stdin.
  int arr_1[ARRAY_LENGTH];
  int arr_2[ARRAY_LENGTH];

  for (int i =0; i<ARRAY_LENGTH; i++) {
    scanf("%i", &arr_1[i]);
  }

  for (int i =0; i<ARRAY_LENGTH; i++) {
    scanf("%i", &arr_2[i]);
  }

  //TODO 2. To 3rd array of length MERGED_ARRAY_LENGTH copy first and 
  //second arrays respectively and resulting third array print to stdout.
  int arr_3[MERGED_ARRAY_LENGTH];

  for (int i = 0; i < MERGED_ARRAY_LENGTH; i++) {
    if (i < ARRAY_LENGTH) {
      arr_3[i] = arr_1[i];
    }
    else {
      arr_3[i] = arr_2[i - ARRAY_LENGTH];
    }
  }

  for (int i = 0; i < MERGED_ARRAY_LENGTH; i++) {
    printf("%i", arr_3[i]);
  }


  return;
}


#ifndef TEST_BUILD
//int argc, char *argv[]
int main() {
  
  printf("\n--read_print_array_reverse--\n");
  read_print_array_reverse();

  printf("\n--read_print_array_max--\n");
  read_print_array_max();
  
  printf("\n--read_print_array_avg--\n");
  read_print_array_avg();

  printf("\n--read_print_array_merge--\n");
  read_print_array_merge();

  return 0;
}

#endif
