#include <stdio.h>
#include <string.h>
#include "Library.h"

Dados_Pessoas dados[1000];

void cadastraUsuario(int numeroClientes){ // numero de clientes é usado para controlar a posição dos indices do array de structs
  printf("Digite o nome do usuario: "); 
  scanf("%s", dados[numeroClientes].nome); // Recebe o nome de usuario digitado e passa para o array de strcut

  printf("Digite o Cpf do usuario: ");
  scanf("%s", dados[numeroClientes].cpf); // Recebe o Cpf de usuario digitado e passa para o array de strcut

  printf("Digite a senha do usuario: ");
  scanf("%d", &dados[numeroClientes].senha); // Recebe a senha de usuario digitado e passa para o array de strcut

  printf("Digite o valor inicial da Conta: "); // Recebe valor inical de usuario digitado e passa para o array de strcut
  scanf("%lf", &dados[numeroClientes].valor_incial);
}

void tipoConta(int numeroClientes, int escolhaConta){ // escolha conta é uma variavel global usada para a escolha
  printf("Escolha a o tipo da sua conta:\n");
  printf("Digite 1 - Para escolher a conta Comum\n");
  printf("Digite 2 - Para escolher a conta Premium\n");
  printf("Digite sua opção: ");
  scanf("%d", &escolhaConta); // Recebe a escolha feita pelo usuario 
  if (escolhaConta == 1){ // Caso for 1 a conta salva na variavel tipo_conta da struct recebe comum
    strcpy(dados[numeroClientes].tipo_conta, "Comum");
  } else if(escolhaConta == 2) { //Caso for 2 a conta salva na variavel tipo_conta da struct recebe premim
    strcpy(dados[numeroClientes].tipo_conta, "Premium");
  } else {
      printf("Digite um numero valido\n"); 
  }
}

void apagarCliente(int numeroClientes,char cpf[15]){ 
  int i;
  for (i = 0; i < numeroClientes; i++) { // identa o array para procura o cpf recebido
      if (strcmp(cpf, dados[i].cpf) == 0) { // se existe armazena o valor na variavel i e sai do loop
          break;
      }
  }

  if (i == numeroClientes) { // CPF não encontrado
      printf("Digite um CPF valido\n");
      printf("\n");
      return;
  }

  for (; i < numeroClientes - 1; i++) { // apaga o clietente com o cpf igual ao indice i
      dados[i] = dados[i + 1];
  }
}
void listaCliente(int numeroClientes){
  for(int i = 0; i < numeroClientes; i++){  // identa o array de structs e imprime as informações dos usuarios
    printf("Nome: %s\n", dados[i].nome); // imprime o nome
    printf("CPF: %s\n", dados[i].cpf); // imprime o cpf
    printf("Tipo da Conta: %s\n", dados[i].tipo_conta); //imprime o tipo da conta
    printf("Saldo: %lf\n", dados[i].valor_incial); //imprime o saldo
    printf("\n");
  }
}

void deposito(int numeroClientes, char cpf[15]){ 
  double valorDeposito;
  for(int i =0; i < numeroClientes; i ++){ // identa o array de structs ate o numero de pessoas existentes
    if (strcmp(cpf, dados[i].cpf) == 0){  //compara os cpfs do array de structs com o digitado
      printf("Digite o valor a ser depositado: "); // recebe o valor depositado
      scanf("%lf", &valorDeposito);
      dados[i].operacoes->deposito= valorDeposito; // armazena o valor depositado na struct operações
      dados[i].valor_incial = dados[i].valor_incial + valorDeposito; // altera o saldo na conta
      break;
    } 
    printf("Digite um cpf existente\n");
  }
}

void debito(int numeroClientes, char cpf[15], int senha){ 
  double valorDigitado;
  double valorDebito;
  for(int i =0; i < numeroClientes; i ++){
    if (strcmp(cpf, dados[i].cpf) == 0){ //compara os cpfs do array de structs com o digitado
      if (strcmp(dados[i].tipo_conta, "Comum") == 0){ // se a conta for comum
        if(senha == dados[i].senha){ // se a senha estiver correta
          if(dados[i].valor_incial > -1000){ // caso o saldo for menor que -1000 
            printf("Digite o valor a ser debitado: "); // recebe o valor debitado
            scanf("%lf", &valorDigitado);
            valorDebito = valorDigitado + (valorDigitado * 0.05); // calcula o valor debitado mais 5% de taxa
            dados[i].operacoes->debito = valorDebito; //armazena o valor debitado na struct de operações
            dados[i].valor_incial = dados[i].valor_incial - valorDebito; // altera o saldo na conta
            break;
          } else {
            printf("Saldo Insuficinete\n"); // caso o saldo for menor que -1000 não deixa fazer a operação
            printf("\n");
            break;
          }
        } 
        printf("Digite a senha correta");
      } else { // se a conta for premium
        if(senha == dados[i].senha){ // se a senha estiver correta
          if(dados[i].valor_incial > -5000){ // caso o saldo for menor que -5000 
            printf("Digite o valor a ser debitado: "); // recebe o valor debitado
            scanf("%lf", &valorDigitado);
            valorDebito = valorDigitado + (valorDigitado * 0.03); // calcula o valor debitado mais 3% de taxa
            dados[i].operacoes->debito = valorDebito; //armazena o valor debitado na struct de operações
            dados[i].valor_incial = dados[i].valor_incial - valorDebito; // altera o saldo na conta
            break;
          } else {
            printf("Saldo Insuficinete\n"); // caso o saldo for menor que -5000 não deixa fazer a operação
            printf("\n");
            break;
          }
        } 
      }
    } 
  }
}

void transferencia(int numeroClientes, char cpf[15], int senha){ 
  char cpfRecebe[15];
  double valorEnviado;
  for(int i = 0; i < numeroClientes; i ++){ 
    if(strcmp(dados[i].cpf, cpf ) == 0){ //compara os cpfs do array de structs com o digitado
        if(senha == dados[i].senha){
          printf("Digite um valor a ser transferido: ");// recebe o valor transferido
          scanf("%lf", &valorEnviado);
          if (strcmp(dados[i].tipo_conta, "Comum") == 0){
            if(dados[i].valor_incial > -1000){ // caso o saldo for menor que -1000 
              dados[i].valor_incial = dados[i].valor_incial - valorEnviado; // altera o saldo na conta
              dados[i].operacoes->transferencia = valorEnviado; //armazena o valor tranferido na struct de operações
            } else {
              printf("Saldo Insuficiente\n"); // caso o saldo for menor que -1000 não deixa fazer a operação
              printf("\n");
              break;
            } 
          } else { // se a conta for premium 
            if(dados[i].valor_incial > -5000){  // caso o saldo for menor que -5000 
              dados[i].valor_incial = dados[i].valor_incial - valorEnviado; // altera o saldo na conta
            } else {
              printf("Saldo Insuficinete\n"); // caso o saldo for menor que -5000 não deixa fazer a operação
              printf("\n");
              break;
            }
          } 
          printf("Digite o CPF da conta que vai receber o dinheiro: ");  // recebe o cpf que vai receber a transferencia
          scanf("%s", cpfRecebe); 
          for(int i = 0; i < numeroClientes; i++){
            if(strcmp(cpfRecebe, dados[i].cpf) == 0){ // se o cpf existe
              dados[i].valor_incial = dados[i].valor_incial + valorEnviado; // altera o saldo na conta 
            }
          }
        }
      }   
    }
  }

void escrever(int numeroClientes) { // escreve um arquivo binario
  FILE *arquivo;
  arquivo = fopen("arquivo.bin", "wb");
  if (arquivo) {
     fwrite(dados, sizeof(Dados_Pessoas), numeroClientes, arquivo);
    fclose(arquivo);
  }
}

void ler(int numeroClientes) { // ler o arquivo binario
    FILE *arquivo = fopen("arquivo.bin", "rb");
    fread(dados, sizeof(Dados_Pessoas), numeroClientes, arquivo);
    fclose(arquivo);
}

void extrato(int num_elementos, char cpf[15], int senha){
    FILE *fp; 
    char filename[20];
    for (int i = 0; i < num_elementos; i++){ // identa o array structs operações
      if(strcmp(dados[i].cpf, cpf ) == 0){ //compara os cpfs do array de structs com o digitado
        if(senha == dados[i].senha){ // se a senha estiver correta
        sprintf(filename, "%s.txt", dados[i].cpf); // cria um arquivo txt que no nome recebe o cpf que solicitou o extrato
        fp = fopen(filename, "w"); // cria o arquivo txt

        fprintf(fp, "Extrato para CPF: %s\n", dados[i].cpf);
        for (int j = 0; j < 100; j++) {
            if (dados[i].operacoes[j].deposito != 0) {
                fprintf(fp, "Depósito: %.2lf\n", dados[i].operacoes[j].deposito); // verifica se há depositos
            }
            if (dados[i].operacoes[j].debito != 0) {
                fprintf(fp, "Débito: %.2lf\n", dados[i].operacoes[j].debito); // verifica se há debitos
            }
            if (dados[i].operacoes[j].transferencia != 0) {
                fprintf(fp, "Transferência: %.2lf\n", dados[i].operacoes[j].transferencia); // verifica se há tranferencias
             }
        }
        fclose(fp); // fecha o arquivo
      }
    }
   }
}