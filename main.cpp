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
        file_fixo.adicionarRegistro(aluno);
        file_delimitado.adicionarRegistro(aluno);
        file_comprimento.adicionarRegistro(aluno);
    }
    cout<<"Registros escritos em arquivos de formatos diferentes."<<endl;
    
    cout<<"Lendo registros do arquivo de formato fixo:"<<endl;
    alunos.clear();
    alunos = file_fixo.lerRegistros();
    for(RegistroAluno aluno:alunos){
        cout<<aluno.nome<<"|"<<aluno.matricula<<"|"<<aluno.curso<<endl;
    }
    cout<<"Lendo registros do arquivo de formato delimitado:"<<endl;
    alunos.clear();
    alunos = file_delimitado.lerRegistros();
    for(RegistroAluno aluno:alunos){
        cout<<aluno.nome<<"|"<<aluno.matricula<<"|"<<aluno.curso<<endl;
    }
    cout<<"Lendo registros do arquivo de formato comprimento:"<<endl;
    alunos.clear();
    alunos = file_comprimento.lerRegistros();
    for(RegistroAluno aluno:alunos){
        cout<<aluno.nome<<"|"<<aluno.matricula<<"|"<<aluno.curso<<endl;
    }

    cout<<"programa finalizado."<<endl;
    return 0;
}