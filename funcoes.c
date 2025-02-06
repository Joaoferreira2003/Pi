/**
* @file funcoes.c
 * @brief Ponto de entrada do programa para gestão de funcionários e ementas.
 *
 * @author João Ferreira
 * @email al27988@alunos.ipca.pt
 * @date Dezembro 2024
 *
 *
 * @details Projeto desenvolvido para a disciplina de Programação Imperativa.
 * @brief Implementação das funções para manipulação de dados de funcionários, ementas e escolhas.
 */


#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Lê os dados dos funcionários a partir de um ficheiro.
 *
 * @param funcionario Array para armazenar os dados dos funcionários.
 * @return int Número de funcionários lidos.
 */
int lerFuncionarios(Funcionarios funcionario[])
{
    FILE* fp;
    int i = 0, numero, NIF, telefone;
    char nome[MAX_NOME];
    fp = fopen("funcionarios.txt","rt");  // Ler texto
    if (fp != NULL)
    {
        do {
            fscanf(fp, "%d;%20[^;];%d;%d\n", &numero, nome, &NIF, &telefone);
            funcionario[i].numero = numero;
            strcpy(funcionario[i].nome, nome);
            funcionario[i].NIF = NIF;
            funcionario[i].telefone = telefone;
            i++;
        } while ((!feof(fp) && (i < 3)));  // Fim do ficheiro  feof ==> >0
        fclose(fp);
        return(i);
    }
    else return(0);
}

/**
 * @brief Lê os dados das ementas a partir de um ficheiro.
 *
 * @param ementa Array para armazenar os dados das ementas.
 * @return int Número de ementas lidas.
 */
int lerEmentas(Ementas ementa[])
{
    FILE* fp;
    int i = 0, calPeixe, calCarne, calDieta, calVegetariano;
    char dia[MAX_NOME], data[MAX_NOME];
    char pratoPeixe[MAX_NOME], pratoCarne[MAX_NOME], pratoDieta[MAX_NOME], pratoVegetariano[MAX_NOME];
    fp = fopen("ementas.txt", "rt");  // Read Text
    if (fp != NULL)
    {
        do {
            fscanf(fp, "%20[^;];%20[^;];%20[^;];%d;%20[^;];%d;%20[^;];%d;%20[^;];%d\n",
                   dia, data, pratoPeixe, &calPeixe, pratoCarne, &calCarne, pratoDieta, &calDieta, pratoVegetariano, &calVegetariano);
            strcpy(ementa[i].dia, dia);
            strcpy(ementa[i].data, data);
            strcpy(ementa[i].pratoPeixe, pratoPeixe);
            ementa[i].calPeixe = calPeixe;
            strcpy(ementa[i].pratoCarne, pratoCarne);
            ementa[i].calCarne = calCarne;
            strcpy(ementa[i].pratoDieta, pratoDieta);
            ementa[i].calDieta = calDieta;
            strcpy(ementa[i].pratoVegetariano, pratoVegetariano);
            ementa[i].calVegetariano = calVegetariano;
            i++;
        } while ((!feof(fp) && (i < 5)));  // end of file  feof ==> >0
        fclose(fp);
        return(i);
    }
    else return(0);
}

/**
 * @brief Lê as escolhas dos utentes a partir de um ficheiro.
 *
 * @param escolha Array para armazenar as escolhas dos utentes.
 * @return int Número de escolhas lidas.
 */
int lerEscolhas(Escolhas escolha[])
{
    FILE* fp;
    int i = 0, numeroFuncionario;
    char dia[MAX_NOME], tipoPrato;
    fp = fopen("escolhas.txt", "rt");  // Read Text
    if (fp != NULL)
    {
        do {
            fscanf(fp, "%20[^;];%d;%c\n", dia, &numeroFuncionario, &tipoPrato);
            strcpy(escolha[i].dia, dia);
            escolha[i].numeroFuncionario = numeroFuncionario;
            escolha[i].tipoPrato = tipoPrato;
            i++;
        } while ((!feof(fp) && (i < 10)));  // end of file  feof ==> >0
        fclose(fp);
        return(i);
    }
    else return(0);
}

/**
 * @brief Apresenta as refeições requeridas para um dia especificado.
 *
 * @param escolha Array com as escolhas dos utentes.
 * @param ementa Array com os dados das ementas.
 * @param numEscolhas Número de escolhas registradas.
 * @param numEmentas Número de ementas registradas.
 * @param funcionario Array com os dados dos funcionários.
 * @param numFuncionarios Número de funcionários registrados.
 * @param diaRequerido Dia para o qual as refeições devem ser apresentadas.
 */
void apresentarRefeicoes(Escolhas escolha[], Ementas ementa[], int numEscolhas, int numEmentas, Funcionarios funcionario[], int numFuncionarios, const char* diaRequerido)
{
    for (int i = 0; i < numEscolhas; i++) {
        // Verifica se o dia da escolha corresponde ao dia requerido
        if (strcmp(escolha[i].dia, diaRequerido) == 0) {
            // Encontrar o funcionário correspondente
            for (int j = 0; j < numFuncionarios; j++) {
                if (funcionario[j].numero == escolha[i].numeroFuncionario) {
                    // Encontra o prato correspondente
                    char pratoEscolhido[MAX_NOME];
                    switch (escolha[i].tipoPrato) {
                        case 'C':
                            strcpy(pratoEscolhido, ementa[i].pratoCarne);
                        break;
                        case 'P':
                            strcpy(pratoEscolhido, ementa[i].pratoPeixe);
                        break;
                        case 'D':
                            strcpy(pratoEscolhido, ementa[i].pratoDieta);
                        break;
                        case 'V':
                            strcpy(pratoEscolhido, ementa[i].pratoVegetariano);
                        break;
                        default:
                            strcpy(pratoEscolhido, "Prato desconhecido");
                        break;
                    }

                    // Exibe as informações
                    printf("Funcionario: %s\n", funcionario[j].nome);
                    printf("Numero do Funcionário: %d\n", funcionario[j].numero);
                    printf("Dia: %s\n", escolha[i].dia);
                    printf("Prato escolhido: %s\n", pratoEscolhido);
                    printf("-----------------------------------\n");
                }
            }
        }
    }
}

/**
 * @brief Lista o número de refeições por funcionário ao longo da semana.
 *
 * @param funcionario Array com os dados dos funcionários.
 * @param numFuncionarios Número de funcionários registrados.
 * @param escolha Array com as escolhas dos utentes.
 * @param numEscolhas Número de escolhas registradas.
 */
void listarRefeicoesSemana(Funcionarios funcionario[], int numFuncionarios, Escolhas escolha[], int numEscolhas) {
    // Array para armazenar o número de refeições por funcionário
    int refeicoesPorFuncionario[MAX_NOME] = {0};

    // Contar o número de refeições servidas por funcionário
    for (int i = 0; i < numEscolhas; i++) {
        int numeroFuncionario = escolha[i].numeroFuncionario;
        for (int j = 0; j < numFuncionarios; j++) {
            if (funcionario[j].numero == numeroFuncionario) {
                refeicoesPorFuncionario[j]++;
            }
        }
    }

    // Estrutura para o relatório
    typedef struct {
        int numeroFuncionario;
        char nome[MAX_NOME];
        int totalRefeicoes;
        float totalDespesa;
    } Relatorio;

    Relatorio relatorio[MAX_FUNCIONARIOS];

    // Preencher o relatório
    for (int i = 0; i < numFuncionarios; i++) {
        relatorio[i].numeroFuncionario = funcionario[i].numero;
        strcpy(relatorio[i].nome, funcionario[i].nome);
        relatorio[i].totalRefeicoes = refeicoesPorFuncionario[i];
        relatorio[i].totalDespesa = refeicoesPorFuncionario[i] * 6.0;
    }

    // Ordenar por ordem decrescente do número do funcionário
    for (int i = 0; i < numFuncionarios - 1; i++) {
        for (int j = i + 1; j < numFuncionarios; j++) {
            if (relatorio[i].numeroFuncionario < relatorio[j].numeroFuncionario) {
                Relatorio temp = relatorio[i];
                relatorio[i] = relatorio[j];
                relatorio[j] = temp;
            }
        }
    }

    // Exibir o relatório
    printf("\nRelatorio Semanal de Refeicoes e Despesas\n");
    printf("------------------------------------------\n");
    printf("Funcionario | Nome               | Refeicoes | Despesa (EUR)\n");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < numFuncionarios; i++) {
        if (relatorio[i].totalRefeicoes > 0) {  // Exibe apenas funcionários que fizeram refeições
            printf("%-11d | %-18s | %-9d | %.2f\n",
                   relatorio[i].numeroFuncionario,
                   relatorio[i].nome,
                   relatorio[i].totalRefeicoes,
                   relatorio[i].totalDespesa);
        }
    }
}

/**
 * @brief Lista as refeições de um determinado funcionário ao longo de um período.
 *
 * Esta função exibe as refeições consumidas por um funcionário em um período específico,
 * incluindo o número de calorias consumidas em cada refeição.
 *
 * @param funcionario Array com os dados dos funcionários.
 * @param numFuncionarios Número de funcionários cadastrados.
 * @param escolha Array com as escolhas dos utentes.
 * @param numEscolhas Número de escolhas registradas.
 * @param ementa Array com as ementas disponíveis.
 * @param numEmentas Número de ementas cadastradas.
 * @param numeroFuncionario Número do funcionário cujas refeições serão listadas.
 * @param diaInicio Dia de início do período.
 * @param diaFim Dia de fim do período.
 */
void listarRefeicoesUtente(Funcionarios funcionario[], int numFuncionarios,
                           Escolhas escolha[], int numEscolhas,
                           Ementas ementa[], int numEmentas,
                           int numeroFuncionario, const char* diaInicio, const char* diaFim) {
    int caloriasTotais = 0;

    printf("\nRefeições do Funcionário %d:\n", numeroFuncionario);
    printf("------------------------------------------\n");

    for (int i = 0; i < numEscolhas; i++) {
        if (escolha[i].numeroFuncionario == numeroFuncionario) {
            // Verifica se o dia da escolha está no período especificado
            if (strcmp(escolha[i].dia, diaInicio) >= 0 && strcmp(escolha[i].dia, diaFim) <= 0) {
                // Localizar a ementa correspondente
                for (int j = 0; j < numEmentas; j++) {
                    if (strcmp(escolha[i].dia, ementa[j].dia) == 0) {
                        char pratoEscolhido[MAX_NOME];
                        int calorias = 0;

                        switch (escolha[i].tipoPrato) {
                            case 'C':
                                strcpy(pratoEscolhido, ementa[j].pratoCarne);
                                calorias = ementa[j].calCarne;
                                break;
                            case 'P':
                                strcpy(pratoEscolhido, ementa[j].pratoPeixe);
                                calorias = ementa[j].calPeixe;
                                break;
                            case 'D':
                                strcpy(pratoEscolhido, ementa[j].pratoDieta);
                                calorias = ementa[j].calDieta;
                                break;
                            case 'V':
                                strcpy(pratoEscolhido, ementa[j].pratoVegetariano);
                                calorias = ementa[j].calVegetariano;
                                break;
                            default:
                                strcpy(pratoEscolhido, "Prato desconhecido");
                                calorias = 0;
                                break;
                        }

                        caloriasTotais += calorias;

                        // Exibir informações
                        printf("Dia: %s\n", ementa[j].dia);
                        printf("Prato: %s\n", pratoEscolhido);
                        printf("Calorias: %d\n", calorias);
                        printf("------------------------------------------\n");
                    }
                }
            }
        }
    }

    printf("Calorias Totais Consumidas no Período: %d\n", caloriasTotais);
}

/**
 * @brief Calcula a média de calorias consumidas por dia da semana em um período especificado.
 *
 * Esta função percorre as escolhas registradas e calcula a média de calorias
 * consumidas em cada dia da semana.
 *
 * @param escolha Array com as escolhas dos utentes.
 * @param numEscolhas Número de escolhas registradas.
 * @param ementa Array com as ementas disponíveis.
 * @param numEmentas Número de ementas cadastradas.
 * @param diaInicio Dia de início do período.
 * @param diaFim Dia de fim do período.
 */
void calcularMediaCaloriasPorDia(Escolhas escolha[], int numEscolhas,
                                 Ementas ementa[], int numEmentas,
                                 const char* diaInicio, const char* diaFim) {
    int totalCalorias[7] = {0};
    int contadorRefeicoes[7] = {0};
    const char* diasSemana[] = {"2feira", "3feira", "4feira", "5feira", "6feira", "Sabado", "Domingo"};

    for (int i = 0; i < numEscolhas; i++) {
        // Verifica se o dia da escolha está no período especificado
        if (strcmp(escolha[i].dia, diaInicio) >= 0 && strcmp(escolha[i].dia, diaFim) <= 0) {
            // Localizar a ementa correspondente
            for (int j = 0; j < numEmentas; j++) {
                if (strcmp(escolha[i].dia, ementa[j].dia) == 0) {
                    int calorias = 0;

                    // Determina as calorias com base no tipo de prato
                    switch (escolha[i].tipoPrato) {
                        case 'C':
                            calorias = ementa[j].calCarne;
                            break;
                        case 'P':
                            calorias = ementa[j].calPeixe;
                            break;
                        case 'D':
                            calorias = ementa[j].calDieta;
                            break;
                        case 'V':
                            calorias = ementa[j].calVegetariano;
                            break;
                        default:
                            calorias = 0;
                            break;
                    }

                    // Identificar o índice do dia da semana
                    for (int k = 0; k < 7; k++) {
                        if (strcmp(escolha[i].dia, diasSemana[k]) == 0) {
                            totalCalorias[k] += calorias;
                            contadorRefeicoes[k]++;
                        }
                    }
                }
            }
        }
    }

    // Calcular e exibir médias
    printf("\nMedias de Calorias por Dia da Semana:\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < 7; i++) {
        if (contadorRefeicoes[i] > 0) {
            double media = (double)totalCalorias[i] / contadorRefeicoes[i];
            printf("%s: Media de %.2f calorias (%d refeicoes)\n",
                   diasSemana[i], media, contadorRefeicoes[i]);
        } else {
            printf("%s: Nenhuma refeicao registrada\n", diasSemana[i]);
        }
    }
}

/**
 * @brief Gera uma tabela semanal de ementas para um funcionário.
 *
 * Esta função exibe as ementas consumidas por um funcionário durante uma semana,
 * listando os pratos e as calorias correspondentes para cada dia útil.
 *
 * @param escolha Array com as escolhas dos utentes.
 * @param numEscolhas Número de escolhas registradas.
 * @param ementa Array com as ementas disponíveis.
 * @param numEmentas Número de ementas cadastradas.
 * @param funcionario Array com os dados dos funcionários.
 * @param numFuncionarios Número de funcionários cadastrados.
 * @param numeroFuncionario Número do funcionário a ser considerado.
 */
void gerarTabelaEmentaSemanal(Escolhas escolha[], int numEscolhas,
                              Ementas ementa[], int numEmentas,
                              Funcionarios funcionario[], int numFuncionarios, int numeroFuncionario) {
    printf("Tabela de Ementa Semanal para o Funcionario %d\n", numeroFuncionario);
    printf("-------------------------------------------------------------------------------------\n");
    printf("| Dia Semana | Prato Peixe      | Calorias | Prato Carne      | Calorias | Prato Dieta      | Calorias | Prato Vegetariano | Calorias |\n");
    printf("-------------------------------------------------------------------------------------\n");

    const char* diasSemana[] = {"2feira", "3feira", "4feira", "5feira", "6feira"};

    for (int i = 0; i < 5; i++) {  // Itera pelos dias da semana de 2ª a 6ª feira
        printf("| %-10s", diasSemana[i]);

        int encontrouEscolha = 0;

        for (int j = 0; j < numEscolhas; j++) {
            if (escolha[j].numeroFuncionario == numeroFuncionario && strcmp(escolha[j].dia, diasSemana[i]) == 0) {
                encontrouEscolha = 1;

                for (int k = 0; k < numEmentas; k++) {
                    if (strcmp(escolha[j].dia, ementa[k].dia) == 0) {
                        printf("| %-15s | %-8d", ementa[k].pratoPeixe, ementa[k].calPeixe);
                        printf("| %-15s | %-8d", ementa[k].pratoCarne, ementa[k].calCarne);
                        printf("| %-15s | %-8d", ementa[k].pratoDieta, ementa[k].calDieta);
                        printf("| %-15s | %-8d |\n", ementa[k].pratoVegetariano, ementa[k].calVegetariano);
                        break;
                    }
                }
                break;
            }
        }

        if (!encontrouEscolha) {  // Caso o funcionário não tenha feito escolha no dia
            printf("| %-15s | %-8s | %-15s | %-8s | %-15s | %-8s | %-15s | %-8s |\n",
                   "-", "-", "-", "-", "-", "-", "-", "-");
        }
    }

    printf("-------------------------------------------------------------------------------------\n");
}
