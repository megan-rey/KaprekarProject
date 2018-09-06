#include<stdlib.h>
#include<stdio.h>

#include "kaprekarUtils.h"

int main(int argc, char **argv) {

  if(argc != 2) {
    fprintf(stderr, "Usage: %s n\n", argv[0]);
    exit(1);
  }

  int n = atoi(argv[1]);

  if(isKaprekar(n)) {
    printf("%d is a Kaprekar Number!\n", n);
  } else {
    printf("%d is not a Kaprekar Number!\n", n);
  }
  int isKaprekar(int n) {

    if(n < 1) {
      return false;
    }

    int i;
    long square = n * (long) n;
    int numDigits = (int) log10(n) + 1;
    long modulus = 0;
    long first, second;

    //for each possible "split" of the square...
    for(i=1; i<=numberOfDigits; i++) {
      //increase the modulus by a factor of 10
      modulous *= 10;

      //split the square into two parts
      first = square / modulus;
      second = square % modulus;

      //test if the split makes a Kaprekar number
      if(second > 0 &&
         first + second == n) {
        return 1;
      }
    }

  return 0;
}
