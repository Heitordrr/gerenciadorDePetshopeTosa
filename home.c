/*
	Arquivo: •	Sistema_de_gerenciamento_de_banho_e_tosa_PetShop.c
	Autor: Heitor dos Reis Ribeiro

*/

//-----DIRETIVAS-----//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
//-----DIRETIVAS-----//

struct cliente{
   int codigo,telefone,excluido;
   char email[50],nome[30];

 };
struct servico{
   char funcionario[20],servico[20],situopcao[20],nome_do_animal[20];
   int peso_do_animal,excluido,codigo;

 };
struct executados{
   char funcionario[20],servico[20],situopcao[20],nome_do_animal[20];
   int peso_do_animal,excluido,codigo;

 };
struct cancelados{
   char funcionario[20],servico[20],situopcao[20],nome_do_animal[20];
   int peso_do_animal,excluido,codigo;

 };
struct emexecucao{
   char funcionario[20],servico[20],situopcao[20],nome_do_animal[20];
   int peso_do_animal,excluido,codigo;

 };
 
 //-----INTERFACE-----//
 /* Assinatura da função (declaração da função/protótipo)*/
void cadastrar_cliente();
void consultar_cliente();
void listar_cliente();
void excluir_cliente();
void cadastrar_servico();
void alocar_funcionario_ao_pedido();
void concluir_servico();
void cancelar_pedido();
void todos_servicos();
//-----INTERFACE-----//

//-----MAIN-----//
int main(){
// A função setlocale garante que caracteres especiais e acentuação sejam exibidos normalmente na execução.
	setlocale (LC_ALL, "Portuguese");
  struct cliente c;
  struct servico s;
  FILE *arquivo;
  int opcao;
     do {
/*
 *  MENU PRINCIPAL
*/
         system("clear");
         printf(" =================================================\n\n");
         printf("   Bem vindo ao Sistema de Cadastro do Pet Shop\n\n");
         printf ("===================== MENU ======================\n\n");
         printf("  1 - CADASTRAR CLIENTE\n");
         printf("  2 - CONSULTAR CLIENTE\n");
         printf("  3 - LISTAR CLIENTES\n");
         printf("  4 - EXCLUIR CLIENTE\n");
         printf("  5 - CADASTRAR SERVIÇO\n");
         printf("  6 - ALOCAR FUNCIONÁRIO\n");
         printf("  7 - CONCLUIR SERVIÇO\n"); 
         printf("  8 - CANCELAR SERVIÇO\n");
         printf("  9 - LISTAR SERVIÇOS\n");
         printf("  0 - SAIR\n");
             printf(" =================================================\n\n");
         printf("\n Escolha uma opção:");
         scanf("%d", &opcao); /* Receber a escolha do usuário */
         
 /*Switch Case para controlar o fluxo do programa e permitir especificar uma função diferente para ser executada dentro das opções */
    switch (opcao){
      case 1:
        system("clear");
        cadastrar_cliente();
                 break;
      case 2:
        system("clear");
        consultar_cliente();
      break;
      case 3:
         system("clear");
        listar_cliente();
      break;
      case 4:
         system("clear");
         excluir_cliente();
         break;
      case 5:
          system("clear");
          cadastrar_servico();
       break;
      case 6:
      system("clear");
      alocar_funcionario_ao_pedido();
       break;
      case 7:
       system("clear");
        concluir_servico();
         break;     
      case 8:
        system("clear");
        cancelar_pedido();
                 break;
      case 9:
        system("clear");
         todos_servicos();
                 break;
      case 0:
          system("clear");
           return 0;
       default:
        system("clear");
        printf("Opção inválida\n");
        printf("--------------\n");
       printf("Voltando...\n");
         }
     }while (opcao != opcao + 10);
   return 0;
}
/*
 *      CADASTRO
*/
void cadastrar_cliente(){
   struct cliente ct;
   FILE *arquivo;
   int i,opcao;
   opcao = 0;
   arquivo = fopen("CLIENTE","rb+");
   if (!arquivo)
   arquivo = fopen("CLIENTE", "wb");
   if (!arquivo){
      printf("\n Erro:");
      exit(1);
  }
   do {
      system("clear");
      printf("\n*****  CADASTRO DE CLIENTE  ***** \n");
      printf("\nDigite o codigo do cliente:");
      scanf("%d",&ct.codigo);
      printf("\nDigite o e-mail do cliente:");
      scanf("%s",&ct.email);
      printf("\nDigite o nome do cliente:");
      scanf("%s",&ct.nome);
      printf("\nDigite o telefone do cliente:");
      scanf("%d",&ct.telefone);
      ct.excluido = 0;
      fseek(arquivo, 0, SEEK_END);
      fwrite(&ct, sizeof(ct), 1, arquivo);
      printf("\nDigite 1 para cadastrar um novo cliente ou digite 0 para voltar ao menu\n");
      scanf("%d", &opcao);
    }while (opcao==1);
    fclose(arquivo);
}
/*
 *      CONSULTA
*/
void consultar_cliente(){
    printf("\n*****  CONSULTAR CLIENTE  *****\n");
    FILE *arquivo;
    struct cliente ct;
    int codigo1,opcao;
    arquivo = fopen("CLIENTE", "rb+");
    if (!arquivo) {
    printf("\n Nenhum registro encontrado.");
  } else {
    printf("Digite o codigo do cliente: ");
    scanf("%d", &codigo1);
    fseek(arquivo, 0, SEEK_SET);
    while (fread(&ct, sizeof(ct), 1, arquivo)) {
    if (ct.codigo==codigo1){ 
          fseek(arquivo, ftell(arquivo) - sizeof(ct), 0);
          printf("\n Codigo: %d", ct.codigo);
          printf("\n E-mail: %s", ct.email);
          printf("\n Nome: %s", ct.nome);
          printf("\n Telefone: %d", ct.telefone);
          fseek(arquivo, 0, SEEK_END);
          printf("\n\nDigite 1 para alterar os dados ou 0 para voltar.\n");
          scanf("%d",&opcao);
          if(opcao==0){
          return;
          }
          if(opcao==1){
           printf("\n*****  ALTERANDO DADOS  *****\n");
    FILE *arquivo;
    if ((arquivo = fopen("CLIENTE", "rb+")) == NULL) {
    printf("\n ERRO! Arquivo inexistente");
  } else {
    fseek(arquivo, 0, SEEK_SET);
    while (fread(&ct, sizeof(ct), 1, arquivo)) {
          fseek(arquivo, ftell(arquivo) - sizeof(ct), 0);
          printf("\nDigite o novo codigo do cliente:");
          scanf("%d",&ct.codigo);
          printf("\nDigite o novo e-mail do cliente:");
          scanf("%s",&ct.email);
          printf("\nDigite o novo nome do cliente: ");
          scanf("%s", &ct.nome);
          printf("\nDigite o novo numero de telefone do cliente:");
          scanf("%d",&ct.telefone);
          fwrite(&ct, sizeof(ct), 1, arquivo);
          printf("\n Registro alterado com sucesso!\n");
          fseek(arquivo, 0, SEEK_END);
         }
    fclose(arquivo);
      }
     }
    }
   }
 }  
}
/*
 *      LISTAR
*/
void listar_cliente(){
    struct cliente ct;
    FILE *arquivo;
    int opcao;
    arquivo = fopen("CLIENTE", "rb");
    if (!arquivo) {
    printf("\n Arquivo não existe. Crie sua base de dados na opção '1' \n");
  } else {
        fseek(arquivo, 0, SEEK_SET);
        printf("\n*****  LISTA DE CLIENTES  *****\n");
        printf("\n---------------------------------------------------\n");
    while (fread(&ct, sizeof(ct),1, arquivo)) {
      if (ct.excluido == 0) {
        printf("\n Codigo: %d", ct.codigo);
        printf("\n Nome: %s", ct.nome);
        printf("\n E-mail: %s", ct.email);
        printf("\n Telefone: %d\n", ct.telefone);
        printf("\n---------------------------------------------------\n");
      }
    }
        printf("\nDigite 0 para retornar ao menu principal.\n");
        scanf("%d", &opcao);
        fclose(arquivo);
        return;
     }
   }
/*
 *      EXCLUIR
*/
void excluir_cliente(){
  struct cliente ct;
  int codigo2,op;
  FILE *arquivo, *arquivotemp;
  arquivo = fopen("CLIENTE", "rb"); // abre base
    if (!arquivo) {
    printf("\n Nenhum registro encontrado!");
  } else {
    arquivotemp = fopen("ARQUIVOTEMP", "wb");
    if (!arquivotemp) {
      printf("\n ERRO!");
      exit(1);
    }
  }
  
  printf("Informe o codigo do cliente que deseja excluir: ");
  scanf("%d", &codigo2);
  fseek(arquivo, 0, SEEK_SET);
  while (fread(&ct, sizeof(ct), 1, arquivo)) {
    if (ct.codigo == codigo2) {
        printf("\n Codigo: %d", ct.codigo);
        printf("\n Nome: %s", ct.nome);
        printf("\n E-mail: %s", ct.email);
        printf("\n Telefone: %d\n", ct.telefone);
  } else {
      fwrite(&ct, sizeof(ct), 1, arquivotemp);
    }
  }
  fclose(arquivo);
  fclose(arquivotemp);
  
  rename("ARQUIVOTEMP", "CLIENTE");
  remove("ARQUIVOTEMP");
  }
/*
 *      CADASTRO DE SERVIÇO
*/
void cadastrar_servico(){
   struct cliente ct;
   struct servico s;
   FILE *arquivo,*servico;
   int opcao,codcodigo3,O,op;
    opcao = 0;
    arquivo = fopen("CLIENTE", "rb");
   if (!arquivo) {
    printf("\n Arquivo não existe, utilize a opção '1' \n");
  } else {
        fseek(arquivo, 0, SEEK_SET);
    while (fread(&ct, sizeof(ct),1, arquivo)) {
    if (ct.excluido == 0) {
        printf("\n Codigo: %d",ct.codigo);
        printf("\n Nome: %s",ct.nome);
        printf("\n E-mail: %s", ct.email);
        printf("\n Telefone: %d\n", ct.telefone);
      }
    }
 }
  
  servico = fopen("SERVICO","rb+");
    if (!servico)
  servico = fopen("SERVICO", "wb");
    if (!servico){
      printf("\n Erro:");
      exit(1);
  }
  arquivo = fopen("CLIENTE", "rb+");
    if (!arquivo) {
    printf("\n registro não encontrado.");
  } else {
    printf("\nInforme o codigo do cliente que deseja cadastrar um serviço:\n ");
    scanf("%d", &codcodigo3);
    fflush(stdin);
    fseek(arquivo, 0, SEEK_SET);
    system("clear");
    while (fread(&ct, sizeof(ct), 1, arquivo))
    if(ct.codigo==codcodigo3){ 
          while (fread(&s, sizeof(s), 1, servico))
          ct.codigo==1;
          printf("***  DADOS DO CLIENTE  ***\n");
          printf("\n\t Codigo: %d", ct.codigo);
          printf("\n\t E-mail: %s", ct.email);
          printf("\n\t Nome: %s", ct.nome);
          printf("\n\t Telefone: %d", ct.telefone);
      printf("\n\n****  CADASTRO DE SERVIÇO  ****\n");
      printf("\nDigite o codigo do serviço:");
      scanf("%d",&s.codigo);
      printf("\nDigite o nome do animal do cliente:");
      scanf("%s",&s.nome_do_animal);
      printf("\nDigite o peso do animal do cliente:");
      scanf("%d",&s.peso_do_animal);
      printf("  -----------------------");
      printf("\n   -----|Serviços|-----        ");
      printf("\n 1-Banho \n");
      printf("\n 2-Tosa  \n");
      printf("  -----------------------\n");
      scanf ("%d", &O);
      if (O == 1) { strcpy ( s.servico, "Banho" );}else if(O==2){ strcpy ( s.servico, "Tosa" );}
      strcpy ( s.situopcao, "INCLUIDO" );
      s.excluido = 0;
      fseek(servico, 0, SEEK_END);
      fwrite(&s, sizeof(s), 1, servico);
      printf("Cadastro de serviço concluido!");
      printf("\n\nRetornando ao menu principal\n");
    }      
   }fclose(servico);
    fclose(arquivo);
    return;
}
/*
 *      ALOCAR FUNCIONARIO
*/
void alocar_funcionario_ao_pedido(){
  int codigo4,B,opcao;
  FILE *servico, *temp,*sit;
  struct servico s;
  struct emexecucao x;
    servico = fopen("SERVICO", "rb");
    if (!servico) {
    printf("\n Arquivo inexistente. \n");
  } else {
    fseek(servico, 0, SEEK_SET);
    while (fread(&s, sizeof(s),1, servico)){ 
      if (s.excluido == 0) {
        printf("\n Codigo do serviço: %d", s.codigo);
        printf("\n Nome do animal: %s", s.nome_do_animal);
        printf("\n Peso do animal: %d", s.peso_do_animal);
        printf("\n Serviço: %s ", s.servico);
        printf("\n Situação: %s ", s.situopcao );
        printf("\n");
      }
    }
  }
  servico = fopen("SERVICO", "rb");
    if (!servico) {
    printf("\n Nenhum registro encontrado!");
    } else {
    temp = fopen("TEMPORARIO", "wb");
    if (!temp) {
      printf("\n ERRO!");
      exit(1);
    }
  }
  sit = fopen("EXECUCAO", "rb+");
    if (!sit) {
        sit = fopen("EXECUCAO", "wb");
    if (!sit) {
        printf("\n ERRO!");
        exit(1);
      }
    }
  printf("\nInforme o Serviço que deseja alocar funcionario: ");
  scanf("%d", &codigo4);
  fseek(servico, 0, SEEK_SET);
  system("clear");
  while (fread(&s, sizeof(s), 1, servico)) {
    if (s.codigo == codigo4) {
      printf("\n****  Dados do Serviço  ****\n");
                printf("\nDigite o codigo do serviço do cliente: %d", s.codigo);
                printf("\nDigite o nome do animal do cliente: %s", s.nome_do_animal);
                printf("\nDigite o peso do animal do cliente: %d", s.peso_do_animal);
                printf("\n Serviço: %s ", s.servico);
                printf("\n Situação: %s ", s.situopcao );
                printf("\n\nDigite 1 para alocar funcionario ou 0 para voltar. \n");
          scanf("%d",&opcao);
          if(opcao==0){
          return;
          }
          if(opcao==1){
      printf("\n\nDigite novamente os dados do Serviço para alocar funcionario\n");
      printf("\nDigite o codigo do serviço:");
      scanf("%d", &x.codigo);
      printf("\nDigite o nome do animal:");
      scanf("%s", &x.nome_do_animal);
      printf("\nDigite o peso do animal:");
      scanf("%d", &x.peso_do_animal);
      printf("Serviço:");
      printf("\n 1-Banho \n");
      printf("\n 2-Tosa  \n");
      scanf ("%d", &B);
      if (B == 1) { strcpy ( x.servico, "Banho" );} else if (B==2)  { strcpy ( x.servico, "Tosa" );}
      printf("\n Funcionario:");
      scanf("%s", &x.funcionario);
      strcpy ( x.situopcao, "EM EXECUÇÃO" );
      fseek(sit, 0, SEEK_END);
      fwrite(&x, sizeof(x), 1, sit);
      }
    } else{
      fwrite(&s, sizeof(s), 1, temp); 
      } 
  }
  fclose(servico);
  fclose(temp);
  fclose(sit);
  rename("TEMPORARIO", "SERVICO");
  remove("TEMPORARIO");
  return;
 }
/*
 *      CONCLUIR SERVIÇO
*/
void concluir_servico(){
  int codigo5,T,opcao;
  FILE *faz, *temp,*sit;
  struct executados executed;
  struct emexecucao execute;
  sit = fopen("EXECUCAO", "rb");
    if (!sit) {
    printf("\n Nenhum registro encontrado!");
    } else {
    temp = fopen("TEMPORARIO", "wb");
    if (!temp) {
      printf("\n ERRO!");
      exit(1);
    }
  }
  faz = fopen("EXECUTADOS", "rb+");
    if (!faz) {
        faz = fopen("EXECUTADOS", "wb");
    if (!faz) {
        printf("\n ERRO!");
        exit(1);
      }
    }
  printf("\nInforme o codigo do Serviço para se concluir(Serviços em execução): ");
  scanf("%d", &codigo5);
  fseek(sit, 0, SEEK_SET);
  system("clear");
  while (fread(&execute, sizeof(execute), 1, sit)) {
    if (execute.codigo == codigo5) {
                printf("\n****  Dados do Serviço  ****\n");
                printf("\nDigite o codigo do serviço: %d", execute.codigo);
                printf("\nDigite o nome do animal: %s", execute.nome_do_animal);
                printf("\nDigite o peso do animal: %d", execute.peso_do_animal);
                printf("\n Serviço: %s ", execute.servico);
                printf("\n Funcionario: %s ", execute.funcionario);
                printf("\n Situação: %s ", execute.situopcao );
                printf("\n\n0-voltar. 1-Concluir Seviço.\n");
          scanf("%d",&opcao);
          if(opcao==0){
          return;
          }
          if(opcao==1){
      printf("\n\nDigite novamente os dados para que o serviço seja concluido\n");
      printf("\nDigite o codigo do serviço:");
      scanf("%d", &executed.codigo);
      printf("\nDigite o nome do animal:");
      scanf("%s", &executed.nome_do_animal);
      printf("\nDigite o peso do animal:");
      scanf("%d", &executed.peso_do_animal);
      printf("Serviço:");
      printf("\n 1-Banho \n");
      printf("\n 2-Tosa  \n");
      scanf ("%d", &T);
      if (T == 1) { strcpy ( executed.servico, "Banho" );} else if (T==2)  { strcpy ( executed.servico, "Tosa" );}
      printf("\n Funcionario:");
      scanf("%s", &executed.funcionario);
      strcpy ( executed.situopcao, "EXECUTADO" );
      fseek(faz, 0, SEEK_END);
      fwrite(&executed, sizeof(executed), 1, faz);
      }
    } else{
      fwrite(&execute, sizeof(execute), 1, temp); 
      } 
  }
  fclose(faz);
  fclose(temp);
  fclose(sit);
  rename("TEMPORARIO", "EXECUCAO");
  remove("TEMPORARIO");
  return;
  }  
/*
 *      CANCELAR PEDIDO
*/
void cancelar_pedido(){
    int codigo6, se,opcao;
    FILE *servico, *arqNovo,*cancel;
    struct servico sc;
    struct cancelados can;
    servico = fopen("SERVICO", "rb");
    if (!servico) {
    printf("\n Arquivo inexistente. \n");
  } else {
    fseek(servico, 0, SEEK_SET);
    while (fread(&sc, sizeof(sc),1, servico)){ 
      if (sc.excluido == 0) {
        printf("\n Codigo do serviço: %d", sc.codigo);
        printf("\n Nome do animal: %s", sc.nome_do_animal);
        printf("\n Peso do animal: %d", sc.peso_do_animal);
        printf("\n Serviço: %s ", sc.servico);
        printf("\n Situação: %s ", sc.situopcao );
        printf("\n");
      }
    }
  }
  servico = fopen("SERVICO", "rb");
    if (!servico) {
    printf("\n Nenhum registro encontrado!");
    } else {
    arqNovo = fopen("NOVABD", "wb");
    if (!arqNovo) {
      printf("\n ERRO!");
      exit(1);
    }
  }
  cancel = fopen("CANCELADOS", "rb+");
    if (!cancel) {
        cancel = fopen("CANCELADOS", "wb");
    if (!cancel) {
        printf("\n ERRO!");
        exit(1);
      }
    }
  printf("\nInforme o codigo do Serviço para cancelar: ");
  scanf("%d", &codigo6);
  fseek(servico, 0, SEEK_SET);
  system("clear");
  while (fread(&sc, sizeof(sc), 1, servico)) {
    if (sc.codigo == codigo6) {
                printf("\n****  Dados do Serviço  ****\n");
                printf("\nDigite o codigo do serviço: %d", sc.codigo);
                printf("\nDigite o nome do animal: %s", sc.nome_do_animal);
                printf("\nDigite o peso do animal: %d", sc.peso_do_animal);
                printf("\n Serviço: %s ", sc.servico);
                printf("\n Situação: %s ", sc.situopcao );
                printf("\n\nDigite 1 para confirmar cancelamento ou 0 para voltar. \n");
          scanf("%d",&opcao);
          if(opcao==0){
          return;
          }
          if(opcao==1){
      if (se == 1) { strcpy ( can.servico, "Banho" );} else if (se==2)  { strcpy ( can.servico, "Tosa" );}
      strcpy ( can.situopcao, "CANCELADO" );
      fseek(cancel, 0, SEEK_END);
      fwrite(&can, sizeof(can), 1, cancel);
      }
    } else{
      fwrite(&sc, sizeof(sc), 1, arqNovo); 
      } 
  }
  fclose(servico);
  fclose(arqNovo);
  fclose(cancel);
  rename("NOVABD", "SERVICO");
  remove("NOVABD");
}
/*
 *      LISTAR TODOS OS SERVIÇOS
*/
void todos_servicos(){//se não haver a base de dados de todos os serviços a primeira execução ira criar.
    struct servico sc;
    struct executados et;
    struct emexecucao execute;
    FILE *servico,*faz,*sit;
    int opcao;
    servico = fopen("SERVICO", "rb");
    if (!servico) {
    printf("\n Arquivo não existe. Crie sua base de dados na opção '5'\n");
  } else {
    printf("\n****  TODOS OS SERVIÇOS  ****\n");
    fseek(servico, 0, SEEK_SET);
    while (fread(&sc, sizeof(sc),1, servico)){ 
      if (sc.excluido == 0) {
        printf("\n Codigo do serviço: %d", sc.codigo);
        printf("\n Nome do animal: %s", sc.nome_do_animal);
        printf("\n Peso do animal: %d", sc.peso_do_animal);
        printf("\n Serviço: %s ", sc.servico);
        printf("\n Situação: %s ", sc.situopcao );
        printf("\n");
      }
    }
  }
       faz = fopen("EXECUTADOS", "rb");
    if (!faz) {faz = fopen("EXECUTADOS", "wb");
  } else {
    fseek(faz, 0, SEEK_SET);
    while (fread(&et, sizeof(et), 1, faz)) {
         printf("\n Codigo do serviço: %d", et.codigo);
         printf("\n Nome do animal: %s", et.nome_do_animal);
         printf("\n Peso do animal: %d", et.peso_do_animal);
         printf("\n Serviço: %s ", et.servico);
         printf("\n Funcionario: %s", et.funcionario);
         printf("\n Situação: %s ", et.situopcao );
         printf("\n");
    } 
    sit = fopen("EXECUCAO", "rb");
    if (!sit) {sit = fopen("EXECUCAO", "wb");
  } else {
    fseek(sit, 0, SEEK_SET);
    while (fread(&execute, sizeof(execute), 1, sit)) {
         printf("\n Codigo do serviço: %d", execute.codigo);
         printf("\n Nome do animal: %s", execute.nome_do_animal);
         printf("\n Peso do animal: %d", execute.peso_do_animal);
         printf("\n Serviço: %s ", execute.servico);
         printf("\n Funcionario: %s", execute.funcionario);
         printf("\n Situação: %s ", execute.situopcao );
         printf("\n");
    }
    }
        printf("\nDigite 0 para Retornar ao menu princial.\n");
        scanf("%d", &opcao);
        fclose(servico);
        return;
      }
  
  }