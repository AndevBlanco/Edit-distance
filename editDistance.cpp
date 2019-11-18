#include <bits/stdc++.h>
using namespace std;
// funcion para calcular la penalidad
void penalidad(string x, string y, int psus, int peli){
    int i, j;

    int m = x.length(); // longitud de cadena1
    int n = y.length(); // longitud de cadena2
	// tabla para guardar la subestructura de la solucion optima
    int dp[n+m+1][n+m+1] = {0};

    // inicializacion de la tabla
    for (i = 0; i <= (n+m); i++){
        dp[i][0] = i * peli;
        dp[0][i] = i * peli;
    }

    // calculando la penalidad
    for (i = 1; i <= m; i++){
        for (j = 1; j <= n; j++){
            if (x[i - 1] == y[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = min({dp[i - 1][j - 1] + psus , dp[i - 1][j] + peli, dp[i][j - 1] + peli    });
            }
        }
    }

    // reconstruyendo la solucion
    int l = n + m; // longitud maxima posible

    i = m; j = n;

    int xpos = l;
    int ypos = l;
	// respuesta final para las cadenas
    int xres[l+1], yres[l+1];

    while ( !(i == 0 || j == 0)){
        if (x[i - 1] == y[j - 1]){
            xres[xpos--] = (int)x[i - 1];
            yres[ypos--] = (int)y[j - 1];
            i--; j--;
        }
        else if (dp[i - 1][j - 1] + psus == dp[i][j]){
            xres[xpos--] = (int)x[i - 1];
            yres[ypos--] = (int)y[j - 1];
            i--; j--;
        }
        else if (dp[i - 1][j] + peli == dp[i][j]){
            xres[xpos--] = (int)x[i - 1];
            yres[ypos--] = (int)'_';
            i--;
        }
        else if (dp[i][j - 1] + peli == dp[i][j]){
            xres[xpos--] = (int)'_';
            yres[ypos--] = (int)y[j - 1];
            j--;
        }
    }
    while (xpos > 0){
        if (i > 0) xres[xpos--] = (int)x[--i];
        else xres[xpos--] = (int)'_';
    }
    while (ypos > 0){
        if (j > 0) yres[ypos--] = (int)y[--j];
        else yres[ypos--] = (int)'_';
    }

    // Dado que asumimos que la respuesta tiene una longitud de n + m,
    // necesitamos eliminar los espacios adicionales en el
    // id inicial que representa el índice del que son útiles las matrices
    // xres, xres
    int id = 1;
    for (i = l; i >= 1; i--){
        if ((char)yres[i] == '_' && (char)xres[i] == '_'){
            id = i + 1;
            break;
        }
    }

    // imprimiendo la respuesta final
    cout << "Distancia de edicion = ";
    cout << dp[m][n] << "\n";
    cout << "Las cadenas transformadas son :\n";
    for (i = id; i <= l; i++){
        cout<<(char)xres[i];
    }
    cout << "\n";
    for (i = id; i <= l; i++){
        cout << (char)yres[i];
    }
    return;
}
int main(){
    // cadenas de entrada
    string cadena1 = "AGCTTACC";
    string cadena2 = "ACGTAATCAG";

    // inicializando el valor de las penalizaciones
    int sustitucion = 3;
    int eliminacion = 2;

    // llamado de la funcion para calcular la penalidad
    penalidad(cadena1, cadena2, sustitucion, eliminacion);
    return 0;
}
