#include <string>
#include <vector>
using namespace std;

enum Formato { FIXO, DELIMITADO, COMPRIMENTO };

class Buffer{
    private:
    vector<char> data;
    int ponteiro;

    public: 
    void packFixo(string str,int tamanho);
    string unpackFixo(int tamanho); 
    void packDelimitado(string str,char delim);
    string unpackDelimitado(char delim);
    void packComprimento(string str);
    string unpackComprimento();
    void pack(int valor);
    int unpackInt();
    bool read(istream &stream, int tamanho);
    void write(ostream &stream);
    void clear();
};

class Registro {
    public: 
    virtual void pack(Buffer buffer, Formato formato) = 0;
    virtual void unpack(Buffer buffer, Formato formato) = 0;
    virtual string getChave() = 0;
    virtual int getTamanhoFixo() = 0;
};