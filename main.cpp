#include "RegistroAluno.h"
#include "Arquivo.h"
#include "Registro.h"

int main(){
    Arquivo<RegistroAluno> file("dados.csv",Formato::DELIMITADO);
    vector<RegistroAluno> alunos = file.lerRegistros();

    Arquivo<RegistroAluno> file_fixo("dados_fixo.csv",Formato::FIXO);
    Arquivo<RegistroAluno> file_delimitado("dados_delimitado.csv",Formato::DELIMITADO);
    Arquivo<RegistroAluno> file_comprimento("dados_comprimento.csv",Formato::COMPRIMENTO);

    for(auto aluno:alunos){
        file_fixo.adicionarRegistro(aluno);
        file_delimitado.adicionarRegistro(aluno);
        file_comprimento.adicionarRegistro(aluno);
    }

    alunos.clear();
    alunos = file_fixo.lerRegistros();
    Arquivo<RegistroAluno> file_fixo_2("dados_fixo_2.csv",Formato::FIXO);

    alunos.clear();
    alunos = file_delimitado.lerRegistros();
    Arquivo<RegistroAluno> file_delimitado_2("dados_delimitado_2.csv",Formato::DELIMITADO);

    alunos.clear();
    alunos = file_comprimento.lerRegistros();
    Arquivo<RegistroAluno> file_comprimento_2("dados_comprimento_2.csv",Formato::COMPRIMENTO);

    return 0;
}