/**
* @file menu.c
 * @brief Ponto de entrada do programa para gestão de funcionários e ementas.
 *
 * @author João Ferreira
 * @email al27988@alunos.ipca.pt
 * @date Dezembro 2024
 *
 *
 * @details Projeto desenvolvido para a disciplina de Programação Imperativa.
 * @brief Implementação do menu principal para gestão de funcionários, ementas e escolhas..
 */

#include "funcoes.h"
#include "menu.h"
#include <stdio.h>

/**
 * @brief Exibe o menu principal e processa as opções escolhidas pelo usuário.
 *
 * Esta função apresenta um menu interativo ao usuário, permitindo a visualização
 * de dados de funcionários, ementas e escolhas, além de cálculos estatísticos.
 *
 * @param funcionario Array de funcionários.
 * @param numFuncionarios Número de funcionários registrados.
 * @param ementa Array de ementas disponíveis.
 * @param numEmentas Número de ementas registradas.
 * @param escolha Array de escolhas realizadas.
 * @param numEscolhas Número de escolhas registradas.
 */
void menu(Funcionarios funcionario[], int numFuncionarios, Ementas ementa[], int numEmentas, Escolhas escolha[], int numEscolhas) {
    int opcao;
    do {
        printf("\n========== MENU PRINCIPAL ==========\n");
        printf("1. Apresentar dados dos funcionarios\n");
        printf("2. Apresentar informacao da ementa semanal\n");
        printf("3. Apresentar as escolhas para a semana dos utentes\n");
        printf("4. Apresentar refeicoes requeridas para um dado dia\n");
        printf("5. Listar utentes com numero de refeicoes e despesa semanal\n");
        printf("6. Listar refeicoes e calorias de um utente ao longo de um periodo\n");
        printf("7. Calcular medias de calorias consumidas por refeicao por dia\n");
        printf("8. Gerar tabela de ementa semanal de um utente\n");
        printf("9. Sair\n");
        printf("====================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n========== DADOS DOS FUNCIONARIOS ==========\n");
                for (int i = 0; i < numFuncionarios; i++) {
                    printf("Funcionario %d:\n", i + 1);
                    printf("Numero: %d\n", funcionario[i].numero);
                    printf("Nome: %s\n", funcionario[i].nome);
                    printf("NIF: %d\n", funcionario[i].NIF);
                    printf("Telefone: %d\n", funcionario[i].telefone);
                    printf("------------------------------------\n");
                }
                break;

            case 2:
                printf("\n========== EMENTA SEMANAL ==========\n");
                for (int i = 0; i < numEmentas; i++) {
                    printf("Dia: %s\n", ementa[i].dia);
                    printf("Prato Peixe: %s (Calorias: %d)\n", ementa[i].pratoPeixe, ementa[i].calPeixe);
                    printf("Prato Carne: %s (Calorias: %d)\n", ementa[i].pratoCarne, ementa[i].calCarne);
                    printf("Prato Dieta: %s (Calorias: %d)\n", ementa[i].pratoDieta, ementa[i].calDieta);
                    printf("Prato Vegetariano: %s (Calorias: %d)\n", ementa[i].pratoVegetariano, ementa[i].calVegetariano);
                    printf("------------------------------------\n");
                }
                break;

            case 3:
                printf("\n========== ESCOLHAS DOS UTENTES ==========\n");
                for (int i = 0; i < numEscolhas; i++) {
                    printf("Dia: %s\n", escolha[i].dia);
                    printf("Numero do Funcionario: %d\n", escolha[i].numeroFuncionario);
                    printf("Tipo de Prato: %c\n", escolha[i].tipoPrato);
                    printf("------------------------------------\n");
                }
                break;

            case 4: {
                char dia[50];
                printf("\nDigite o dia para conferencia (Ex: 2feira): ");
                scanf("%s", dia);
                apresentarRefeicoes(escolha, ementa, numEscolhas, numEmentas, funcionario, numFuncionarios, dia);
                break;
            }

            case 5:
                printf("\n========== LISTAGEM DE UTENTES E DESPESA ==========\n");
                listarRefeicoesSemana(funcionario, numFuncionarios, escolha, numEscolhas);
                break;

            case 6: {
                int numeroFuncionario;
                char diaInicio[50], diaFim[50];
                printf("\nDigite o numero do funcionario: ");
                scanf("%d", &numeroFuncionario);
                printf("Digite o dia de início (Ex: 2feira): ");
                scanf("%s", diaInicio);
                printf("Digite o dia de fim (Ex: 6feira): ");
                scanf("%s", diaFim);
                listarRefeicoesUtente(funcionario, numFuncionarios, escolha, numEscolhas, ementa, numEmentas, numeroFuncionario, diaInicio, diaFim);
                break;
            }

            case 7: {
                char diaInicio[50], diaFim[50];
                printf("\nDigite o dia de início (Ex: 2feira): ");
                scanf("%s", diaInicio);
                printf("Digite o dia de fim (Ex: 6feira): ");
                scanf("%s", diaFim);
                calcularMediaCaloriasPorDia(escolha, numEscolhas, ementa, numEmentas, diaInicio, diaFim);
                break;
            }

            case 8: {
                int numeroFuncionario;
                printf("\nDigite o número do funcionário: ");
                scanf("%d", &numeroFuncionario);
                gerarTabelaEmentaSemanal(escolha, numEscolhas, ementa, numEmentas, funcionario, numFuncionarios, numeroFuncionario);
                break;
            }

            case 9:
                printf("\nA sair do programa...\n");
                break;

            default:
                printf("\nOpção invalida! Tente novamente.\n");
                break;
        }
    } while (opcao != 9);
}