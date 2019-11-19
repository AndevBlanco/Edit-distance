#include<bits/stdc++.h>
using namespace std;
// Función para encontrar el mínimo de tres números
int min(int x, int y, int z){
   if(min(min(x, y), z)==y){
   	//cout<<"Valor "<<y<< endl;
   }
   if(min(min(x, y), z)==x){
   	//cout<<"Valor "<<x<<endl;
   }
	if(min(min(x, y), z)==z){
   	//cout<<"Valor "<<z<<endl;
   }
	return min(min(x, y), z);
}

int editDistDP(string cadena1, string cadena2, int m, int n){
	// Crear una tabla para almacenar resultados de subproblemas
	int dp[m+1][n+1];
	// llenar d[][] de abajo hacia arriba
	for (int i=0; i<=m; i++){
		for (int j=0; j<=n; j++){
			// Si la primera cadena está vacía, la única opción es
			// inserta todos los caracteres de la segunda cadena
			if (i==0){
				dp[i][j] = j*2; // Operaciones = j
			}
			// Si la segunda cadena está vacía, la única opción es
			// elimina todos los caracteres de la segunda cadena
			else if (j==0){
				dp[i][j] = i; // Operations = i
			}
			// Si los últimos caracteres son iguales, ignore el último carácter
			// y se repite para la cadena restante
			else if ((cadena1[i-1] == cadena2[j-1]) && (i == j)){
				dp[i][j] = dp[i-1][j-1];
			}
			// Si el último caracter es diferente, considere todos
			// posibilidades y encuentra el mínimo
			else{
				dp[i][j] = min(dp[i][j-1]+2 , // Insertar
								dp[i-1][j]+1 , // Remover
								dp[i-1][j-1]+3 ); // Reemplazar
			}
		}
	}
	//Imprimir la matriz
	cout<<"         A    G    C    T    T    A    C    C    A    G"<<endl<<endl<<"    ";
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			string s=to_string(dp[i][j]);
			if(s.length()==1){
				cout<<dp[i][j]<<"    ";
			}else{
				cout<<dp[i][j]<<"   ";
			}
			
		}
		cout<<endl<<endl;
		cout<<cadena1[i]<<"   ";
	}
	cout <<endl<<"La distancia de edicion es: "<<dp[m][n];
	return dp[m][n];
}
int main(){
	string cadena1 = "AGCTTACC";
	string cadena2 = "ACGTAATCAG";
	cout<<"Cadena Inicial: "<<cadena1<<endl<<"Cadena Final:   "<<cadena2<<endl;
	cout<<endl<<"El peso de la eliminacion es: 1"<<endl<<"El peso de la insercion es:   2"<<endl<<"El peso de la sustitucion es: 3"<<endl<<endl;
	editDistDP(cadena1, cadena2, cadena1.length(), cadena2.length());
	
	return 0;
}
