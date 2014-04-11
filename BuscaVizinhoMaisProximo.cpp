/*  Algoritmo de busca em um grafo, buscando pelo vizinho mais proximo   */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <locale.h>
    
     
 
 int main()
 {
    FILE *fp;
   
    int i=0,j=0,a=0,b=0,c=0,x=0;
    int inicial=0;
    int noDeMenorCusto=0;
    int noAtual=0;
    int achoufinal = 0 ;
    int menorcusto = 99999;
    int menorcaminho[10];
    int final;
    int qtd;
    int matriz[10][10];
    int noAnterior=0;
    
    
    	
  
    fp = fopen ("C:\\es.txt", "r");
    if (fp == NULL) {
       printf ("Houve um erro ao abrir o arquivo.\n");
       return 1;
    }
    printf ("Arquivo de busca lido com sucesso.\n");
    
	fscanf(fp,"%d",&inicial);
	fscanf(fp,"%d",&final);
	fscanf(fp,"%d",&qtd);
	
	for(i=0;i<10;i++){     // for para colocar 0 em todo o vetor.
			menorcaminho[i]=0;
        }
    
 	
 	for(i=0;i<10;i++){     // for para preencher a matriz com 0
            for(x=0;x<10;x++){
         	   matriz[i][x]=0;
		 }
	}
   
	for(i=0;i<qtd;i++){    // for para ler as liga��es dos n�s e seus determinados custos
			fscanf(fp,"%d%d%d",&a,&b,&c);
			matriz[a][b]=c;
        }
        
     for(i=0;i<10;i++){     //   for para imprimir a matriz
         for(x=0;x<10;x++){
         	    if (matriz[i][x] > 0)
	            printf("\nmatrix[%d][%d] == %d",i,x,matriz[i][x]);
		 }
	}
		 printf("\n\n"); 
		 
     noAtual=inicial;
     noDeMenorCusto = 0;
     menorcaminho[0]=inicial;
     for(i=0;i<10;i++){
	   
	   if(noAtual != final || achoufinal != 1 ){     // se o no que esta sendo verificado for o no final ele termina a busca ou achoufinal for igual a 1
	       
             for(j=0;j<10;j++){
         	        
                 if(matriz[noAtual][j] < menorcusto && matriz[noAtual][j] > 0 && j != noAnterior  ){   // se o custo que est� sendo verificado no momento for menor que o menor custo j� salvo, ele salva o atuall
			menorcusto = matriz[noAtual][j];    // o custo que foi verificado recebe o menor custo
                 	noDeMenorCusto = j;          // noDeMenorCusto recebe a posi��o destino do no atual.
                    }else{
                    	if(matriz[noAtual][j] > 0 && j == final){         // se o custo for maior que 0 e j for igual o final ele grava j e acaba a busca
                    		achoufinal = 1; noDeMenorCusto = j; j=10;
                    	}
                    }
	      }
			         
	      noAnterior=noAtual;     // noAnterior recebe o no atual para que na proxima vez ele seja o anterior e n�o possa ser verificado
             }else{
                 printf("Destino encontrado");      // se o no atual for o no final passado no arquivo, ele escreve na tela "Destino encontrado".
                 break;
                 i=10;
               }
          
           for(x=0;x<10;x++){     
       
                  if(menorcaminho[x] == noDeMenorCusto){     // verifica se o no de menor custo ja existe no vetor de menor caminho
			  printf("Destino Nao encontrado");    //    se ja existir, ele exibe "Destino Nao encontrado"
          	          i=10;      //  i recebe 10 para sair do for
                          break;
                       }else{
                           if(menorcaminho[x] == 0){           //   se o vetor menorcaminho estiver em uma posi��o igual a zero, significa que � o final do arquivo
              
	                          noAtual = noDeMenorCusto;       // o noAtual passa a ser o proximo n� de menor custo
	                          menorcaminho[i+1]=noDeMenorCusto;    // o no de menor custo � atribuido no final do vetor.
	                          menorcusto=9999999;       // menorcusto recebe um valor alto para que na proxima vez possa ser comparado de novo.
	                          break;
	                      }
	               } 
	        }
	 	     
            }
       
              printf("\nMelhor Caminho = ");
		 
		 for(i=0;i<10;i++){
			if(menorcaminho[i] > 0)       
			printf("%d",menorcaminho[i]);                 // exibe na tela as posi��es do vetor de menor caminho maior que 0
                 }  
	
	    	 printf("\n");
	
	fclose (fp);

   system("pause");
   return 0;
}

