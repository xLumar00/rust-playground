#include "types.h"
#include <stdio.h>


void print_helloworld() {
  //TODO 1. Print 'Hello World' to stdout.
  printf("Hello World!\n");
  printf("Hello World!\n");

  return;
}

#define A -4
#define B 2
#define C 3
void print_discriminant() {
  //TODO 1. Calculate and print discriminant with values defined above to stdout.
  int dis = 0;
  dis = B*B-4*A*C;
  printf("%i",dis);

  return;
}

void read_print_is_even() {
  //TODO 1. Read a number from stdin and output to stdout whether the read number is even or not.
  int parne;
  scanf("%i",&parne);

  if (parne %2 ==0) {
    printf("je parne\n");
  }

  return;
}

void read_print_is_in_interval() {
  //TODO 1. Read 2 numbers from stdin. These two numbers represent a interval.
  int number_1;
  int number_2;
  scanf("%i",&number_1);
  scanf("%i",&number_2);

  //TODO 2. Read third number from stdin. Output to stdout whether the third number is contained in the previously read interval.

  int number_3;
  scanf("%i",&number_3);
  if (number_3>number_1 && number_3<number_2) {
    printf("Cislo patri do intervalu.\n");
  }

  return;
}

void read_print_is_leap_year() {
  //TODO 1. Read a number representing a year from stdin.
  int year;
  scanf("%d",&year);

  //TODO 2. Determine whether the year is a leap year or not.
  if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
      printf("Is a leap year.\n");
  }

  return;
}
  

void read_print_maximum() {
  //TODO 1. Read 3 numbers from stdin.
  float number_4;
  float number_5;
  float number_6;


  scanf("%f",&number_4);
  scanf("%f",&number_5);
  scanf("%f",&number_6);

  //TODO 2. Output the largest of read numbers to stdout.
  float max = number_4;
  if (number_5 > number_4) {
    max = number_5;}
  if (number_6 > number_4) {
    max = number_6;}
  printf("%f",max);
  
  return;
}


#ifndef TEST_BUILD

int main() {
  
  printf("\n--print_helloworld--\n");
  print_helloworld();

  printf("\n--print_discriminant--\n");
  print_discriminant();
  
  printf("\n--read_print_is_even--\n");
  read_print_is_even();

  printf("\n--read_print_is_in_interval--\n");
  read_print_is_in_interval();

  printf("\n--read_print_is_leap_year--\n");
  read_print_is_leap_year();

  printf("\n--read_print_maximum--\n");
  read_print_maximum();

  return 0;
}

#endif

// Najčastejšie formátovacie špecifikátory (printf):

// %d / %i → celé číslo so znamienkom (int)

// %u → celé číslo bez znamienka (unsigned int)

// %f → desatinné číslo (float, double)

// %lf → desatinné číslo typu double (pri scanf nutné, pri printf stačí %f)

// %c → jeden znak (char)

// %s → reťazec (char[])

// %p → adresa v pamäti (ukazovateľ)

// %x / %X → celé číslo v hexadecimálnom tvare (malé / veľké písmená)

// %o → celé číslo v osmičkovej sústave