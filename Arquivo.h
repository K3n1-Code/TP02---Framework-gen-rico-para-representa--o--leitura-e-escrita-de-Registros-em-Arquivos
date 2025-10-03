#include <string>
#include "Registro.h"

template <class T>
 

class Arquivo {
    private:
    string nomeArquivo;
    Formato formato;

    public:
    Arquivo(string nomeArquivo, Formato formato);
    void adicionarRegistro(T reg);
    vector<T> lerRegistros();
};