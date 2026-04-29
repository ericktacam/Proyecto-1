#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int filas[3][7];
int puntaje_j1 = 0, puntaje_j2 = 0;

/* Inicializa las filas */
void nueva_partida(){
	int base[3] = {3,5,7};
	for(int i=0;i<3;i++){
		for(int j=0;j<7;j++){
			if(j < base[i])
				filas[i][j] = 1;
			else
				filas[i][j] = 0;
		}
	}
}
	
	/* Muestra el tablero */
	void mostrar(){
		printf("\n");
		for(int i=0;i<3;i++){
			printf("Fila %d: ", i+1);
			for(int j=0;j<7;j++){
				if(filas[i][j] == 1)
					printf("[%d]", j+1);
				else
					printf("   ");
			}
			printf("\n");
		}
	}
		
		/* Cuenta cuántas casillas quedan */
		int contar_restantes(){
			int total = 0;
			for(int i=0;i<3;i++)
				for(int j=0;j<7;j++)
				total += filas[i][j];
				return total;
		}
			
			/* Elimina posiciones elegidas */
			void eliminar(int fila, char posiciones[]){
				for(int i=0; posiciones[i] != '\0'; i++){
					int pos = posiciones[i] - '0' - 1;
					if(pos >= 0 && pos < 7 && filas[fila][pos] == 1){
						filas[fila][pos] = 0;
					}
				}
			}
				
				int main(){
					char jugador1[20], jugador2[20];
					int opcion, turno, fila;
					char quitar[20], regresar;
					
					do{
						system("cls"); // usa "clear" si estás en Linux
						printf("1. Nueva partida\n");
						printf("2. Reglas\n");
						printf("3. Puntajes\n");
						printf("4. Salir\n");
						scanf("%d", &opcion);
						
						switch(opcion){
							
						case 1:
							printf("Nombre jugador 1: ");
							scanf("%s", jugador1);
							printf("Nombre jugador 2: ");
							scanf("%s", jugador2);
							
							nueva_partida();
							turno = 1;
							
							while(contar_restantes() > 1){
								system("cls");
								printf("%s (%d puntos) vs %s (%d puntos)\n",
									   jugador1, puntaje_j1, jugador2, puntaje_j2);
								
								mostrar();
								
								if(turno)
									printf("Turno de %s\n", jugador1);
								else
									printf("Turno de %s\n", jugador2);
								
								printf("Seleccione fila (1-3): ");
								scanf("%d", &fila);
								
								printf("Posiciones a quitar (ej: 135): ");
								scanf("%s", quitar);
								
								eliminar(fila-1, quitar);
								
								turno = !turno;
							}
							
							system("cls");
							mostrar();
							printf("\nFIN DE LA PARTIDA\n");
							
							/* El turno ya cambió, el ganador es el contrario */
							if(turno){
								printf("Gana %s\n", jugador1);
								puntaje_j1 += 3;
							}else{
								printf("Gana %s\n", jugador2);
								puntaje_j2 += 3;
							}
							
							printf("Presione s para volver al menu: ");
							scanf(" %c", &regresar);
							break;
							
						case 2:
							system("cls");
							printf("Reglas del juego (Nim):\n");
							printf("- Hay 3 filas con 3, 5 y 7 objetos.\n");
							printf("- En tu turno puedes quitar uno o varios de UNA sola fila.\n");
							printf("- El jugador que deja un solo objeto pierde.\n");
							printf("Presione s para volver: ");
							scanf(" %c", &regresar);
							break;
							
						case 3:
							system("cls");
							printf("Puntajes:\n");
							printf("%s: %d puntos\n", jugador1, puntaje_j1);
							printf("%s: %d puntos\n", jugador2, puntaje_j2);
							printf("Presione s para volver: ");
							scanf(" %c", &regresar);
							break;
							
						case 4:
							exit(0);
						}
						
					}while(regresar == 's');
					
					return 0;
				}
