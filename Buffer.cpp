#include "Buffer.h"
#include <istream>
#include <ostream>
#include <iostream>
#include <fstream>

    Buffer::Buffer(int tamanho){
        data = vector<char>(tamanho);
        for(int k=0;k<tamanho;k++) data[k]=' ';
        ponteiro = 0;
    }
    void Buffer::packFixo(string str,int tamanho){
        data.insert(data.end(), str.begin(), str.end());
        if(data.size()<tamanho){
            vector<char> aux(tamanho - data.size());
            for(int k=0;k<aux.size();k++) aux[k]=' ';
            data.insert(data.end(), aux.begin(), aux.end());
        }
    }
    string Buffer::unpackFixo(int tamanho){
        string ret(reinterpret_cast<const char*>(&data[ponteiro]), tamanho);
        ponteiro += tamanho;
        return ret;
    }
    void Buffer::packDelimitado(string str,char delim){
        string subs = str+delim;
        data.insert(data.end(), subs.begin(), subs.end());
    }
    string Buffer::unpackDelimitado(char delim){
        string ret;
        while (ponteiro < data.size() && data[ponteiro] != delim) {
            ret += data[ponteiro++];
        }
        if (ponteiro < data.size() && data[ponteiro] == delim) {
            ponteiro++;
        }
        return ret;
    }
    void Buffer::packComprimento(string str){
        packDelimitado(str, '\n');
    }
    string Buffer::unpackComprimento(){
        return unpackDelimitado('\n');
    }
    void Buffer::pack(int valor){
        const int* bytes = reinterpret_cast<const int*>(&valor);
        data.insert(data.end(), bytes, bytes + sizeof(valor));
    }
    int Buffer::unpackInt(){
        int valor;
        std::wmemcpy((wchar_t*)&valor, (wchar_t*)&data[ponteiro], sizeof(valor));
        ponteiro += sizeof(valor);
        return valor;
    }
    bool Buffer::read(istream &stream, int const tamanho){
        if (!stream.good()) return false;
        stream.read(data.data(), tamanho);
        int start,end;
        //Removedor de cabeçalho
        for (int k=0; k<tamanho-1; k++){
            if(data[k]=='\n'){
                start = k;
                break;
            }  
        }
         for (int k=data.size()-1; k>start; k--){
            if(data[k]=='\n'){
                end = data.size()-k;
                break;
            }  
        }
        data= vector<char>(data.begin()+start+1,data.end()-end-1);
        ponteiro = 0;

        return stream.good();
    }
    void Buffer::write(ostream &stream){
        for(char c: data){
            stream <<c;
        }
    }
    void Buffer::clear(){
        data.clear();
        ponteiro = 0;
    }
