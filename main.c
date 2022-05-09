#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct {
  char regi1   [20];
  char regi2   [20];
  char Usuario [20];
  char Senha   [20];
} Funcionario;

typedef struct {
  char Nome           [30];
  char CPF            [30];
  char Telefone       [30];
  char Rua            [30];
  char Numero         [30];
  char Bairro         [30];
  char Cidade         [30];
  char Estado         [30];
  char CEP            [30];
  char Dia_Nascimento [30];
  char Mes_Nascimento [30];
  int  Ano_Nascimento     ;
  char Email          [30];
  char Datadiag       [30];
  char Comorbidade    [30];

} Paciente;




int main()
{
   setlocale(LC_ALL, "");
   Funcionario Funcionario;
   int res;

   // Inicio

   printf("--------------------------------------------");
   printf("\n SE DESEJA REALIZAR UM CADASTRO, DIGITE 1\n");
   printf("--------------------------------------------");
   printf("\n CASO JA TENHA UM CADASTRO, DIGITE 2\n");
   printf("--------------------------------------------");
   printf("\n");

   // Cadastro
      scanf("%d", &res);
      if (res == 1){
      system("cls");


      printf("\t----------------------------------");
    printf("\n\t ||||| CADASTRO FUNCIONARIO |||||\n");
      printf("\t----------------------------------");
      printf("\n");



    printf("\n | REGISTRAR LOGIN |");
      scanf("%s", Funcionario.regi1);

    printf("\n | REGISTRAR SENHA |");
      scanf("%s", Funcionario.regi2);

      system("cls");

      printf("\t----------------------------------");
    printf("\n\t ||||| USUARIO REGISTRADO |||||\n");
      printf("\t----------------------------------");
      printf("\n");


      // Arquiva Cadastro

    FILE *file;
    file = fopen("Cadastro Funcionarios", "a");
    fprintf(file, "%s", Funcionario.regi1);
    fprintf(file, ",%s\n", Funcionario.regi2);
    fclose(file);

      }

      // Login


     system("cls");

    printf("\t----------------------------------");
    printf("\n\t ||||| LOGIN FUNCIONARIO |||||\n");
    printf("\t----------------------------------");
    printf ("\n");

    printf("\n\t | Login |");
    scanf("%s", Funcionario.Usuario);

    printf("\n\t | Senha |");
    scanf("%s", Funcionario.Senha);

    FILE *file;
    file = fopen("Cadastro Funcionarios", "r");

    char linha[100];
    char *usuaux = strcat(Funcionario.Usuario, ",");
    char *senaux = strcat(usuaux, Funcionario.Senha);

    int acertou = 0;

    while(fscanf(file, "%[^\n]\n", linha) != EOF) {
      int cmp = strcmp(linha, senaux);

      if (cmp == 0) {
        acertou = 1;
        break;
      }
    }
    system("cls");

    if(!acertou){
    printf("\n\t---------------------------------------------------------------------------");
    printf("\n\t ||||| DADOS INVALIDOS, CADASTRE-SE OU INSIRA OS DADOS NOVAMENTE ! |||||\n");
    printf("\t---------------------------------------------------------------------------\n");
    system("pause");
    return 0;
    fclose(file);
    }

    printf("\n\t----------------------------------");
    printf("\n\t ||||| LOGIN BEM-SUCEDIDO ! |||||\n");
    printf("\t----------------------------------\n");


    // Cadastro Paciente


    printf("\n\t----------------------------------");
    printf("\n\t ||||| INSIRA OS DADOS DO PACIENTE ! |||||\n");
    printf("\t----------------------------------\n");

    getchar();

    Paciente Paciente;

    printf("\n\t | Nome |");
    fgets(Paciente.Nome, sizeof(Paciente.Nome), stdin);

    printf("\n\t | CPF |");
    fgets(Paciente.CPF, sizeof(Paciente.CPF), stdin);

    printf("\n\t | Telefone |");
    fgets(Paciente.Telefone, sizeof(Paciente.Telefone), stdin);

    printf("\n\t | Rua |");
    fgets(Paciente.Rua, sizeof(Paciente.Rua), stdin);

    printf("\n\t | Numero do Complemento |");
    fgets(Paciente.Numero, sizeof(Paciente.Numero), stdin);

    printf("\n\t | Bairro |");
    fgets(Paciente.Bairro, sizeof(Paciente.Bairro), stdin);

    printf("\n\t | Cidade |");
    fgets(Paciente.Cidade, sizeof(Paciente.Cidade), stdin);

    printf("\n\t | Estado |");
    fgets(Paciente.Estado, sizeof(Paciente.Estado), stdin);

    printf("\n\t | CEP |");
    fgets(Paciente.CEP, sizeof(Paciente.CEP), stdin);

    printf("\n\t | Dia de Nascimento |");
    fgets(Paciente.Dia_Nascimento, sizeof(Paciente.Dia_Nascimento), stdin);


    printf("\n\t | Mes de Nascimento |");
    fgets(Paciente.Mes_Nascimento, sizeof(Paciente.Mes_Nascimento), stdin);


    printf("\n\t | Ano de Nascimento |");
    char ano[10];
    fgets(ano, sizeof(ano), stdin);
    Paciente.Ano_Nascimento = atoi(ano);


    printf("\n\t | E-mail |");
    fgets(Paciente.Email, sizeof(Paciente.Email), stdin);

    printf("\n\t | Data do Diagnóstico |");
    fgets(Paciente.Datadiag, sizeof(Paciente.Datadiag), stdin);

    printf("\n\t | Comorbidade |");
    fgets(Paciente.Comorbidade, sizeof(Paciente.Comorbidade), stdin);

    FILE *paci;
    paci = fopen("Cadastro de Pacientes", "a");
    fprintf(paci, "\n");
    fprintf(paci, "|Nome                |%s", Paciente.Nome);
    fprintf(paci, "|CPF                 |%s", Paciente.CPF);
    fprintf(paci, "|Telefone            |%s", Paciente.Telefone);
    fprintf(paci, "|Rua                 |%s", Paciente.Rua);
    fprintf(paci, "|Numero              |%s", Paciente.Numero);
    fprintf(paci, "|Bairro              |%s", Paciente.Bairro);
    fprintf(paci, "|Cidade              |%s", Paciente.Cidade);
    fprintf(paci, "|Estado              |%s", Paciente.Estado);
    fprintf(paci, "|Cep                 |%s", Paciente.CEP);
    fprintf(paci, "|Dia de Nascimento   |%s", Paciente.Dia_Nascimento);
    fprintf(paci, "|Mes de Nascimento   |%s", Paciente.Mes_Nascimento);
    fprintf(paci, "|Ano de Nascimento   |%d\n", Paciente.Ano_Nascimento);
    fprintf(paci, "|Email               |%s", Paciente.Email);
    fprintf(paci, "|Datadiag            |%s", Paciente.Datadiag);
    fprintf(paci, "|Comorbidade         |%s", Paciente.Comorbidade);
    fprintf(paci, "------------------------------------------------");

    system("cls");

    printf("\n                          -----------------------------------------");
    printf("\n                            ||||| DIAGNOSTICO DO PACIENTE ! |||||\n");
    printf("                          -----------------------------------------\n");


    int idade;


    idade = 2021 - Paciente.Ano_Nascimento;
    int possuiComorbidade = strcmp("\n", Paciente.Comorbidade) != 0;
    int grupodeRisco = 0;


    if(idade > 65 && possuiComorbidade){
        printf("----------------------------------------------------------------------------------------------------------------\n");
        printf("O PACIENTE POSSUI UMA COMORBIDADE, %sE TEM %d ANOS, PORTANTO PERTENCE AO GRUPO DE RISCO", Paciente.Comorbidade, idade);
        printf("\n----------------------------------------------------------------------------------------------------------------\n");
        printf("                          INFORMAÇÕES DO PACIENTE SALVAS EM ARQUIVO");
        printf("\n----------------------------------------------------------------------------------------------------------------\n");
        printf("                                    PROGRAMA FINALIZADO");
        printf("\n----------------------------------------------------------------------------------------------------------------");
        grupodeRisco ++;
    }
    else if (idade <=65 && !possuiComorbidade){
        printf("----------------------------------------------------------------------------------------------------------------\n");
        printf("O PACIENTE NÃO POSSUI NENHUMA COMORBIDADE E NÃO TEM MAIS DE 65 ANOS, PORTANTO NÃO PERTENCE AO GRUPO DE RISCO");
        printf("\n----------------------------------------------------------------------------------------------------------------\n");
        printf("                                    PROGRAMA FINALIZADO");
        printf("\n----------------------------------------------------------------------------------------------------------------");
    }
    else if (idade <=65){
        printf("----------------------------------------------------------------------------------------------------------------\n");
        printf("O PACIENTE POSSUI UMA COMORBIDADE, %sPORÉM NÃO TEM MAIS DE 65 ANOS, PORTANTO NÃO PERTENCE AO GRUPO DE RISCO", Paciente.Comorbidade);
        printf("\n----------------------------------------------------------------------------------------------------------------\n");
        printf("                                    PROGRAMA FINALIZADO");
        printf("\n----------------------------------------------------------------------------------------------------------------");
    }
    else if (idade > 65){
        printf("---------------------------------------------------------------------------------------------\n");
        printf(" O PACIENTE NÃO TEM UMA COMORBIDADE PORÉM TEM %d ANOS, PORTANTO PERTENCE AO GRUPO DE RISCO", idade);
        printf("\n---------------------------------------------------------------------------------------------\n");
        printf("                          INFORMAÇÕES DO PACIENTE SALVAS EM ARQUIVO");
        printf("\n---------------------------------------------------------------------------------------------\n");
        printf("                                    PROGRAMA FINALIZADO");
        printf("\n---------------------------------------------------------------------------------------------");
        grupodeRisco++;

    }

    if(grupodeRisco == 1){
    FILE *risco;
    risco = fopen("Grupo de Risco", "a");
    fprintf(risco, "\n");
    fprintf(risco, "|Nome              |%s", Paciente.Nome);
    fprintf(risco, "|Idade             |%d\n", idade);
    fprintf(risco, "|CEP               |%s", Paciente.CEP);
    fprintf(risco, "------------------------------------------------");
    }
    fclose(file);
    system("pause");
    return 0;
}

