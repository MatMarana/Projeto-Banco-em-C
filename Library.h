#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED
typedef struct Dados_Pessoas{

    int senha;
    char tipo_conta[10];
    int valor_incial;
    char nome[100];
    char cpf[15];

}Dados_Pessoas;

typedef struct Dados_Conta{

    int deposito;
    int debito;
    int transferencia;

}Dados_Conta;

char* tipoConta(int escolha);
void cadastraUsuario();
int verificaCPF();

#endif // LIBRARY_H_INCLUDED
