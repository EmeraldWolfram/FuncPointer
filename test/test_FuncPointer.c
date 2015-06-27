#include "unity.h"
#include "FuncPointer.h"
#include <stdio.h>

void setUp(void){}

void tearDown(void){}

void dummy(int value){
  printf("I am a dummy with value %d\n", value);
}

void test_FuncPointer(void){
  char value = 7;
  char* ptrToChar;
  char* ptrToChar1;
  char** ptrToPtrToChar = NULL;
  ptrToChar = &value;
  ptrToPtrToChar = &ptrToChar;
  
  void (*FuncPtr)(int) = dummy;         //FuncPtr is pointer to function that take (int) and return void
  void (**FuncPtrPtr1)(int) = &FuncPtr; //FuncPtrPtr is pointer to pointer to function that take (int) and return void
  
  (*FuncPtrPtr1)(40);
  
  printf("Address of value is 0x%p\n", &value);
  printf("Address of ptrToChar is 0x%p\n", &ptrToChar);
  printf("Address of ptrToChar1 is 0x%p\n", &ptrToChar1);
  printf("Address of ptrToPtrToChar is 0x%p\n\n", &ptrToPtrToChar);
  
  printf("Number of value is 0x%X\n", value);
  printf("Number of ptrToChar is 0x%X\n", ptrToChar);
  printf("Number of ptrToChar1 is 0x%X\n", ptrToChar1);
  printf("Number of ptrToPtrToChar is 0x%X\n\n", ptrToPtrToChar);

  ptrToPtrToChar = &ptrToChar1;
  *ptrToPtrToChar = &value;
  **ptrToPtrToChar = 88;
  printf("Number of new ptrToPtrToChar is 0x%X\n", ptrToPtrToChar);
  printf("Number of new ptrToChar is 0x%X\n", ptrToChar);
  printf("Number of new value is 0x%X\n", value);

}
