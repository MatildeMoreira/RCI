/***********************************************************************
 * Projecto: Peer-to-Peer Stream Delivery Network
 *
 * Disciplina: Redes de Computadores e Internet
 * 2o Semestre 2018/2019
 *
 * Realizado por:
 * 				Matilde Moreira, nº 84137
 * 				Francisco Branco,nº 84047
 *
 * Turno de Laboratório: 2a feira, 8h00-10h00
 *
 * Última data modificação: 02/03/2019
 * Nome do Ficheiro: main.c
 **********************************************************************/

/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "util.h"



/***********************************************************************
 * main ()
 *
 * Argumentos: argc - numero de argumentos da linha de comandos
 * 	           argv - tabela de ponteiros para argumentos do tipo string
 * Retorno: int
 *
 * Descrição: Programa Principal
 *
 **********************************************************************/

int main (int argc, char *argv[])
{

	/*Funcao que analisa os parametros de arranque da aplicacao iamroot*/
	leitura_argumentos(argc,argv);

  return 0;
}
