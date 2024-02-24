// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <math.h>


bool checkPrime(uint64_t value) {
  uint64_t val = fabs(value);
  if ((1 == val) || (0 == val)) return false;
  if (2 == val) return true;
  for (int i = 2; i * i <= val; i++) {
      if (0 == val % i) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t num = 0;
  if (1 == n)return 2;
  for (auto i = 2; i < 1000000; ++i) {
      if (checkPrime(i)) ++num;
      else continue;
      if (num == n) return i;
  }
}

uint64_t nextPrime(uint64_t value) {
  for (auto i = value+1; i < value + 30; ++i) {
      if (checkPrime(i))return i;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  if ((1 == hbound) || (2 == hbound))return 0;
  else
      for (auto i = 1; i < hbound; ++i) {
          if (checkPrime(i)) sum += i;
          else continue;
      }
  return sum;
}
