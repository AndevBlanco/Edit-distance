#include<bits/stdc++.h> 
using namespace std; 
// Función de utilidad para encontrar el mínimo de tres números
int contI=0;
int contR=0;
int conRe=0;
int min(int x, int y, int z){ 
   if(min(min(x, y), z)==y){
   	contI=+1;
   	//cout<<"Se realizo una eliminacion cuyo peso es de 1"<< endl; 
   }
   if(min(min(x, y), z)==x){
   	//cout<<"se realizo una insersion cuyo peso es de 2 "<<endl;
   }
    if(min(min(x, y), z)==z){
   	//cout<<"Se realizo un remplazo cuyo peso es de 3"<<endl;
   }
	return min(min(x, y), z); 
} 

int editDistDP(string str1, string str2, int m, int n){ 
	// Crear una tabla para almacenar resultados de subproblemas
	int dp[m+1][n+1]; 
	// llenar d[][] de abajo hacia arriba
	for (int i=0; i<=m; i++){ 
		for (int j=0; j<=n; j++){ 
			// Si la primera cadena está vacía, la única opción es
			// inserta todos los caracteres de la segunda cadena
			if (i==0){ 
				dp[i][j] = j*2; // Min. operaciones = j 
			}
			// Si la segunda cadena está vacía, la única opción es
			// elimina todos los caracteres de la segunda cadena
			else if (j==0){ 
				dp[i][j] = i; // Min. operations = i 
			}
			// Si los últimos caracteres son iguales, ignore el último carácter
			// y se repite para la cadena restante
			else if (str1[i-1] == str2[j-1]){ 
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
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			cout<<dp[i][j]<<"   ";
		}
		cout<<endl;
	}
	return dp[m][n]; 
} 
int main(){ 
	string str1 = "agcttacc"; 
	string str2 = "acgtaatcag"; 

	cout << editDistDP(str1, str2, str1.length(), str2.length()); 

	return 0; 
}
