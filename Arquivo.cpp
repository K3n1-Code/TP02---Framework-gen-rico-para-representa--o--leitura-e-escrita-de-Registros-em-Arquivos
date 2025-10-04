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
  out.open(this->nomeArquivo, std::ios::ate);

  // fazer um try catch para testar a a abertura de arquivos

  reg.pack(buffer, formato);

  buffer.write(out);
  out.close();
  return;
}

template <class T> vector<T> Arquivo<T>::lerRegistros() {
  vector<T> registros;
  Buffer buffer;
  Formato formato;
  ifstream in;
  in.open(this->nomeArquivo);
  while (??) {
    T reg;
    buffer.read(in, 500); // Desconfie dessa implementação
    reg.pack(buffer, formato);
    registros.push_back();
  }
  in.close();

  return registros;
}
