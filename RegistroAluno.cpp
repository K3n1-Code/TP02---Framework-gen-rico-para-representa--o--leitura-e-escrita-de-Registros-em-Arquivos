#include "RegistroAluno.h"
#include "Registro.h"
#include "Arquivo.h"

using namespace std;

    // Buffer
    void Buffer::packFixo(string str,int tamanho){}
    string Buffer::unpackFixo(int tamanho){}
    void Buffer::packDelimitado(string str,char delim){}
    string Buffer::unpackDelimitado(char delim){}
    void Buffer::packComprimento(string str){}
    string Buffer::unpackComprimento(){}
    void Buffer::pack(int valor){}
    int Buffer::unpackInt(){}
    bool Buffer::read(istream &stream, int tamanho){}
    void Buffer::write(ostream &stream){}
    void Buffer::clear(){}

    // RegistroAluno

    void RegistroAluno::pack(Buffer buffer, Formato formato){}
    void RegistroAluno::unpack(Buffer buffer, Formato formato){}
    string RegistroAluno::getChave(){}
    int RegistroAluno::getTamanhoFixo(){}

    // Arquivo

    template<class T>
    Arquivo<T>::Arquivo(string nomeArquivo, Formato formato){}
    template<class T>
    void Arquivo<T>::adicionarRegistro(T reg){}
    template<class T>
    vector<T> Arquivo<T>::lerRegistros(){ return vector<T>(); }