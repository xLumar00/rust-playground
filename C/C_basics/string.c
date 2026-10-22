#include "types.h"
#include <stdio.h>

#define SIZE 101

void read_print_string(void) {
  //TODO: 1. Read a string from stdin of max-length of 100 characters.
  char str[SIZE];
  printf("Eneter a word: ");

  scanf(" %100s", str);

  //if (scanf("%100s", str ) ==1 ){
  //  printf("Entered: %s\n",str);
  //}


  
  //TODO: 2. Print read string to stdout.
  printf("%s \n", str);
  return;
}
//TODO: Implement the function find_length(char *str1) which returns the length of the string (do not count '\0').
int find_length(char *str1) {
    int count = 0;
    for (int i = 0; str1[i] != '\0'; i++) {
        count++;
    }
    return count;
  }

void read_print_string_length(void) {
  //TODO: 1. Read a string from stdin of max-length of 100 characters.
  char str1[SIZE];
  printf("Eneter a word: ");
  scanf(" %100s", str1);

  //TODO: 2. Print the length of the read string to stdout. (do not count '\0').

  printf("%i \n", find_length(str1));
  return;
}



void read_print_string_alphnum(void) {
  //TODO: 1. Read a string from stdin of max-length of 100 characters.
  char str2[SIZE];
  printf("Eneter a word: \n");
  scanf(" %100s", str2);

  //TODO: 2. Print both the number of letters (a-z, A-Z) and the number of numerals (0-9) in the read string to stdout.
  int count_letters = 0;
  int count_numbers = 0;

  for (int i =0; str2[i] != '\0'; i++) {
      if ((str2[i] >= 'a' && str2[i] <= 'z' )||( str2[i] >= 'A' && str2[i] <= 'Z')) {
        count_letters ++;
      } else if (str2[i] >= '0' && str2[i] <= '9') {
        count_numbers ++;
      }
  }

  printf("number of letters: %i \n", count_letters);
  printf("number of numbers: %i \n", count_numbers);

  return;
}

void read_print_string_lower(void) {
  //TODO: 1. Read a string from stdin of max-length of 100 characters.
  char str3[SIZE];
  char str3_lower[SIZE];
  printf("Eneter a word: \n");
  scanf(" %100s", str3);

  //TODO: 2. Print the read string with all letters in lowercase (e.g., A => a) to stdout.
  for (int i=0; str3[i] != '\0'; i++) {

      if (str3[i] >= 'A' && str3[i] <= 'Z') {
        str3_lower[i] = str3[i] + 32 ;
      }

      else {
        str3_lower[i] = str3[i]; 
      }

  }
  printf("%s \n", str3_lower);

  return;
}

void read_print_string_replace(void) {
  //TODO: 1. Read a character and a string of max-length of 100 characters from stdin.
  char str4[SIZE];
  char str4_replaced [SIZE];
  char character;
  
  printf("Enter a occurences to replace: \n");
  scanf(" %c", &character);
  printf("Eneter a word: \n");
  scanf(" %100s", str4);

  //TODO: 2. Print the read string with all occurences of read string replaced with '_' (e.g., ('a', "abba") => _bb_) to stdout.
  for (int i = 0; str4[i] != '\0'; i++) {
    if (str4[i] == character) {
      str4_replaced[i] = '_'; 
    }
    else {
      str4_replaced[i] = str4[i];
    }
  }
  printf("%s \n", str4_replaced);


  return;
}


void read_print_string_compare(void) {
  //TODO: 1. Read  2 string, each of max-length of 100 characters, from stdin.
  char str_A[SIZE];
  char str_B[SIZE];

  int value = 1;

  printf("Eneter a word: \n");
  scanf(" %100s", str_A);

  printf("Eneter a word: \n");
  scanf(" %100s", str_B);

  //TODO: 2. Determine whether strings are equal (two strings are equal if they have the same length and characters in both strings on a given index are identical).

  for (int i = 0; str_A[i] != '\0' && str_B[i] != '\0'; i++) {
    if (str_A[i] != str_B[i]) {
      value = 0;
      break;
    }
  }

  if (find_length(str_A) != find_length(str_B)) {
    value = 0;
  }

  if (value == 1) {
    printf("Strings are identical \n");
  }
  else {
    printf("Strings are not identical \n");
  }
  
  
  return;
}


#ifndef TEST_BUILD

int main() {

  printf("read_print_string \n");
  //read_print_string();

  printf("read_print_string_length \n");
  read_print_string_length();

  printf("read_print_string_alphnum \n");
  //read_print_string_alphnum();

  printf("read_print_string_lower \n");
  //read_print_string_lower();

  printf("read_print_string_replace \n");
  //read_print_string_replace();

  printf("read_print_string_compare \n");
  read_print_string_compare();

  return 0;
}

#endif
