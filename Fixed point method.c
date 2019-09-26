
/* Metodo de Punto Fijo para encontrar una raiz*/     

#include <stdio.h>
#include <stdlib.h>                                
#include <math.h>

double Emin=(10e-9), Xi, Error=1., Xact, c, d, dh=0.001, Der, g;                        //error minimo e iteraciones maximas
int Iteraciones=0, Nmax=1000, Bandera=0;

int main(int argc, char *argv[]) {
	
	printf("\nMETODO DE PUNTO FIJO PARA ENCONTRAR UNA RAIZ\n");    //mensaje de bienvenida, metodo a usar y funcion a evaluar
	printf("Funcion f(x) predefinida: (e^-x)-x=0\n");			  //INTRODUCIR
	printf("Funcion g(x) predefinida: (e^-x)=f(x)+x\n");         //despeje utilizado para g(x)=f(x)+x, en general
	
	while ((Bandera==0)&&(Error!=0)&&(Iteraciones<10))             //while para introducir x inicial 
	{                                                              //en un numero determinado de intentos
		printf("\nIntroduzca Xi\n");                      
		scanf("%lf", &Xi);
		c=(pow(exp(1),-Xi)-Xi);  								   //funcion a evaluar f(x) (INTRODUCIR)
		g=(c+Xi);          					  //funcion g(x)
		Der=(((pow(exp(1),-(Xi+dh))-(Xi+dh))+(Xi+dh))-g)/dh;	//Derivada de la funcion g(x) (INTRODUCIR)
		
		if(fabs(Der)<=1)
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
			c=(pow(exp(1),-Xi)-Xi); //funcion f(x) a evaluar raiz (INTRODUCIR)
			Xact=(c+Xi);      //metodo de aproximacion
			
			if ((pow(exp(1),-Xact)-Xact)==0)    //funcion a evaluar f(x) (INTRODUCIR)
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
		    								    	
			d=(pow(exp(1),-Xact)-Xact);         //evaluar la función f(x) para imprimir resultado (INTRODUCIR)
														    								    	
		printf("\nLa raiz es: %8.18f\n",Xact);                              //imprimir resultados
		printf("El valor de la funcion es: %8.18e\n",d);
		printf("El error es: %8.18e\n",Error);
		printf("El numero de Iteraciones fue: %i\n",Iteraciones);
		
	system("PAUSE");
	return 0;
}
