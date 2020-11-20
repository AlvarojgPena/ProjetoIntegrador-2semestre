#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>

#define TAM_VETOR 5
#define DIM_MATRIZ 3
#define PI 3.14159265
#define E 2.71828183

char sessao[20] = {};
int opcao, opcao_aux;

//ÚTIL
void inicio();
void imprime_header();
void menu_principal();

int valida_entrada(int min, int max);

//ORDENAR VETOR
int *vetor_inicial;
int *vetor_crescente;
int *vetor_decrescente;

void preenche_vetor_inicial();
void menu_ordenar();
void resultado_ordenar();

int *ordena_crescente(int *vetor, int tamanho);
int *ordena_decrescente(int *vetor, int tamanho);

void imprime_vetor(int *vetor, int tam);
void imprime_vetor_ordenado();

int *aloca_vetor(int tamanho);

//MATRIZES
int **matrizA;
int qtd_linhas_A, qtd_colunas_A;
int **matrizB;
int qtd_linhas_B, qtd_colunas_B;
int **matrizC;
int qtd_linhas_C, qtd_colunas_C;

void menu_matrizes();

void dimenciona_matriz(int *linhas, int *colunas, char letra);
void dimenciona_matriz_quadrada(int *linhas, int *colunas, char letra);
void preenche_matriz(int **matriz, int linhas, int colunas, char letra);

void imprime_matriz(int **matriz, int linhas, int colunas);

void resultado_determinante();
void resultado_matrizes();

int calcula_determinante(int **matriz, int linhas);
void soma_matrizes_A_B();
void subtrai_matrizes_A_B();
void produto_matrizes_A_B();

int **aloca_matriz(int linhas, int colunas);
void finaliza_matriz(int **matriz, int linhas);

//FUNÇÕES
void menu_funcoes();

double calcula_funcao1(double x, double k);
double calcula_funcao2(double x, double k);
double calcula_funcao3(double x, double k);
double calcula_funcao4(double x);
double calcula_funcao5(double x, double k);
double calcula_funcao6(double x);
double calcula_funcao7(double x);
double calcula_funcao8(double x);
double calcula_funcao9(double x);
double calcula_funcao10(double x);

//
double x, k, resultado;

void lista_funcoes();
void imprime_inserir_valor(char letra);
void insere_angulo(double *variavel, char letra);
void resultado_funcoes_derivadas();
//

//DERIVADAS
void menu_derivadas();

double calcula_derivada1(double x, double k);
double calcula_derivada2(double x, double k);
double calcula_derivada3(double x, double k);
double calcula_derivada4(double x);
double calcula_derivada5(double x, double k);
double calcula_derivada6(double x);
double calcula_derivada7(double x);
double calcula_derivada8(double x);
double calcula_derivada9(double x);
double calcula_derivada10(double x);

int main()
{
    setlocale(LC_ALL, "portuguese");

    inicio();
    while(opcao != -1)
    {
    strcpy(sessao, "MENU PRINCIPAL");
    menu_principal();
        switch(opcao)
        {
        //ORDENAR VETOR
        case 1:
            strcpy(sessao, "ORDENAR VETOR");
            vetor_inicial = aloca_vetor(TAM_VETOR);
            vetor_crescente = aloca_vetor(TAM_VETOR);
            vetor_decrescente = aloca_vetor(TAM_VETOR);
            do
            {
                opcao = 0;
                opcao_aux = 0;
                do
                {
                    preenche_vetor_inicial();
                    menu_ordenar();
                    switch(opcao)
                    {
                    case 1:
                        vetor_crescente = ordena_crescente(vetor_inicial, TAM_VETOR);
                        break;
                    case 2:
                        vetor_decrescente = ordena_decrescente(vetor_inicial, TAM_VETOR);
                        break;
                    }
                }while(!opcao);
                resultado_ordenar();
                switch(opcao_aux)
                {
                case 1:
                    if(opcao == 1)
                        vetor_decrescente = ordena_decrescente(vetor_inicial, TAM_VETOR);
                    else
                        vetor_crescente = ordena_crescente(vetor_inicial, TAM_VETOR);
                    resultado_ordenar();
                    break;
                }
            }while(opcao_aux);
            free(vetor_inicial);
            free(vetor_crescente);
            free(vetor_decrescente);
            break;
        //MATRIZES
        case 2:
            strcpy(sessao, "MATRIZES");
            do
            {
                menu_matrizes();
                if(opcao)
                {
                    matrizA = aloca_matriz(DIM_MATRIZ, DIM_MATRIZ);
                    if(opcao > 1)
                    {
                        matrizB = aloca_matriz(DIM_MATRIZ, DIM_MATRIZ);
                        matrizC = aloca_matriz(DIM_MATRIZ, DIM_MATRIZ);
                    }
                }
                do
                {
                    switch(opcao)
                    {
                    case 1:
                        dimenciona_matriz_quadrada(&qtd_linhas_A, &qtd_colunas_A, 'A');
                        preenche_matriz(matrizA, qtd_linhas_A, qtd_colunas_A, 'A');
                        resultado_determinante();
                        break;
                    case 2:
                        dimenciona_matriz(&qtd_linhas_A, &qtd_colunas_A, 'A');
                        preenche_matriz(matrizA, qtd_linhas_A, qtd_colunas_A, 'A');
                        dimenciona_matriz(&qtd_linhas_B, &qtd_colunas_B, 'B');
                        preenche_matriz(matrizB, qtd_linhas_B, qtd_colunas_B, 'B');
                        soma_matrizes_A_B();
                        resultado_matrizes();
                        break;
                    case 3:
                        dimenciona_matriz(&qtd_linhas_A, &qtd_colunas_A, 'A');
                        preenche_matriz(matrizA, qtd_linhas_A, qtd_colunas_A, 'A');
                        dimenciona_matriz(&qtd_linhas_B, &qtd_colunas_B, 'B');
                        preenche_matriz(matrizB, qtd_linhas_B, qtd_colunas_B, 'B');
                        subtrai_matrizes_A_B();
                        resultado_matrizes();
                        break;
                    case 4:
                        do
                        {
                            dimenciona_matriz(&qtd_linhas_A, &qtd_colunas_A, 'A');
                            dimenciona_matriz(&qtd_linhas_B, &qtd_colunas_B, 'B');
                            if(qtd_colunas_A != qtd_linhas_B)
                            {
                                imprime_header();
                                printf("O NUMERO DE COLUNAS DE A DEVE SER IGUAL AO NUMERO DE LINHAS DE B\n\n");
                                system("PAUSE");
                            }
                        }while(qtd_colunas_A != qtd_linhas_B);
                        preenche_matriz(matrizA, qtd_linhas_A, qtd_colunas_A, 'A');
                        preenche_matriz(matrizB, qtd_linhas_B, qtd_colunas_B, 'B');
                        produto_matrizes_A_B();
                        resultado_matrizes();
                        break;
                    case 0:
                        opcao_aux = 0;
                    }
                }while(opcao_aux == 1);
                if(opcao > 0)
                {
                    finaliza_matriz(matrizA, DIM_MATRIZ);
                    if(opcao > 1)
                    {
                        finaliza_matriz(matrizB, DIM_MATRIZ);
                        finaliza_matriz(matrizC, DIM_MATRIZ);
                    }
                }
            }while(opcao_aux);
            break;
        //FUNÇÕES
        case 3:
            strcpy(sessao, "FUNCOES\t");
            while(opcao)
            {
                menu_funcoes();
                do
                {
                    if(opcao) imprime_header();
                    switch(opcao)
                    {
                    case 1:
                        printf("f(x) = k\n\n");
                        imprime_inserir_valor('k');
                        scanf("%lf", &k);
                        imprime_inserir_valor('x');
                        scanf("%lf", &x);
                        resultado = calcula_funcao1(x, k);
                        break;
                    case 2:
                        printf("f(x) = x^k\n\n");
                        imprime_inserir_valor('k');
                        scanf("%lf", &k);
                        imprime_inserir_valor('x');
                        scanf("%lf", &x);
                        resultado = calcula_funcao2(x, k);
                        break;
                    case 3:
                        printf("f(x) = k^x\n\n");
                        imprime_inserir_valor('k');
                        scanf("%lf", &k);
                        imprime_inserir_valor('x');
                        scanf("%lf", &x);
                        resultado = calcula_funcao3(x, k);
                        break;
                    case 4:
                        printf("f(x) = e^x\n\n");
                        imprime_inserir_valor('x');
                        scanf("%lf", &x);
                        resultado = calcula_funcao4(x);
                        break;
                    case 5:
                        printf("f(x) = log k (x)\n\n");
                        imprime_inserir_valor('k');
                        scanf("%lf", &k);
                        imprime_inserir_valor('x');
                        scanf("%lf", &x);
                        resultado = calcula_funcao5(x, k);
                        break;
                    case 6:
                        printf("f(x) = ln(x)\n\n");
                        imprime_inserir_valor('x');
                        scanf("%lf", &x);
                        resultado = calcula_funcao6(x);
                        break;
                    case 7:
                        printf("f(x) = 1 / x\n\n");
                        imprime_inserir_valor('x');
                        scanf("%lf", &x);
                        resultado = calcula_funcao7(x);
                        break;
                    case 8:
                        printf("f(x) = sen(x)\n\n");
                        insere_angulo(&x, 'x'); // aqui o valor já é inserido na variável parâmetro
                        resultado = calcula_funcao8(x);
                        break;
                    case 9:
                        printf("f(x) = cos(x)\n\n");
                        insere_angulo(&x, 'x');
                        resultado = calcula_funcao9(x);
                        break;
                    case 10:
                        printf("f(x) = tg(x)\n\n");
                        insere_angulo(&x, 'x');
                        resultado = calcula_funcao10(x);
                        break;
                    }
                    resultado_funcoes_derivadas();
                    switch(opcao_aux)
                    {
                    case 0:
                        opcao = 0;
                        break;
                    }
                }while(opcao_aux == 1);
            }
            x = 0;
            k = 0;
            resultado = 0;
            break;
        //DERIVADAS
        case 4:
            strcpy(sessao, "FUNCOES\t");
            while(opcao)
            {
                menu_funcoes();
                do
                {
                    if(opcao) imprime_header();
                    switch(opcao)
                    {
                    case 1:
                        printf("f'(x) = [k]' = 0\n\n");
                        imprime_inserir_valor('k');
                        scanf("%lf", &k);
                        imprime_inserir_valor('x');
                        scanf("%lf", &x);
                        resultado = calcula_derivada1(x, k);
                        break;
                    case 2:
                        printf("f'(x) = [x^k]' = k * x^k-1\n\n");
                        imprime_inserir_valor('k');
                        scanf("%lf", &k);
                        imprime_inserir_valor('x');
                        scanf("%lf", &x);
                        resultado = calcula_derivada2(x, k);
                        break;
                    case 3:
                        printf("f'(x) = [k^x]' = k^x * ln(k)\n\n");
                        imprime_inserir_valor('k');
                        scanf("%lf", &k);
                        imprime_inserir_valor('x');
                        scanf("%lf", &x);
                        resultado = calcula_derivada3(x, k);
                        break;
                    case 4:
                        printf("f'(x) = [e^x]' = e^x\n\n");
                        imprime_inserir_valor('x');
                        scanf("%lf", &x);
                        resultado = calcula_derivada4(x);
                        break;
                    case 5:
                        printf("f'(x) = [log k (x)]' = 1 / (x * ln(k))\n\n");
                        imprime_inserir_valor('k');
                        scanf("%lf", &k);
                        imprime_inserir_valor('x');
                        scanf("%lf", &x);
                        resultado = calcula_derivada5(x, k);
                        break;
                    case 6:
                        printf("f'(x) = [ln(x)]' = 1 / x\n\n");
                        imprime_inserir_valor('x');
                        scanf("%lf", &x);
                        resultado = calcula_derivada6(x);
                        break;
                    case 7:
                        printf("f'(x) = [1 / x]' = 1 / x^2\n\n");
                        imprime_inserir_valor('x');
                        scanf("%lf", &x);
                        resultado = calcula_derivada7(x);
                        break;
                    case 8:
                        printf("f'(x) = [sen(x)]' = cos(x)\n\n");
                        insere_angulo(&x, 'x'); // aqui o valor já é inserido na variável parâmetro
                        resultado = calcula_derivada8(x);
                        break;
                    case 9:
                        printf("f'(x) = [cos(x)]' = -sen(x)\n\n");
                        insere_angulo(&x, 'x');
                        resultado = calcula_derivada9(x);
                        break;
                    case 10:
                        printf("f'(x) = [tg(x)]' = sec^2(x)\n\n");
                        insere_angulo(&x, 'x');
                        resultado = calcula_derivada10(x);
                        break;
                    }
                    resultado_funcoes_derivadas();
                    switch(opcao_aux)
                    {
                    case 0:
                        opcao = 0;
                        break;
                    }
                }while(opcao_aux == 1);
            }
            x = 0;
            k = 0;
            resultado = 0;
            break;
        //
        case 0:
            printf("\nFIM\n");
            opcao = -1;
            break;
        }
    }
    return 0;
}

void inicio()
{
    system("CLS");
    printf("+-------------------------------------------------------+\n");
    printf("| Lorenzetti's Palace\t  ___                  _ \t|\n");
    printf("|\t Inc.\t\t / _ \\                | | \t|\n");
    printf("|    /|       |\\\t/ /_\\ \\_ __ ___  _ __ | | ___ \t|\n");
    printf("|  /  |       |  \\\t|  _  | '_ ` _ \\| '_ \\| |/ _ \\ \t|\n");
    printf("| |    \\     /    |\t| | | | | | | | | |_) | | (_) | |\n");
    printf("| |  \\ /     \\ /  |\t\\_| |_/_| |_| |_| .__/|_|\\___/ \t+----------------+\n");
    printf("| | \\  |     |  / |\t  ____       _  | |       _       _ \t\t |\n");
    printf("| | \\ _\\_/^\\_/_ / |\t / __ \\     | | |_|      | |     | | \t\t |\n");
    printf("| |    --\\//--    |\t| /  \\/ __ _| | ___ _   _| | __ _| |_ ___  _ __  |\n");
    printf("|  \\_  \\     /  _/\t| |    / _` | |/ __| | | | |/ _` | __/ _ \\| '__| |\n");
    printf("|    \\__  |  __/\t| \\__/\\ (_| | | (__| |_| | | (_| | || (_) | | \t |\n");
    printf("|       \\ _ /\t\t \\____/\\__,_|_|\\___|\\__,_|_|\\__,_|\\__\\___/|_| \t |\n");
    printf("|      _/   \\_ \t\t______     _ \t\t\t\t\t |\n");
    printf("|     / _/|\\_ \\\t\t| ___ \\   | | \t\t\t   +-------------+\n");
    printf("|      /  |  \\\t\t| |_/ /___| |__   ___  _ __ _ __   |\n");
    printf("|       / v \\\t\t|    // _ \\ '_ \\ / _ \\| '__| '_ \\  |\n");
    printf("|\t\t\t| |\\ \\  __/ |_) | (_) | |  | | | | |\n");
    printf("| All Rights Reserved\t\\_| \\_\\___|_.__/ \\___/|_|  |_| |_| |\n");
    printf("|\t2020\t\t\t\t\t\t   |\n");
    printf("+----------------------------------------------------------+\n");
    printf("\n");
    system("PAUSE");
}

void imprime_header()
{
    system("CLS");
    printf("+-------------------------------------------------------+\n");
    printf("|    /|       |\\\t\t\t\t\t|\n");
    printf("|  /  |       |  \\\t\t\t\t\t|\n");
    printf("| |    \\     /    |\t\t\t\t\t|\n");
    printf("| |  \\ /     \\ /  |\t  ___         ____      ______\t|\n");
    printf("| | \\  |     |  / |\t / _ \\       / __ \\     | ___ \\\t|\n");
    printf("| | \\ _\\_/^\\_/_ / |\t/ /_\\ \\     | /  \\/     | |_/ /\t|\n");
    printf("| |    --\\//--    |\t|  _  |     | |         |    /\t|\n");
    printf("|  \\_  \\     /  _/\t| | | |  _  | \\__/\\  _  | |\\ \\\t|\n");
    printf("|    \\__  |  __/\t\\_| |_/ (_)  \\____/ (_) \\_| \\_|\t|\n");
    printf("|       \\ _ /\t\t\t\t\t\t|\n");
    printf("|      _/   \\_ \t\t\t\t\t\t|\n");
    printf("|     / _/|\\_ \\\t\t\t%s\t\t|\n", sessao);
    printf("|      /  |  \\\t\t\t\t\t\t|\n");
    printf("|       / v \\\t\t\t\t\t\t|\n");
    printf("+-------------------------------------------------------+\n");
    printf("\n");
}

void menu_principal()
{
    imprime_header();
    printf("ESCOLHA A OPCAO DESEJADA:\n\n");

    printf("1. Ordenar vetor\n");
    printf("2. Matrizes\n");
    printf("3. Funcoes\n");
    printf("4. Derivadas\n\n");

    printf("0. SAIR\n\n");

    opcao = valida_entrada(0, 4);
}

int valida_entrada(int min, int max)
{
    int dado_entrado;
    do
    {
        scanf("%d", &dado_entrado);
        if(dado_entrado > max || dado_entrado < min)
        {
            printf("INVALIDO\n");
            printf("Digite um numero entre %d e %d: ", min, max);
        }
    }while(dado_entrado > max || dado_entrado < min);
    return dado_entrado;
}

//ORDENAR VETOR
void preenche_vetor_inicial()
{
    imprime_header();
    printf("PREENCHA O VETOR COM %d VALORES NUMERICOS\n\n", TAM_VETOR);
    int i;
    for(i=0; i<TAM_VETOR; i++)
    {
        printf("Digite");
        if(!i) printf(" um");
        else printf(" outro");
        printf(" numero: ");
        scanf("%d", &vetor_inicial[i]);
    }
}

void menu_ordenar()
{
    imprime_header();
    imprime_vetor(vetor_inicial, TAM_VETOR);
    printf("ESCOLHA A OPERACAO DESEJADA:\n\n");

    printf("1. Ordenar elementos de forma crescente\n");
    printf("2. Ordenar elementos de forma decrescente\n\n");

    printf("0. PREENCHER NOVAMENTE\n\n");

    opcao = valida_entrada(0, 2);
}

void resultado_ordenar()
{
    int n = 1;
    imprime_header();
    imprime_vetor(vetor_inicial, TAM_VETOR);
    imprime_vetor_ordenado();
    printf("1. ");
    if(!opcao_aux)
    {
        n = 2;
        printf("Ordenar de forma ");
        if(opcao == 1)
            printf("decrescente");
        else
            printf("crescente");
        printf("\n");
        printf("2. ");
    }
    printf("Preencher o vetor com novos numeros\n\n");

    printf("0. VOLTAR AO MENU PRINCIPAL\n\n");

    opcao_aux = valida_entrada(0, n);
}

int *ordena_crescente(int *vetor, int tamanho)
{
    int i, j, aux;
    int *vetor_ordenado = aloca_vetor(tamanho);
    // passa os elementos de vetor para vetor_ordenado
    for(i=0; i<tamanho; i++)
        vetor_ordenado[i] = vetor[i];
    // ordena vetor_ordenado
    for(i=0; i<tamanho; i++)
        for(j=0; j<tamanho; j++)
         {
             if(vetor_ordenado[i] < vetor_ordenado[j])
             {
                aux = vetor_ordenado[i];
                vetor_ordenado[i] = vetor_ordenado[j];
                vetor_ordenado[j] = aux;
             }
         }
    return vetor_ordenado;
}

int *ordena_decrescente(int *vetor, int tamanho)
{
    int i, j, aux;
    int *vetor_ordenado = aloca_vetor(tamanho);
    // passa os elementos de vetor para vetor_ordenado
    for(i=0; i<tamanho; i++)
        vetor_ordenado[i] = vetor[i];
    // ordena vetor_ordenado
    for(i=0; i<tamanho; i++)
        for(j=0; j<tamanho; j++)
         {
             if(vetor_ordenado[i] > vetor_ordenado[j])
             {
                aux = vetor_ordenado[i];
                vetor_ordenado[i] = vetor_ordenado[j];
                vetor_ordenado[j] = aux;
             }
         }
    return vetor_ordenado;
}

void imprime_vetor(int *vetor, int tam)
{
    int i;
    printf("{");
    for(i=0; i<tam; i++)
    {
        printf(" %d", vetor[i]);
        if(i < tam-1)
            printf(",");
    }
    printf(" }\n\n");
}

void imprime_vetor_ordenado()
{
    if(opcao == 1)
    {
        printf("Ordem crescente\n");
        imprime_vetor(vetor_crescente, TAM_VETOR);
        if(opcao_aux)
        {
            printf("Ordem decrescente\n");
            imprime_vetor(vetor_decrescente, TAM_VETOR);
        }
    }
    else
    {
        printf("Ordem decrescente\n");
        imprime_vetor(vetor_decrescente, TAM_VETOR);
        if(opcao_aux)
        {
            printf("Ordem crescente\n");
            imprime_vetor(vetor_crescente, TAM_VETOR);
        }
    }
}

int *aloca_vetor(int tamanho)
{
  int *vetor_alocado;
  vetor_alocado = malloc(tamanho * sizeof(int *));
  return vetor_alocado;
}

//MATRIZES
void menu_matrizes()
{
    imprime_header();
    printf("ESCOLHA A OPCAO DESEJADA:\n\n");

    printf("1. Determinante\n");
    printf("2. Soma\n");
    printf("3. Subtracao\n");
    printf("4. Produto\n\n");

    printf("0. VOLTAR\n\n");

    opcao = valida_entrada(0, 4);
}

void dimenciona_matriz(int *linhas, int *colunas, char letra)
{
    imprime_header();
    printf("DETERMINE O NUMERO DE LINHAS DA MATRIZ %c: ", letra);
    *linhas = valida_entrada(1, DIM_MATRIZ);
    printf("DETERMINE O NUMERO DE COLUNAS DA MATRIZ %c: ", letra);
    *colunas = valida_entrada(1, DIM_MATRIZ);
}

void dimenciona_matriz_quadrada(int *linhas, int *colunas, char letra)
{
    imprime_header();
    printf("ESSA OPERACAO E FEITA COM MATRIZES QUADRADAS, QUE POSSUEM DIMENSOES IGUAIS\n\n");
    printf("PORTANTO, A MATRIZ TERA A MESMA QUANTIDADE DE LINHAS E COLUNAS\n\n");
    printf("Determine o numero de linhas da matriz quadrada %c: ", letra);
    *linhas = valida_entrada(1, DIM_MATRIZ);
    *colunas = *linhas;
}

void preenche_matriz(int **matriz, int linhas, int colunas, char letra)
{
    int i, j;
    for(i=0; i<linhas; i++)
    {
        imprime_header();
        printf("PREENCHA A MATRIZ %c COM %d VALORES NUMERICOS\n\n", letra, colunas);
        printf("Linha %d\n", i+1);
        for(j=0; j<colunas; j++)
        {
            printf("Digite");
            if(!j) printf(" um");
            else printf(" outro");
            printf(" numero: ");
            scanf("%d", &matriz[i][j]);
        }
    }
}

void resultado_determinante()
{
    imprime_header();
    printf("MATRIZ\n");
    imprime_matriz(matrizA, qtd_linhas_A, qtd_colunas_A);
    printf("DETERMINANTE: %d\n\n", calcula_determinante(matrizA, qtd_linhas_A));
    printf("1. Calcular o determinante de outra matriz\n");
    printf("2. Realizar outra operacao\n\n");

    printf("0. VOLTAR AO MENU PRINCIPAL\n\n");

    opcao_aux = valida_entrada(0, 2);
}

void resultado_matrizes()
{
    imprime_header();
    printf("MATRIZ A\n");
    imprime_matriz(matrizA, qtd_linhas_A, qtd_colunas_A);
    printf("MATRIZ B\n");
    imprime_matriz(matrizB, qtd_linhas_B, qtd_colunas_B);
    printf("MATRIZ RESULTANTE\n");
    imprime_matriz(matrizC, qtd_linhas_C, qtd_colunas_C);
    printf("1. Calcular novamente com novos valores\n");
    printf("2. Realizar outra operacao\n\n");

    printf("0. VOLTAR AO MENU PRINCIPAL\n\n");

    opcao_aux = valida_entrada(0, 2);
}

void imprime_matriz(int **matriz, int linhas, int colunas)
{
    int i, j;
    for(i=0; i<linhas; i++)
    {
        printf("{");
        for(j=0; j<colunas; j++)
        {
            printf(" %d", matriz[i][j]);
        }
        printf(" }\n");
    }
    printf("\n");
}

int calcula_determinante(int **matriz, int linhas)
{
    int i, j;
    int determinante;
    int positivo = 1, negativo = 1;
    switch(linhas)
    {
    case 1:
        determinante = matriz[0][0];
        break;
    case 2:
        i = linhas - 1;
        for(j=0; j<linhas; j++)
        {
            positivo *= matriz[j][j];
            negativo *= matriz[i][j];
            i--;
        }
        determinante = positivo - negativo;
        break;
    case 3:
        positivo = (matriz[0][0] * matriz[1][1] * matriz[2][2]) + (matriz[0][1] * matriz[1][2] * matriz[2][0]) + (matriz[0][2] * matriz[1][0] * matriz[2][1]);
        negativo = (matriz[0][2] * matriz[1][1] * matriz[2][0]) + (matriz[0][0] * matriz[1][2] * matriz[2][1]) + (matriz[0][1] * matriz[1][0] * matriz[2][2]);
        determinante = positivo - negativo;
        break;
    }
    return determinante;
}

void soma_matrizes_A_B()
{
    int i, j;
    for(i=0; i<DIM_MATRIZ; i++)
        for(j=0; j<DIM_MATRIZ; j++)
            matrizC[i][j] = matrizA[i][j] + matrizB[i][j];

    if(qtd_linhas_A > qtd_linhas_B)
        qtd_linhas_C = qtd_linhas_A;
    else
        qtd_linhas_C = qtd_linhas_B;

    if(qtd_colunas_A > qtd_colunas_B)
        qtd_colunas_C = qtd_colunas_A;
    else
        qtd_colunas_C = qtd_colunas_B;
}

void subtrai_matrizes_A_B()
{
    int i, j;
    for(i=0; i<DIM_MATRIZ; i++)
        for(j=0; j<DIM_MATRIZ; j++)
            matrizC[i][j] = matrizA[i][j] - matrizB[i][j];

    if(qtd_linhas_A > qtd_linhas_B)
        qtd_linhas_C = qtd_linhas_A;
    else
        qtd_linhas_C = qtd_linhas_B;

    if(qtd_colunas_A > qtd_colunas_B)
        qtd_colunas_C = qtd_colunas_A;
    else
        qtd_colunas_C = qtd_colunas_B;
}

void produto_matrizes_A_B()
{
    int i, j, k;
    int soma_produto = 0;

    int maximoC;
    if(qtd_linhas_A > qtd_colunas_A)
        maximoC = qtd_linhas_A;
    else
        maximoC = qtd_colunas_A;

    for(i=0; i<qtd_linhas_A; i++)
        for(j=0; j<qtd_colunas_B; j++)
        {
            for(k=0; k<maximoC; k++)
                soma_produto += matrizA[i][k] * matrizB[k][j];
            matrizC[i][j] = soma_produto;
            soma_produto = 0;
        }
    qtd_linhas_C = qtd_linhas_A;
    qtd_colunas_C = qtd_colunas_B;
}

int **aloca_matriz(int linhas, int colunas)
{
    int **matriz_alocada;
    int i, j;

    matriz_alocada = malloc(linhas * sizeof(int *));
    for(i=0; i<linhas; i++)
        matriz_alocada[i] = malloc(colunas * sizeof(int));

    for(i=0; i<linhas; i++)
        for(j=0; j<colunas; j++)
            matriz_alocada[i][j] = 0;
    return matriz_alocada;
}

void finaliza_matriz(int **matriz, int linhas)
{
    int i;
    for(i=0; i<linhas; i++)
        free(matriz[i]);
    free(matriz);
}

//FUNÇÕES
void menu_funcoes()
{
    imprime_header();
    printf("ESCOLHA A FUNCAO DESEJADA:\n\n");
    lista_funcoes();
    opcao = valida_entrada(0, 10);
}

double calcula_funcao1(double x, double k)
{
    return k;
}

double calcula_funcao2(double x, double k)
{
    double r;
    r = pow(x, k);
    return r;
}

double calcula_funcao3(double x, double k)
{
    double r;
    r = pow(k, x);
    return r;
}

double calcula_funcao4(double x)
{
    double r;
    r = pow(E, x);
    return r;
}

double calcula_funcao5(double x, double k)
{
    double r;
    r = log10(x) / log10(k);
    return r;
}

double calcula_funcao6(double x)
{
    double r;
    r = log(x) * 2.3;
    return r;
}

double calcula_funcao7(double x)
{
    double r;
    r = ((double)1 / x);
    return r;
}

double calcula_funcao8(double x)
{
    double r;
    r = sin(x);
    return r;
}

double calcula_funcao9(double x)
{
    double r;
    r = cos(x);
    return r;
}

double calcula_funcao10(double x)
{
    double r;
    r = tan(x);
    return r;
}

//
void lista_funcoes()
{
    printf("1. f(x) = k\n");
    printf("2. f(x) = x^k\n");
    printf("3. f(x) = k^x\n");
    printf("4. f(x) = e^x\n");
    printf("5. f(x) = logK(x)\n");
    printf("6. f(x) = ln(x)\n");
    printf("7. f(x) = 1/x\n");
    printf("8. f(x) = sen(x)\n");
    printf("9. f(x) = cos(x)\n");
    printf("10. f(x) = tg(x)\n\n");

    printf("0. VOLTAR\n\n");
}

void imprime_inserir_valor(char letra)
{
    printf("INSIRA O VALOR DE %c ", letra);
}

void insere_angulo(double *variavel, char letra)
{
    printf("DIGITE O ANGULO DE %c ", letra);
    double angulos;
    angulos = valida_entrada(0, 360);
    *variavel = ((angulos * PI) / 180);
}

void resultado_funcoes_derivadas()
{
    printf("\n");
    if(opcao == 0)
        return 0;
    printf("f(%0.2lf) = %lf\n", x, resultado);
    if(opcao >= 8)
        printf("Obs: A calculadora converteu o angulo de x para radianos\n");
    printf("\n");
    printf("1. Calcular novamente com novos valores\n");
    printf("2. Realizar outra operacao\n");
    printf("\n");
    printf("0. VOLTAR AO MENU PRINCIPAL\n");
    printf("\n");

    opcao_aux = valida_entrada(0, 2);
}
//

//DERIVADAS
void menu_derivadas()
{
    imprime_header();
    printf("ESCOLHA A DERIVADA DESEJADA DAS SEGUINTES FUNCOES:\n\n");
    lista_funcoes();
    opcao = valida_entrada(0, 10);
}

double calcula_derivada1(double x, double k)
{
    return 0;
}

double calcula_derivada2(double x, double k)
{
    double r;
    r = pow(x, k-1);
    r = k * r;
    return r;
}

double calcula_derivada3(double x, double k)
{
    double r, aux;
    r = pow(k, x);
    aux = log(k);
    aux *= 2.3;
    r *= aux;
    return r;
}

double calcula_derivada4(double x)
{
    double r;
    r = pow(E, x);
    return r;
}

double calcula_derivada5(double x, double k)
{
    double r;
    r = log10(k) / log10(E);
    r = x * r;
    return r;
}

double calcula_derivada6(double x)
{
    double r;
    r = ((double)1 / x);
    return r;
}

double calcula_derivada7(double x)
{
    double r;
    r = pow(x, 2);
    r = ((double)- 1 / r);
    return r;
}

double calcula_derivada8(double x)
{
    double r;
    r = cos(x);
    return r;
}

double calcula_derivada9(double x)
{
    double r;
    r = -sin(x);
    return r;
}

double calcula_derivada10(double x)
{
    double r;
    double aux = 1 / cos(x);
    r = pow(aux, 2);
    return r;
}
