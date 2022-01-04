#include <bits/stdc++.h>
#include "HeapSort.h"
#include "Struct.h"

using namespace std;

// Heapify gera o heap do arr[]
void heapify(pessoa arr[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2;  

    // Se o filho da esqueda for maior que a raiz
	if	(l < n && arr[l].dado > arr[largest].dado)
        largest = l;
 
    // Se o filho da direita for maior que a raiz 
  	if	(r < n && arr[r].dado > arr[largest].dado)
        largest = r;
   
	 // Se o maior não é a raiz
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
 
void heapSort(pessoa arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    //Extrai os elementos do heap um por um
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual pra o final
        swap(arr[0], arr[i]);
 
        // chama o max heapify no heap reduzido
        heapify(arr, i, 0);
    }
}
