/**
* @file main.c
 * @brief Ponto de entrada do programa para gestão de funcionários e ementas.
 *
 * @author João Ferreira
 * @email al27988@alunos.ipca.pt
 * @date Dezembro 2024
 *
 *
 * @details Projeto desenvolvido para a disciplina de Programação Imperativa.
 * Este programa permite a gestão de funcionários, ementas e escolhas alimentares .
 */

#include <stdio.h>
#include "funcoes.c"
#include "menu.c"

// Função para exibir ajuda
void exibirAjuda() {
    printf("\n=== AJUDA DO PROGRAMA ===\n");
    printf("Uso: ./prog [opcoes]\n");
    printf("Opções disponíveis:\n");
    printf("  -ajuda Exibe esta mensagem de ajuda.\n");
    printf("  -tab <funcionarios.csv> <ementas.csv> <escolhas.csv>  Lê ficheiros delimitados por ponto e vírgula.\n");
    printf("  -bin Lê os ficheiros binários de dados.\n");
    printf("(Sem opções)  O programa lê ficheiros de texto padrão.\n");
    printf("========================\n");
}

void gravarFuncionariosBin(Funcionarios funcionario[], int numFuncionarios) {
    FILE *fp = fopen("funcionarios.bin", "wb");
    if (fp) {
        fwrite(funcionario, sizeof(Funcionarios), numFuncionarios, fp);
        fclose(fp);
    }
}

void gravarEmentasBin(Ementas ementa[], int numEmentas) {
    FILE *fp = fopen("ementas.bin", "wb");
    if (fp) {
        fwrite(ementa, sizeof(Ementas), numEmentas, fp);
        fclose(fp);
    }
}

void gravarEscolhasBin(Escolhas escolha[], int numEscolhas) {
    FILE *fp = fopen("escolhas.bin", "wb");
    if (fp) {
        fwrite(escolha, sizeof(Escolhas), numEscolhas, fp);
        fclose(fp);
    }
}

int lerFuncionariosBin(Funcionarios funcionario[]) {
    FILE *fp = fopen("funcionarios.bin", "rb");
    if (fp) {
        int numLidos = fread(funcionario, sizeof(Funcionarios), MAX_FUNCIONARIOS, fp);
        fclose(fp);
        return numLidos;
    }
    return 0;
}

int lerEmentasBin(Ementas ementa[]) {
    FILE *fp = fopen("ementas.bin", "rb");
    if (fp) {
        int numLidos = fread(ementa, sizeof(Ementas), 5, fp);
        fclose(fp);
        return numLidos;
    }
    return 0;
}

int lerEscolhasBin(Escolhas escolha[]) {
    FILE *fp = fopen("escolhas.bin", "rb");
    if (fp) {
        int numLidos = fread(escolha, sizeof(Escolhas), 10, fp);
        fclose(fp);
        return numLidos;
    }
    return 0;
}

int lerFuncionariosTab(Funcionarios funcionario[], const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp) {
        int i = 0;
        while (fscanf(fp, "%d;%49[^;];%d;%d\n",
                      &funcionario[i].numero,
                      funcionario[i].nome,
                      &funcionario[i].NIF,
                      &funcionario[i].telefone) == 4) {
            i++;
        }
        fclose(fp);
        return i;
    }
    return 0;
}

int lerEmentasTab(Ementas ementa[], const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp) {
        int i = 0;
        while (fscanf(fp, "%49[^;];%49[^;];%49[^;];%d;%49[^;];%d;%49[^;];%d;%49[^;];%d\n",
                      ementa[i].dia, ementa[i].data,
                      ementa[i].pratoPeixe, &ementa[i].calPeixe,
                      ementa[i].pratoCarne, &ementa[i].calCarne,
                      ementa[i].pratoDieta, &ementa[i].calDieta,
                      ementa[i].pratoVegetariano, &ementa[i].calVegetariano) == 9) {
            i++;
        }
        fclose(fp);
        return i;
    }
    return 0;
}

int lerEscolhasTab(Escolhas escolha[], const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp) {
        int i = 0;
        while (fscanf(fp, "%49[^;];%d;%c\n",
                      escolha[i].dia,
                      &escolha[i].numeroFuncionario,
                      &escolha[i].tipoPrato) == 3) {
            i++;
        }
        fclose(fp);
        return i;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int numFuncionarios = 0, numEmentas = 0, numEscolhas = 0;

    if (argc == 2 && strcmp(argv[1], "-ajuda") == 0) {
        exibirAjuda();
        return 0;
    }
    else if (argc == 2 && strcmp(argv[1], "-bin") == 0) {
        numFuncionarios = lerFuncionariosBin(funcionario);
        numEmentas = lerEmentasBin(ementa);
        numEscolhas = lerEscolhasBin(escolha);
    }
    else if (argc == 5 && strcmp(argv[1], "-tab") == 0) {
        numFuncionarios = lerFuncionariosTab(funcionario, argv[2]);
        numEmentas = lerEmentasTab(ementa, argv[3]);
        numEscolhas = lerEscolhasTab(escolha, argv[4]);
    }
    else {
        numFuncionarios = lerFuncionarios(funcionario);
        numEmentas = lerEmentas(ementa);
        numEscolhas = lerEscolhas(escolha);
    }

    //gravarFuncionariosBin(funcionario, numFuncionarios);
    //gravarEmentasBin(ementa, numEmentas);
    //gravarEscolhasBin(escolha, numEscolhas);

    // Chama o menu original do teu código
    menu(funcionario, numFuncionarios, ementa, numEmentas, escolha, numEscolhas);
    return 0;
}

// Funções para manipulação de ficheiros binários e CSV com ;



/**
 * @brief Função principal para inicializar e gerir o sistema de menus.
 *
 * Lê dados dos ficheiros e invoca o menu para interação com o usuário.
 *
 * @return int Estado de saída.
 */
