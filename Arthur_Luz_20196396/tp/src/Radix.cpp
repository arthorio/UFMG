#include <bits/stdc++.h>
#include "Radix.h"
#include "Struct.h"

using namespace std;

char digit(pessoa p, int a)
{
	return p.dado[7-a];
}

void quicksortB(pessoa a[], int l, int r, int w) 
{	
	int i = l, j = r;
	
	if (r <= l || w < 0) return;
	while (j != i) 
	{
		while (digit(a[i], w) == '0' && (i < j)) i++;
		while (digit(a[j], w) == '1' && (j > i)) j--;
		swap(a[i], a[j]);
	}

	if (digit(a[r], w) == '0') j++;
	quicksortB(a, l, j-1, w-1);
	quicksortB(a, j, r, w-1);
}


void radixSort(pessoa a[], int l, int r)
{
	quicksortB(a, l, r, 7);
}


