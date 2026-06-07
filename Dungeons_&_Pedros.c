#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
	int i,j,k;
    int dano = 0;
    int sala = 0;
    int jogar = 1;
    int arma = 0, escarma = 0;
    int interagir = 0, mensagem = 0;
    char tecla;
    while(jogar == 1){
    	int vida = 3;
    	system("cls");
	printf("===================================\n        Dungeons and Pedros\n===================================\n1. Iniciar\n2. Como jogar\n3. Sair\n===================================\n");
	scanf("%d",&escarma);
	while(escarma!=1 && escarma!=2 && escarma!=3){
	   	printf("Escolha uma das 3 opcoes que lhe dei. 1, 2 ou 3.\n");
	   	while(getchar()!='\n');
	   	scanf("%d", &escarma);
		}
		if(escarma == 2){
			system("cls");
			printf("Pedro Desejava muito um pao de forma, mas o unico lugar que vendia era no fundo de uma masmorra ao lado de sua vila.\nAgora ele deve seguir em frente para comprar seu pao antes que estrague.\n\n\n===================== Comandos ======================\n W \nASD : andar\n\n O  : atacar\n \n I  : interagir\n \n===================== Simbolos ======================\n\n * : parede          / L : proxima sala\n # : espinho         / k : caixa\n @ : chave           / O : botao\n D : porta fechada   / = : porta aberta\n v : jogador e npc   / X : inimigo 1\n Y : inimigo 2       / Z : chefao (mofo)\n");
			vida=0;
			scanf("%d",&k);
			escarma = 0;
		}if(escarma == 3){
			jogar = 0;
		}
	
	
	
	while(vida > 0&&jogar==1) {
		char mapa0[12][12] = {
            {'*','*','*','*','*','*','*','*','*','*','*','*'},
            {'*',' ',' ',' ',' ','L','L',' ',' ','*','*','*'},
            {'*',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*'},
            {'*',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*'},
            {'*','*','*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
            {'*','*','*',' ','v',' ',' ',' ',' ',' ',' ','*'},
            {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
            {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
            {'*',' ',' ',' ','*','*',' ',' ',' ',' ',' ','*'},
            {'*',' ',' ',' ','*','*',' ',' ',' ',' ',' ','*'},
            {'*',' ',' ',' ','*','*',' ',' ',' ',' ',' ','*'},
            {'*','*','*','*','*','*','*','*','*','*','*','*'}
        };
		int x = 8, npcx = 4;
        int y = 7, npcy = 5;
        char jogador = '^';

        int cx, cy;
		while(sala == 0){
		mapa0[1][5] = 'L';
		mapa0[1][6] = 'L';	
		mapa0[y][x] = jogador;
		// Desenha o mapa
			system("cls");
            for(cy = 0; cy < 12; cy++) {
                for(cx = 0; cx < 12; cx++) {
                    printf(" %c ", mapa0[cy][cx]);
                }
                printf("\n");
            }

            printf("\n\nVida: %d", vida);
			if((x==npcx+1 || x==npcx-1 || x==npcx)&&(y==npcy+1 || y==npcy-1 || y==npcy)){
				interagir = 1;
				printf("\nPressione [i] para interagir\n\n");
			} else {
				interagir = 0;
			}
			if(mensagem==1){
				if(arma == 0){
				printf("Eh perigoso ir na masmorra. Leve um desses:\n\n             A A                                   A A A\n1. Espada: > A A   2. Arco: > A A A A   3. Cajado: A ^ A\n             A A                                   A A A\n\n");
				scanf("%d",&escarma);
				while(escarma!=1 && escarma!=2 && escarma!=3){
					printf("Escolha uma das 3 opcoes que lhe dei. 1, 2 ou 3.\n");
					while(getchar()!='\n');
					scanf("%d", &escarma);
				}
				arma = escarma;
				printf("Sabia escolha. Agora va!");
				} else if(arma>0){
					printf("Agora siga em frente.");
				}
				mensagem = 0;
			}
			
			// Tira o efeito de ataque
			for(cy = 0; cy < 12; cy++) {
                for(cx = 0; cx < 12; cx++) {
                    if(mapa0[cy][cx] == 'A'){
						mapa0[cy][cx] = ' ';
					}
                }
            }
			tecla = getch();
			// Movimento do jogador
            if(tecla == 'w' || tecla == 'W') {
                if(mapa0[y-1][x] != '*'  && mapa0[y-1][x] != 'v') {
                    if(mapa0[y][x] != 'X' && mapa0[y][x] != 'Y') mapa0[y][x] = ' ';
                    y--;
                }
                jogador = '^';
            }
            else if(tecla == 's' || tecla == 'S') {
                if(mapa0[y+1][x] != '*' && mapa0[y+1][x] != 'v') {
                    if(mapa0[y][x] != 'X' && mapa0[y][x] != 'Y' ) mapa0[y][x] = ' ';
                    y++;
                }
                jogador = 'v';
            }
            else if(tecla == 'a' || tecla == 'A') {
                if(mapa0[y][x-1] != '*' && mapa0[y][x-1] != 'v') {
                    if(mapa0[y][x] != 'X' && mapa0[y][x] != 'Y') mapa0[y][x] = ' ';
                    x--;
                }
                jogador = '<';
            }
            else if(tecla == 'd' || tecla == 'D') {
                if(mapa0[y][x+1] != '*' && mapa0[y][x+1] != 'v') {
                    if(mapa0[y][x] != 'X' && mapa0[y][x] != 'Y') mapa0[y][x] = ' ';
                    x++;
                }
                jogador = '>';
            }
			else if(tecla == 'o' || tecla == 'O') {
				if(arma == 1){
					if(jogador == '^'){
						for(i=-1;i<2;i++){
							for(j=-1;j>-3;j--){
								if(!(mapa0[y+j][x+i]=='*' || mapa0[y+j][x+i]=='#' || mapa0[y+j][x+i]=='v')){
								mapa0[y+j][x+i] = 'A';
								}
							}
						}
					} else if(jogador == 'v'){
						for(i=-1;i<2;i++){
							for(j=1;j<3;j++){
								if(!(mapa0[y+j][x+i]=='*' || mapa0[y+j][x+i]=='#' || mapa0[y+j][x+i]=='v')){
								mapa0[y+j][x+i] = 'A';
								}
							}
						}
					} else if(jogador == '<'){
						for(i=-2;i<0;i++){
							for(j=-1;j<2;j++){
								if(!(mapa0[y+j][x+i]=='*' || mapa0[y+j][x+i]=='#' || mapa0[y+j][x+i]=='v')){
								mapa0[y+j][x+i] = 'A';
								}
							}
						}
					} else if(jogador == '>'){
						for(i=1;i<3;i++){
							for(j=-1;j<2;j++){
								if(!(mapa0[y+j][x+i]=='*' || mapa0[y+j][x+i]=='#' || mapa0[y+j][x+i]=='v')){
								mapa0[y+j][x+i] = 'A';
								}
							}
						}
					}
				} else if(arma == 2){
					if(jogador == '^'){
						for(j=-1;j>-5;j--){
							if(!(mapa0[y+j][x]=='*' || mapa0[y+j][x]=='#' || mapa0[y+j][x] == 'v')){
							mapa0[y+j][x] = 'A';
							}
						}
					} else if(jogador == 'v'){
						for(j=1;j<5;j++){
							if(!(mapa0[y+j][x]=='*' || mapa0[y+j][x]=='#' || mapa0[y+j][x] == 'v')){
							mapa0[y+j][x] = 'A';
							}
						}
					} else if(jogador == '<'){
						for(i=-1;i>-5;i--){
							if(!(mapa0[y][x+i]=='*' || mapa0[y][x+i]=='#' || mapa0[y][x+i] == 'v')){
							mapa0[y][x+i] = 'A';
							}
						}
					} else if(jogador == '>'){
						for(i=1;i<5;i++){
							if(!(mapa0[y][x+i]=='*' || mapa0[y][x+i]=='#' || mapa0[y][x+i] == 'v')){
							mapa0[y][x+i] = 'A';
							}
						}
					}
				} else if(arma == 3){
					for(j=-1;j<2;j++){
						for(i=-1;i<2;i++){
							if(!((i==x)&&(j==y))){
								if(!(mapa0[y+j][x+i]=='*' || mapa0[y+j][x+i]=='#' || mapa0[y+j][x+i]=='v')){
								mapa0[y+j][x+i] = 'A';
								}
							}
						}
					}
				}
			} else if((tecla == 'i' || tecla == 'I') && interagir == 1){
				mensagem = 1;
			}
			if(((x==5||x==6)&&y==1)&&arma>0){
				sala++;
			}
			
		}
		
		
		
		
		
		
		
		
		/////////////////////////////////////////////////////////////////////////////////
		while(sala == 1&&jogar==1){
			dano++;
        char mapa1[12][12] = {
            {'*','*','*','*','*','*','*','*','*','*','*','*'},
            {'*','k','k',' ',' ','#','#','*',' ',' ',' ','*'},
            {'*',' ',' ',' ',' ',' ','k','*',' ',' ',' ','*'},
            {'*',' ',' ',' ',' ',' ','k','*',' ',' ',' ','*'},
            {'*',' ',' ','*',' ',' ',' ','*','*','D','*','*'},
            {'*',' ','#','*',' ',' ',' ',' ','k','k','k','*'},
            {'*','k','k','*',' ',' ',' ',' ',' ','k','k','*'},
            {'*','k',' ','*',' ',' ',' ',' ','k',' ','k','*'},
            {'*','#','k','*',' ',' ',' ',' ','k','k','k','*'},
            {'*','k','k','*',' ',' ',' ',' ','k','k','k','*'},
            {'*','@','k','*',' ',' ',' ',' ',' ','#','#','*'},
            {'*','*','*','*','*','*','*','*','*','*','*','*'}
        };
    	int chave = 0, existe = 1, aberta = 0;
        int x = 5, xi = 3;
        int y = 9, yi = 2;
        char jogador = '^', inimigo = 'X';
        int cx, cy, co;

        // LOOP PRINCIPAL
        while (dano > 0) {

            system("cls");
			
            // Coloca jogador e elementos no mapa
            if(aberta == 1){
				mapa1[4][9] = '=';
			}
			mapa1[1][9] = 'L';
            mapa1[y][x] = jogador;
            mapa1[yi][xi] = inimigo;
            
            // Desenha o mapa
            for(cy = 0; cy < 12; cy++) {
                for(cx = 0; cx < 12; cx++) {
                    printf(" %c ", mapa1[cy][cx]);
                }
                printf("\n");
            }

            printf("\nVida: %d", vida);
            if(x==9 && y==5 && chave>0){
				interagir = 1;
				printf("\nPressione [i] para interagir\n\n");
			} else {
				interagir = 0;
			}
			// Tira o efeito de ataque
			for(cy = 0; cy < 12; cy++) {
                for(cx = 0; cx < 12; cx++) {
                    if(mapa1[cy][cx] == 'A'){
						mapa1[cy][cx] = ' ';
					}
                }
            }
            // Frame por input
            tecla = getch();

            // Movimento do inimigo X (aleatório)
            co = rand() % 4;

            if(co == 0) {
                if(mapa1[yi-1][xi] == ' ') {
                    mapa1[yi][xi] = ' ';
                    yi--;
                }
            }
            else if(co == 1) {
                if(mapa1[yi+1][xi] == ' ') {
                    mapa1[yi][xi] = ' ';
                    yi++;
                }
            }
            else if(co == 2) {
                if(mapa1[yi][xi-1] == ' ') {
                    mapa1[yi][xi] = ' ';
                    xi--;
                }
            }
            else if(co == 3) {
                if(mapa1[yi][xi+1] == ' ') {
                    mapa1[yi][xi] = ' ';
                    xi++;
                }
            }

            // Movimento do jogador
            if(tecla == 'w' || tecla == 'W') {
                if(mapa1[y-1][x] != '*' && mapa1[y-1][x] != 'k' && mapa1[y-1][x] != 'D') {
                    if(mapa1[y][x] != 'X' && mapa1[y][x] != 'Y') mapa1[y][x] = ' ';
                    y--;
                }
                jogador = '^';
            }
            else if(tecla == 's' || tecla == 'S') {
                if(mapa1[y+1][x] != '*' && mapa1[y+1][x] != 'k' && mapa1[y+1][x] != 'D') {
                    if(mapa1[y][x] != 'X' && mapa1[y][x] != 'Y') mapa1[y][x] = ' ';
                    y++;
                }
                jogador = 'v';
            }
            else if(tecla == 'a' || tecla == 'A') {
                if(mapa1[y][x-1] != '*' && mapa1[y][x-1] != 'k' && mapa1[y][x-1] != 'D') {
                    if(mapa1[y][x] != 'X' && mapa1[y][x] != 'Y') mapa1[y][x] = ' ';
                    x--;
                }
                jogador = '<';
            }
            else if(tecla == 'd' || tecla == 'D') {
                if(mapa1[y][x+1] != '*' && mapa1[y][x+1] != 'k' && mapa1[y][x+1] != 'D') {
                    if(mapa1[y][x] != 'X' && mapa1[y][x] != 'Y') mapa1[y][x] = ' ';
                    x++;
                }
                jogador = '>';
            }
			else if(tecla == 'o' || tecla == 'O') {
				if(arma == 1){
					if(jogador == '^'){
						for(i=-1;i<2;i++){
							for(j=-1;j>-3;j--){
								if(!(mapa1[y+j][x+i]=='*' || mapa1[y+j][x+i]=='#' || mapa1[y+j][x+i]=='D' || mapa1[y+j][x+i]=='@')){
								mapa1[y+j][x+i] = 'A';
								}
							}
						}
					} else if(jogador == 'v'){
						for(i=-1;i<2;i++){
							for(j=1;j<3;j++){
								if(!(mapa1[y+j][x+i]=='*' || mapa1[y+j][x+i]=='#' || mapa1[y+j][x+i]=='D' || mapa1[y+j][x+i]=='@')){
								mapa1[y+j][x+i] = 'A';
								}
							}
						}
					} else if(jogador == '<'){
						for(i=-2;i<0;i++){
							for(j=-1;j<2;j++){
								if(!(mapa1[y+j][x+i]=='*' || mapa1[y+j][x+i]=='#' || mapa1[y+j][x+i]=='D' || mapa1[y+j][x+i]=='@')){
								mapa1[y+j][x+i] = 'A';
								}
							}
						}
					} else if(jogador == '>'){
						for(i=1;i<3;i++){
							for(j=-1;j<2;j++){
								if(!(mapa1[y+j][x+i]=='*' || mapa1[y+j][x+i]=='#' || mapa1[y+j][x+i]=='D' || mapa1[y+j][x+i]=='@')){
								mapa1[y+j][x+i] = 'A';
								}
							}
						}
					}
				} else if(arma == 2){
					if(jogador == '^'){
						for(j=-1;j>-5;j--){
							if(!(mapa1[y+j][x]=='*' || mapa1[y+j][x]=='#' || mapa1[y+j][x]=='D' || mapa1[y+j][x]=='@')){
							mapa1[y+j][x] = 'A';
							}
						}
					} else if(jogador == 'v'){
						for(j=1;j<5;j++){
							if(!(mapa1[y+j][x]=='*' || mapa1[y+j][x]=='#' || mapa1[y+j][x]=='D' || mapa1[y+j][x]=='@')){
							mapa1[y+j][x] = 'A';
							}
						}
					} else if(jogador == '<'){
						for(i=-1;i>-5;i--){
							if(!(mapa1[y][x+i]=='*' || mapa1[y][x+i]=='#' || mapa1[y][x+i]=='D' || mapa1[y][x+i]=='@')){
							mapa1[y][x+i] = 'A';
							}
						}
					} else if(jogador == '>'){
						for(i=1;i<5;i++){
							if(!(mapa1[y][x+i]=='*' || mapa1[y][x+i]=='#' || mapa1[y][x+i]=='D' || mapa1[y][x+i]=='@')){
							mapa1[y][x+i] = 'A';
							}
						}
					}
				} else if(arma == 3){
					for(j=-1;j<2;j++){
						for(i=-1;i<2;i++){
							if(!((i==x)&&(j==y))){
								if(!(mapa1[y+j][x+i]=='*' || mapa1[y+j][x+i]=='#' || mapa1[y+j][x+i]=='D' || mapa1[y+j][x+i]=='@')){
								mapa1[y+j][x+i] = 'A';
								}
							}
						}
					}
				}
			}  else if((tecla == 'i' || tecla == 'I') && interagir == 1){
				chave--;
				aberta++;
			}
			//posse de chave
			if(x==1 && y==10 && existe>0){
				chave++;
				existe--;
			}
            // Dano: espinho, inimigo X ou vilão Y
            if(mapa1[y][x] == '#' || mapa1[y][x] == 'X' || mapa1[y][x] == 'Y' || (x == xi && y == yi)) {
                vida--;
                dano--;
            }
            // checagem pra ver se os inimigos morreram
			if(mapa1[yi][xi] == 'A'){
				yi = -1;
				xi = -1;
			}
			if((x==9)&&(y==1)){
				sala++;
				dano--;
			}
			if(vida<=0){
				sala = 67;
				dano--;
			}
        }
		}
/////////////////////////////////////////////////////////////////////////////////
		while(sala == 2&&jogar==1){
			dano++;
        char mapa1[17][17] = {
            {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
            {'*',' ','#','#','#','#','#',' ',' ','L',' ','#','#','#','#','#','*'},
            {'*',' ',' ',' ','#','#','#','#',' ',' ',' ',' ','*','#','O','#','*'},
            {'*',' ',' ','@',' ','#','#','#',' ',' ',' ',' ','*',' ',' ','#','*'},
            {'*',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ','D',' ',' ',' ','*'},
            {'*',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ','*',' ',' ',' ','*'},
            {'*',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ','*',' ',' ',' ','*'},
            {'*','#','#',' ',' ',' ',' ',' ',' ','#','#','#','*',' ',' ',' ','*'},
            {'*','#','#','*','*',' ',' ',' ',' ','#','#','#','*','*','D','*','*'},
            {'*','#','#',' ','*',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ','*'},
            {'*','#','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
            {'*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
			{'*',' ',' ',' ','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
			{'*',' ',' ',' ','*','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
			{'*',' ','@',' ','*','#','#',' ',' ',' ',' ',' ','#','#',' ',' ','*'},
			{'*',' ',' ',' ','*','#',' ',' ',' ',' ',' ','#','#','#','#','#','*'},					
            {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'}
        };

        int x = 8, xi = 4,xj = 14;
        int y = 14, yi = 4,yj = 11;
		int chave = 0, existe = 2, aberta1 = 0, aberta2 = 0, ativo = 0;
        // NOVO: vilão perseguidor
        int xv = 1, yv = 1;

        char jogador = '^', inimigo = 'X', vilao = 'Y';
        char tecla;
        int cx, cy, co;

        // LOOP PRINCIPAL
        while (dano > 0) {

            system("cls");

            // Coloca jogador e inimigos no mapa
            if(aberta1 == 1){
				mapa1[8][14] = '=';
			}
			if(aberta2 == 1){
				mapa1[4][12] = '=';
			}
			if(ativo == 1){
				for(i=1;i<3;i++){
					for(j=7;j<11;j++){
						if(mapa1[j][i]!='A'){
						mapa1[j][i] = ' ';
						}
					}
				}
			}
            mapa1[y][x] = jogador;
            mapa1[yi][xi] = inimigo;
            mapa1[yj][xj] = inimigo;
            mapa1[yv][xv] = vilao;   // NOVO
            
            // Desenha o mapa
            for(cy = 0; cy < 17; cy++) {
                for(cx = 0; cx < 17; cx++) {
                    printf(" %c ", mapa1[cy][cx]);
                }
                printf("\n");
            }

            printf("\nVida: %d", vida);
  			if((x==14&&y==9&&chave>0)||(x==13&&y==4&&chave>0)||(x==14&&y==3)){
				interagir = 1;
				printf("\nPressione [i] para interagir\n\n");
			  } else {
				  interagir = 0;
			  }
			// Tira o efeito de ataque
			for(cy = 0; cy < 17; cy++) {
                for(cx = 0; cx < 17; cx++) {
                    if(mapa1[cy][cx] == 'A'){
						mapa1[cy][cx] = ' ';
					}
                }
            }
            // Frame por input
            tecla = getch();

            // Movimento do inimigo X (aleatório)
            co = rand() % 4;

            if(co == 0) {
                if(mapa1[yi-1][xi] == ' ') {
                    mapa1[yi][xi] = ' ';
                    yi--;
                }
            }
            else if(co == 1) {
                if(mapa1[yi+1][xi] == ' ') {
                    mapa1[yi][xi] = ' ';
                    yi++;
                }
            }
            else if(co == 2) {
                if(mapa1[yi][xi-1] == ' ') {
                    mapa1[yi][xi] = ' ';
                    xi--;
                }
            }
            else if(co == 3) {
                if(mapa1[yi][xi+1] == ' ') {
                    mapa1[yi][xi] = ' ';
                    xi++;
                }
            }
            // Movimento do inimigo X 2 (aleatório)
            co = rand() % 4;

            if(co == 0) {
                if(mapa1[yj-1][xj] == ' ') {
                    mapa1[yj][xj] = ' ';
                    yj--;
                }
            }
            else if(co == 1) {
                if(mapa1[yj+1][xj] == ' ') {
                    mapa1[yj][xj] = ' ';
                    yj++;
                }
            }
            else if(co == 2) {
                if(mapa1[yj][xj-1] == ' ') {
                    mapa1[yj][xj] = ' ';
                    xj--;
                }
            }
            else if(co == 3) {
                if(mapa1[yj][xj+1] == ' ') {
                    mapa1[yj][xj] = ' ';
                    xj++;
                }
            }

            // IA DO VILAO Y

int decisao = rand() % 100;

if(decisao < 75){

    // PERSEGUIR

    if(abs(x - xv) > abs(y - yv)){

        if(x > xv){

            if(mapa1[yv][xv+1]==' '){
                mapa1[yv][xv] = ' ';
                xv++;
            }
        }

        else if(x < xv){

            if(mapa1[yv][xv-1]==' '){
                mapa1[yv][xv] = ' ';
                xv--;
            }
        }
    }

    else{

        if(y > yv){

            if(mapa1[yv+1][xv]==' '){
                mapa1[yv][xv] = ' ';
                yv++;
            }
        }

        else if(y < yv){

            if(mapa1[yv-1][xv]==' '){
                mapa1[yv][xv] = ' ';
                yv--;
            }
        }
    }
}

else{

    // MOVIMENTO ALEATORIO

    int dir = rand() % 4;

    if(dir == 0){

        if(mapa1[yv-1][xv]==' '){
            mapa1[yv][xv] = ' ';
            yv--;
        }
    }

    else if(dir == 1){

        if(mapa1[yv+1][xv]==' '){
            mapa1[yv][xv] = ' ';
            yv++;
        }
    }

    else if(dir == 2){

        if(mapa1[yv][xv-1]==' '){
            mapa1[yv][xv] = ' ';
            xv--;
        }
    }

    else if(dir == 3){

        if(mapa1[yv][xv+1]==' '){
            mapa1[yv][xv] = ' ';
            xv++;
        }
    }
}

            // Movimento do jogador
            if(tecla == 'w' || tecla == 'W') {
                if(mapa1[y-1][x] != '*' && mapa1[y-1][x] != 'D' && mapa1[y-1][x] != 'O') {
                    if(mapa1[y][x] != 'X' && mapa1[y][x] != 'Y') mapa1[y][x] = ' ';
                    y--;
                }
                jogador = '^';
            }
            else if(tecla == 's' || tecla == 'S') {
                if(mapa1[y+1][x] != '*' && mapa1[y+1][x] != 'D' && mapa1[y+1][x] != 'O') {
                    if(mapa1[y][x] != 'X' && mapa1[y][x] != 'Y') mapa1[y][x] = ' ';
                    y++;
                }
                jogador = 'v';
            }
            else if(tecla == 'a' || tecla == 'A') {
                if(mapa1[y][x-1] != '*' && mapa1[y][x-1] != 'D' && mapa1[y][x-1] != 'O') {
                    if(mapa1[y][x] != 'X' && mapa1[y][x] != 'Y') mapa1[y][x] = ' ';
                    x--;
                }
                jogador = '<';
            }
            else if(tecla == 'd' || tecla == 'D') {
                if(mapa1[y][x+1] != '*' && mapa1[y][x+1] != 'D' && mapa1[y][x+1] != 'O') {
                    if(mapa1[y][x] != 'X' && mapa1[y][x] != 'Y') mapa1[y][x] = ' ';
                    x++;
                }
                jogador = '>';
            }
			else if(tecla == 'o' || tecla == 'O') {
				if(arma == 1){
					if(jogador == '^'){
						for(i=-1;i<2;i++){
							for(j=-1;j>-3;j--){
								if(!(mapa1[y+j][x+i]=='*' || mapa1[y+j][x+i]=='#' || mapa1[y+j][x+i]=='D' || mapa1[y+j][x+i]=='@' || mapa1[y+i][x+i]=='O')){
								mapa1[y+j][x+i] = 'A';
								}
							}
						}
					} else if(jogador == 'v'){
						for(i=-1;i<2;i++){
							for(j=1;j<3;j++){
								if(!(mapa1[y+j][x+i]=='*' || mapa1[y+j][x+i]=='#' || mapa1[y+j][x+i]=='D' || mapa1[y+j][x+i]=='@' || mapa1[y+i][x+i]=='O')){
								mapa1[y+j][x+i] = 'A';
								}
							}
						}
					} else if(jogador == '<'){
						for(i=-2;i<0;i++){
							for(j=-1;j<2;j++){
								if(!(mapa1[y+j][x+i]=='*' || mapa1[y+j][x+i]=='#' || mapa1[y+j][x+i]=='D' || mapa1[y+j][x+i]=='@' || mapa1[y+i][x+i]=='O')){
								mapa1[y+j][x+i] = 'A';
								}
							}
						}
					} else if(jogador == '>'){
						for(i=1;i<3;i++){
							for(j=-1;j<2;j++){
								if(!(mapa1[y+j][x+i]=='*' || mapa1[y+j][x+i]=='#' || mapa1[y+j][x+i]=='D' || mapa1[y+j][x+i]=='@' || mapa1[y+i][x+i]=='O')){
								mapa1[y+j][x+i] = 'A';
								}
							}
						}
					}
				} else if(arma == 2){
					if(jogador == '^'){
						for(j=-1;j>-5;j--){
							if(!(mapa1[y+j][x]=='*' || mapa1[y+j][x]=='#' || mapa1[y+j][x]=='D' || mapa1[y+j][x]=='@' || mapa1[y+i][x]=='O')){
							mapa1[y+j][x] = 'A';
							}
						}
					} else if(jogador == 'v'){
						for(j=1;j<5;j++){
							if(!(mapa1[y+j][x]=='*' || mapa1[y+j][x]=='#' || mapa1[y+j][x]=='D' || mapa1[y+j][x]=='@' || mapa1[y+i][x]=='O')){
							mapa1[y+j][x] = 'A';
							}
						}
					} else if(jogador == '<'){
						for(i=-1;i>-5;i--){
							if(!(mapa1[y][x+i]=='*' || mapa1[y][x+i]=='#' || mapa1[y][x+i]=='D' || mapa1[y][x+i]=='@' || mapa1[y][x+i]=='O')){
							mapa1[y][x+i] = 'A';
							}
						}
					} else if(jogador == '>'){
						for(i=1;i<5;i++){
							if(!(mapa1[y][x+i]=='*' || mapa1[y][x+i]=='#' || mapa1[y][x+i]=='D' || mapa1[y][x+i]=='@' || mapa1[y][x+i]=='O')){
							mapa1[y][x+i] = 'A';
							}
						}
					}
				} else if(arma == 3){
					for(j=-1;j<2;j++){
						for(i=-1;i<2;i++){
							if(!((i==x)&&(j==y))){
								if(!(mapa1[y+j][x+i]=='*' || mapa1[y+j][x+i]=='#' || mapa1[y+j][x+i]=='D' || mapa1[y+j][x+i]=='@' || mapa1[y+i][x+i]=='O')){
								mapa1[y+j][x+i] = 'A';
								}
							}
						}
					}
				}
			} else if((tecla == 'i' || tecla == 'I') && interagir == 1){
				if(x==14&&y==9&&chave>0){
				chave--;
				aberta1++;
				} else if(x==13&&y==4&&chave>0){
				chave--;
				aberta2++;	
				} else if(x==14&&y==3){
				ativo++;	
				}
			}
			// posse de chave 2
				if(x==2 && y==14 && existe==1){
				chave++;
				existe--;
			}
			// posse de chave 1
				if(x==3 && y==3 && existe==2){
				chave++;
				existe--;
			}
            // Dano: espinho, inimigo X ou vilão Y
            if(mapa1[y][x] == '#' || mapa1[y][x] == 'X' || mapa1[y][x] == 'Y' || (x == xi && y == yi) || (x == xv && y == yv) || (x == xj && y == yj)) {
                vida--;
                dano--;
            }
            // checagem pra ver se os inimigos morreram
			if(mapa1[yi][xi] == 'A'){
				yi = -1;
				xi = -1;
			}
			if(mapa1[yv][xv] == 'A'){
				yv = -1;
				xv = -1;
			}
			if(mapa1[yj][xj] == 'A'){
				yj = -1;
				xj = -1;
			}
			if((x==9)&&(y==1)){
				sala++;
				dano--;
			}
			if(vida<=0){
				sala = 67;
				dano--;
			}
        }
		}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		while(sala == 3&&jogar==1){
			dano++;
        char mapa1[27][27] = {
            {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
            {'*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
            {'*',' ','L',' ','D',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
            {'*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
            {'*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
            {'*',' ','@',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
            {'*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
            {'*','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
            {'*','#','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
			{'*','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
			{'*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
			{'*',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
			{'*',' ','#','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
			{'*',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
			{'*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
			{'*','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
			{'*','#','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
			{'*','#',' ',' ','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','D','*','*'},										
            {'*',' ',' ',' ','*','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
            {'*',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
            {'*',' ','#','#','*','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ','*'},
            {'*',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#',' ',' ',' ',' ','*'},
			{'*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','#','#','#','#','*','*',' ',' ',' ','*'},
			{'*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ','*'},
			{'*',' ',' ',' ','D',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','@',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','*'},
			{'*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','#','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},					
            {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'}
        };

        int x = 2, xi = 21,xj = 24;
        int y = 24, yi = 19,yj = 24;
		int chave = 0, existe = 3, aberta1 = 0, aberta2 = 0, aberta3 = 0;
        int xv = 3, yv = 8;
        int xb = 20, yb = 10;

        char jogador = '^', inimigo = 'X', vilao = 'Y', boss = 'Z';
        char tecla;
        int cx, cy, co;

        // LOOP PRINCIPAL
        while (dano > 0) {

            system("cls");
			if(aberta1 == 1){
				mapa1[24][4] = '=';
			}
			if(aberta2 == 1){
				mapa1[17][24] = '=';
			}
			if(aberta3 == 1){
				mapa1[2][4] = '=';
			}			
            mapa1[y][x] = jogador;
            mapa1[yi][xi] = vilao;
            mapa1[yj][xj] = inimigo;
            mapa1[yv][xv] = vilao;
            
			
			
			
			
			// Boss meio leso (to com sono cara me da uma folga)
			if(xb!= -1 && yb!= -1){
			co = rand()%20 + 5;
			xb = co;
			co = rand()%16 + 1;
			yb = co;
			}
			mapa1[yb][xb] = boss;
            
            // Desenha o mapa
            for(cy = 0; cy < 27; cy++) {
                for(cx = 0; cx < 27; cx++) {
                    printf(" %c ", mapa1[cy][cx]);
                }
                printf("\n");
            }

            printf("\nVida: %d", vida);
            if((x==3&&y==24&&chave>0)||(x==24&&y==18&&chave>0)||(x==5&&y==2&&chave>0)){
				interagir = 1;
				printf("\nPressione [i] para interagir");
			  } else {
				  interagir = 0;
			  }
			// Tira o efeito de ataque
			for(cy = 0; cy < 27; cy++) {
                for(cx = 0; cx < 27; cx++) {
                    if(mapa1[cy][cx] == 'A'){
						mapa1[cy][cx] = ' ';
					}
                }
            }
            // Frame por input
            tecla = getch();
			
            // Movimento do inimigo Y 1 (aleatório)
			int decisao = rand() % 100;

if(decisao < 75){

    // PERSEGUIR

    if(abs(x - xi) > abs(y - yi)){

        if(x > xi){

            if(mapa1[yi][xi+1]==' '){
                mapa1[yi][xi] = ' ';
                xi++;
            }
        }

        else if(x < xi){

            if(mapa1[yi][xi-1]==' '){
                mapa1[yi][xi] = ' ';
                xi--;
            }
        }
    }

    else{

        if(y > yi){

            if(mapa1[yi+1][xi]==' '){
                mapa1[yi][xi] = ' ';
                yi++;
            }
        }

        else if(y < yi){

            if(mapa1[yi-1][xi]==' '){
                mapa1[yi][xi] = ' ';
                yi--;
            }
        }
    }
}

else{

    // MOVIMENTO ALEATORIO

    int dir = rand() % 4;

    if(dir == 0){

        if(mapa1[yi-1][xi]==' '){
            mapa1[yi][xi] = ' ';
            yi--;
        }
    }

    else if(dir == 1){

        if(mapa1[yi+1][xi]==' '){
            mapa1[yi][xi] = ' ';
            yi++;
        }
    }

    else if(dir == 2){

        if(mapa1[yi][xi-1]==' '){
            mapa1[yi][xi] = ' ';
            xi--;
        }
    }

    else if(dir == 3){

        if(mapa1[yi][xi+1]==' '){
            mapa1[yi][xi] = ' ';
            xi++;
        }
    }
}
			
            // Movimento do inimigo X (aleatório)
            co = rand() % 4;

            if(co == 0) {
                if(mapa1[yj-1][xj] == ' ') {
                    mapa1[yj][xj] = ' ';
                    yj--;
                }
            }
            else if(co == 1) {
                if(mapa1[yj+1][xj] == ' ') {
                    mapa1[yj][xj] = ' ';
                    yj++;
                }
            }
            else if(co == 2) {
                if(mapa1[yj][xj-1] == ' ') {
                    mapa1[yj][xj] = ' ';
                    xj--;
                }
            }
            else if(co == 3) {
                if(mapa1[yj][xj+1] == ' ') {
                    mapa1[yj][xj] = ' ';
                    xj++;
                }
            }

            // IA DO VILAO Y 2

decisao = rand() % 100;

if(decisao < 75){

    // PERSEGUIR

    if(abs(x - xv) > abs(y - yv)){

        if(x > xv){

            if(mapa1[yv][xv+1]==' '){
                mapa1[yv][xv] = ' ';
                xv++;
            }
        }

        else if(x < xv){

            if(mapa1[yv][xv-1]==' '){
                mapa1[yv][xv] = ' ';
                xv--;
            }
        }
    }

    else{

        if(y > yv){

            if(mapa1[yv+1][xv]==' '){
                mapa1[yv][xv] = ' ';
                yv++;
            }
        }

        else if(y < yv){

            if(mapa1[yv-1][xv]==' '){
                mapa1[yv][xv] = ' ';
                yv--;
            }
        }
    }
}

else{

    // MOVIMENTO ALEATORIO

int dir = rand() % 4;

    if(dir == 0){

        if(mapa1[yv-1][xv]==' '){
            mapa1[yv][xv] = ' ';
            yv--;
        }
    }

    else if(dir == 1){

        if(mapa1[yv+1][xv]==' '){
            mapa1[yv][xv] = ' ';
            yv++;
        }
    }

    else if(dir == 2){

        if(mapa1[yv][xv-1]==' '){
            mapa1[yv][xv] = ' ';
            xv--;
        }
    }

    else if(dir == 3){

        if(mapa1[yv][xv+1]==' '){
            mapa1[yv][xv] = ' ';
            xv++;
        }
    }
}

            // Movimento do jogador
            if(tecla == 'w' || tecla == 'W') {
                if(mapa1[y-1][x] != '*' && mapa1[y-1][x] != 'D' && mapa1[y-1][x] != 'O') {
                    if(mapa1[y][x] != 'X' && mapa1[y][x] != 'Y') mapa1[y][x] = ' ';
                    y--;
                }
                jogador = '^';
            }
            else if(tecla == 's' || tecla == 'S') {
                if(mapa1[y+1][x] != '*' && mapa1[y+1][x] != 'D' && mapa1[y+1][x] != 'O') {
                    if(mapa1[y][x] != 'X' && mapa1[y][x] != 'Y') mapa1[y][x] = ' ';
                    y++;
                }
                jogador = 'v';
            }
            else if(tecla == 'a' || tecla == 'A') {
                if(mapa1[y][x-1] != '*' && mapa1[y][x-1] != 'D' && mapa1[y][x-1] != 'O') {
                    if(mapa1[y][x] != 'X' && mapa1[y][x] != 'Y') mapa1[y][x] = ' ';
                    x--;
                }
                jogador = '<';
            }
            else if(tecla == 'd' || tecla == 'D') {
                if(mapa1[y][x+1] != '*' && mapa1[y][x+1] != 'D' && mapa1[y][x+1] != 'O') {
                    if(mapa1[y][x] != 'X' && mapa1[y][x] != 'Y') mapa1[y][x] = ' ';
                    x++;
                }
                jogador = '>';
            }
			else if(tecla == 'o' || tecla == 'O') {
				if(arma == 1){
					if(jogador == '^'){
						for(i=-1;i<2;i++){
							for(j=-1;j>-3;j--){
								if(!(mapa1[y+j][x+i]=='*' || mapa1[y+j][x+i]=='#' || mapa1[y+j][x+i]=='D' || mapa1[y+j][x+i]=='@' || mapa1[y+i][x+i]=='O')){
								mapa1[y+j][x+i] = 'A';
								}
							}
						}
					} else if(jogador == 'v'){
						for(i=-1;i<2;i++){
							for(j=1;j<3;j++){
								if(!(mapa1[y+j][x+i]=='*' || mapa1[y+j][x+i]=='#' || mapa1[y+j][x+i]=='D' || mapa1[y+j][x+i]=='@' || mapa1[y+i][x+i]=='O')){
								mapa1[y+j][x+i] = 'A';
								}
							}
						}
					} else if(jogador == '<'){
						for(i=-2;i<0;i++){
							for(j=-1;j<2;j++){
								if(!(mapa1[y+j][x+i]=='*' || mapa1[y+j][x+i]=='#' || mapa1[y+j][x+i]=='D' || mapa1[y+j][x+i]=='@' || mapa1[y+i][x+i]=='O')){
								mapa1[y+j][x+i] = 'A';
								}
							}
						}
					} else if(jogador == '>'){
						for(i=1;i<3;i++){
							for(j=-1;j<2;j++){
								if(!(mapa1[y+j][x+i]=='*' || mapa1[y+j][x+i]=='#' || mapa1[y+j][x+i]=='D' || mapa1[y+j][x+i]=='@' || mapa1[y+i][x+i]=='O')){
								mapa1[y+j][x+i] = 'A';
								}
							}
						}
					}
				} else if(arma == 2){
					if(jogador == '^'){
						for(j=-1;j>-5;j--){
							if(!(mapa1[y+j][x]=='*' || mapa1[y+j][x]=='#' || mapa1[y+j][x]=='D' || mapa1[y+j][x]=='@' || mapa1[y+i][x]=='O')){
							mapa1[y+j][x] = 'A';
							}
						}
					} else if(jogador == 'v'){
						for(j=1;j<5;j++){
							if(!(mapa1[y+j][x]=='*' || mapa1[y+j][x]=='#' || mapa1[y+j][x]=='D' || mapa1[y+j][x]=='@' || mapa1[y+i][x]=='O')){
							mapa1[y+j][x] = 'A';
							}
						}
					} else if(jogador == '<'){
						for(i=-1;i>-5;i--){
							if(!(mapa1[y][x+i]=='*' || mapa1[y][x+i]=='#' || mapa1[y][x+i]=='D' || mapa1[y][x+i]=='@' || mapa1[y][x+i]=='O')){
							mapa1[y][x+i] = 'A';
							}
						}
					} else if(jogador == '>'){
						for(i=1;i<5;i++){
							if(!(mapa1[y][x+i]=='*' || mapa1[y][x+i]=='#' || mapa1[y][x+i]=='D' || mapa1[y][x+i]=='@' || mapa1[y][x+i]=='O')){
							mapa1[y][x+i] = 'A';
							}
						}
					}
				} else if(arma == 3){
					for(j=-1;j<2;j++){
						for(i=-1;i<2;i++){
							if(!((i==x)&&(j==y))){
								if(!(mapa1[y+j][x+i]=='*' || mapa1[y+j][x+i]=='#' || mapa1[y+j][x+i]=='D' || mapa1[y+j][x+i]=='@' || mapa1[y+i][x+i]=='O')){
								mapa1[y+j][x+i] = 'A';
								}
							}
						}
					}
				}
			} else if((tecla == 'i' || tecla == 'I') && interagir == 1){
				if(x==3&&y==24&&chave>0){
				chave--;
				aberta1++;
				} else if(x==24&&y==18&&chave>0){
				chave--;
				aberta2++;	
				} else if(x==5&&y==2&&chave>0){
				chave--;	
				aberta3++;	
				}
			}
            // Dano: espinho, inimigo X ou vilão Y
            if(mapa1[y][x] == '#' || mapa1[y][x] == 'X' || mapa1[y][x] == 'Y' || (x == xi && y == yi) || (x == xv && y == yv) || (x == xj && y == yj) || mapa1[y][x] == 'Z' || (x == xb && y == yb)) {
                vida--;
                dano--;
            }
            // posse de chave 1
				if(x==2 && y==5 && existe==3){
				chave++;
				existe--;
				}
			// posse de chave 2
				if(x==15 && y==24 && existe==2){
				chave++;
				existe--;
				}	
			// posse da ultima chave	
			k=1;
			for(cy = 1; cy < 25; cy++) {
                for(cx = 1; cx < 25; cx++) {
                    if(mapa1[cy][cx]=='Z'){
						k=0;
					}
                }
            }
			if(k==1&&existe==1){
				chave++;
				existe--;
				mapa1[2][5] = '@';
			}	
            // checagem pra ver se os inimigos morreram
			if(mapa1[yi][xi] == 'A'){
				yi = -1;
				xi = -1;
			}
			if(mapa1[yv][xv] == 'A'){
				yv = -1;
				xv = -1;
			}
			if(mapa1[yj][xj] == 'A'){
				yj = -1;
				xj = -1;
			}
			if(mapa1[yb][xb] == 'A'){
				yb = -1;
				xb = -1;
			}
			if((x==2)&&(y==2)){
				sala++;
				dano--;
			}
			if(vida<=0){
				sala = 67;
				dano--;
			}
        }
		}
		while(sala==4&&jogar==1){
			system("cls");
			printf("Pedro Derrotou todo o mofo da ultima sala e conseguiu seu pao.\nParabens voce terminou o jogo!!\n\nDigite 1 para retornar ao menu e 2 para sair. ");
			scanf("%d",&k);
		   	while(k!=1 && k!=2){
	   		printf("Escolha uma das 2 opcoes que lhe dei. 1 ou 2. \n");
	   		while(getchar()!='\n');
	   		scanf("%d", &k);
			}
			if(k == 1){
				vida=0;
				sala=0;
			} else if(k==2){
				jogar = 0;
			}
		}
		while(sala==67&&jogar==1){
			system("cls");
			printf("Voce morreu :(\nDigite 1 para retornar ao menu e 2 para sair. ");
			scanf("%d",&k);
		   	while(k!=1 && k!=2){
	   		printf("Escolha uma das 2 opcoes que lhe dei. 1 ou 2. \n");
	   		while(getchar()!='\n');
	   		scanf("%d", &k);
			}
			if(k==1){
				arma=0;
				sala=0;
			} else if(k==2){
				jogar = 0;
			}
		}		
	}
	}
	system("cls");
	printf("Obrigado por jogar.\n\nCriado por:\nRodrigo Ryoji Oliveira Monma\nPedro Augusto Leao Queiroz\n\n\n\n\n");
    return 0;
}