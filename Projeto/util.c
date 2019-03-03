/*******************************************************************************
* Nome do ficheiro : util.c
*
* Autores: Matilde Moreira, nº84137
           Francisco Branco,
*
* Ultima modificação: 03-03-2019
*
* Comentários:
*           Funções auxiliares para interface do utilizador
*******************************************************************************/

#include "util.h"


/*******************************************************************************
 * leitura_argumentos(int argc, char *argv[])
 *
 * Parametros de Entrada: argv [] , argc
 * Parametros de Saida : void
 * Descricao: Leitura de argumentos da linha de comandos associada à invocação
 *            da aplicação
 ******************************************************************************/
 void leitura_argumentos(int argc, char *argv[])
 {
   int n=0,j=0;
   long flag_int;
   char stream[SIZE], ipfonte[SIZE], ipaddr[SIZE], rsaddr[SIZE];
   int portofonte=0,tport=58000,uport=58000,rsport=59000,tcpsessions=1,bestpops=1,tsecs=5;
   char Flag[SIZE];

   if ( argc < 4){
     printf("Erro: Faltam Parametros\n");
     exit(1);
   }
   
   if (sscanf(argv[1],"%[^:]:%[^:]:%d" ,stream,ipfonte,&portofonte) !=3){
		printf("Erro =  Stream não especificada\n");
		/* adicionar funcao que imprime a lista de streams registadas no servidor de raízes */
		exit(1);
   }
   printf("Tamanho de caracteres do <streamID>= %ld\n",strlen(argv[1]));
   if(strlen(argv[1]) > 63){
     printf("Excede o numero maximo de caracteres(63)\n");
     exit(1);
   }
   printf("Stream = %s\n",stream);
   printf("Ipfonte= %s\n",ipfonte);
   printf("portofonte= %d\n",portofonte);

   for(j=2; j+1<argc;j++){
	   n = sscanf(argv[j],"-%s",Flag);
	   printf("Flag= %s | ",Flag);
       if (n != 1){
		   printf("Erro: Falta a Flag\n");
		   exit(1);
	   }
	   /*lagchar= Flag[0];
	   printf("Flagchar = %c\n",flagchar);*/
	   flag_int=(int)Flag[0];
       printf("Flag_int=%ld\n",flag_int);
       j++;
       switch (flag_int){
		   case 'i':
           if ( sscanf(argv[j],"%s",ipaddr) != 1 ){
           printf("Erro: Falta o IP da interface\n");
           exit(1);
          }
          break;
       case 't':
          if (sscanf(argv[j],"%d",&tport) != 1){
            printf("Erro: Falta o porto TCP onde a aplicacao aceita sessoes de outros pares a jusante\n");
            exit(1);
          }
          break;
       case 'u':
          if (sscanf(argv[j],"%d",&uport) != 1){
            printf("Erro: Falta o porto UDP do servidor de acesso\n");
            exit(1);
          }
          break;
       case 's':
          if (sscanf(argv[j],"%s:%d",rsaddr,&rsport)!= 2){
            if (sscanf(argv[j],"%s",rsaddr)!= 1){
              printf("Erro: Falta o endereço IP do seridor de raizes \n");
              exit(1);
            }
          }
          break;
       case 'p':
          if (sscanf(argv[j],"%d",&tcpsessions) != 1){
            printf("Erro: Falta o numero de sessoes tcp\n");
            exit(1);
          }
          if (tcpsessions < 1){
            printf("Numero de sessoes tem de ser superior ou igual a 1\n");
            exit(1);
          }
          break;
       case 'n':
          if (sscanf(argv[j],"%d",&bestpops) != 1){
            printf("Erro: Falta o numero de pontos de acesso a recolher por esta instancia da aplicacao, quando raiz, durante a descoberta de pontos de acesso\n");
            exit(1);
          }
          if (bestpops < 1){
              printf("Numero de pontos de acesso tem de ser superior ou igual a 1\n");
            exit(1);
          }
          break;
       case 'x':
          if ( sscanf(argv[j],"%d",&tsecs) != 1){
            printf("Erro: Falta o periodo , em seg, associado ao registo periodico que a raiz deve fazer no servidor de raizes ");
            exit(1);
          }
          if (tsecs < 0){
            printf("Periodo em segundo tem de ser maior ou igual a 0\n");
            exit(1);
          }
          break;
       case 'b':
          break;
       case 'd':
          break;
       case 'h':
          break;
       default:
          printf("Flag invalida!!\n");
          exit(1);
          break;
     }
   }

   printf("StreamID= %s:%s:%d \n IPAddr= %s\nRsAddr=%s\n tport=%d | uport=%d | rsport=%d |tcpsessions=%d |bestpops=%d |tsecs=%d\n",stream,ipfonte,portofonte,ipaddr,rsaddr,tport,uport,rsport,tcpsessions,bestpops,tsecs);

 }
