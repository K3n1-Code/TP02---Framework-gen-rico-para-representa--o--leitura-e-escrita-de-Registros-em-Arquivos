#include "Registro.h"
class RegistroAluno : public Registro {
    public:
    int matricula;
    string nome;
    string curso;

    public:
    void pack(Buffer buffer, Formato formato) override;
    void unpack(Buffer buffer, Formato formato) override;
    string getChave() override;
    int getTamanhoFixo() override;

};