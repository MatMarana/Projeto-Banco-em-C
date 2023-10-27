#include <stdio.h>
#include <string.h>
#include "Library.h"

Dados_Pessoas dados[1000];
Dados_Conta operacoes[100];

void cadastraUsuario(){
    int escolha;

    printf("Digite o nome do usuario");
    scanf("%s", dados[0].nome);

    printf("Digite o Cpf do usuario");
    scanf("%s", dados[0].cpf);
    verificaCPF();

    printf("Digite a senha do usuario");
    scanf("%d", &dados[0].senha);

    printf("Escolha o tipo da conta\n");
    printf("Digite 1 - Para escolhar a conta Comum\n");
    printf("Digite 2 - Para escolher a conta Premium\n");
    scanf("%d", &escolha);
    tipoConta(escolha);

    printf("Digite o valor inicial da Conta");
    scanf("%d", &dados[0].valor_incial);

  
}

char* tipoConta(int escolha){
    if (escolha == 1){
      strcpy(dados[0].tipo_conta, "Comum");
    } else if(escolha == 2) {
      strcpy(dados[0].tipo_conta, "Premium");
    } else {
        printf("Digite um numero valido");
    }
  return 0;
}

int verificaCPF(){
  char cpf[15];
  printf("Digite o Cpf do usuario que deseja deletar");
  scanf("%s", cpf);
      if (strcmp(cpf, dados[0].cpf) == 0) {
          printf("As duas strings são iguais.\n");
      } else {
          printf("As duas strings são diferentes.\n");
      }
      return 0;
};


void apagarCliente(){
  int n;
  char cpf[15];
  printf("Digite o Cpf do usuario que deseja deletar:");
  verificaCPF();
  for(int i = 0; i < n; i++){
    dados[i] = dados[i-n];
  }
  
}

void listaCliente(){
  for(int i = 0; i < 1000; i++){
    printf("Nome: %s\n", dados[i].nome);
    printf("CPF: %s\n", dados[i].cpf);
    printf("Tipo da Conta: %s\n", dados[i].tipo_conta);
    printf("Saldo: %d\n", dados[i].valor_incial);
  }
}

