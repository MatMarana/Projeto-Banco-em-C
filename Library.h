#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED
typedef struct Dados_Pessoas{

    int senha;
    char tipo_conta[10];
    double valor_incial;
    char nome[100];
    char cpf[15];

}Dados_Pessoas;

typedef struct Dados_Conta{

    double deposito;
    double debito;
    double transferencia;

}Dados_Conta;

void apagarCliente(char cpf[15]);
void listaCliente();
void tipoConta(int *numeroClientes, int escolhaConta, Dados_Pessoas novoUsuario);
void cadastraUsuario(int *numeroClientes,Dados_Pessoas novoUsuario);
int verificaCPF(char cpf[15]);

#endif // LIBRARY_H_INCLUDED
