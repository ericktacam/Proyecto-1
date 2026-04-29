#include <iostream>
using namespace std;
int bloque1_f3,bloque2_f3, bloque3_f3,bloque4_f3,bloque5_f3,bloque6_f3,bloque7_f3;
int bloque1_f2,bloque2_f2,bloque3_f2,bloque4_f2,bloque5_f2;
int bloque1_f1,bloque2_f1,bloque3_f1;
bool seleccion_fila = true,turno,columna = true;
int no_columna,puntaje_j1,puntaje_j2,partida,selecciones;
char no_fila[7];

int fila1(int i){
	if(i == 1){
	cout<<endl;
	cout<<endl;
	cout<<endl;
	if(bloque1_f1 == 1){
		cout<<"                         [1]";	
	}else{
		cout<<"                            ";
	}
	if(bloque2_f1 == 1){
		cout<<" [2]";	
	}else{
		cout<<"    ";
	}
	if(bloque3_f1 == 1){
		cout<<" [3]";	
	}else{
		cout<<"    ";
	}
	cout<<endl;
	return 0;
	}
	return -1;
}
int fila2(int i){
	if(i == 1){
	if(bloque1_f2 == 1){
		cout<<("                     [1]");	
	}else{
		cout<<("                        ");
	}
	if(bloque2_f2 == 1){
		cout<<(" [2]");	
	}else{
		cout<<("    ");
	}
	if(bloque3_f2 == 1){
		cout<<(" [3]");	
	}else{
		cout<<("    ");
	}
	if(bloque4_f2 == 1){
		cout<<(" [4]");	
	}else{
		printf("    ");
	}
	if(bloque5_f2 == 1){
		cout<<(" [5]");	
	}else{
		cout<<("    ");
	}
	cout<<endl;
	return 0;
	}
	return -1;
}
int fila3(int i){
	if(i==1){
	if(bloque1_f3 == 1){
		cout<<"                 [1]";	
	}else{
		cout<<"                    ";
	}
	if(bloque2_f3 == 1){
		cout<<" [2]";	
	}else{
		cout<<"    ";
	}
	if(bloque3_f3 == 1){
		cout<<" [3]";	
	}else{
		cout<<"    ";
	}
	if(bloque4_f3 == 1){
		cout<<" [4]";	
	}else{
		cout<<"    ";
	}
	if(bloque5_f3 == 1){
		cout<<" [5]";	
	}else{
		cout<<"    ";
	}
	if(bloque6_f3 == 1){
		cout<<" [6]";	
	}else{
		cout<<"    ";
	}
	if(bloque7_f3 == 1){
		cout<<" [7]";	
	}else{
		cout<<"    ";
	}
	cout<<endl;
	return 0;
	}
	return -1;
}
int suma(int i){
	if (i==1){
	partida = bloque1_f1+bloque2_f1+bloque3_f1+bloque1_f2+bloque2_f2+bloque3_f2+bloque4_f2+bloque5_f2+bloque1_f3+bloque2_f3+bloque3_f3+bloque4_f3+bloque5_f3+bloque6_f3+bloque7_f3;
	return 0;
	}
	return -1;
}
int nueva_partida(int i){
	if(i==1){
	bloque1_f3 = 1;
	bloque2_f3 = 1;
	bloque3_f3 = 1;
	bloque4_f3 = 1;
	bloque5_f3 = 1;
	bloque6_f3 = 1;
	bloque7_f3 = 1;
	bloque1_f2 = 1;
	bloque2_f2 = 1;
	bloque3_f2 = 1;
	bloque4_f2 = 1;
	bloque5_f2 = 1;
	bloque1_f1 = 1;
	bloque2_f1 = 1;
	bloque3_f1 = 1;
	puntaje_j1 = 0;
	puntaje_j2 = 0;
	return 0;
	};
	return -1;
}


int main(int argc, char *argv[]) {
	char jugador1[10],jugador2[10],regresar;
	int opcion_menu,reiniciar,limpieza;
	do{
		system("cls");
		reiniciar = 0;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"                    1. nueva partida"<<endl;
		cout<<"                    2. reglas"<<endl;
		cout<<"                    3. puntajes"<<endl;
		cout<<"                    4. salir"<<endl;
		cin>>opcion_menu;
		switch(opcion_menu){
		case 1:
			system("cls");
			cout<<endl;
			cout<<endl;
			cout<<endl;
			cout<<"                    ingrese el jugador "<<endl;
			cin>>jugador1;
			cout<<"                    ingrese el jugador 2"<<endl;
			cin>>jugador2;
			nueva_partida(1);
			if(turno =!false){
				turno = true;
			}
			do{
				suma(1);
				limpieza = 0;
				system("cls");
				cout<<jugador1<<"                                           ";
				cout<<jugador2<<endl;
				cout<<puntaje_j1<<"                                           ";
				cout<<puntaje_j2;
				fila1(1);
				fila2(1);
				fila3(1);
				if(turno == true){
					cout<<"turno de jugador 1";
				}else {
					cout<<"turno de jugador 2";
				}
				if(partida <= 1){
					limpieza = 0;
					columna = false;
					seleccion_fila = true;
				}
				if(columna == true){
					cout<<endl<<" seleccione la columna: ";
					cin>>no_columna;
					columna = false;
					seleccion_fila = false;
					limpieza = 1;
				}
				if(seleccion_fila == false){
					cout<<"seleccione los objetos a robar: ";
					cin>>no_fila;
					columna = false;
					seleccion_fila = true;
					limpieza = 1;
				}
				for(int i = 0;no_fila[i] != '\0'; i++){
					int digito = no_fila[i] - '0';
					switch(no_columna){
					case 1:
						if(digito == 1){
							bloque1_f1 = 0;
						}
						if(digito == 2){
							bloque2_f1 = 0;
						}
						if(digito == 3){
							bloque3_f1 = 0;
						}
						columna= true;
						break;
					case 2:
						if(digito == 1){
							bloque1_f2 = 0;
						}
						if(digito == 2){
							bloque2_f2 = 0;
						}
						if(digito == 3){
							bloque3_f2 = 0;
						}
						if(digito == 4){
							bloque4_f2 = 0;
						}
						if(digito == 5){
							bloque5_f2 = 0;
						}
						columna= true;
						break;
					case 3:
						if(digito == 1){
							bloque1_f3 = 0;
						}
						if(digito == 2){
							bloque2_f3 = 0;
						}
						if(digito == 3){
							bloque3_f3 = 0;
						}
						if(digito == 4){
							bloque4_f3 = 0;
						}
						if(digito == 5){
							bloque5_f3 = 0;
						}
						if(digito == 6){
							bloque6_f3 = 0;
						}
						if(digito == 7){
							bloque7_f3 = 0;
						}
						columna= true;
						break;
					default:
						cout<<"no selecciono nada pierde su turno :b";
						columna= true;
						break;
					}
					if(turno == true){
						puntaje_j1 = puntaje_j1+(digito);
					}
					if(turno == false){
						puntaje_j2 = puntaje_j2+(digito);
					}
				}
				turno = !turno;
			}while(limpieza == 1);
			system("cls");
			cout<<endl;
			cout<<endl;
			cout<<endl;
			cout<<endl<<"                    fin de la partida "<<endl;
			if(turno == false){
				cout<<"     jugador 1 pierde"<<endl;
				cout<<"     resultados: "<<puntaje_j1<<endl;
				cout<<"     jugador 2 gana"<<endl;
				cout<<"     resultados: "<<puntaje_j2<<endl;
			}else{
				cout<<"     jugador 2 pierde;"<<endl;
				cout<<"     resultados: "<<puntaje_j2<<endl;
				cout<<"     jugador 1 gana"<<endl;
				cout<<"     resultados: %i\n"<<puntaje_j1<<endl;
			}
			cout<<endl;
			cout<<"desea regresar al menu s o n?";
			cin>>regresar;
			break;
		case 2:
			system("cls");
			cout<<"1.juegan dos personas un turno a la vez"<<endl;
			cout<<"2.existen tres filas con cuadrados en cada turno un jugador"<<endl;
			cout<<"puede retirar la cantidad de objetos que quiera dentro de una misma fila"<<endl;
			cout<<"3.el jugador que se quede con un unico objeto pierde"<<endl;
			cout<<endl<<"precione s para volver al menu"<<endl;
			cin>>regresar;
			break;
		case 3:
			system("cls");
			cout<<endl;
			cout<<endl;
			cout<<endl;
			cout<<"                   puntaje del J1"<<endl;
			cout<<"                                 "<<puntaje_j1<<endl;
			cout<<"                   puntaje del "<<endl;
			cout<<"                                 "<<puntaje_j2<<endl;
			cout<<endl<<"precione s para volver al menu"<<endl;
			cin>>regresar;
			break;
		case 4:
			exit(0);
			break;
		default:
			reiniciar = 1;
			break;
		}
	}while(reiniciar == 1||regresar == 's');
	return 0;
}
