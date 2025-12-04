#include <stdio.h> // vou usar para entrada e saída de dados
#include <string.h> // vou usar para manipulação de strings
#include <windows.h> // vou usar para simular o tempo de espera nas estações
#include <time.h> // vou usar para simular o tempo de espera nas estações

#define MAX_ESTACOES 13
#define TEMPO_ESPERA 2 

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
    printf("--- Porta ABERTA. Tempo de espera: %d segundos. ---\n", TEMPO_ESPERA);

    fflush(stdout); //garante que a linha a cima apareça antes do sleep

    Sleep(TEMPO_ESPERA * 1000);
    /*O Sleep geralmente usa milissegundos, não segundos puros.
    Se você está usando <windows.h> ou <unistd.h>,
    verifique se 'Sleep()' espera segundos (s) ou milissegundos (ms).
    Se for milissegundos, use TEMPO_ESPERA * 1000
    Se TEMPO_ESPERA é 5, isso será 5000ms (5 segundos)*/

    fechar_porta();
    printf("--- PI PI PI PI PI PI. Porta FECHADA.---\n");
}

void movimento() {
    printf("Próxima estação: %s\n", metro[estacao_atual + 1].nome);

    fflush(stdout);
    Sleep(2 * 1000); // simula o tempo de viagem entre as estações
}

void linha() {
    //para cada estacao, passe por cada uma ++ e pare na estacao
    for (int i = 0; i < MAX_ESTACOES; i++) {
        parar_estacao();


        //se a estacao atual for = que a max = 1, a ultima
        if(estacao_atual == MAX_ESTACOES - 1) {
            printf("Estação final: %s\n", metro[estacao_atual].nome);
            printf("\n Obrigado por usar o metrô de São Paulo\n");
            return;
        }

        movimento();

        estacao_atual++;
    }
}

int main() {
    printf("Bem vindo ao metrô de São Paulo! Tenha a todos uma boa viagem!\n");

    linha();

    return 0;
}
