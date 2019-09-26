
/* Metodo de Newton para varias variables*/     

#include <stdio.h>
#include <stdlib.h>                                
#include <math.h>

double Emin=(10e-9), Xi, Yi, Errorx=1., Errory=1.;    //error minimo e iteraciones maximas
double U, V, Uf, Vf, dh=0.001, DUx, DUy, DVx, DVy, det, Xact, Yact;
int Iteraciones=0, Nmax=1000, Bandera=0;

int main(int argc, char *argv[]) 
{
	printf("\nMETODO DE NEWTON PARA VARIAS VARIABLES\n");    //mensaje de bienvenida, metodo a usar y funciones a evaluar
	printf("\nFuncion predefinida U(x,y)= (x**2)+xy-10\n"); // Primera ecuacion (INTRODUCIR)
	printf("Funcion predefinida V(x,y)= y+3(x*(y**2))-57\n");  //Segunda ecuacion (INTRODUCIR)    
	
	while ((Bandera==0)&&(Errorx!=0)&&(Errory!=0)&&(Iteraciones<=10))             //while para introducir x inicial 
	{                                                              				//en un numero determinado de intentos
		printf("\nIntroduzca Xi\n");                      
		scanf("%lf", &Xi);
		printf("\nIntroduzca Yi\n");                      
		scanf("%lf", &Yi);
		U=(pow(Xi,2)+(Xi*Yi)-10);  		//funcion a evaluar U(x,y) en xi y en yi (INTRODUCIR)      					 
		V=(Yi+(3*Xi*pow(Yi,2))-57);			//funcion a evaluar V(x,y) en xi y en yi (INTRODUCIR)
		DUx=(((pow(Xi+dh,2)+((Xi+dh)*Yi)-10)-U)/dh);      //Derivada Ux de la forma D=(U(Xi+dh,Yi)-U(Xi,Yi))/dh (INTRODUCIR)
		DUy=(((pow(Xi,2)+(Xi*(Yi+dh))-10)-U)/dh);			//Derivada Uy de la forma D=(U(Xi,Yi+dh)-U(Xi,Yi))/dh (INTRODUCIR)
		DVx=(((Yi+(3*(Xi+dh)*pow(Yi,2))-57)-V)/dh);			//Derivada Vx de la forma D=(V(Xi+dh,Yi)-V(Xi,Yi))/dh (INTRODUCIR)
		DVy=((((Yi+dh)+(3*Xi*pow((Yi+dh),2))-57)-V)/dh);	//Derivada Vy de la forma D=(V(Xi,Yi+dh)-V(Xi,Yi))/dh (INTRODUCIR)
		
		det=(DUx*DVy)-(DUy*DVx); 	//determinante (jacobiano), criterio de convergencia
		
		if(det!=0)        	//Criterio de convergencia
			{
			Bandera=1; 
			} 
		else
			Bandera=0;	
		
		if((U==0)&&(V==0)) 
		{
			Errorx=0;
			Errory=0;		
		}

		Iteraciones++;				
    }	//fin del while para introducir condiciones iniciales
	  
	if((U==0)&&(V==0)) //introdujo la raiz? terminar proceso
		{
			printf("\n\nIntrodujo una Solucion!\n");
			printf("El Error es cero!\n\n");		
		}
	
	else //no introdujo solucion, usar metodo de aproximacion
	{ 
	Iteraciones=0;				//refrescamos el numero de iteraciones  
	    
	
		while ((Errorx>=Emin)&&(Errory>=Emin)&&(Iteraciones<=Nmax)&&(Bandera==1))         //while para aproximar la raiz
		{
			
			U=(pow(Xi,2)+(Xi*Yi)-10);  		// para estos renglones solo copiarlos de arriba      					 
			V=(Yi+(3*Xi*pow(Yi,2))-57);			
			DUx=(((pow(Xi+dh,2)+((Xi+dh)*Yi)-10)-U)/dh);    
			DUy=(((pow(Xi,2)+(Xi*(Yi+dh))-10)-U)/dh);			
			DVx=(((Yi+(3*(Xi+dh)*pow(Yi,2))-57)-V)/dh);			
			DVy=((((Yi+dh)+(3*Xi*pow((Yi+dh),2))-57)-V)/dh);	
			det=(DUx*DVy)-(DUy*DVx); 							//copiar y pegar lo mismo de arriba
			
			
			Xact=Xi-(U*DVy-V*DUy)/det;  //metodo de aproximacion
			Yact=Yi-(V*DUx-U*DVx)/det;	//Xact=Xi-(Ui*DViy-Vi*DUiy)/J(U,V)i
										//Yact=Yi-(Vi*DUix-Ui*DVix)/J(U,V)i
										
			if (((pow(Xact,2)+(Xact*Yact)-10)==0)&&((Yi+(3*Xi*pow(Yi,2))-57)))  //funciones U y V a evaluar en Xact,Yact (INTRODUCIR)
				{
				  Errorx=0;
				  Errory=0; 
				}
			else
		    	{	
					if (Xact==0)  
	   					{
					  		Xact=Emin;
	    				}
	    			if (Yact==0)
	    			  	{
					  		Yact=Emin;
	    				}	  
					Errorx=(fabs((Xact-Xi)/Xact));  
					Errory=(fabs((Yact-Yi)/Yact));
				}       		 
				
		    		Iteraciones++;
		    		Xi=Xact;
		    		Yi=Yact;
				
		}                                                          //fin del while
		    								    	
			Uf=(pow(Xact,2)+(Xact*Yact)-10);       //evaluar la función para imprimir resultado final (INTRODUCIR)
			Vf=(Yact+(3*Xact*pow(Yact,2))-57);		//copiar lo de arriba cambiar Xi,Yi por Xact,Yact (INTRODUCIR)
														    								    	
		printf("\n\nLa solucion es:\n\tX= %f\n\tY= %f\n", Xact, Yact);              //imprimir resultados
		printf("\nEl valor de las ecuaciones es:\n\tU= %e\n\tV= %e\n", Uf, Vf);
		printf("\nEl error en X es:\n\t%e\n",Errorx);
		printf("\nEl error en Y es:\n\t%e\n",Errory);
		printf("\nEl numero de Iteraciones fue:\n\t%i\n\n",Iteraciones);
	}
		
	system("PAUSE");
	return 0;
}
