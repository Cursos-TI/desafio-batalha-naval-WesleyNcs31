#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.


// Tamanho do tabuleiro e dos navios
#define TAM_TABULEIRO 10  // tabuleiro 10x10
#define TAM_NAVIO 3       // navios com 3 partes

int main() {
    // Fazendo o tabuleiro, que é uma matriz 10x10
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    
    // Colocando 0 em tudo, que é agua
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;  // agua
        }
    }
    
    // Coordenadas dos navios, eu escolhi assim
    // Navio horizontal: linha 2, coluna 3
    int linha_navio_horizontal = 2;
    int coluna_navio_horizontal = 3;
    
    // Navio vertical: linha 1, coluna 7
    int linha_navio_vertical = 1;
    int coluna_navio_vertical = 7;
    
    // Ver se o navio horizontal cabe no tabuleiro
    if (coluna_navio_horizontal + (TAM_NAVIO - 1) >= TAM_TABULEIRO) {
        printf("Erro: Navio horizontal nao cabe.\n");
        return 1;
    }
    
    // Ver se o navio vertical cabe
    if (linha_navio_vertical + (TAM_NAVIO - 1) >= TAM_TABULEIRO) {
        printf("Erro: Navio vertical nao cabe.\n");
        return 1;
    }
    
    // Ver se os navios se batem
    int sobreposicao = 0;
    for (int k = 0; k < TAM_NAVIO; k++) {
        int pos_h_linha = linha_navio_horizontal;
        int pos_h_coluna = coluna_navio_horizontal + k;
        
        int pos_v_linha = linha_navio_vertical + k;
        int pos_v_coluna = coluna_navio_vertical;
        
        if (pos_h_linha == pos_v_linha && pos_h_coluna == pos_v_coluna) {
            sobreposicao = 1;
            break;
        }
    }
    
    if (sobreposicao) {
        printf("Erro: Navios se batem.\n");
        return 1;
    }
    
    // Colocando o navio horizontal no tabuleiro
    for (int k = 0; k < TAM_NAVIO; k++) {
        tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + k] = 3;  // parte do navio
    }
    
    // Colocando o navio vertical
    for (int k = 0; k < TAM_NAVIO; k++) {
        tabuleiro[linha_navio_vertical + k][coluna_navio_vertical] = 3;  // parte do navio
    }
    
    // Mostrando o tabuleiro
    printf("Tabuleiro do Batalha Naval:\n");
    printf("  ");  // espaco
    for (int j = 0; j < TAM_TABULEIRO; j++) {
        printf("%d ", j + 1);  // colunas 1 a 10
    }
    printf("\n");
    
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%d ", i + 1);  // linha
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);  // mostra 0 ou 3
        }
        printf("\n");
    }
    
    return 0;
}

