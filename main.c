#include <stdio.h>
#include "Library.h"

int main(){
  char verificaCpf[15];
  int escolha;
  int escolhaConta;
  int numeroDeClientes = 0;
  while(1){

    printf("               Bem Vindo Ao Seu Banco              \n");
    printf("---------------------------------------------------\n");
    printf("Escolha a ação que deseja realizar:\n");
    printf("Digite 1 - Para cadastrar um novo cliente\n");
    printf("Digite 2 - Para apagar um cliente já cadastrado\n");
    printf("Digite 3 - Para listar os clientes cadstrados\n");
    printf("Digite 4 - Para fazer depósito\n");
    printf("Digite 5 - Para fazer um débito\n");
    printf("Digite 6 - Para fazer uma transfêrencia\n");
    printf("Digite 7 - Para verificar seu extrato\n");
    printf("Digite 0 - Para sair\n");
    printf("\n");
    printf("Digite sua opção ");
  
  
    scanf("%d", &escolha);
  
    switch(escolha){
      case(1):{
        cadastraUsuario(numeroDeClientes);
        tipoConta(numeroDeClientes,escolhaConta);
        numeroDeClientes++;
        break;
      }
      case(2):{
        printf("Digite o CPF que deseja deletar: ");
        scanf("%s", verificaCpf);
        apagarCliente(numeroDeClientes, verificaCpf);
        numeroDeClientes--;
        break;
      }
      case(3):{
        listaCliente(numeroDeClientes);
        break;
      }
      case(4):{
        printf("Digite o CPF da conta que deseja fazer o deposito: ");
        scanf("%s", verificaCpf);
        deposito(numeroDeClientes,verificaCpf);
        break;
      }
      case(5):{
        printf("Digite o CPF da conta que deseja fazer o debito: ");
        scanf("%s", verificaCpf);
        debito(numeroDeClientes, verificaCpf);
        break;
      }
      case(6):{
        printf("Digite o CPF da conta que deseja fazer a transferencia: ");
        scanf("%s", verificaCpf);
        transferencia(numeroDeClientes, verificaCpf);
        break;
      }
      case(0):{
        printf("Muito Obrigado Pela Preferencia\n");
      }
    }
    if(escolha == 0){
      break;
    }
  }
}
