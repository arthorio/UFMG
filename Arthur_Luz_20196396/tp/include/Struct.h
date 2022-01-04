#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

#include <string>

using namespace std;

struct pessoa {
    string nome, dado;
    pessoa() {}
    pessoa(string nome_, string dado_) : nome(nome_), dado(dado_) {}
};

#endif //STRUCT

