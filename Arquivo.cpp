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
    ifstream in;
    
    streampos start = in.tellg();
    in.seekg(0, ios::end);
    long size = in.tellg();
    in.seekg(start);

    in.open(this->nomeArquivo);
    buffer.read(in, size); // Desconfie dessa implementação
    while(buffer.ponteiro<size){
        T reg;
        reg.unpack(buffer, this->formato);
        registros.push_back(reg);
    }
    
    in.close();
    return registros;
}
