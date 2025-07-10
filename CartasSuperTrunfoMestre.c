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

// Função para comparar dois atributos (carta1, carta2) e retornar os valores
float compararAtributos(int atributo, struct Carta carta1, struct Carta carta2, float densidade1, float densidade2) {
    switch (atributo) {
        case 1: // População
            printf("População: %d (Carta 1), %d (Carta 2)\n", carta1.populacao, carta2.populacao);
            return carta1.populacao + carta2.populacao;
        case 2: // Área
            printf("Área: %.2f km² (Carta 1), %.2f km² (Carta 2)\n", carta1.area, carta2.area);
            return carta1.area + carta2.area;
        case 3: // PIB
            printf("PIB: R$ %.2f (Carta 1), R$ %.2f (Carta 2)\n", carta1.pib, carta2.pib);
            return carta1.pib + carta2.pib;
        case 4: // Número de pontos turísticos
            printf("Pontos Turísticos: %d (Carta 1), %d (Carta 2)\n", carta1.numPontosTuristicos, carta2.numPontosTuristicos);
            return carta1.numPontosTuristicos + carta2.numPontosTuristicos;
        case 5: // Densidade Populacional
            printf("Densidade Populacional: %.2f hab/km² (Carta 1), %.2f hab/km² (Carta 2)\n", densidade1, densidade2);
            return densidade1 + densidade2;
        default:
            return 0.0; // Caso de erro
    }
}

int main() {
    // ==============================
    // 1. Cadastro de duas cartas
    // ==============================
    struct Carta carta1 = {
        "SP", "SP001", "São Paulo", 12300000, 1521.11, 230000000000.0, 150
    };
    struct Carta carta2 = {
        "RJ", "RJ002", "Rio de Janeiro", 6748000, 1182.30, 160000000000.0, 120
    };

    // ==============================
    // 2. Cálculo dos indicadores
    // ==============================
    float densidade1 = carta1.populacao / carta1.area;
     float densidade2 = carta2.populacao / carta2.area;
     float pibPerCapita1 = carta1.pib / carta1.populacao;
    float pibPerCapita2 = carta2.pib / carta2.populacao;

    // ==============================
    // 3. Menu de seleção de atributos
    // ==============================
    int atributo1, atributo2;

    // Menu de seleção para o primeiro atributo
    printf("Escolha o primeiro atributo para comparação:\n");
     printf("1. População\n2. Área\n3. PIB\n4. Número de pontos turísticos\n5. Densidade Populacional\n");

    // Limpar o buffer para garantir que a entrada seja capturada corretamente
    while (scanf("%d", &atributo1) != 1) {
        printf("Entrada inválida. Escolha uma opção válida de 1 a 5:\n");
        while (getchar() != '\n'); // Limpar o buffer de entrada
    }

    // Validação para garantir que o atributo1 seja válido
    if (atributo1 < 1 || atributo1 > 5) {
        printf("Opção inválida para o primeiro atributo.\n");
        return 1; // Encerra o programa em caso de erro
    }

    // Menu de seleção para o segundo atributo
    printf("Escolha o segundo atributo para comparação (não pode ser o mesmo do primeiro):\n");
     printf("1. População\n2. Área\n3. PIB\n4. Número de pontos turísticos\n5. Densidade Populacional\n");

    // Limpar o buffer para garantir que a entrada seja capturada corretamente
    while (scanf("%d", &atributo2) != 1 || atributo2 == atributo1) {
        if (atributo2 == atributo1) {
            printf("O segundo atributo não pode ser o mesmo que o primeiro. Escolha novamente:\n");
        } else {
            printf("Entrada inválida. Escolha uma opção válida de 1 a 5:\n");
        }
        while (getchar() != '\n'); // Limpar o buffer de entrada
    }

    // ==============================
    // 4. Comparação dos Atributos e Cálculo da Soma
    // ==============================
    float valorCarta1 = 0.0, valorCarta2 = 0.0;

    // Comparação do primeiro atributo
    printf("\n===== Comparação de Atributos =====\n");
    valorCarta1 += compararAtributos(atributo1, carta1, carta2, densidade1, densidade2);
    valorCarta2 += compararAtributos(atributo2, carta1, carta2, densidade1, densidade2);

    // Exibição dos valores totais
    printf("\nSoma dos valores para a Carta 1: %.2f\n", valorCarta1);
     printf("Soma dos valores para a Carta 2: %.2f\n", valorCarta2);

    // ==============================
    // 5. Determinação do vencedor ou empate
    // ==============================
    if (valorCarta1 > valorCarta2) {
        printf("\nResultado: Carta 1 venceu!\n");
    } else if (valorCarta2 > valorCarta1) {
        printf("\nResultado: Carta 2 venceu!\n");
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
