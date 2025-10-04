#include "Registro.h"
#include <string>

template <class T>

class Arquivo {
private:
public:
  string nomeArquivo;
  Formato formato;
  Arquivo(string nomeArquivo, Formato formato);
  void adicionarRegistro(T reg);
  vector<T> lerRegistros();
};
