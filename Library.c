#include <stdio.h>
#include <string.h>
#include "Library.h"

Dados_Pessoas dados[1000];

void cadastraUsuario(int numeroClientes){ 
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
  printf("Digite sua opção: ");
  scanf("%d", &escolhaConta);
  if (escolhaConta == 1){
    strcpy(dados[numeroClientes].tipo_conta, "Comum");
  } else if(escolhaConta == 2) {
    strcpy(dados[numeroClientes].tipo_conta, "Premium");
  } else {
      printf("Digite um numero valido\n");
  }
}

void apagarCliente(int numeroClientes,char cpf[15]){ //arrumar, está apagando o cliente mesmo se o cpf é invalido
  for(int i =0; i < numeroClientes; i ++){
    if (strcmp(cpf, dados[i].cpf) == 0){
      dados[i] = dados[i-1];
    } else {
      printf("Digite um CPF valido\n");
      printf("\n");
    }
  } 
}

void listaCliente(int numeroClientes){
  for(int i = 0; i < numeroClientes; i++){
    printf("Nome: %s\n", dados[i].nome);
    printf("CPF: %s\n", dados[i].cpf);
    printf("Tipo da Conta: %s\n", dados[i].tipo_conta);
    printf("Saldo: %lf\n", dados[i].valor_incial);
    printf("\n");
  }
}

void deposito(int numeroClientes, char cpf[15]){ 
  double valorDeposito;
  for(int i =0; i < numeroClientes; i ++){
    if (strcmp(cpf, dados[i].cpf) == 0){
      printf("Digite o valor a ser depositado: ");
      scanf("%lf", &valorDeposito);
      dados->operacoes[i].deposito = valorDeposito;
      dados[i].valor_incial = dados[i].valor_incial + valorDeposito;
      break;
    } 
    printf("Digite um cpf existente\n");
  }
}

void debito(int numeroClientes, char cpf[15], int senha){ 
  double valorDigitado;
  double valorDebito;
  for(int i =0; i < numeroClientes; i ++){
    if (strcmp(cpf, dados[i].cpf) == 0){
      if (strcmp(dados[i].tipo_conta, "Comum") == 0){
        if(senha == dados[i].senha){
          if(dados[i].valor_incial > -1000){
            printf("Digite o valor a ser debitado: ");
            scanf("%lf", &valorDigitado);
            valorDebito = valorDigitado + (valorDigitado * 0.05);
            dados->operacoes[i].debito = valorDebito;
            dados[i].valor_incial = dados[i].valor_incial - valorDebito;
            break;
          } else {
            printf("Saldo Insuficinete\n");
            printf("\n");
            break;
          }
        } 
        printf("Digite a senha correta");
      } else {
        if(senha == dados[i].senha){
          if(dados[i].valor_incial > -5000){
            printf("Digite o valor a ser depositado:");
            scanf("%lf", &valorDigitado);
            valorDebito = valorDigitado + (valorDigitado * 0.03);
            dados->operacoes[i].debito = valorDebito;
            dados[i].valor_incial = dados[i].valor_incial - valorDebito;
            break;
          } else {
            printf("Saldo Insuficinete\n");
            printf("\n");
            break;
          }
        } 
        printf("Digite a senha correta");
      }
    } 
    printf("Digite um cpf existente\n");
  }
}

void transferencia(int numeroClientes, char cpf[15], int senha){ 
char cpfRecebe[15];
double valorEnviado;
for(int i = 0; i < numeroClientes; i ++){ //Passar a verificação
  if(strcmp(dados[i].cpf, cpf ) == 0){
      if(senha == dados[i].senha){
        printf("Digite um valor a ser transferido: ");
        scanf("%lf", &valorEnviado);
        if (strcmp(dados[i].tipo_conta, "Comum") == 0){
          if(dados[i].valor_incial > -1000){
            dados[i].valor_incial = dados[i].valor_incial - valorEnviado;
            dados->operacoes->transferencia = valorEnviado;
          } else {
            printf("Saldo Insuficiente\n");
            printf("\n");
            break;
          }
        } else {
          if(dados[i].valor_incial > -5000){
            dados[i].valor_incial = dados[i].valor_incial - valorEnviado;
          } else {
            printf("Saldo Insuficinete\n");
            printf("\n");
            break;
          }
        } 
        printf("Digite o CPF da conta que vai receber o dinheiro: ");
        scanf("%s", cpfRecebe); 
        for(int i = 0; i < numeroClientes; i++){
          if(strcmp(cpfRecebe, dados[i].cpf) == 0){
            dados[i].valor_incial = dados[i].valor_incial + valorEnviado;
          }
          printf("Digite um cpf existente\n");
        }
      }
      printf("Digite a senha correta");
    } 
    printf("Digite um cpf existente\n"); 
  }
}

void escrever(int numeroClientes) {
  FILE *arquivo;
  arquivo = fopen("arquivo.bin", "wb");
  if (arquivo) {
     fwrite(dados, sizeof(Dados_Pessoas), numeroClientes, arquivo);
    fclose(arquivo);
  }
}

void ler(int numeroClientes) { // arrumar
    FILE *arquivo = fopen("arquivo.bin", "rb");
    fread(dados, sizeof(Dados_Pessoas), numeroClientes, arquivo);
    fclose(arquivo);
}

void extrato(int num_elementos){
    FILE *fp;
    char filename[20];
    for (int i = 0; i < num_elementos; i++) {
        sprintf(filename, "%s.txt", dados[i].cpf);
        fp = fopen(filename, "w");

        fprintf(fp, "Extrato para CPF: %s\n", dados[i].cpf);
        for (int j = 0; j < 100; j++) {
            if (dados[i].operacoes[j].deposito != 0) {
                fprintf(fp, "Depósito: %.2lf\n", dados[i].operacoes[j].deposito);
            }
            if (dados[i].operacoes[j].debito != 0) {
                fprintf(fp, "Débito: %.2lf\n", dados[i].operacoes[j].debito);
            }
            if (dados[i].operacoes[j].transferencia != 0) {
                fprintf(fp, "Transferência: %.2lf\n", dados[i].operacoes[j].transferencia);
            }
        }

        fclose(fp);
    }
}