#include "RegistroAluno.h"
#include "Arquivo.h"
#include <iostream>

using namespace std;
int main(){

    cout<<"Iniciando programa..."<<endl;
    Arquivo<RegistroAluno> file("dados.csv",Formato::DELIMITADO);
    vector<RegistroAluno> alunos = file.lerRegistros();

    cout<<"Registros lidos: "<<alunos.size()<<endl;

    Arquivo<RegistroAluno> file_fixo("dados_fixo.csv",Formato::FIXO);
    Arquivo<RegistroAluno> file_delimitado("dados_delimitado.csv",Formato::DELIMITADO);
    Arquivo<RegistroAluno> file_comprimento("dados_comprimento.csv",Formato::COMPRIMENTO);

    int k=0;
    for(auto aluno:alunos){
        cout<<"Nome: "<<aluno.nome<<endl;
        cout<<"Matricula: "<<aluno.matricula<<endl;
        cout<<"Curso: "<<aluno.curso<<endl;
        cout<<++k<<endl;
        cout<<"--------------------"<<endl;
        file_fixo.adicionarRegistro(aluno);
        file_delimitado.adicionarRegistro(aluno);
        file_comprimento.adicionarRegistro(aluno);
    }
    cout<<"Registros escritos em arquivos de formatos diferentes."<<endl;
    
    /*
    alunos.clear();
    alunos = file_fixo.lerRegistros();
    Arquivo<RegistroAluno> file_fixo_2("dados_fixo_2.csv",Formato::FIXO);

    alunos.clear();
    alunos = file_delimitado.lerRegistros();
    Arquivo<RegistroAluno> file_delimitado_2("dados_delimitado_2.csv",Formato::DELIMITADO);

    alunos.clear();
    alunos = file_comprimento.lerRegistros();
    Arquivo<RegistroAluno> file_comprimento_2("dados_comprimento_2.csv",Formato::COMPRIMENTO);
    */

    cout<<"programa finalizado."<<endl;
    return 0;
}