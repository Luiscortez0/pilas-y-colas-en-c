//objetivo: hpc que manipule una pila
//autor: luis carlos cortez guzman
//fecha: 17/05/2022

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(int x, int y){
	HANDLE a;
	a=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD g;
	g.X=x;
	g.Y=y;
	SetConsoleCursorPosition(a,g);
}

int main(){
	//declarar variables
	int silla[7],y,salir,i,cima;
	char z;
	
	//inicializar
	salir=0;
	cima=0;
	y=7;
	
	//bucle del programa
	do{
		//limpiar pantalla
		system("cls");
		//imprimir la pila
		gotoxy(52,19);
		printf("MI PILA");
		for(i=0;i<=cima-1;i++){
			gotoxy(55,17-(i*2));
			printf("%d",silla[i]);
		}
		//imprimir el menu de opciones
		gotoxy(15,5);
		printf("OPERACIONES DE UNA PILA");
		gotoxy(15,7);
		printf("1. insertar elemento");
		gotoxy(15,9);
		printf("2. retirar elemento");
		gotoxy(15,11);
		printf("3. salir");
		gotoxy(11,y);
		printf("--->");
		
		//leer la valor de la tecla presionada
		z=getch();
		if(z==-32)
		   z=getch();
		//condicionar cual es la tecla presionada
		switch(z){
			case 72: //flecha arriba
			    if(y==7)
			        y=11;
			    else
			        y=y-2;
			break;
			case 80: //flecha abajo
			    if(y==11)
			        y=7;
			    else
			        y=y+2;
			break;
			case 13: //enter
			    //condicionar la opcion precionada
			    switch(y){
			    	case 7: //push
			    	     if(cima==7){ //pila llena
			    	           gotoxy(15,13);
			    	           printf("PILA LLENA");
			    	           getch();
			    	     }else{
			    	     	   gotoxy(15,13);
			    	     	   printf("teclea un valor: ");
			    	     	   scanf("%d",&silla[cima]);
			    	     	   cima++;
			    	     }
			    	break;
			    	case 9: //pop
			    	     if(cima==0){ //pila vacia
			    	           gotoxy(15,13);
			    	           printf("PILA VACIA");
			    	           getch();
			    	     }else{
			    	     	   cima--;
			    	break;
			    	case 11: //salir
			    	     salir=191105;
			    	break;
			    }
			break;
		}
	}
	}while(salir==0);
}
