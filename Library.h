#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

typedef struct Dados_Conta{
    double deposito;
    double debito;
    double transferencia;
}Dados_Conta;

typedef struct Dados_Pessoas{
    int senha;
    char tipo_conta[10];
    double valor_incial;
    char nome[100];
    char cpf[15];
    Dados_Conta operacoes[100];
}Dados_Pessoas;

void apagarCliente(int numeroClientes, char cpf[15]);
void listaCliente(int numeroClientes);
void tipoConta(int numeroClientes, int escolhaConta);
int verificaCliente(int numeroClientes, char cpf[15], int senha, int indice);
void cadastraUsuario(int numeroClientes);
void deposito(int numeroClientes, char cpf[15]);
void debito(int numeroClientes, char cpf[15], int senha);
void escrever(int quantidade_tarefa);
void ler(int numeroClientes);
void transferencia(int numeroClientes, char cpf[15], int senha);
void extrato(int num_elementos, char cpf[15], int senha);

#endif
