#include <bits/stdc++.h>
#include "MergeSort.h"
#include "Struct.h"

using namespace std;

// Faz o merge de dois subarrays do array[].
// O primeiro subarray é arr[começo..meio]
// O segundo subarray é arr[meio+1..final]
void merge(pessoa array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
 
    // Arrays temporários
    auto *leftArray = new pessoa[subArrayOne],
         *rightArray = new pessoa[subArrayTwo];
 
    // Copia os dados para os arrays temporarios
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, 
        indexOfSubArrayTwo = 0; 
    int indexOfMergedArray = left; 
 
    // Faz o merge dos arrays temporarios de volta para o array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne].nome <= rightArray[indexOfSubArrayTwo].nome) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copia os elementos restantes
    // de left[], se ainda tiver algum
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copia os elementos restantes
	// de right[], se ainda tiver algum
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
 
// begin = left index 
// end = right index do 
// sub-array de arr a ser ordenado
void mergeSort(pessoa array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Return recursivo
 
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
