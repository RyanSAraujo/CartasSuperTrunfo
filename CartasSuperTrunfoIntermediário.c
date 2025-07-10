#include <stdio.h>

// Estrutura que representa uma carta do Super Trunfo de cidades brasileiras
struct Carta {
    char estado[3];             // Sigla do estado (ex: "SP")
     char codigo[10];            // Código identificador da carta
      char nomeCidade[50];        // Nome da cidade
       int populacao;              // População da cidade
      float area;                 // Área em km²
     float pib;                  // PIB em reais
    int numPontosTuristicos;    // Quantidade de pontos turísticos
};

int main() {
    // ====================================
    // Cadastro das cartas (exemplos fixos)
    // ====================================

    struct Carta carta1 = {
        "SP", "SP001", "São Paulo",
        12300000,
        1521.11,
        230000000000.0,
        150
    };

    struct Carta carta2 = {
        "RJ", "RJ002", "Rio de Janeiro",
        6748000,
        1182.30,
        160000000000.0,
        120
    };

    // ================================
    // Cálculo dos indicadores derivados
    // ================================

    float densidade1 = carta1.populacao / carta1.area;
      float densidade2 = carta2.populacao / carta2.area;

    float pibPerCapita1 = carta1.pib / carta1.populacao;
      float pibPerCapita2 = carta2.pib / carta2.populacao;

    int escolha;

    while (1) {
        // ============================
        // Menu interativo com o jogador
        // ============================

        printf("\n======= SUPER TRUNFO - CIDADES BRASILEIRAS =======\n");
         printf("Escolha um atributo para comparar:\n");
          printf("1. Nome da Cidade\n");
           printf("2. População\n");
            printf("3. Área\n");
           printf("4. PIB\n");
          printf("5. Pontos Turísticos\n");
         printf("6. Densidade Demográfica\n");
        printf("Digite sua escolha (1-6): ");

        if (scanf("%d", &escolha) != 1) {
            printf("Entrada inválida. Digite um número de 1 a 6.\n");
            while (getchar() != '\n'); // limpa o buffer
            continue;
        }

        printf("\n Comparando:\n");

        switch (escolha) {
            case 1:
                printf("Nome das Cidades:\n");
                 printf("- %s (%s)\n", carta1.nomeCidade, carta1.estado);
                 printf("- %s (%s)\n", carta2.nomeCidade, carta2.estado);
                printf(" Resultado: Sem comparação, apenas exibição.\n");
                break;

            case 2:
                printf("👥 População:\n");
                 printf("- %s: %d habitantes\n", carta1.nomeCidade, carta1.populacao);
                printf("- %s: %d habitantes\n", carta2.nomeCidade, carta2.populacao);

                if (carta1.populacao > carta2.populacao)
                    printf(" Vitória de %s!\n", carta1.nomeCidade);
                else if (carta2.populacao > carta1.populacao)
                    printf(" Vitória de %s!\n", carta2.nomeCidade);
                else
                    printf(" Empate técnico!\n");
                break;

            case 3:
                printf(" Área territorial:\n");
                 printf("- %s: %.2f km²\n", carta1.nomeCidade, carta1.area);
                printf("- %s: %.2f km²\n", carta2.nomeCidade, carta2.area);

                if (carta1.area > carta2.area)
                    printf(" Vitória de %s!\n", carta1.nomeCidade);
                else if (carta2.area > carta1.area)
                    printf(" Vitória de %s!\n", carta2.nomeCidade);
                else
                    printf(" Empate técnico!\n");
                break;

            case 4:
                printf(" PIB:\n");
                 printf("- %s: R$ %.2f\n", carta1.nomeCidade, carta1.pib);
                printf("- %s: R$ %.2f\n", carta2.nomeCidade, carta2.pib);

                if (carta1.pib > carta2.pib)
                    printf(" Vitória de %s!\n", carta1.nomeCidade);
                else if (carta2.pib > carta1.pib)
                    printf(" Vitória de %s!\n", carta2.nomeCidade);
                else
                    printf(" Empate técnico!\n");
                break;

            case 5:
                printf(" Pontos Turísticos:\n");
                 printf("- %s: %d locais\n", carta1.nomeCidade, carta1.numPontosTuristicos);
                printf("- %s: %d locais\n", carta2.nomeCidade, carta2.numPontosTuristicos);

                if (carta1.numPontosTuristicos > carta2.numPontosTuristicos)
                    printf(" Vitória de %s!\n", carta1.nomeCidade);
                else if (carta2.numPontosTuristicos > carta1.numPontosTuristicos)
                    printf(" Vitória de %s!\n", carta2.nomeCidade);
                else
                    printf(" Empate técnico!\n");
                break;

            case 6:
                printf("Densidade Demográfica:\n");
                 printf("- %s: %.2f hab/km²\n", carta1.nomeCidade, densidade1);
                printf("- %s: %.2f hab/km²\n", carta2.nomeCidade, densidade2);

                if (densidade1 > densidade2)
                    printf(" Vitória de %s!\n", carta1.nomeCidade);
                else if (densidade2 > densidade1)
                    printf(" Vitória de %s!\n", carta2.nomeCidade);
                else
                    printf(" Empate técnico!\n");
                break;

            default:
                printf(" Opção inválida! Tente novamente com um número de 1 a 6.\n");
                break;
        }
    }

    return 0;
}
