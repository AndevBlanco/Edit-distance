#include<bits/stdc++.h>
using namespace std;
int edicion=0;
// Función para encontrar el mínimo de tres números
int min(int x, int y, int z){
	if(min(min(x, y), z)==y){
		edicion=1;
	}
	if(min(min(x, y), z)==x){
		edicion=0;
	}
	if(min(min(x, y), z)==z){
		edicion=2;
	}
	return min(min(x, y), z);
}

int editDistDP(string cadena1, string cadena2, int m, int n){
	// Crear una tabla para almacenar resultados de subproblemas
	int dp[m+1][n+1];
	string array[3]={"Insertar","Eliminar","Sustituir"};
	// llenar d[][] de abajo hacia arriba
	for (int i=0; i<=m; i++){
		for (int j=0; j<=n; j++){
			// Si la primera cadena está vacía, la única opción es
			// inserta todos los caracteres de la segunda cadena
			if (i==0){
				dp[i][j] = j*2; // Operaciones = j
				cout<<"Caso base: primera cadena esta vacia, se asigna "<<j*2<<" en ["<<i<<"]["<<j<<"]"<<endl;
			}
			// Si la segunda cadena está vacía, la única opción es
			// elimina todos los caracteres de la segunda cadena
			else if (j==0){
				dp[i][j] = i; // Operations = i
				cout<<"Caso base: segunda cadena esta vacia, se asigna "<<i<<" en ["<<i<<"]["<<j<<"]"<<endl;
			}
			// Si los últimos caracteres son iguales, ignore el último carácter
			// y se repite para la cadena restante
			else if ((cadena1[i-1] == cadena2[j-1]) && (i == j)){
				dp[i][j] = dp[i-1][j-1];
				cout<<endl<<"Caracteres iguales entre las cadenas, se asigna "<<dp[i-1][j-1]<<" en ["<<i<<"]["<<j<<"]"<<endl<<endl;
			}
			// Si el caracter es diferente, considere todos
			// posibilidades y encuentra el mínimo
			else{
				dp[i][j] = min(dp[i][j-1]+2 , // Insertar
								dp[i-1][j]+1 , // Remover
								dp[i-1][j-1]+3 ); // Reemplazar
				if(edicion==0){
					cout<<"La cadena 1 falta de caracteres se procede a "<<array[edicion]<<" "<<cadena1[i]<<endl;
				}else if(edicion==1){
					cout<<"La cadena 1 tiene caracteres sobrantes se procede a "<<array[edicion]<<" "<<cadena1[i]<<endl;
				}else if(edicion==2){
					cout<<"La cadena 1 y 2 tiene caracteres diferentes se procede a "<<array[edicion]<<" "<<cadena1[i]<<" por "<<cadena2[j]<<endl;
				}
				cout<<endl<<array[edicion]<<", se asigna "<<dp[i][j]<<" en ["<<i<<"]["<<j<<"] (suma de los pesos)"<<endl<<endl;
			}
		}
	}
	//Imprimir la matriz
	cout<<endl;
	cout<<"          A     C     G     T      A     A     T     C     A     G"<<endl<<endl<<"    ";
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			string s=to_string(dp[i][j]);
			if(s.length()==1){
				cout<<dp[i][j]<<"  |  ";
			}else{
				cout<<dp[i][j]<<"  | ";
			}
			
		}
		cout<<endl<<"   ------------------------------------------------------------------"<<endl;
		cout<<cadena1[i]<<"   ";
	}
	//Termina impresion de la matriz
	cout <<endl<<"La distancia de edicion es: "<<dp[m][n];
	return dp[m][n];
}
int main(){
	string cadena1 = "AGCTTACC";
	string cadena2 = "ACGTAATCAG";
	cout<<"Programa de distancia de edicion"<<endl<<endl;
	cout<<"Cadena Inicial: "<<cadena1<<endl<<"Cadena Final:   "<<cadena2<<endl;
	cout<<endl<<"El peso de la eliminacion es: 1"<<endl<<"El peso de la insercion es:   2"<<endl<<"El peso de la sustitucion es: 3"<<endl<<endl;
	editDistDP(cadena1, cadena2, cadena1.length(), cadena2.length());
	
	return 0;
}
