#include <stdio.h>
#include <stdlib.h>

int fibRecursive(int num);
int fibIterative(int num);

int main(int argc, char* argv[]) {
    // Set argument as variables
    int integer = atoi(argv[1]);
    char type = argv[2][0];
    char* filename = argv[3];

    
    FILE *fileTxt = fopen(filename, "r");
    char content[100];
    fgets(content, 100, fileTxt);

    int number2 = atoi(content);
    int N = number2 + integer;

    // Resolve the -1 indexing by substracing value
    if (type == 'r') {
        printf("%d\n", fibRecursive(N - 1)); // Recursive call
    }
    else if(type == 'i') {
        printf("%d\n", fibIterative(N - 1)); // Iterative call
    }

   return 0;
}

int fibRecursive(int num) {
    if (num <= 1) return num;
    else return fibRecursive(num - 2) + fibRecursive(num - 1);
}

int fibIterative(int num) {
    int prevPrevNumber = 0;
    int prevNumber = 1;
    int summation;
    
    for(int iter = 0; iter < num - 1; iter++) {
        summation = prevNumber + prevPrevNumber;
        prevPrevNumber = prevNumber;
        prevNumber = summation;
    }
    
    return summation;
}