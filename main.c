#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define QTD 3
#define TAM_NOME 100

typedef struct {
    char nome[TAM_NOME + 1];
    double preco_anterior;
    double preco_atual;
    double variacao;           // em %
    char situacao[16];         // "AUMENTO", "QUEDA", "ESTÁVEL"
    char observacao[32];       // "Aumento abusivo", "Limite de aumento", "Redução de preço" ou ""
} Produto;

/* Remove \n do final de uma string lida por fgets */
void tira_newline(char *s) {
    size_t n = strlen(s);
    if (n > 0 && s[n-1] == '\n') s[n-1] = '\0';
}

/* Converte string para double aceitando vírgula como separador decimal */
double parse_double_br(const char *s) {
    char buf[128];
    size_t i, j = 0;
    for (i = 0; s[i] != '\0' && j < sizeof(buf)-1; i++) {
        buf[j++] = (s[i] == ',') ? '.' : s[i];
    }
    buf[j] = '\0';
    return strtod(buf, NULL);
}

int main(void) {
    Produto p[QTD];
    char linha[128];

    printf("=== Monitor de Precos - Cesta Basica ===\n");
    printf("Digite os precos com ponto ou virgula (ex.: 22.50 ou 22,50)\n\n");

    for (int i = 0; i < QTD; i++) {
        printf("Produto %d - nome: ", i + 1);
        if (!fgets(p[i].nome, sizeof(p[i].nome), stdin)) return 1;
        tira_newline(p[i].nome);

        printf("Preco no mes anterior (R$): ");
        if (!fgets(linha, sizeof(linha), stdin)) return 1;
        p[i].preco_anterior = parse_double_br(linha);

        printf("Preco no mes atual (R$): ");
        if (!fgets(linha, sizeof(linha), stdin)) return 1;
        p[i].preco_atual = parse_double_br(linha);

        // Cálculo da variacao (%)
        if (p[i].preco_anterior == 0.0) {
            // Evita divisao por zero; decide regra pedagógica:
            // Aqui consideramos variacao 0 e marcamos observacao.
            p[i].variacao = 0.0;
            strcpy(p[i].situacao, "ESTÁVEL");
            strcpy(p[i].observacao, "Preco anterior zero");
        } else {
            p[i].variacao = ((p[i].preco_atual - p[i].preco_anterior) / p[i].preco_anterior) * 100.0;

            // Classificação principal
            if (p[i].variacao > 0.0) {
                strcpy(p[i].situacao, "AUMENTO");
            } else if (p[i].variacao < 0.0) {
                strcpy(p[i].situacao, "QUEDA");
            } else {
                strcpy(p[i].situacao, "ESTÁVEL");
            }

            // Observações adicionais
            if (p[i].variacao > 10.0) {
                strcpy(p[i].observacao, "Aumento abusivo");
            } else if (p[i].variacao == 10.0) {
                strcpy(p[i].observacao, "Limite de aumento");
            } else if (p[i].variacao < 0.0) {
                strcpy(p[i].observacao, "Reducao de preco");
            } else {
                p[i].observacao[0] = '\0'; // sem observacao extra
            }
        }

        printf("\n");
    }

    // Saída (resumo)
    printf("\n==== RESUMO DA ANALISE ====\n");
    for (int i = 0; i < QTD; i++) {
        printf("Produto: %s\n", p[i].nome);
        printf("Preco anterior: R$ %.2f\n", p[i].preco_anterior);
        printf("Preco atual:    R$ %.2f\n", p[i].preco_atual);
        printf("Variacao: %.1f%%\n", p[i].variacao);
        if (p[i].observacao[0] != '\0') {
            printf("Situacao: %s - %s\n", p[i].situacao, p[i].observacao);
        } else {
            printf("Situacao: %s\n", p[i].situacao);
        }
        printf("---------------------------\n");
    }

    return 0;
}
