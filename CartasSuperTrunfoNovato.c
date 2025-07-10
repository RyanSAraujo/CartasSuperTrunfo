#include <stdio.h>

// Estrutura que representa uma carta do Super Trunfo
struct Carta {
    char estado[3];             // Ex: "SP"
    char codigo[10];            // Código da carta
    char nomeCidade[50];        // Nome da cidade
    int populacao;              // População total
    float area;                 // Área da cidade (em km²)
    float pib;                  // Produto Interno Bruto (em reais)
    int numPontosTuristicos;    // Número de pontos turísticos
};

int main() {
    // ==============================
    // 1. Cadastro de duas cartas
    // ==============================

    // Carta 1 - São Paulo
    struct Carta carta1 = {
        "SP", "SP001", "São Paulo",
        12300000,         // População
        1521.11,          // Área
        230000000000.0,   // PIB
        150               // Pontos turísticos
    };

    // Carta 2 - Rio de Janeiro
    struct Carta carta2 = {
        "RJ", "RJ002", "Rio de Janeiro",
        6748000,          // População
        1182.30,          // Área
        160000000000.0,   // PIB
        120               // Pontos turísticos
    };

    // ==============================
    // 2. Cálculo dos indicadores
    // ==============================

    // Densidade populacional = População / Área
    float densidade1 = carta1.populacao / carta1.area;
    float densidade2 = carta2.populacao / carta2.area;

    // PIB per capita = PIB / População
    float pibPerCapita1 = carta1.pib / carta1.populacao;
    float pibPerCapita2 = carta2.pib / carta2.populacao;

    // ==============================
    // 3. Escolha do atributo a ser comparado
    // ==============================
    // Altere a variável abaixo para escolher o atributo:
    // 1 - População | 2 - Área | 3 - PIB | 4 - Densidade Populacional | 5 - PIB per capita
    int atributoEscolhido = 1; // <- Troque aqui o número para mudar o atributo

    // ==============================
    // 4. Lógica de comparação com if e if-else
    // ==============================

    printf("===== COMPARAÇÃO DE CARTAS (SUPER TRUNFO) =====\n\n");

    if (atributoEscolhido == 1) {
        // Comparar POPULAÇÃO
        printf("Comparação por POPULAÇÃO:\n");
        printf("%s (%s): %d habitantes\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
        printf("%s (%s): %d habitantes\n", carta2.nomeCidade, carta2.estado, carta2.populacao);

        if (carta1.populacao > carta2.populacao)
            printf("Resultado: %s venceu!\n", carta1.nomeCidade);
        else if (carta2.populacao > carta1.populacao)
            printf("Resultado: %s venceu!\n", carta2.nomeCidade);
        else
            printf("Resultado: Empate!\n");
    }

    else if (atributoEscolhido == 2) {
        // Comparar ÁREA
        printf("Comparação por ÁREA:\n");
        printf("%s (%s): %.2f km²\n", carta1.nomeCidade, carta1.estado, carta1.area);
        printf("%s (%s): %.2f km²\n", carta2.nomeCidade, carta2.estado, carta2.area);

        if (carta1.area > carta2.area)
            printf("Resultado: %s venceu!\n", carta1.nomeCidade);
        else if (carta2.area > carta1.area)
            printf("Resultado: %s venceu!\n", carta2.nomeCidade);
        else
            printf("Resultado: Empate!\n");
    }

    else if (atributoEscolhido == 3) {
        // Comparar PIB
        printf("Comparação por PIB:\n");
        printf("%s (%s): R$ %.2f\n", carta1.nomeCidade, carta1.estado, carta1.pib);
        printf("%s (%s): R$ %.2f\n", carta2.nomeCidade, carta2.estado, carta2.pib);

        if (carta1.pib > carta2.pib)
            printf("Resultado: %s venceu!\n", carta1.nomeCidade);
        else if (carta2.pib > carta1.pib)
            printf("Resultado: %s venceu!\n", carta2.nomeCidade);
        else
            printf("Resultado: Empate!\n");
    }

    else if (atributoEscolhido == 4) {
        // Comparar DENSIDADE POPULACIONAL (quem tiver MENOR valor vence)
        printf("Comparação por DENSIDADE POPULACIONAL:\n");
        printf("%s (%s): %.2f hab/km²\n", carta1.nomeCidade, carta1.estado, densidade1);
        printf("%s (%s): %.2f hab/km²\n", carta2.nomeCidade, carta2.estado, densidade2);

        if (densidade1 < densidade2)
            printf("Resultado: %s venceu!\n", carta1.nomeCidade);
        else if (densidade2 < densidade1)
            printf("Resultado: %s venceu!\n", carta2.nomeCidade);
        else
            printf("Resultado: Empate!\n");
    }

    else if (atributoEscolhido == 5) {
        // Comparar PIB PER CAPITA
        printf("Comparação por PIB PER CAPITA:\n");
        printf("%s (%s): R$ %.2f\n", carta1.nomeCidade, carta1.estado, pibPerCapita1);
        printf("%s (%s): R$ %.2f\n", carta2.nomeCidade, carta2.estado, pibPerCapita2);

        if (pibPerCapita1 > pibPerCapita2)
            printf("Resultado: %s venceu!\n", carta1.nomeCidade);
        else if (pibPerCapita2 > pibPerCapita1)
            printf("Resultado: %s venceu!\n", carta2.nomeCidade);
        else
            printf("Resultado: Empate!\n");
    }

    else {
        printf("Atributo escolhido inválido.\n");
    }

    return 0;
}
