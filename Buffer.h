#ifndef BUFFER_H
#define BUFFER_H

#include <fstream>
#include <istream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;

class Buffer {
public:
  vector<char> data;
  int ponteiro;
  Buffer(int tamanho);
  void packFixo(string str, int tamanho);
  string unpackFixo(int tamanho);
  void packDelimitado(string str, char delim);
  string unpackDelimitado(char delim);
  void packComprimento(string str);
  string unpackComprimento();
  void pack(int valor);
  int unpackInt();
  bool read(istream &stream, int tamanho);
  void write(ostream &stream);
  void clear();
};

#endif // BUFFER_H
