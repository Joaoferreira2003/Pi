/**
* @file funcoes.h
 * @brief Ponto de entrada do programa para gestão de funcionários e ementas.
 *
 * @author João Ferreira
 * @email al27988@alunos.ipca.pt
 * @date Dezembro 2024
 *
 *
 * @details Projeto desenvolvido para a disciplina de Programação Imperativa.
 * @brief Declaração das funções para manipulação de dados de funcionários, ementas e escolhas.
 */


#ifndef FUNCOES_H
#define FUNCOES_H

#include "global.h"

// Declaração das funções em funcoes.c
int lerFuncionarios(Funcionarios funcionario[]);
int lerEmentas(Ementas ementa[]);
int lerEscolhas(Escolhas escolha[]);

void apresentarRefeicoes(Escolhas escolha[], Ementas ementa[], int numEscolhas, int numEmentas, Funcionarios funcionario[], int numFuncionarios, const char* diaRequerido);
void listarRefeicoesSemana(Funcionarios funcionario[], int numFuncionarios, Escolhas escolha[], int numEscolhas);
void listarRefeicoesUtente(Funcionarios funcionario[], int numFuncionarios, Escolhas escolha[], int numEscolhas, Ementas ementa[], int numEmentas, int numeroFuncionario, const char* diaInicio, const char* diaFim);
void calcularMediaCaloriasPorDia(Escolhas escolha[], int numEscolhas, Ementas ementa[], int numEmentas, const char* diaInicio, const char* diaFim);
void gerarTabelaEmentaSemanal(Escolhas escolha[], int numEscolhas, Ementas ementa[], int numEmentas, Funcionarios funcionario[], int numFuncionarios, int numeroFuncionario);

#endif
