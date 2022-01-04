#include <bits/stdc++.h>
#include "QuickSort.h"
#include <string>
#include "Struct.h"

using namespace std;
 
/* Essa função pega o último elemento como pivo, muda
   o pivo para sua posição final correta no array ord-
   enado e coloca todos os elementos menores que o pivo
   a sua esquerda e todos os elementos maiores que o pivo
   a sua esqueda*/
int partition (pessoa arr[], int low, int high)
{
    pessoa pivot = arr[high];    
    int i = (low - 1);  // Indice do menor elemento
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j].nome <= pivot.nome)
        {
            i++;    
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

 
/* arr[] --> Array que sera ordenado,
  low  --> Primeiro indice,
  high  --> Ultimo indice */
void quickSort(pessoa arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
