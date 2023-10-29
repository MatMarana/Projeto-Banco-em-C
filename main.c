#include <stdio.h>
#include "Library.h"

int main(){
  char cpf[15];
  int escolha;
  int escolhaConta;
  int *numeroDeClientes = 0;
  Dados_Pessoas novoUsuario;
  while(1){
  printf("--------------------------------------------------\n");
  printf("Escolha a ação que deseja frealizar:\n");
  printf("Digite 1 - Para cadastrar um novo cliente\n");
  printf("Digite 2 - Para apagar um cliente já cadastrado\n");
  printf("Digite 3 - Para listar os clientes cadstrados\n");
  printf("Digite 4 - Para fazer depósito\n");
  printf("Digite 5 - Para fazer um débito\n");
  printf("Digite 6 - Para fazer uma transfêrencia\n");
  printf("Digite 7 - Para verificar seu extrato\n");
  printf("-------------------------------------------------\n");
  
  
  scanf("%d", &escolha);
  
  switch(escolha){
    case(1):{
      cadastraUsuario(numeroDeClientes, novoUsuario);
      printf("Escolha o tipo da conta\n");
      printf("Digite 1 - Para escolhar a conta Comum\n");
      printf("Digite 2 - Para escolher a conta Premium\n");
      scanf("%d", &escolhaConta);
      tipoConta(numeroDeClientes,escolhaConta, novoUsuario);
    }
    case(2):
      printf("Digite o Cpf do usuario que deseja deletar:");
      scanf("%s", cpf);
      apagarCliente(cpf);
    break;
    case(3):
      listaCliente();
    break;
   }
  }
}
