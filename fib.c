#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long fibRecursive(long num);
long fibIterative(long num);

int main(int argc, char* argv[]) {
    // Set argument as variables
    clock_t start = clock();
    int integer = atoi(argv[1]);
    char type = argv[2][0];
    char* filename = argv[3];

    
    FILE *fileTxt = fopen(filename, "r");
    char content[100];
    fgets(content, 100, fileTxt);

    int number2 = atoi(content);
    long N = number2 + integer;

    // Resolve the -1 indexing by substracing value
    if (type == 'r') {
        printf("%d\n", fibRecursive(N - 1)); // Recursive call
    }
    else if(type == 'i') {
        printf("%d\n", fibIterative(N - 1)); // Iterative call
    }
  
  clock_t total = clock() - start;
  double time = ((double)total)/CLOCKS_PER_SEC;
  // printf("%f\n", time); Prints runtime in seconds
  return 0;
}

long fibRecursive(long num) {
    if (num <= 1) return num;
    else return fibRecursive(num - 2) + fibRecursive(num - 1);
}

long fibIterative(long num) {
    long prevPrevNumber = 0;
    long prevNumber = 1;
    long summation;
    
    for(int iter = 0; iter < num - 1; iter++) {
        summation = prevNumber + prevPrevNumber;
        prevPrevNumber = prevNumber;
        prevNumber = summation;
    }
    
    return summation;
}