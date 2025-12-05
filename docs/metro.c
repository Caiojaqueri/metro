#include <stdio.h> 
#include <string.h>
#include <windows.h> 
#include <time.h> 

#define MAX_ESTACOES 13
#define TEMPO_ESPERA 3

#define PORTA_ABERTA 1
#define PORTA_FECHADA 0

int estacao_atual = 0;
int estacao_final = MAX_ESTACOES - 1;
int proxima_estacao = 1;
int estado_porta = PORTA_FECHADA;

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

void abrirPorta() {
    estado_porta = PORTA_ABERTA;
}

void fechar_porta() {
    estado_porta = PORTA_FECHADA;
}

void parar_estacao() {
    printf("Estação %s\n", metro[estacao_atual].nome);//pega o nome da estacao atual do vetor metro
    abrirPorta();

    //loop do temporizador
    for(int i = TEMPO_ESPERA; i > 0; i--){
        printf("--- Porta ABERTA. Tempo restante: %d ---\r", i);

        fflush(stdout); //garante que a linha a cima apareça antes do sleep
        Sleep(3 * 1000);
    }

    fechar_porta();
    printf("--- PI PI PI PI PI PI. Porta FECHADA.---\n\n");
}

void movimento() {
    printf("([:::])_([:::])_([:::])_([:::])_([:::])====>\n\n");
    printf("Próxima estação: %s\n\n", metro[estacao_atual + 1].nome);

    fflush(stdout);
    Sleep(2 * 1000); // simula o tempo de viagem entre as estações
}

void linha() {
    //para cada estacao, passe por cada uma ++ e pare na estacao
    for (int i = 0; i < MAX_ESTACOES; i++) {
        parar_estacao();


        //se a estacao atual for = a max - 1, a ultima
        if(estacao_atual == MAX_ESTACOES - 1) {
            printf("Estação final: %s\n\n", metro[estacao_atual].nome);
            printf("\n Obrigado por usar o metrô de São Paulo\n");
            return;
        }

        movimento();

        estacao_atual++;
    }
}

int main() {
    printf("Bem vindo ao metrô de São Paulo! Tenha a todos uma boa viagem!\n\n");

    linha();

    return 0;
}
