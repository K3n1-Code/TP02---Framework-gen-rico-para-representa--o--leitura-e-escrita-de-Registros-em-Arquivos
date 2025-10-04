#include "Arquivo.h"

// Arquivo::Arquivo(string nomeArquivo, Formato formato) {}
// Arquivo

template <class T> Arquivo<T>::Arquivo(string nomeArquivo, Formato formato) {
  this->nomeArquivo = nomeArquivo;
  this->formato = formato;
}
template <class T> void Arquivo<T>::adicionarRegistro(T reg) {

  Buffer buffer;
  Formato formato;
  ofstream out;
  out.open(this->nomeArquivo);

  reg.pack(buffer, formato);

  buffer.write(out);
}

template <class T> vector<T> Arquivo<T>::lerRegistros() { return vector<T>(); }
