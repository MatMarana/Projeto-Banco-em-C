#include <stdio.h>
#include <string.h>
#include "Library.h"

Dados_Pessoas dados[1000];
Dados_Conta operacoes[100];

void cadastraUsuario(int numeroClientes){ //verificar cpf
  printf("Digite o nome do usuario: ");
  scanf("%s", dados[numeroClientes].nome);

  printf("Digite o Cpf do usuario: ");
  scanf("%s", dados[numeroClientes].cpf);

  printf("Digite a senha do usuario: ");
  scanf("%d", &dados[numeroClientes].senha);

  printf("Digite o valor inicial da Conta: ");
  scanf("%lf", &dados[numeroClientes].valor_incial);
}

void tipoConta(int numeroClientes, int escolhaConta){
  printf("Escolha a o tipo da sua conta:\n");
  printf("Digite 1 - Para escolher a conta Comum\n");
  printf("Digite 2 - Para escolher a conta Premium\n");
  scanf("%d", &escolhaConta);
  if (escolhaConta == 1){
    strcpy(dados[numeroClientes].tipo_conta, "Comum");
  } else if(escolhaConta == 2) {
    strcpy(dados[numeroClientes].tipo_conta, "Premium");
  } else {
      printf("Digite um numero valido");
  }
}

void apagarCliente(int numeroClientes,char cpf[15]){ //arrumar, está apagando o cliente mesmo se o cpf é invalido
  for(int i =0; i < numeroClientes; i ++){
    if (strcmp(cpf, dados[i].cpf) == 0){
      dados[i] = dados[i-1];
    } else {
      printf("Digite um CPF valido\n");
    }
  } 
}

void listaCliente(int numeroClientes){
  for(int i = 0; i < numeroClientes; i++){
    printf("Nome: %s\n", dados[i].nome);
    printf("CPF: %s\n", dados[i].cpf);
    printf("Tipo da Conta: %s\n", dados[i].tipo_conta);
    printf("Saldo: %lf\n", dados[i].valor_incial);
  }
}

void deposito(int numeroClientes, char cpf[15]){ // arrumar print do else
  double valorDeposito;
  for(int i =0; i < numeroClientes; i ++){
    if (strcmp(cpf, dados[i].cpf) == 0){
      printf("Digite o valor a ser depositado:");
      scanf("%lf", &valorDeposito);
      operacoes[i].deposito = valorDeposito;
      dados[i].valor_incial = dados[i].valor_incial + valorDeposito;
      break;
    } else {
      printf("Digite um CPF valido\n");
    }
  }
}

void debito(int numeroClientes, char cpf[15]){
  double valorDigitado;
  double valorDebito;
  for(int i =0; i < numeroClientes; i ++){
    if (strcmp(cpf, dados[i].cpf) == 0){
      if (strcmp(dados[i].tipo_conta, "Comum") == 0){
        printf("Digite o valor a ser debitado: ");
        scanf("%lf", &valorDigitado);
        valorDebito = valorDigitado + (valorDigitado * 0.05);
        operacoes[i].deposito = valorDebito;
        dados[i].valor_incial = dados[i].valor_incial - valorDebito;
      } else {
        printf("Digite o valor a ser depositado:");
        scanf("%lf", &valorDigitado);
        valorDebito = valorDigitado + (valorDigitado * 0.03);
        operacoes[i].deposito = valorDebito;
        dados[i].valor_incial = dados[i].valor_incial - valorDebito;
      }
    } else {
      printf("Digite um CPF valido\n");
    }
  }
}


