
/* Metodo de biseccion para encontrar una raiz */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Nmax=1000, Iteraciones=0, Bandera=0;                                //error minimo e iteraciones maximas
double Emin=10E-9, Eact, Xizq, Xder, Xant, Xact, a, b, Error, c, d;

int main(int argc, char *argv[]) 
{
	printf("\nMETODO DE LA BISECCION PARA CALCULAR RAICES\n");   //mensaje de bienvenida, metodo a usar y funcion a evaluar
	printf("Funcion predefinida: (e^-x)-x=0\n");                 // f(x) (INTRODUCIR)
	
	while (Bandera==0)                       //while para introducir un intervalo correcto
	{ printf("\nIntroduzca Xizq\n");
	  scanf("%lf", &Xizq);
	  printf("\nIntroduzca Xder\n");
	  scanf("%lf", &Xder);
	  
	  a=(pow(exp(1),-Xizq)-Xizq); //funcion a evaluar f(x) (INTRODUCIR)
	  b=(pow(exp(1),-Xder)-Xder); //(INTRODUCIR)
	   
	  if (a*b<=0)
	      {Bandera=1;}
	  else    
	       Bandera=0;
    }                                     //fin del while
		                           
	 if ((a==0) || (b==0))    //if para probar si el intervalo es raiz
	 { 
	   Error=0;
	 }
	  else	                                                            //el intervalo no es raiz (entrar al while)
	  	{ 
		  if (Xder==0)
	  	  { 
			Xder=Emin;
		  }		  
		    Error=(fabs((Xder-Xizq)/Xder));  
	   	}	  
			  							    		
	
				while ((Error>Emin) && (Iteraciones<=Nmax) && (Bandera==1))           //while para aproximar la raiz
				{
					Xant=Xder;
					Xact=((Xder+Xizq)/2);       //metodo de aproximacion 
					            
					c=(pow(exp(1),-Xact)-Xact); //funcion a evaluar f(x) (INTRODUCIR)
					d=(pow(exp(1),-Xder)-Xder); //(INTRODUCIR)
	
					if ((c*d)<0)                    
	   				{
					   Xizq=Xact;
	             	}	
					else
	   				{
					   Xder=Xact;
	            	}
	            
					if (Xact==0)  
	   				{
					   Xact=Emin;
	    			}
	                
				Error=(fabs((Xact-Xant)/Xact));  
	
				if (c==0)   
	   			{ 
				   Error=0;
	      		}
					Iteraciones++;
					Xant=Xact; 
				} //fin del while
				
		a=(pow(exp(1),-Xizq)-Xizq); //funcion a evaluar (Copiar de arriba)
		b=(pow(exp(1),-Xder)-Xder); //(Copiar de arriba)                                                                    
											  
	   				              
		if ((a==0) || (b==0))      //if para ver que resultados imprimir 
			{ 
			 printf("Introdujo la raiz!\n");                                 //imprimir: se introdujo la raiz
		       
				if (a==0)    		 			             
			{  
				printf("\nLa raiz es: %g\n",Xizq);
			}												 
       			else
     			printf("\nLa raiz es: %g\n",Xder);
	
        		printf("El valor de la funcion es cero\n");
		    	printf("El error es cero\n");
		    	printf("El numero de Iteraciones fue cero\n"); 
			}
	
	
	    else	                                                           //imprimir: resultados de iteraciones (no se introdujo la raiz)
	      {  
	       printf("\nLa raiz es: %8.18f\n",Xact);
		   printf("El valor de la funcion es: %8.18e\n",c);
		   printf("El error es: %8.18e\n",Error);
		   printf("El numero de Iteraciones fue: %i\n",Iteraciones);	 
	      } 					  
							  	
	system("PAUSE");
	return 0;
}
