#include "RegistroAluno.h"

using namespace std;

    void RegistroAluno::pack(Buffer buffer, Formato formato){
        switch(formato){
            case FIXO:
                buffer.packFixo(nome,100);
                buffer.packFixo(to_string(matricula),sizeof(int));
                buffer.packFixo(curso,5);
                break;
            case DELIMITADO:
                char delim = ';';
                buffer.packDelimitado(nome,delim);
                buffer.packDelimitado(to_string(matricula), delim);
                buffer.packDelimitado(curso, '\n');
                break;
            case COMPRIMENTO:
                buffer.packComprimento(nome+"\n");
                buffer.packComprimento(to_string(matricula)+"\n");
                buffer.packComprimento(curso+"\n");
                break;
        }
    }

    void RegistroAluno::unpack(Buffer buffer, Formato formato){
        switch(formato){
            case FIXO:
                nome = buffer.unpackFixo(100);
                matricula = stoi(buffer.unpackFixo(sizeof(int)));
                curso = buffer.unpackFixo(5);
                break;
            case DELIMITADO:
                char delim = ';';
                nome = buffer.unpackDelimitado(delim);
                matricula = stoi(buffer.unpackDelimitado(delim));
                curso = buffer.unpackDelimitado('\n');
                break;
            case COMPRIMENTO:
                nome = buffer.unpackComprimento();
                matricula = stoi(buffer.unpackComprimento());
                curso = buffer.unpackComprimento();
                break;
        }
    }
    string RegistroAluno::getChave(){
        //???
    }
    int RegistroAluno::getTamanhoFixo(){return 105+sizeof(int);}
