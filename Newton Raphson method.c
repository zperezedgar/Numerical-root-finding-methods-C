
/* Metodo de Newton Rapshon para encontrar una raiz*/     

#include <stdio.h>
#include <stdlib.h>                                
#include <math.h>

double Emin=(10e-9), Xi, Error=1., Xact, c, d, dh=0.001, Der, Der2, Derg;                        //error minimo e iteraciones maximas
int Iteraciones=0, Nmax=1000, Bandera=0;

int main(int argc, char *argv[]) {
	
	printf("\nMETODO DE NEWTON-RAPHSON PARA ENCONTRAR UNA RAIZ\n");    //mensaje de bienvenida, metodo a usar y funcion a evaluar
	printf("Funcion f(x) predefinida: (e^-x)-x=0\n"); //f(x) (INTRODUCIR)
	printf("Funcion f'(x) predefinida: -(e^-x)-1=f'(x)\n");	//Evaluar la derivada a mano (INTRODUCIR)
	printf("Funcion g(x) predefinida: (e^-x)=x-(f(x)/f'(x))\n");         //funcion g(x)= f(x)+x, en general (no necesario introducir)
	
	while ((Bandera==0)&&(Error!=0)&&(Iteraciones<10))             //while para introducir x inicial 
	{                                                              //en un numero determinado de intentos
		printf("\nIntroduzca Xi\n");                      
		scanf("%lf", &Xi);
		c=(pow(exp(1),-Xi)-Xi);  							//funcion a evaluar f(x) (INTRODUCIR)          					 
		Der=((((pow(exp(1),-(Xi+dh))-(Xi+dh)))-c)/dh);      //Derivada f'(x) de la forma D=(f(Xi+dh)-f(Xi))/dh (INTRODUCIR)
		Der2=((-pow(exp(1),-(Xi+dh))-1)-(-pow(exp(1),-Xi)-1))/dh; //obtener la expresion de la funcion primera derivada f'(x) a mano (INTRODUCIR)
		Derg=((c)*(Der2)/(Der*Der));   //derivada de g(x), el criterio de convergencia
		
		if((fabs(Derg))<=1)        	//Criterio de convergencia
			{
			Bandera=1; 
			} 
		else
			Bandera=0;	
		
		if(c==0)
			{
			Error=0; 
			} 

		Iteraciones++;				
    }
	  
	Iteraciones=0;				//refrescamos el numero de iteraciones  
	  
	  
	
		while ((Error>=Emin) && (Iteraciones<=Nmax)&&(Bandera==1))              //while para aproximar la raiz
		{
			c=(pow(exp(1),-Xi)-Xi); //Funcion f(x) (INTRODUCIR)
			Der=((((pow(exp(1),-(Xi+dh))-(Xi+dh)))-c)/dh); //Funcion f'(x) (INTRODUCIR)
			
			Xact=Xi-(c/Der);  //metodo de aproximacion: g(x)=Xi-[f(Xi)/f'(Xi)]
																											
			if (((pow(exp(1),-Xact)-Xact)-Xact)==0)    //Funcion a ealuar f(x) (INTRODUCIR)
				{
				  Error=0; 
				}
			else
		    	
				if (Xact==0)  
	   				{
					  Xact=Emin;
	    			}
	    			           		 
				Error=(fabs((Xact-Xi)/Xact));
		    	
		    		Iteraciones++;
		    		Xi=Xact;
		    		
		}                                                          //fin del while
		    								    	
			d=(pow(exp(1),-Xact)-Xact);    //evaluar f(x) (INTRODUCIR)
														    								    	
		printf("\nLa raiz es: %8.18f\n",Xact);                              //imprimir resultados
		printf("El valor de la funcion es: %8.18e\n",d);
		printf("El error es: %8.18e\n",Error);
		printf("El numero de Iteraciones fue: %i\n",Iteraciones);
		
	system("PAUSE");
	return 0;
}
