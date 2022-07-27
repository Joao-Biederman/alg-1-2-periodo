// agenda.c
// Exemplo de manipulação de arquivos binários
// Implementa uma pequena agenda com as operações de inserir registro, listar
// registro e buscar registro.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 30
#define TAM_END 40
#define TAM_FONE 15

// Definicao do registro de dados
typedef struct
{
   char nome [TAM_NOME];
   char endereco[TAM_END];
   char telefone[TAM_FONE];
} registro;

FILE *arquivo;

//===================================================================================
// Funções
//===================================================================================

//------------------------------------------------------------------------------
// Funcao para inserir um registro de dados no arquivo
//------------------------------------------------------------------------------
int insereRegistro()
{
  registro a;
  fseek(arquivo, 0, SEEK_END);
  system("clear");
  printf("\tInserção de registro\n\n");
  printf("Nome: ");
  getchar();
  gets(a.nome);
  printf("Endereço: ");
  gets(a.endereco);
  printf("Telefone: ");
  gets(a.telefone);
  fwrite(&a, sizeof(registro), 1, arquivo);
  printf("\n\tRegistro inserido! Tecle [ENTER]\n");
  getchar();
  return 0;
}

//--------------------------------------------------------------
// Funcao para listar os registros no arquivo
//--------------------------------------------------------------

//--------------------------------------------------------
//Função para ordenação de arquivo pelo método Bubblesort
//--------------------------------------------------------
void bubblesort(FILE *F)
{
  int i, j, n;
  registro aux1, aux2;
  int sizer = sizeof(registro);

  // Calcula o número de registros
  fseek(F, 0, SEEK_END);
  n = ftell(F) / sizer;
  for (i = 1; i < n; i++)
  {
    for (j = n - 1; j >= i; j--)
    {
      // posiciona para fazer a leitura
      fseek(F, (j-1)*sizer, SEEK_SET);
      // lê os dados dos registros adjacentes para a memória
      fread(&aux1, sizer, 1, F);
      fread(&aux2, sizer, 1, F);
      // Compara os registros por nome
      if (strcmp(aux1.nome, aux2.nome) > 0) // aux1 > aux2
      {
        // posiciona para trocar
        fseek(F, (j-1)*sizer, SEEK_SET);
        //troca aux1 e aux2
        fwrite(&aux2, sizeof(registro), 1, F);
        fwrite(&aux1, sizeof(registro), 1, F);
      }
    }
  }       
}
//--------------------------------------------------------------
// Funcao para listar os registros no arquivo
//--------------------------------------------------------------
int listaRegistros()
{
  registro a;
  int n;

  fseek(arquivo, 0, SEEK_END);
  n = ftell(arquivo)/sizeof(registro); // calcula o número de registros
  getchar(); //limpa o buffer do teclado
  system("clear");

  // ordena antes de listar
 bubblesort(arquivo);
  rewind(arquivo);
  while (1)
  {
    fread(&a, sizeof(registro), 1, arquivo);
    if (!feof(arquivo))
    {
      printf("Registro: %lu/%d\n", ftell(arquivo)/sizeof(registro), n);
      printf("Nome: %s\nEndereço: %s\nTelefone: %s\n", a.nome, a.endereco, a.telefone);
      printf("\nTecle [ENTER] para o próximo registro\n");
      getchar(); // captura a tecla [ENTER]
    }
    else break;
  }
  return 0;
}

//--------------------------------------------------------------------
// Funcao para buscar um registro no arquivo
//--------------------------------------------------------------------
int buscaRegistro()
{
  registro a;
  char chave[TAM_NOME];
  int found = 0;
  
  getchar(); // limpa o buffer de teclado
  rewind(arquivo);
  system("clear");
  printf("\tBusca por nome\n");
  printf("Buscar por: ");
  gets(chave);
  while (1)
  {
    fread(&a, sizeof(registro), 1, arquivo);
    if (!feof(arquivo))
    {
      if (!strncmp(a.nome, chave, strlen(chave))) // achou
      {
        printf("Nome: %s \n", a.nome);
        printf("Endereço: %s\n", a.endereco);
        printf("Telefone: %s\n", a.telefone);          
        printf("Tecle [ENTER]");
        getchar(); // captura a tecla [ENTER]
        found = 1;
      }
    }
    else break;
  }
  if (!found)
  {
    printf("Nome não encontrado.\n"); // não achou
    printf("Tecle [ENTER]");
    getchar(); // captura a tecla [ENTER]
  }
  return 0;
}

//----------------------------------------
// Altera um registro de dados
//----------------------------------------
int alteraRegistro()
{
   registro a;
   char chave[TAM_NOME];
 
   getchar(); // limpa o buffer de teclado
   rewind(arquivo);
   system("clear");
   printf("\tAlteração de dados\n");
   printf("Buscar por: ");
   gets(chave);
   while (!feof(arquivo))
   {
      fread(&a, sizeof(registro), 1, arquivo);
      if (!feof(arquivo))
      {
         if (!strcmp(a.nome, chave)) // achou
         {
            printf("Endereço: %s\n", a.endereco);
            printf("Telefone: %s\n", a.telefone);
            printf("\nAlterar dados:\n");
            printf("Novo Nome: ");
            gets(a.nome);
            fflush(stdin);
            printf("Novo Endereço: ");
            gets(a.endereco);
            fflush(stdin);
            printf("Novo Telefone: ");
            gets(a.telefone);
            fflush(stdin);
            fseek(arquivo, -sizeof(registro), 1);
            fwrite(&a, sizeof(registro), 1, arquivo);
            printf("Tecle [ENTER]");
            getchar(); // captura a tecla [ENTER]
            return 0;
         }
      }  
   }
   printf("Nome não encontrado.\n"); // não achou
   printf("Tecle [ENTER]");
   getchar(); // captura a tecla [ENTER]
   return 0;
}

//---------------------------------
// Função para apagar um registro
//---------------------------------
int apagaRegistro()
{
   system("clear");
   printf("+======================================+\n");
   printf("| Função não implementada              |\n");
   printf("| Cabe a voce implementar esta funcao! |\n");
   printf("| :-P                                  |\n");
   printf("|            Tecle [ENTER]             |\n");
   printf("+======================================+\n");
   getchar(); // captura a tecla [ENTER]
   getchar();
   return 1;
}

//===================================================================================
// Função principal
//===================================================================================
int main()
{
  int opcao = -1;  // variável para ler a opção do usuário
  int (*pf[6])();  // vetor de ponteiros de função para as funções a serem execuadas 
                   // pelo menu
  
  // preenche o vetor de funções
  pf[0] = insereRegistro;
  pf[1] = listaRegistros;
  pf[2] = buscaRegistro;
  pf[3] = alteraRegistro;
  pf[4] = NULL;

  // abre o arquivo de dados
  if (!(arquivo = fopen("dados.dat", "rb+")))
  {
    printf("\nErro: não foi possível abrir o arquivo de dados!\n");
    printf("\nCriando novo arquivo de dados...\n");
    arquivo = fopen("dados.dat", "wb+");
    system("pause");
 }

  // Exibição do Menu
  while (opcao)
  {
    system("clear");
    printf("\tAgenda\n\n");
    printf("Menu principal\n\n");
    printf("\t[0] Sair\n");
    printf("\t[1] Inserir registro\n");
    printf("\t[2] Listar registros\n");
    printf("\t[3] Buscar registro\n");
    printf("\t[4] Alterar registro\n");
    printf("\t[5] Apagar Registro\n");
    printf("\nQual a sua opção? ");
    scanf("%d", &opcao);
    if ((opcao > 0) && (opcao <= 5))
    {
       (*pf[opcao - 1])();
    }
  }
  if (fclose(arquivo))
  {
    printf("\nErro: não foi possível fechar o arquivo de dados!\n");
    return 1;
  }
  return 0;
}
