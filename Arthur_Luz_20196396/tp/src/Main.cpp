#include <iostream>
#include <fstream>
#include <string>

#include "QuickSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "Radix.h"
#include "Struct.h"

#define MAXTAM 200001	

using namespace std;

pessoa P[MAXTAM];

int main(int argc, char* argv[])
{
	int config, linhas;
    ifstream file(argv[1], fstream::in);
	
	config = atoi(argv[2]);
	linhas = atoi(argv[3]);

    string line;
	
	int i =0;
    if(file.is_open())
    {
       	string nome;
        string limitador = " ";

        while(i < linhas)
        {
            getline(file, line);

            //pega o comando a ser executado
            size_t pos;
            if((pos = line.find(limitador)) != string::npos)
            {
                nome = line.substr(0, pos);
                line.erase(0, pos + limitador.length());
            }
            else
                nome = line;
			
			P[i].nome = nome;
			P[i].dado = line;
			i++;
        }

        file.close();
    }
    else
    {
        cout << "Não existe" << endl;
    }

	switch(config)
	{
		case 1:
			quickSort(P, 0, linhas-1);
			heapSort(P, linhas);
			break;
		case 2:
			quickSort(P, 0, linhas-1);
			radixSort(P, 0, linhas-1);
			break;
		case 3:
			mergeSort(P, 0, linhas-1);	
			heapSort(P, linhas);		
			break;
		case 4:
			mergeSort(P, 0, linhas-1);	
			radixSort(P, 0, linhas-1);
			break;
	}

	// Printando homologação ordenado na configuração selecionada
	for(int i = 0; i < linhas; i++)
		cout << P[i].nome << " " << P[i].dado << endl;

    return 0;
}

