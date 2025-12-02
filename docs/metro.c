// indo para o trabalho me peguei pensando em como eu faria um programa simulando o metrô de São Paulo, então aqui estou eu, iniciando esse pequeno projeto, com o objetivo de colocar em prática meus conhecimentos em C e lógica de programação. 

#include <stdio.h> // vou usar para entrada e saída de dados
#include <string.h> // vou usar para manipulação de strings
#include <windows.h> // vou usar para simular o tempo de espera nas estações
#include <time.h> // vou usar para simular o tempo de espera nas estações

#define MAX_ESTACOES 12 
#define ESTACAO_FINAL 1
#define TEMPO_ESPERA 5 

#define PORTA_ABERTA 1
#define PORTA_FECHADA 0

typedef struct {
    int numero;
    char nome[50];
} estacao;

estacao metro[MAX_ESTACOES] = {
    {0, "Vila Prudente"},
    {1, "Tamanduateí"},
    {2, "Sacomã"},
    {3, "Alto do ipiranga"},
    {4, "Santos-Imigrantes"},
    {5, "Chácara Klabin"},
    {6, "Ana Rosa"},
    {7, "Paraíso"},
    {8, "Brigadeiro"},
    {9, "Trianon-Masp"},
    {10, "Consolação"},
    {11, "Clínicas"},
    {12, "Vila Madalena"},
};

int estacao_atual = 0;
int proxima_estacao = 1;
int estado_porta = PORTA_FECHADA;

void abrirPorta() {
    estado_porta = PORTA_ABERTA;
    printf("Porta aberta na estação %s\n", metro[estacao_atual].nome);
}

void fechar_porta() {
    estado_porta = PORTA_FECHADA;
    printf("Porta fechada na estação %d\n", estacao_atual);
}

void parar_estacao() {
    printf("Você chegou na estação %d\n", estacao_atual);
    abrirPorta();
    Sleep(TEMPO_ESPERA);
    fechar_porta();
}

void movimento() {
    printf("Indo para a próxima estação: %d\n", estacao_atual + 1);
    Sleep(5); // simula o tempo de viagem entre as estações
}

void linha() {
    while (estacao_atual < ESTACAO_FINAL) {
        movimento(); //viaja para a próxima
        estacao_atual++; //chegou e acrescenta 1 na estação atual
        parar_estacao(); //abre porta, espera, fecha porta
    }
    printf("Você chegou na estação final: %d\n", ESTACAO_FINAL);
    parar_estacao(); //parada final
}

/* 
por enquanto eu penso em fazer a lógica dessa forma: 

enquanto: 
    o trem não chega até a estação final:
faça:
    pare em todas as estações
    abre a porta 
    espere 30 segundos
    feche a porta 
siga para a próxima estação
 */ 

int main() {
    printf("Bem vindo ao metrô de São Paulo!\n");

    linha();

    printf("Obrigado por usar o metrô de São Paulo!\n");


    return 0;
}