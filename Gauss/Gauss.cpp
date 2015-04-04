#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <fstream>

char TextResults[5][50]={
	"Que pedo no hubo resultado","Solucion Unica","Solucion Infinita","Sin Solucion"
};

using namespace std;
class Equationes{
public:
	float Equation[15];
	int Result; 
	int i;
	ofstream File;

	
	enum Results{
		NOT_SET_YET,
		UNIQUE_SOLUTION,
		INFINITE_SOLUTION,
		WITHOUT_SOLUTION
	};
	
	
	
	void SetInitialValueToArray(void){
		for(i=0;i<12;i++)Equation[i]=0;	
		Result=0;
		File.open("Output.txt");
	}
	void SetValuesToArray(void){
		system("cls");
		cout << "*********    Metodo Gauss-Jordan-Silva   *********"<<endl;
		cout << "     Ejemplo de Formato:"<<endl<<"        0x+-2y+3.5z=36 " <<endl << "1.-Solo se pueden sistemas de 3 Variables"<<endl
			<<"2.-Si no tienes valor en alguna de las variables respeta el formato agrega el 0"<<endl
			<<"3.-Si tienes un numero Negativo debes pones +- como en el ejemplo EXCEPTO EN EL = ahi si se puede"<<endl
			<<"4.-Si Tienes un quebrado de entrada ponlo en decimales"<<endl
			<<"5.-Este programa usa la logica del PUNTO FLOTANTE "<< endl<<"si utilizas fracciones muy complicadas puede haber un margen de error"<<endl
		    <<"6.-Si no respetas el formato el programa no funcionara bien"<<endl<<endl;
		cout<< "Primera Equation:  ";
		scanf("%fx+%fy+%fz=%f",&Equation[0],&Equation[1],&Equation[2],&Equation[3]);
		
		cout << "Segunda Equation:  ";
		scanf("%fx+%fy+%fz=%f",&Equation[4],&Equation[5],&Equation[6],&Equation[7]);
		
		cout << "Tercera Equation:  ";
		scanf("%fx+%fy+%fz=%f",&Equation[8],&Equation[9],&Equation[10],&Equation[11]);
		
		cout << endl <<endl;
		
	}
	void PrintCapturedValues(void){
		cout <<"[  "<<Equation[0]<<"  "<<Equation[1]<<"  "<<Equation[2]<<"  |  "<<Equation[3]<<"  ]"<<endl;
		cout <<"[  "<<Equation[4]<<"  "<<Equation[5]<<"  "<<Equation[6]<<"  |  "<<Equation[7]<<"  ]"<<endl;
		cout <<"[  "<<Equation[8]<<"  "<<Equation[9]<<"  "<<Equation[10]<<"  |  "<<Equation[11]<<"  ]"<<endl<<endl;	
		
		File <<"[  "<<Equation[0]<<"  "<<Equation[1]<<"  "<<Equation[2]<<"  |  "<<Equation[3]<<"  ]"<<endl;
		File <<"[  "<<Equation[4]<<"  "<<Equation[5]<<"  "<<Equation[6]<<"  |  "<<Equation[7]<<"  ]"<<endl;
		File <<"[  "<<Equation[8]<<"  "<<Equation[9]<<"  "<<Equation[10]<<"  |  "<<Equation[11]<<"  ]"<<endl<<endl;	 
		
	}
	void CheckResult(void){
		float temp=0;
		
		for(i=4;i<7;i++)temp+=Equation[i];
		if(temp==0&&Result==NOT_SET_YET){
           if(Equation[7]!=0)Result=WITHOUT_SOLUTION;
           else Result=INFINITE_SOLUTION;
        }
		temp=0;
		for(i=8;i<11;i++)temp+=Equation[i];
		if(temp==0&&Result==NOT_SET_YET){
            if(Equation[11]!=0)Result=WITHOUT_SOLUTION;
            else Result=INFINITE_SOLUTION;
        }
	}
	void GaussMetod(void){
		float Divisor,Factor;
		float TempEq[4];
		for(i=0;i<12;i++)TempEq[i]=0;	
		//Fase 1 Asegurar tener un 1 en la Primera Fila Primera Columna
		
		if(Equation[0]!=1){
			Divisor=Equation[0];
			for(i=0;i<4;i++)Equation[i]/=Divisor;
		}
		
		CheckResult();
		PrintCapturedValues();
		
		//Fase 2 Restas la primera por la segunda para que sea 0
		if(Result==NOT_SET_YET){
			Factor=Equation[4]*(-1.0f);
			for(i=0;i<4;i++)TempEq[i]=Factor*Equation[i];
			for(i=0;i<4;i++)Equation[4+i]+=TempEq[i];
			CheckResult();
            PrintCapturedValues();
			
		}
		
		//Fase 3
		if(Result==NOT_SET_YET){
			Factor=Equation[8]*(-1.0f);
			for(i=0;i<4;i++)TempEq[i]=Factor*Equation[i];
			for(i=0;i<4;i++)Equation[8+i]+=TempEq[i];
			CheckResult();
            PrintCapturedValues();
		}
		
		//Fase 4
		if(Result==NOT_SET_YET){
			if(Equation[5]!=1){
				Divisor=Equation[5];
				for(i=1;i<4;i++)Equation[4+i]/=Divisor;
			}
			CheckResult();
            PrintCapturedValues();
		}
		
		//Fase 5 Restas la segunda por la tercera para que sea 0
		if(Result==NOT_SET_YET){
			Factor=Equation[9]*(-1.0f);
			for(i=1;i<4;i++)TempEq[i]=Factor*Equation[4+i];
			for(i=1;i<4;i++)Equation[8+i]+=TempEq[i];
			CheckResult();
            PrintCapturedValues();
		}
		
		//Fase 6
		if(Result==NOT_SET_YET){
			if(Equation[10]!=1){
				Divisor=Equation[10];
				for(i=2;i<4;i++)Equation[8+i]/=Divisor;
			}
			CheckResult();
            PrintCapturedValues();
		}
		
		//Fase 7 Restas la segunda por la tercera para que sea 0
		if(Result==NOT_SET_YET){
			Factor=Equation[1]*(-1.0f);
			for(i=1;i<4;i++)TempEq[i]=Factor*Equation[4+i];
			for(i=1;i<4;i++)Equation[i]+=TempEq[i];
			CheckResult();
            PrintCapturedValues();
		}
		
		//Fase 8 Restas la segunda por la tercera para que sea 0
		if(Result==NOT_SET_YET){
			Factor=Equation[2]*(-1.0f);
			for(i=2;i<4;i++)TempEq[i]=Factor*Equation[8+i];
			for(i=2;i<4;i++)Equation[i]+=TempEq[i];
			CheckResult();
            PrintCapturedValues();
		}
		
		//Fase 9 Restas la segunda por la tercera para que sea 0
		if(Result==NOT_SET_YET){
			Factor=Equation[6]*(-1.0f);
			for(i=2;i<4;i++)TempEq[i]=Factor*Equation[8+i];
			for(i=2;i<4;i++)Equation[4+i]+=TempEq[i];
			CheckResult();
            PrintCapturedValues();
		}
		if(Result==NOT_SET_YET){
			Result=UNIQUE_SOLUTION;
		}
		PrintCapturedValues();
		cout << endl <<"Resultado: ***"<<TextResults[Result]<<"***"<<endl;
		File << endl <<"Resultado: ***"<<TextResults[Result]<<"***"<<endl;
		system("notepad Output.txt");
	}
	
	
};

int main(void)
{
	Equationes Sample;
	Sample.SetInitialValueToArray();
	Sample.SetValuesToArray();
	Sample.GaussMetod();
	
	
	
	return 0;
	
}

