/**
* @file global.h
 * @brief Ponto de entrada do programa para gestão de funcionários e ementas.
 *
 * @author João Ferreira
 * @email al27988@alunos.ipca.pt
 * @date Dezembro 2024
 *
 *
 * @details Projeto desenvolvido para a disciplina de Programação Imperativa.
* @brief Definição de constantes, estruturas de dados e arrays globais para o sistema de gestão de refeições.
 */


#ifndef GLOBAL_H
#define GLOBAL_H

/** @brief Tamanho máximo de strings para nomes e identificadores. */
#define MAX_NOME 50

/** @brief Número máximo de funcionários cadastrados. */
#define MAX_FUNCIONARIOS 50

/**
 * @struct Funcionarios
 * @brief Estrutura que armazena informações de um funcionário.
 */
typedef struct {
    int numero;
    char nome[MAX_NOME];
    int NIF;
    int telefone;
} Funcionarios;

/**
 * @struct Ementas
 * @brief Estrutura que armazena informações de uma ementa semanal.
 */
typedef struct {
    char dia[MAX_NOME];
    char data[MAX_NOME];
    char pratoPeixe[MAX_NOME];
    int calPeixe;
    char pratoCarne[MAX_NOME];
    int calCarne;
    char pratoDieta[MAX_NOME];
    int calDieta;
    char pratoVegetariano[MAX_NOME];
    int calVegetariano;
} Ementas;

/**
 * @struct Escolhas
 * @brief Estrutura que armazena as escolhas alimentares de um funcionário.
 */
typedef struct {
    char dia[MAX_NOME];
    int numeroFuncionario;
    char tipoPrato; // 'C' para carne, 'P' para peixe, 'D' para dieta, 'V' para vegetariano
} Escolhas;

/**
 * @brief Array global para armazenar funcionários.
 */
Funcionarios funcionario[3];

/**
 * @brief Array global para armazenar ementas.
 */
Ementas ementa[5];

/**
 * @brief Array global para armazenar escolhas alimentares.
 */
Escolhas escolha[10];

#endif