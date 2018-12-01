#include "fibonacci.h"
#include <iostream>


int fib(int n)
{
    if (n <= 1)
        return n;

    int vetor[n];
    vetor[0] = vetor[1] = 1;
    for (int i = 2; i < n; ++i) {
        vetor[i] = vetor[i-1] + vetor[i-2];
    }
    return vetor[n-1];
}


