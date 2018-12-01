#include <iostream>
#include "vetor.h"

using namespace std;

void merge(int vetor[], int esq, int meio, int dir)
{
    int i, j, k;
    int n1 = meio - esq + 1;
    int n2 =  dir - meio;

    /* create temp vetorays */
    int L[n1], R[n2];

    /* Copy data to temp vetorays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = vetor[esq + i];
    for (j = 0; j < n2; j++)
        R[j] = vetor[meio + 1+ j];

    /* Merge the temp vetorays back into vetor[l..r]*/
    i = 0; // Initiaesq index of first subvetoray
    j = 0; // Initiaesq index of second subvetoray
    k = esq; // Initiaesq index of merged subvetoray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            vetor[k] = L[i];
            i++;
        }
        else
        {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        vetor[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        vetor[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-vetoray of vetor to be sorted */
void mergeSort(int vetor[], int esq, int dir)
{
    if (esq < dir)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int meio = esq+(dir-esq)/2;

        // Sort first and second halves
        mergeSort(vetor, esq, meio);
        mergeSort(vetor, meio+1, dir);

        merge(vetor, esq, meio, dir);
    }
}

void testar_ms(int vetor[], int n){
    gerar_vetor_ordenado(vetor,n);
    embaralhar(vetor,n);

    mergeSort(vetor, 0, n - 1);

}
