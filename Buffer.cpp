#include "Buffer.h"
#include <istream>
#include <ostream>

    void Buffer::packFixo(string str,int tamanho){
        data.insert(data.end(), str.begin(), str.end());
        vector<char> aux(tamanho - str.size(), '\0');
        data.insert(data.end(), aux.begin(), aux.end());
    }
    string Buffer::unpackFixo(int tamanho){
        string ret(reinterpret_cast<const char*>(&data[ponteiro]), tamanho);
        ponteiro += tamanho;
        return ret;
    }
    void Buffer::packDelimitado(string str,char delim){
        string subs = str.substr(0, str.find(delim));
        data.insert(data.end(), subs.begin(), subs.end());
    }
    string Buffer::unpackDelimitado(char delim){
        string ret;
        while (ponteiro < data.size() && data[ponteiro] != delim) {
            ret += data[ponteiro++];
        }
        if (ponteiro < data.size() && data[ponteiro] == delim) {
            ponteiro++; // Skip the delimiter
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
        const int32_t* bytes = reinterpret_cast<const int32_t*>(&valor);
        data.insert(data.end(), bytes, bytes + sizeof(valor));
    }
    int Buffer::unpackInt(){
        int32_t valor;
        std::memcpy(&valor, &data[ponteiro], sizeof(valor));
        ponteiro += sizeof(valor);
        return valor;
    }
    bool Buffer::read(istream &stream, int tamanho){
        if (!stream.good()) return false;

        data.resize(tamanho);
        stream.read(data.data(), tamanho);
        ponteiro = 0;

        return stream.good();
    }
    void Buffer::write(ostream &stream){
        if (!stream.good()) return;
        
        size_t size = data.size();
        stream.write(reinterpret_cast<const char*>(&size), sizeof(size));
        
        if (size > 0) {
            stream.write(reinterpret_cast<const char*>(data.data()), size);
        }
    }
    void Buffer::clear(){
        data.clear();
        ponteiro = 0;
    }