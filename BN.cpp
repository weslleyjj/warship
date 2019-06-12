/*
	Desenvolvido por Jodeilson Weslley da Silva
	Aluno do TADS UFRN EAJ - maca�ba
	Orientado por Laura Emmanuella Alves dos Santos Santana de Oliveira
	data: 10/06/2019
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

#define tam 10
#define submarino 2
#define fragata 3
#define porta 5

//Submarino: 2 posi��es, Fragata: 3 posi��es, porta: 5 posi��es

char tabuleiro[tam][tam], tabuleirocpu[tam][tam], tabuleirotela[tam][tam];
int navio, pos, linha, coluna, pontojogador=0, pontocpu=0, linhaj=NULL, linhacp=NULL, colunaj=NULL, colunacp=NULL, dificuldade, IA, trava=46;
void jogada(int linha, int coluna,int vez){		//vez==1 - jogador, vez==0 - CPU
	if(vez==1){	//vez do jogador
		if(tabuleirocpu[linha][coluna]=='#'){
			tabuleirotela[linha][coluna]='@';
			pontojogador++;
			
		}else{
			tabuleirotela[linha][coluna]='O';
		}
	}
	if(vez==0){	//vez da cpu
		if(tabuleiro[linha][coluna]=='#'){
			tabuleiro[linha][coluna]='@';
			pontocpu++;
		}else{
			tabuleiro[linha][coluna]='O';
		}
	}	
}
void corrigetab(){
	for(int i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
			if(tabuleiro[i][j]=='-'){
				tabuleiro[i][j]='~';
			}
		}
	}
}
char imprimetab(char tab[tam][tam]){
    for(int i=0;i<tam;i++){
        printf("\t");
        for(int j=0;j<tam;j++){
            if(i==0 && j==0){
                printf("\t   0  1  2  3  4  5  6  7  8  9 \n\t");
            }
            if(j==0){
                printf("\t%d ", i);
            }
            printf(" %c ", tab[i][j]);
        }
        printf("\n");
    }
    //system("pause");
}
void fimdejogo(int vencedor){		//vencedor==1 � o jogador, vencedor==0 � a cpu
	system("cls");
	if(vencedor==1){
		printf("\n\n\t __  __  _____   ____     ____      																\n");
		printf("\t/\\ \\/\\ \\/\\  __`\\/\\  _`\\  /\\  _`\\    														\n");
		printf("\t\\ \\ \\ \\ \\ \\ \\/\\ \\ \\ \\/\\_\\\\ \\ \\L\\_\\  												\n");
		printf("\t \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\/_/_\\ \\  _\\L  													\n");
		printf("\t  \\ \\ \\_/ \\ \\ \\_\\ \\ \\ \\L\\ \\\\ \\ \\L\\ \\												\n");
		printf("\t   \\ `\\___/\\ \\_____\\ \\____/ \\ \\____/														\n");
		printf("\t    `\\/__/  \\/_____/\\/___/   \\/___/ 															\n");
		printf("\t                                    																\n");
		printf("\t                                    \n");
		printf("\t __  __  ____    __  __  ____     ____    __  __  __     											\n");
		printf("\t/\\ \\/\\ \\/\\  _`\\ /\\ \\/\\ \\/\\  _`\\  /\\  _`\\ /\\ \\/\\ \\/\\ \\    						\n");
		printf("\t\\ \\ \\ \\ \\ \\ \\L\\_\\ \\ `\\\\ \\ \\ \\/\\_\\\\ \\ \\L\\_\\ \\ \\ \\ \\ \\ \\   				\n");
		printf("\t \\ \\ \\ \\ \\ \\  _\\L\\ \\ , ` \\ \\ \\/_/_\\ \\  _\\L\\ \\ \\ \\ \\ \\ \\  						\n");	
		printf("\t  \\ \\ \\_/ \\ \\ \\L\\ \\ \\ \\`\\ \\ \\ \\L\\ \\\\ \\ \\L\\ \\ \\ \\_\\ \\ \\_\\ 				\n");
		printf("\t   \\ `\\___/\\ \\____/\\ \\_\\ \\_\\ \\____/ \\ \\____/\\ \\_____\\/\\_\\							\n");			
		printf("\t    `\\/__/  \\/___/  \\/_/\\/_/\\/___/   \\/___/  \\/_____/\\/_/									\n");
		
	}
	if(vencedor==0){
		printf("\n\n\t__      ______   _____ ______   _____  ______ _____  _____  ______ _    _ _ 		\n");
		printf("\t\\ \\    / / __ \\ / ____|  ____| |  __ \\|  ____|  __ \\|  __ \\|  ____| |  | | |		\n");
		printf("\t \\ \\  / / |  | | |    | |__    | |__) | |__  | |__) | |  | | |__  | |  | | |			\n");
		printf("\t  \\ \\/ /| |  | | |    |  __|   |  ___/|  __| |  _  /| |  | |  __| | |  | | |			\n");
		printf("\t   \\  / | |__| | |____| |____  | |    | |____| | \\ \\| |__| | |____| |__| |_|			\n");
		printf("\t    \\/   \\____/ \\_____|______| |_|    |______|_|  \\_\\_____/|______|\\____/(_)		\n");
		
	}
	system("pause");
}
void teladejogo(){
	system("cls");
	printf("\t\t_________________________________________  ________ 	\n");
	printf("\t\t___  __ )__    |__  __/__    |__  /___  / / /__    |	\n");
	printf("\t\t__  __  |_  /| |_  /  __  /| |_  / __  /_/ /__  /| |	\n");
	printf("\t\t_  /_/ /_  ___ |  /   _  ___ |  /___  __  / _  ___ |	\n");
	printf("\t\t/_____/ /_/  |_/_/    /_/  |_/_____/_/ /_/  /_/  |_|	\n");
	//printf("\n\t\tO = Tiro na agua   @ = Navio atingido   # - Seu navio\n\n");
	printf("\n\n\tJOGADOR\t\t\tPONTOS: %d\tCPU\t\t\tPONTOS: %d\n", pontojogador, pontocpu);
	printf("\t-------------------------------		-------------------------------\n");
	printf("\t   0  1  2  3  4  5  6  7  8  9 \t   0  1  2  3  4  5  6  7  8  9 \n");
	for(int i=0;i<tam;i++){						//la�o para impress�o dos tabuleiros lado a lado
        printf("\t");
		for(int j=0;j<tam;j++){
            if(j==0){
                printf("%d ", i);
            }
            printf(" %c ", tabuleiro[i][j]);            
        }
        printf("\t");
        for(int j=0;j<tam;j++){
            if(j==0){
                printf("%d ", i);
            }
            printf(" %c ", tabuleirotela[i][j]);     //pode alterar para tabuleiro cpu para efetuar testes r�pidos
			if(i==1 && j==9){
				printf("   VENCE QUEM ALCAN�AR 27 PONTOS!");
			}
			if(i==3 && j==9){
				printf("     O = Tiro na agua");
			}
			if(i==4 && j==9){
				printf("     @ = Navio atingido");
			}
			if(i==5 && j==9){
				printf("     # = Seu navio");
			}       
        }
        
        printf("\n");
    }
    printf("\n");
	printf("\t�ltimas jogadas\n\tJOGADOR: L-%d C-%d\tCPU: L-%d C-%d\n", linhaj, colunaj, linhacp, colunacp);	
	
}
void gameplay(){
	int erro=0;
	do{	
		teladejogo();
		do{
			printf("\n\tFa�a sua jogada\n\tLinha: ");
			scanf("%d", &linha);
			linhaj=linha;
			printf("\tColuna: ");
			scanf("%d", &coluna);
			colunaj=coluna;
			if(linha>9 || linha<0 || coluna>9 || coluna<0){
				printf("\tPosi��o n�o dispon�vel!");
				erro=1;
			}else if(tabuleirotela[linha][coluna]=='O' || tabuleirotela[linha][coluna]=='@'){
				printf("\tPosi��o j� atacada!");
				erro=1;
			}else{
				erro=0;
			}
		}while(erro==1);
		jogada(linha, coluna, 1);
		printf("\n\tCPU est� jogando...");
		//sleep(1);
		//vez CPU
		dificuldade=0;
		do{
			linha=rand()%10;
			linhacp=linha;
			coluna=rand()%10;
			colunacp=coluna;
			if(tabuleiro[linha][coluna]=='#'){		//cpu ganha chances extras de acordo com o n�vel de dificuldade
				break;
			}else if(tabuleiro[linha][coluna]=='O' || tabuleiro[linha][coluna]=='@'){
				dificuldade--;
			}else{
				dificuldade++;
			}
		}while(dificuldade<IA);
		jogada(linha, coluna, 0);
		if(pontojogador==27){
			teladejogo();
			system("\npause");
			break;		
		}else if(pontocpu==27){
			teladejogo();
			system("\npause");
			break;
		}
	}while(1);
	if(pontojogador==27){
		fimdejogo(1);
		
	}else if(pontocpu==27){
		fimdejogo(0);
	}
}
void atribuir(int linha, int coluna, int pos, int navio, char tab[tam][tam]){		//fun��o para atribuir o navio na posi��o oferecida
	if(pos==0){	
		for(int i=0;i<navio;i++){
			tab[linha+i][coluna]='#';
			tab[linha+i][coluna+1]='-';
			tab[linha+i][coluna-1]='-';
		}
		tab[linha-1][coluna]='-';
		tab[linha+navio][coluna]='-';	
	}
	if(pos==1){
		for(int i=0;i<navio;i++){
			tab[linha][coluna+i]='#';
			tab[linha+1][coluna+i]='-';
			tab[linha-1][coluna+i]='-';
		}
		tab[linha][coluna-1]='-';
		tab[linha][coluna+navio]='-';
	}
}
int liberacao(int linha, int coluna, int pos, int navio, char tab[tam][tam]){		//fun��o para verificar a posi��o dada
	int liberar=0;
	if(pos==0){
		for(int i=0;i<navio;i++){
			if(tab[linha+i][coluna]=='~' && linha+i<tam){
				liberar=1;
			}
			else{
				liberar=0;
				return liberar;
			}
		}
	}else if(pos==1){
		for(int i=0;i<navio;i++){
			if(tab[linha][coluna+i]=='~' && coluna+i<tam){
				liberar=1;
			}
			else{
				liberar=0;
				return liberar;
			}
		}
	}
	return liberar;
}
void telaselecao(){
    system("cls");
    printf("\n\t\t|Atribuir navios ao tabuleiro|\n\n");
    printf("\t~ : �rea livre   - : �rea bloqueada   # : Navio\n");
    printf("Submarino: 2 posi��es  Fragata: 3 posi��es  Porta-avi�es: 5 posi��es\n\n");
    imprimetab(tabuleiro);
}
void naviorand(char tab[tam][tam]){												
	srand(time(NULL));
	int submarin=4, fragat=3, port=2, encerrar=0, check=0;
    
    do{   
	    do{                     //rotina para escolha do navio
	        navio=rand()%3+1;
	            if(navio==1 && submarin!=0 || navio==2 && fragat!=0 || navio==3 && port!=0)
	                check=1;
	            else{
	                check=0;
	            }
	    }while(check==0);
        
		if(navio==1){
			do{
				linha=rand()%10;	//n�mero para a linha				
				coluna=rand()%10;	//n�mero para a coluna
		       	pos=rand()%2;		//vertical ou horizontal
			}while(liberacao(linha, coluna, pos, submarino, tab)==0);
			atribuir(linha, coluna, pos, submarino, tab);
			submarin--;		//controle da quantidade de barcos inseridos
			       	
	    }else if(navio==2){			
	       	do{
				linha=rand()%10;					
				coluna=rand()%10;	
		       	pos=rand()%2;		
			}while(liberacao(linha, coluna, pos, fragata, tab)==0);
			atribuir(linha, coluna, pos, fragata, tab);
			fragat--;
			
	    }else if(navio==3){				
	    	do{
				linha=rand()%10;					
				coluna=rand()%10;	
		       	pos=rand()%2;		
			}while(liberacao(linha, coluna, pos, porta, tab)==0);
			atribuir(linha, coluna, pos, porta, tab);
			port--;
        	}
		encerrar++;	
        	//printf("|Navio:%d\tLinha:%d\tColuna:%d\tPos:%d|\n", navio, linha, coluna, pos); //retorno para efetuar os testes ap�s terminar as atribui��es  
    }while(encerrar!=9);
}
int atribuirnavios(){
    int navio, submarin=4, fragat=3, port=2, encerrar=0, check=0, ok=0;
    char aleatorio;
    do{
       
        do{                     //rotina para escolha do navio e sua posi��o
            telaselecao();
            if(encerrar==0){
            	printf("\n\tAtribuir aleat�riamente?(s/n): ");
            	scanf("%c", &aleatorio);
            	if(aleatorio=='s'){
            		naviorand(tabuleiro);
            		return 0;
				}
			}
            printf("\n\n\t1 - Submarino(%d/4)\n\t2 - Fragata(%d/3)\n\t3 - Porta avi�es(%d/2)\n", submarin, fragat, port);
            printf("\tNavio: ");
            scanf("%d", &navio);
            if(navio==1 && submarin!=0 || navio==2 && fragat!=0 || navio==3 && port!=0)
                check=1;
            else{
                printf("\n\n\tNavios Excedidos!\n");
                system("pause");
                system("cls");
                check=0;
            }
        }while(check==0);
	    do{ 
			   
			do{
	            printf("\n\tVertical (0) ou horizontal(1)? ");
	            scanf("%d", &pos);
	        }while(pos<0 || pos>1);
	        printf("\tLinha: ");
	        scanf("%d", &linha);
	        printf("\tColuna: ");
	        scanf("%d", &coluna);
	       
	        if(navio==1){
	            if(liberacao(linha, coluna, pos, submarino, tabuleiro)==1){
	            	atribuir(linha, coluna, pos, submarino, tabuleiro);
	            	ok=1;
	            	submarin--;
				}else{
					ok=0;
				}
	        }else if(navio==2){
	            if(liberacao(linha, coluna, pos, fragata, tabuleiro)==1){
	            	atribuir(linha, coluna, pos, fragata, tabuleiro);
	            	ok=1;
	            	fragat--;
				}else{
					ok=0;
				}
	        }else if(navio==3){
	            if(liberacao(linha, coluna, pos, porta, tabuleiro)==1){
	            	atribuir(linha, coluna, pos, porta, tabuleiro);
	            	ok=1;
	            	port--;
				}else{
					ok=0;
				}
	        }
	        if(ok==0){
	        	printf("\n\tPosi��o escolhida n�o dispon�vel!\n\tPor favor insira outra posi��o!\n\n\t");
	        	system("pause");
	        	telaselecao();	        	
			}
		}while(ok==0);
        encerrar++;
    }while(encerrar!=9);
}
void game(){
	 char repete;
     pontojogador=0; pontocpu=0;
	 for(int i=0;i<tam;i++){
        for(int j=0;j<tam;j++){
            tabuleiro[i][j]='~';
            tabuleirocpu[i][j]='~';
            tabuleirotela[i][j]='~';
        }
    }
    do{	
		printf("\n\n\t\t\tDigite o n�vel de dificuldade(0 - F�cil � 5 - Dificil): ");
    	scanf("%d", &IA);
    	if(IA==30){
    		break;
		}
    }while(IA<0 || IA>5);
	setbuf(stdin, NULL);
	atribuirnavios();
	naviorand(tabuleirocpu);
	corrigetab();  
   	gameplay();
   	system("cls");
   	setbuf(stdin, NULL);
   	printf("\n\n\n\t\t\t\tDeseja jogar novamente?(s/n):  ");
   	scanf("%c", &repete);
   	if(repete=='n'){
   		printf("\n\tObrigado por jogar!\n\nSaindo...");
		exit(1);
	}
   	
}
void instrucao(){
    system("cls");
    printf("\t\t     ____        __        ____             _   __                  __\n");
    printf("\t\t    / __ )____ _/ /_____ _/ / /_  ____ _   / | / /___ __   ______ _/ /\n");
    printf("\t\t   / __  / __ `/ __/ __ `/ / __ \\/ __ `/  /  |/ / __ `/ | / / __ `/ / \n");
    printf("\t\t  / /_/ / /_/ / /_/ /_/ / / / / / /_/ /  / /|  / /_/ /| |/ / /_/ / /  \n");
    printf("\t\t /_____/\\__,_/\\__/\\__,_/_/_/ /_/\\__,_/  /_/ |_/\\__,_/ |___/\\__,_/_/   \n\n");
	printf("\t\t\t\t|\tInstru��es do jogo\t|\n\n");
    printf("\t  Batalha naval � um jogo de tabuleiro de dois jogadores, no qual os jogadores \n\tt�m de adivinhar em que quadrados est�o os navios do oponente.");
	printf("\n\n\t  Primeiramente voc� dever� colocar seus navios no tabuleiro a mostra apresentando\n\t");
	printf("em qual coordenada de LINHA e COLUNA ele ser� preenchido junto com a dire��o\n\t");
	printf("que pode ser HORIZONTAL ou VERTICAL e que ser�o colocados � direita ou abaixo da posi��o inicial.\n");
	printf("\n\tREGRAS PARA COLOCAR NAVIOS:\n\t");
	printf("1 - N�o coloque navios em posi��es lado a lado");
	printf("\n\t2 - N�o sobreponha os navios");
	printf("\n\t3 - N�o utilize posi��es inexistentes no tabuleiro");
	printf("\n\n\t  Durante o jogo as legendas auxiliar�o o entendimento das caracter�sticas do tabuleiro\n\n\t");
    printf("B�NUS: Digite 5 no menu para ver as dicas secretas!\n\n\t");
}
void creditos(){
    system("cls");
    printf("\t\t     ____        __        ____             _   __                  __\n");
    printf("\t\t    / __ )____ _/ /_____ _/ / /_  ____ _   / | / /___ __   ______ _/ /\n");
    printf("\t\t   / __  / __ `/ __/ __ `/ / __ \\/ __ `/  /  |/ / __ `/ | / / __ `/ / \n");
    printf("\t\t  / /_/ / /_/ / /_/ /_/ / / / / / /_/ /  / /|  / /_/ /| |/ / /_/ / /  \n");
    printf("\t\t /_____/\\__,_/\\__/\\__,_/_/_/ /_/\\__,_/  /_/ |_/\\__,_/ |___/\\__,_/_/   \n\n");
	printf("\t\t\t\t\t|  Cr�ditos  |\n\n");
    printf("\t\tDesenvolvido por: Jodeilson Weslley da Silva\n\t\tOrientado por: Laura Emmanuella Alves dos Santos Santana de Oliveira\n");
    printf("\t\tBaseado em: Batalha Naval de tabuleiro\n\t\tIn�cio do desenvolvimento: 15/05/2019  T�rmino do desenvolviemnto: 10/06/2019 \n\n\n");
}
void dicas(){
	int senha;
	system("cls");
	printf("\n\n\t\tPara visualizar as preciosas dicas digite quantas letras h� no nome do orientador do jogo!\n\tResposta: ");
	scanf("%d", &senha);
	if(senha==trava){
		printf("\t\t\t    ____  _____________   _____		\n");
		printf("\t\t\t   / __ \\/  _/ ____/   | / ___/	\n");
		printf("\t\t\t  / / / // // /   / /| | \__ \ 		\n");
		printf("\t\t\t / /_/ // // /___/ ___ |___/ / 		\n");
		printf("\t\t\t/_____/___/\\____/_/  |_/____/  	\n");	
		printf("\n\t1 - Os navios n�o ficam lado a lado, logo evite atirar em posi��es ao lado de outras ja atingidas");
		printf("\n\t2 - Come�ar a partida atirando nas diagonais facilita que encontre navios inimigos");
		printf("\n\t3 - Quanto maior a dist�ncia entre seus navios mais dificil fica para a CPU encontr�-los");
		printf("\n\t4 - Alterne bastante entre posi��es verticais e horizontais, isso confunde a CPU e lhe dar� tempo");
		printf("\n\t5 - Apesar de tudo 60%% do jogo � sorte");
		printf("\n\n\tB�NUS: digite 30 na dificuldade do jogo e tente vencer no modo imposs�vel!\n\n\t");
	}else{
		printf("\n\t\tVOC� ERROU!\n\n");
	}
}
int main(){
    setlocale(LC_ALL, "portuguese");
    int op;
    do{
    	printf("\t\t     ____        __        ____             _   __                  __\n");
        printf("\t\t    / __ )____ _/ /_____ _/ / /_  ____ _   / | / /___ __   ______ _/ /\n");
        printf("\t\t   / __  / __ `/ __/ __ `/ / __ \\/ __ `/  /  |/ / __ `/ | / / __ `/ / \n");
        printf("\t\t  / /_/ / /_/ / /_/ /_/ / / / / / /_/ /  / /|  / /_/ /| |/ / /_/ / /  \n");
        printf("\t\t /_____/\\__,_/\\__/\\__,_/_/_/ /_/\\__,_/  /_/ |_/\\__,_/ |___/\\__,_/_/   \n\n");
        printf("\t\t\t\t---------------------------------\n");
        printf("\t\t\t\t|\tMENU PRINCIPAL\t\t|\n");
        printf("\t\t\t\t---------------------------------");
        printf("\n\n\t\t\t\t\t1 - Iniciar\n\t\t\t\t\t2 - Instru��es\n\t\t\t\t\t3 - Cr�ditos\n\t\t\t\t\t4 - Sair\n\n\t\tOp��o desejada: ");
        scanf("%d", &op);
        setbuf(stdin, NULL);
        switch(op){
        case 1: game();break;
        case 2: instrucao();break;
        case 3: creditos();break;
        case 4: printf("Saindo...\n");exit(0);
        case 5: dicas();break;
        default: printf("\n\tEscolha uma op��o v�lida!\n\n");break;
        }
        system("pause");
        system("cls");
    }while(1);
    return 0;
}
