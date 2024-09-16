#include <stdio.h>
#include <stdlib.h>

# define NUM 1000 //set array size to 1000
long long array[NUM];
const int NIL = -1;

void initMem() {
  for(long iter = 0; iter < NUM; iter++) {
    array[iter] = NIL;
  }
}

unsigned long long fibRecursive(unsigned long long num);
unsigned long long fibRecursiveMem(unsigned long long num);

unsigned long long fibIterative(unsigned long long num);
unsigned long long fibIterativeMem(unsigned long long num);

int main(int argc, char* argv[]) {
    // Set argument as variables
    int integer = atoi(argv[1]);
    char type = argv[2][0];
    char* filename = argv[3];

    
    FILE *fileTxt = fopen(filename, "r");
    char content[100];
    fgets(content, 100, fileTxt);

    int number2 = atoi(content);
    unsigned long long N = number2 + integer;
    initMem();

    // Resolve the -1 indexing by substracing value
    if (type == 'r') {
        printf("%llu\n", fibRecursiveMem(N - 1)); // Recursive call
    }
    else if(type == 'i') {
        printf("%llu\n", fibIterative(N - 1)); // Iterative call
    }
  return 0;
}

unsigned long long fibRecursiveMem(unsigned long long num) {
  if(array[num] == NIL) {
    if(num <= 1) {
      array[num] = num; 
    } else {
      array[num] = fibRecursiveMem(num - 1) + fibRecursiveMem(num - 2);
    }
  }
  return array[num];
}

unsigned long long fibRecursive(unsigned long long num) {
    
    if (num <= 1) return num;
    else return fibRecursive(num - 2) + fibRecursive(num - 1);
}

unsigned long long fibIterative(unsigned long long num) {
    unsigned long long prevPrevNumber = 0;
    unsigned long long prevNumber = 1;
    unsigned long long summation;
    
    if(num <= 1) {
      return num;
    }
    for(unsigned long long iter = 1; iter < num ; iter++) {
        summation = prevNumber + prevPrevNumber;
        prevPrevNumber = prevNumber;
        prevNumber = summation;
    }
    
    return prevNumber;
}
// TODO make fibIterativeMem() and fibRecursiveMem()