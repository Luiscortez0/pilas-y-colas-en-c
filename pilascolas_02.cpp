//objetivo: hpc que manipule una cola
//autor: luis carlos cortez guzman
//fecha: 20/05/2022

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
	int nalga[7],y,salir,i,ultimo;
	char z;
	
	//inicializar
	salir=0;
	ultimo=0;
	y=7;
	
	//bucle del programa
	do{
		//limpiar pantalla
		system("cls");
		//imprimir la pila
		gotoxy(65,10);
		printf("LA COLA");
		for(i=0;i<=ultimo-1;i++){
			gotoxy(71-(i*3),8);
			printf("%d",nalga[i]);
		}
		//imprimir el menu de opciones
		gotoxy(10,5);
		printf("OPERACIONES DE UNA COLA");
		gotoxy(10,6);
		printf("1. insertar elemento");
		gotoxy(10,7);
		printf("2. retirar elemento");
		gotoxy(10,8);
		printf("3. salir");
		gotoxy(7,y);
		printf("-->");
		
		//leer la valor de la tecla presionada
		z=getch();
		if(z==-32)
		   z=getch();
		//condicionar cual es la tecla presionada
		switch(z){
			case 72: //flecha arriba
			    if(y==6)
			        y=8;
			    else
			        y--;
			break;
			case 80: //flecha abajo
			    if(y==8)
			        y=6;
			    else
			        y++;
			break;
			case 13: //enter
			    //condicionar la opcion precionada
			    switch(y){
			    	case 6: //push
			    	     if(ultimo==7){ //cola llena
			    	           gotoxy(10,10);
			    	           printf("COLA LLENA");
			    	           getch();
			    	     }else{
			    	     	   gotoxy(10,10);
			    	     	   printf("teclea un valor: ");
			    	     	   scanf("%d",&nalga[ultimo]);
			    	     	   ultimo++;
			    	     }
			    	break;
			    	case 7: //pop
			    	     if(ultimo==0){ //cola vacia
			    	           gotoxy(10,10);
			    	           printf("COLA VAC%cA",214);
			    	           getch();
			    	     }else{
			    	     	   ultimo--;
			    	     	   for(i=0;i<=ultimo-1;i++){
			    	     	   	nalga[i]=nalga[i+1];
								}
			    	break;
			    	case 8: //salir
			    	     salir=191105;
			    	break;
			    }
			break;
		}
	}
	}while(salir==0);
}
