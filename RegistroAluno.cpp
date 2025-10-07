#include "RegistroAluno.h"
#include <iostream>

using namespace std;

    void RegistroAluno::pack(Buffer &buffer, Formato formato){
        const char delim = ';';
        switch(formato){
            case Formato::FIXO:
                buffer.packFixo(nome,100);
                buffer.packFixo(to_string(matricula),16);
                buffer.packFixo(curso,5);
                buffer.packFixo("\n",1);
                break;
            case Formato::DELIMITADO:
                buffer.packDelimitado(nome,delim);
                buffer.packDelimitado(to_string(matricula), delim);
                buffer.packDelimitado(curso, '\n');
                break;
            case Formato::COMPRIMENTO:
                buffer.packComprimento(nome);
                buffer.packComprimento(to_string(matricula));
                buffer.packComprimento(curso);
                break;
        }
    }

    void RegistroAluno::unpack(Buffer &buffer, Formato formato){
        const char delim = ';';
        switch(formato){
            case Formato::FIXO:
                nome = buffer.unpackFixo(100);
                matricula = stoi(buffer.unpackFixo(16));
                curso = buffer.unpackFixo(5);
                buffer.ponteiro++;
                break;
            case Formato::DELIMITADO:
                nome = buffer.unpackDelimitado(delim);
                matricula = stoi(buffer.unpackDelimitado(delim));
                curso = buffer.unpackDelimitado('\n');
                break;
            case Formato::COMPRIMENTO:
                nome = buffer.unpackComprimento();
                matricula = stoi(buffer.unpackComprimento());
                curso = buffer.unpackComprimento();
                break;
        }
    }
    string RegistroAluno::getChave(){
        //???
    }
    int RegistroAluno::getTamanhoFixo(){return 121;}
