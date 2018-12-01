#include <iostream>
#include <time.h>
#include "selection_sort.h"
#include "merge_sort.h"
#include "vetor.h"
#include "fibonacci.h"
#include "fractional_knapsack.h"
#include <fstream>
#include <stdlib.h>



#include <bits/stdc++.h>

using namespace std;



int main()
{
   ofstream out;
   out.open("saida.dat");

   clock_t tStart;
   string arquivo;
   int alg, test;
   int n = 0, multi;

   cout << "Escolha uma das opções abaixo:\n";
   cout << "1 - Incremental\n";
   cout << "2 - Divisao e Conquista\n";
   cout << "3 - Programacao Dinamica\n";
   cout << "4 - Guloso\n\n";
   cin >> alg;
   cout << "\n\n\n";


   cout << "Escolha uma das opções abaixo:\n";
   cout << "1 - Testar instancia aleatória\n";
   cout << "2 - Testar e exportar o tempo de execução\n\n";
   cin >> test;
   cout << "\n\n\n";

   if(alg == 1){
     if(test == 1){
       cout << "Entre com o tamanho do vetor\n";
       cin >> n;
       int vetor[n];
       cout << "\n\n\n";
       gerar_vetor_ordenado(vetor, n);
       embaralhar(vetor, n);

       cout << "Vetor desordenado\n";
       imprimir_vetor(vetor,n);
       selection_sort(vetor, n - 1);
       cout << "Vetor ordenado\n";
       imprimir_vetor(vetor,n);
     }
     if(test == 2){
       cout << "Entre com o núméro de testes\n";
       cin >> n;
       cout << "\nEntre com o intervalo do tamanho das instancias\n";
       cin >> multi;

       cout << "---------------Processando os testes---------------\n\n";
       for(int i = 1; i < n; i++){
          int vetor[i*multi];
          gerar_vetor_ordenado(vetor,i*multi);
          selection_sort_desc(vetor,i*multi);

          tStart = clock();
          selection_sort(vetor, i*multi - 1);
          out << "\n"<< i*multi << " " << ((double)(clock() - tStart)/(double)CLOCKS_PER_SEC);
       }
        cout << "---------------Fim dos testes---------------\n\n";

     }
   }

   if(alg == 2){
     if(test == 1){
       cout << "Entre com o tamanho do vetor\n";
       cin >> n;
       int vetor[n];
       cout << "\n\n\n";
       gerar_vetor_ordenado(vetor, n);
       embaralhar(vetor, n);

       cout << "Vetor desordenado\n";
       imprimir_vetor(vetor,n);
       mergeSort(vetor, 0, n - 1);
       cout << "Vetor ordenado\n";
       imprimir_vetor(vetor,n);
     }
     if(test == 2){
       cout << "Entre com o núméro de testes\n";
       cin >> n;
       cout << "\nEntre com o intervalo do tamanho das instancias\n";
       cin >> multi;

       cout << "---------------Processando os testes---------------\n\n";
       for(int i = 1; i < n; i++){
        int vetor[i*multi];
        gerar_vetor_ordenado(vetor,i*multi);
        tStart = clock();
        mergeSort(vetor, 0, i*multi - 1);
        out << "\n"<< i*multi << " " << ((double)(clock() - tStart)/(double)CLOCKS_PER_SEC);
       }
        cout << "---------------Fim dos testes---------------\n\n";

     }
   }

   if(alg == 3){
     if(test == 1){
       cout << "Entre com um numero\n";
       cin >> n;
       cout << "\nO "<< n << "º numero de Fibonacci é: " << fib(n);

     }
     if(test == 2){
       cout << "Entre com o núméro de testes\n";
       cin >> n;
       cout << "\nEntre com o intervalo do tamanho das instancias\n";
       cin >> multi;

       cout << "---------------Processando os testes---------------\n\n";
       for(int i = 1; i < n; i++){
          tStart = clock();
          fib(i*multi);
          out << "\n"<< i*multi  << " " << ((double)(clock() - tStart)/(double)CLOCKS_PER_SEC);
       }
       cout << "---------------Fim dos testes---------------\n\n";

     }
   }

   if(alg == 4){
       int maior = 100;
       int menor = 10;
       int capacidade;
     if(test == 1){
       cout << "Entre com o tamanho do vetor\n";
       cin >> n;
       cout << "Entre com o tamanho da mochila\n";
       cin >> capacidade;

       int vetor[n];
       cout << "\n\n\n";
       int peso_1[n], valor_1[n];
       gerar_vetores_valor_tamanho(peso_1, valor_1, n, maior, menor);
       cout << "Vetor de peso é:\n\n";
       imprimir_vetor(peso_1,n);
       cout << "Vetor de valor é:\n\n";
       imprimir_vetor(valor_1,n);

       selection_sort_tax(peso_1,valor_1,n);
       cout << "\nO maior valor que caiba na mochila é: "<<fractional_knapsack(n, peso_1, valor_1, capacidade);
     }
     if(test == 2){
       capacidade = 100000000000;
       cout << "Entre com o núméro de testes\n";
       cin >> n;
       cout << "\nEntre com o intervalo do tamanho das instancias\n";
       cin >> multi;

       cout << "---------------Processando os testes---------------\n\n";
       for(int i = 1; i < n; i++){
           int peso[i*multi], valor[i*multi];
           gerar_vetores_valor_tamanho(peso, valor, i*multi, maior, menor);

           tStart = clock();
           selection_sort_tax(peso,valor,i*multi);
           fractional_knapsack(i*multi, peso, valor, capacidade);
           out << "\n"<< i*multi  << " " << ((double)(clock() - tStart)/(double)CLOCKS_PER_SEC);
       }
       cout << "---------------Fim dos testes---------------\n\n";

     }
   }
//   int n = 100;
//   int multi = 10;

//

//   int n = 1000;
//   int multi = 10;

//   for(int i = 1; i < n; i++){
//      int vetor[i*multi];
//      gerar_vetor_ordenado(vetor,i*multi);
//      selection_sort_desc(vetor,i*multi);

//      tStart = clock();
//      mergeSort(vetor, 0, i*multi - 1);
//      out << "\n"<< i*multi << " " << ((double)(clock() - tStart)/(double)CLOCKS_PER_SEC);
//   }

//  int n = 10000;
//  int multi = 100;

//  for(int i = 1; i < n; i++){
//    tStart = clock();
//    fib(i*multi);
//    out << "\n"<< i*multi  << " " << ((double)(clock() - tStart)/(double)CLOCKS_PER_SEC);
//}


//   int n = 100;
//   int multi = 10;





   return 0;
}
