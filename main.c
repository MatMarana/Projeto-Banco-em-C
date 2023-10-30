#include <stdio.h>
#include "Library.h"

int main(){
  char verificaCpf[15]; // controle de cpf
  int verificaSenha; // controle de senha
  int escolha; // controle de escolha
  int escolhaConta; // contrle do tipo da conta
  int numeroDeClientes = 0; // variavel de controle de clietentes
  int numeroDeElementos = 0; // variavel de controle de operaçãos
  escrever(numeroDeClientes);
  ler(numeroDeClientes);
  while(1){

    printf("\n               Bem Vindo Ao Seu Banco              \n"); // menu
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
    printf("Digite sua opção: ");
  
  
    scanf("%d", &escolha);
  
    switch(escolha){
      case(1):{
        cadastraUsuario(numeroDeClientes);
        tipoConta(numeroDeClientes,escolhaConta);
        numeroDeClientes++; // itera a variavel numero de clientes, para poder adicionar informações no proximo item do array
        break;
      }
      case(2):{
        printf("Digite o CPF que deseja deletar: ");
        scanf("%s", verificaCpf);
        apagarCliente(numeroDeClientes, verificaCpf);
        numeroDeClientes--; // reduz a variavel numero de clientes, para poder adicionar informações no proximo item do array
        break;
      }
      case(3):{
        listaCliente(numeroDeClientes); // printa a lista de clientes
        break;
      }
      case(4):{
        printf("Digite o CPF da conta que deseja fazer o deposito: ");
        scanf("%s", verificaCpf);
        deposito(numeroDeClientes,verificaCpf); // recebe o cpf do cliente e deposita o valor
        numeroDeElementos++; // adiciona um ao numero de elementos
        break;
      }
      case(5):{
        printf("Digite o CPF da conta que deseja fazer o debito: "); // recebe o cpf do cliente e debita o valor
        scanf("%s", verificaCpf);
        printf("Digite a senha da conta: ");
        scanf("%d", &verificaSenha);
        debito(numeroDeClientes, verificaCpf, verificaSenha); // recebe a senha do cliente para debitar
        numeroDeElementos++;
        break;
      }
      case(6):{
        printf("Digite o CPF da conta que deseja fazer a transferencia: "); // recebe o cpf do cliente e trasnfere o valor
        scanf("%s", verificaCpf);
        printf("Digite a senha da conta: "); // recebe a senha do cliente para transferir o valor
        scanf("%d", &verificaSenha);
        transferencia(numeroDeClientes, verificaCpf, verificaSenha);
        numeroDeElementos++;
        break;
      }
      case(7):{
         printf("Digite o CPF da conta que deseja ver o extrato: "); // recebe o cpf do cliente para ver o extrato 
          scanf("%s", verificaCpf);
          printf("Digite a senha da conta: "); // recebe a senha do cliente para ver o extrato 
          scanf("%d", &verificaSenha);
        extrato(numeroDeElementos, verificaCpf, verificaSenha);
        break;
      }
      case(0):{
        printf("Muito Obrigado Pela Preferencia\n");
      }
    }
    if(escolha == 0){
      escrever(numeroDeClientes);
      break;
    }
  }
}
