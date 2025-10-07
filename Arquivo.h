#include "Registro.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

template <class T> class Arquivo {
private:
public:
  string nomeArquivo;
  Formato formato;

  Arquivo(string nomeArquivo, Formato formato) {
    this->nomeArquivo = nomeArquivo;
    ifstream file(this->nomeArquivo);
    if (!file.good()) {
      ofstream createFile(this->nomeArquivo);
      createFile.close();
    }
    this->formato = formato;
  };

  void adicionarRegistro(T reg) {
    Buffer buffer = Buffer(0);
    ofstream out;
    out.open(this->nomeArquivo, std::ios::app);
    reg.pack(buffer, this->formato);
    
    streampos currentPos = out.tellp();
    string header;
    switch(this->formato){
        case Formato::FIXO:
            header ="Nome Matricula CUR";
            break;
        case Formato::DELIMITADO:
            header ="Nome;Matricula;Curso";
            break;
        case Formato::COMPRIMENTO:
            header ="Nome Matricula Curso";
            break;
    }

    if (filesystem::file_size(this->nomeArquivo)==0) {
      out << header << endl;
    }

    buffer.write(out);
    out.close();
    return;
  };

  vector<T> lerRegistros() {
    vector<T> registros = vector<T>();
    int size = 550;

    ifstream in = ifstream();
    in.open(this->nomeArquivo);
    Buffer buffer = Buffer(size);
    buffer.read(in, size); // Desconfie dessa implementação
    in.close();
    while (buffer.ponteiro < buffer.data.size()) {
      T reg;
      reg.unpack(buffer, this->formato);
      registros.push_back(reg);
    }

    return registros;
  }
};
