#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <string.h>

char TextResults[5][50]={
	"Que pedo no hubo resultado","Solucion Unica","Solucion Infinita","Sin Solucion"
};

enum Results{
	NOT_SET_YET,
	UNIQUE_SOLUTION,
	INFINITE_SOLUTION,
	WITHOUT_SOLUTION
};

using namespace std;
class Equationes{
public:
	
	int m,n;
	float Equation[200];
	int Result; 
	int i,j,k;
	char TempLineBuffer[80];
	ofstream File;

	void SetValuesToArray(void){
		File.open("Output.txt");
		system("cls");
		cout << "***  Matriz Inversa Metodo Gauss-Jordan-Silva  ***"<<endl<<endl;
		cout << "Instrucciones:"<<endl << "1- Para introducir el tamanio de la matriz"<<endl<<"debes poner el numero de renglones x numero de filas"
		<< endl << "mxn. Puede ser de cualquier tamanio mientras no "<<endl<<"sobre pase 10x10.   Ejemplo  3x3" <<endl;
		cout << "2- El programa pedira los la informacion Renglon por"<<"Renglon, y cada elemento del renglon ira separado"<<endl
		<< "por un espacio en blanco, no importa si es negativo,"<<endl<<" y si es un fraccion, se pondra con punto decimal"<<endl;
        cout << "   Ejemplo: "<<endl<< "( 0 -1 3 )"<<endl<<"( 2.5 6 -1)"<<endl<<"( 8 3 1 )"<<endl;
		cout <<"Si no se respeta el formato el programa fallara"<<endl<<"*** Espero que les sirva  :) ***" << endl;
		cout << "Introdusca el tamanio de la Matriz: ";
		scanf("%dx%d",&m,&n);
		
		//Equation= new float [m*n*2] ;
		//Equation= (float *) malloc(m*n*2*8) ;	
		
		for(i=0;i<=m; i++){
			if(i!=0)cout<< "Renglon  " << i<< "> ";
			int c;
			j=0;
			while((c = getchar()) != '\n')
			TempLineBuffer[j++] = c;
			TempLineBuffer[j]='\0';
			
			//cout << endl << TempLineBuffer << endl<<endl;
			
			if(i!=0){
				int Len;
				Len = strlen(TempLineBuffer);
			
				TempLineBuffer[Len]=' ';
				TempLineBuffer[Len+1]='\0';
			
				Len = strlen(TempLineBuffer);
		
				int counter=0;
				int lastspace=-1;
			
				for(j=0;j<Len;j++){
					if(TempLineBuffer[j]==' '){
						char tempcharbuffer[12];
						for(k=0; k<12; k++){
							tempcharbuffer[k]=' ';
						}
						for(k=lastspace+1; k<j; k++){
							tempcharbuffer[k-lastspace-1]=TempLineBuffer[k];
							//cout <<"Tempbuffer="<< TempLineBuffer[k];
						}
						lastspace=j;
						sscanf(tempcharbuffer,"%f ",&Equation[((i-1)*(n*2))+counter]);
						//cout << " Arreglo=" << Equation[((i-1)*(n*2))+counter]<< "num= " << ((i-1)*(n*2))+counter<<"  charbufer="<<tempcharbuffer;
						counter++;
					}
					if(counter>=n)break;
				}
				for(j=n;j<(n*2);j++)Equation[((i-1)*(n*2))+j]=0;
				Equation[((i-1)*(n*2))+n+i-1]=1;//*/
			}
		
		}
		cout << endl <<endl;
		
	}
	void PrintCapturedValues(void){
		int x,y;
		for(x=0;x<m; x++){
			cout << "( ";
			File << "( ";
			for(y=0;y<n;y++){
				cout << Equation[(x*(n*2))+y] << " ";
				File << Equation[(x*(n*2))+y] << " ";
			}
			cout << "| ";
			File << "| ";
			for(y=n;y<n*2;y++){
				cout << Equation[(x*(n*2))+y] << " ";
				File << Equation[(x*(n*2))+y] << " ";
			}
			cout <<")"<< endl;
			File <<")"<< endl;
		}
		cout << endl<<endl;
		File << endl<<endl;
	}
	
	void GaussMetod(void){
		float Divisor,Factor;
		float TempEq[20];
		int Paso=0;
		for(i=0;i<20;i++)TempEq[i]=0;	
		
		for(i=0; i<m; i++){
			
			
			Paso++;
			cout<<"Paso #" << Paso<<endl;
			File<<"Paso #" << Paso<<endl;
			
			if(Equation[(i*n*2)+i]!=1){
				Divisor=Equation[(i*n*2)+i];
				//cout << " *Divisor: "<< Divisor;
				for(j=0;j<n*2;j++){
					Equation[(i*n*2)+j]/=Divisor;
					//cout << "Eq "<< j<< " = "<< Equation[(i*n*2)+j];
				}
			}
			PrintCapturedValues();
			
		
			for(j=0; j<m; j++){
				if(j!=i){
					
					Paso++;
					cout<<"Paso #" << Paso<<endl;
					File<<"Paso #" << Paso<<endl;
					
					Factor=Equation[(j*n*2)+i]*(-1.0f);
					//cout << "factor="<<Factor<<" j="<<j<<" i="<< i<< " ";
					for(k=0; k<n*2; k++){
						TempEq[k]=Factor*Equation[(i*n*2)+k];
						//cout << "tempEq="<<TempEq[k];
					}
					for(k=0; k<n*2; k++)Equation[(j*n*2)+k]+=TempEq[k];
					PrintCapturedValues();
				}
			}
            
			
		}

		
		system("notepad Output.txt");
	}
	
	
};

int main(void)
{
	Equationes Sample;
	Sample.SetValuesToArray();
	Sample.GaussMetod();

	return 0;
	
}

