#include <iostream>
#include <algorithm>
using namespace std;


float fractional_knapsack(int n, int peso[], int valor[], int capacidade) {
   float taxa,total = 0;
   int i, minimo;

   for (i = 0; i < n; i++) {
     taxa = valor[i]/(float)peso[i];
     minimo = min(capacidade, peso[i]);
     total = total + minimo*taxa;
     capacidade = capacidade - minimo;
   }

   return total;

}

void gerar_vetores_valor_tamanho(int tamanho[], int valor[],int n, int maior, int menor){
   srand((unsigned)time(0));
   for (int i = 0; i < n; i++) {
        tamanho[i] = rand()%(maior-menor+1) + menor;
        valor[i] = rand()%(maior-menor+1) + menor;
   }
}

void ordenar_por_taxa(int peso[], int valor[], int n){
   int temp;
   for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
         if (valor[i] / (float)peso[i] < valor[j] / (float)peso[j]) {

            temp = peso[j];
            peso[j] = peso[i];
            peso[i] = temp;

            temp = valor[j];
            valor[j] = valor[i];
            valor[i] = temp;
         }
      }
   }

}
