#include <stdio.h>
#include <string.h>
#include "Library.h"

Dados_Pessoas dados[1000];
Dados_Conta operacoes[100];

void cadastraUsuario(int *numeroClientes, Dados_Pessoas novoUsuario){
    

    printf("Digite o nome do usuario");
    scanf("%s", novoUsuario.nome);

    printf("Digite o Cpf do usuario");
    scanf("%s", novoUsuario.cpf);

    printf("Digite a senha do usuario");
    scanf("%d", &novoUsuario.senha);

    printf("Digite o valor inicial da Conta");
    scanf("%lf", &novoUsuario.valor_incial);
  

  
}

void tipoConta(int *numeroClientes, int escolhaConta,Dados_Pessoas novoUsuario){
  if (escolhaConta == 1){
    strcpy(novoUsuario.tipo_conta, "Comum");
  } else if(escolhaConta == 2) {
    strcpy(novoUsuario.tipo_conta, "Premium");
  } else {
      printf("Digite um numero valido");
  }
}

int verificaCPF(char cpf[15]){
  scanf("%s", cpf);
      if (strcmp(cpf, dados[0].cpf) == 0) {
          return 1;
      } else {
          printf("Digite um CPF valido.\n");
      }
  return 0;
};


void apagarCliente(char cpf[15]){
  int n;
  verificaCPF(cpf);
  for(int i = 0; i < n; i++){
    dados[i] = dados[i-n];
  }
  
}

void listaCliente(){
  for(int i = 0; i < 1000; i++){
    printf("Nome: %s\n", dados[i].nome);
    printf("CPF: %s\n", dados[i].cpf);
    printf("Tipo da Conta: %s\n", dados[i].tipo_conta);
    printf("Saldo: %lf\n", dados[i].valor_incial);
  }
}

double deposito(){
  printf("Digite o valor a ser depositado:");
  double valorDeposito;
  scanf("%lf", &valorDeposito);
  operacoes[0].deposito = valorDeposito;
  dados[0].valor_incial = dados[0].valor_incial + valorDeposito;
  return 0;
}

double debito(){
  printf("Digite o valor a ser depositado:");
  double valorDebito;
  scanf("%lf", &valorDebito);
  operacoes[0].deposito = valorDebito;
  dados[0].valor_incial = dados[0].valor_incial - valorDebito;
  return 0;
}


