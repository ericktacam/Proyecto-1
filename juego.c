#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int filas[3][7];
int seleccion_fila = 1, turno = 1, columna = 1;
int no_columna, puntaje_j1 = 0, puntaje_j2 = 0, partida;
char no_fila[20];

void fila1(int i){
	if(i==1){
		printf("\n\n\n");
		printf("                         ");
		for(int j=0;j<3;j++){
			if(filas[0][j]==1) printf("[%d] ", j+1);
			else printf("    ");
		}
		printf("\n");
	}
}
	
	void fila2(int i){
		if(i==1){
			printf("                     ");
			for(int j=0;j<5;j++){
				if(filas[1][j]==1) printf("[%d] ", j+1);
				else printf("    ");
			}
			printf("\n");
		}
	}
		
		void fila3(int i){
			if(i==1){
				printf("                 ");
				for(int j=0;j<7;j++){
					if(filas[2][j]==1) printf("[%d] ", j+1);
					else printf("    ");
				}
				printf("\n");
			}
		}
			
			void suma(int i){
				if(i==1){
					partida = 0;
					for(int a=0;a<3;a++)
						for(int b=0;b<7;b++)
						partida += filas[a][b];
				}
			}
				
				void nueva_partida(int i){
					if(i==1){
						int base[3]={3,5,7};
						for(int a=0;a<3;a++){
							for(int b=0;b<7;b++){
								if(b<base[a]) filas[a][b]=1;
								else filas[a][b]=0;
							}
						}
					}
				}
					
					void eliminar(int fila, char posiciones[]){
						for(int i=0; posiciones[i]!='\0'; i++){
							int pos = posiciones[i]-'0'-1;
							if(pos>=0 && pos<7){
								if(filas[fila][pos]==1){
									filas[fila][pos]=0;
								}
							}
						}
					}
						
						int main(){
							char jugador1[20], jugador2[20], regresar='s';
							int opcion_menu, reiniciar, limpieza;
							
							do{
								system("cls");
								reiniciar = 0;
								
								printf("\n\n\n");
								printf("                    1. nueva partida\n");
								printf("                    2. reglas\n");
								printf("                    3. puntajes\n");
								printf("                    4. salir\n");
								scanf("%d",&opcion_menu);
								
								switch(opcion_menu){
								case 1:
									system("cls");
									printf("\n\n\n");
									printf("                    ingrese el jugador 1\n");
									scanf("%s",jugador1);
									printf("                    ingrese el jugador 2\n");
									scanf("%s",jugador2);
									
									nueva_partida(1);
									turno = 1;
									
									do{
										suma(1);
										limpieza = 0;
										system("cls");
										
										printf("%s                                           %s\n",jugador1,jugador2);
										printf("%d                                           %d\n",puntaje_j1,puntaje_j2);
										
										fila1(1);
										fila2(1);
										fila3(1);
										
										if(turno) printf("turno de jugador 1\n");
										else printf("turno de jugador 2\n");
										
										if(partida<=1){
											columna = 0;
											seleccion_fila = 1;
										}
										
										if(columna){
											printf("\n seleccione la fila: ");
											scanf("%d",&no_columna);
											columna = 0;
											seleccion_fila = 0;
											limpieza = 1;
										}
										
										if(!seleccion_fila){
											printf("seleccione los objetos a robar: ");
											scanf("%s",no_fila);
											eliminar(no_columna-1,no_fila);
											columna = 1;
											seleccion_fila = 1;
											limpieza = 1;
										}
										
										turno = !turno;
										
									}while(limpieza==1);
									
									system("cls");
									printf("\n\n\n\n                    fin de la partida\n");
									
									if(turno){
										printf("     jugador 1 gana\n");
										puntaje_j1 += 3;
									}else{
										printf("     jugador 2 gana\n");
										puntaje_j2 += 3;
									}
									
									printf("\ndesea regresar al menu s o n? ");
									scanf(" %c",&regresar);
									break;
									
								case 2:
									system("cls");
									printf("1. juegan dos personas un turno a la vez\n");
									printf("2. existen tres filas con objetos\n");
									printf("3. se pueden retirar varios objetos de una misma fila\n");
									printf("4. el jugador que deja un solo objeto pierde\n");
									printf("\nprecione s para volver\n");
									scanf(" %c",&regresar);
									break;
									
								case 3:
									system("cls");
									printf("\n\n\n");
									printf("                   puntaje del J1: %d\n",puntaje_j1);
									printf("                   puntaje del J2: %d\n",puntaje_j2);
									printf("\nprecione s para volver\n");
									scanf(" %c",&regresar);
									break;
									
								case 4:
									exit(0);
								}
							}while(regresar=='s');
							
							return 0;
						}
