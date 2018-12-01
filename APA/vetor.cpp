#include <iostream>
#include "vetor.h"

using namespace std;

void gerar_vetor_ordenado(int vetor[], int n){
     for(int i = 0; i < n; i++){
        vetor[i]=i;
   }
}

void embaralhar(int vetor[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int r = rand() % n;

		int temp = vetor[i];
		vetor[i] = vetor[r];
		vetor[r] = temp;
	}
}



void imprimir_vetor(int vetor[], int n)
{
    int i;
    for (i=0; i < n; i++)
        cout << vetor[i] << " ";
    cout << "\n";
}

void imprimir_vetor(float vetor[], int n)
{
    int i;
    for (i=0; i < n; i++)
        cout << vetor[i] << " ";
    cout << "\n";
}
