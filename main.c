#include <stdio.h>
#include "Library.h"

int main(){
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
  
  int escolha;
  scanf("%d", &escolha);
  
  switch(escolha){
    case(1):
      cadastraUsuario();
    break;
    case(2):
      apagarCliente();
    break;
    case(3):
      listaCliente();
    break;
   }
}
