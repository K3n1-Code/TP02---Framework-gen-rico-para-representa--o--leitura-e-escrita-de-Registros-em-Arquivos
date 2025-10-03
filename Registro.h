#include <string>
#include <vector>
using namespace std;

enum Formato { FIXO, DELIMITADO, COMPRIMENTO };

class Registro {
public:
  virtual void pack(Buffer buffer, Formato formato) = 0;
  virtual void unpack(Buffer buffer, Formato formato) = 0;
  virtual string getChave() = 0;
  virtual int getTamanhoFixo() = 0;
};
