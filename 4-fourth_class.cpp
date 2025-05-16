//https://codeforces.com/group/roU9OApnmM/contest/522712

//A. King Escape

#include <bits/stdc++.h>
using namespace std;


int obtener_cuadricula(int fila, int columna, int reinaFila, int reinaColumna) {
    if (fila < reinaFila && columna < reinaColumna) return 1;
    if (fila < reinaFila && columna > reinaColumna) return 2;
    if (fila > reinaFila && columna < reinaColumna) return 3;
    if (fila > reinaFila && columna > reinaColumna) return 4;
    return 0;
}


bool cuadricula_valida(int reyFila, int reyColumna, int objetivoFila, int objetivoColumna, int reinaFila, int reinaColumna) {
    int cuadriculaRey = obtener_cuadricula(reyFila, reyColumna, reinaFila, reinaColumna);
    int cuadriculaObjetivo = obtener_cuadricula(objetivoFila, objetivoColumna, reinaFila, reinaColumna);
    return cuadriculaRey == cuadriculaObjetivo;
}

int main() {
    int tamanoTablero;
    cin >> tamanoTablero;

    int reinaFila, reinaColumna;
    cin >> reinaFila >> reinaColumna;

    int reyFila, reyColumna;
    cin >> reyFila >> reyColumna;

    int objetivoFila, objetivoColumna;
    cin >> objetivoFila >> objetivoColumna;

    if (cuadricula_valida(reyFila, reyColumna, objetivoFila, objetivoColumna, reinaFila, reinaColumna)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}





//It is suposed to practice Grafhs, so i´m uploading also the intended solution

//(Made by the teacher)
#include <bits/stdc++.h>
 
using namespace std;
 
bool is_in(int x,int y, int n) {
	return (x >= 0 and x < n and y >= 0 and y < n);
}
 
void DFS(int x, int y, vector<vector<bool>> &visto, int n) {
	visto[x][y] = true;
	for(int dx : {-1,0,1}) {
		for(int dy : {-1,0,1}) {
			if(is_in(x+dx,y+dy,n) and !visto[x+dx][y+dy]) {
				DFS(x+dx,y+dy,visto,n);
			}
		}
	}
}
 
int main() {
	int n; cin >> n;
	int ax, ay; cin >> ax >> ay; ax--; ay--;
	int bx, by; cin >> bx >> by; bx--; by--;
	int cx, cy; cin >> cx >> cy; cx--; cy--;
	
	vector<vector<bool>> visto(n,vector<bool>(n,false));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == ax) visto[i][j] = true;
			if(j == ay) visto[i][j] = true;
			if(ax-ay == i-j) visto[i][j] = true;
			if(ax+ay == i+j) visto[i][j] = true;
		}
	}
	
	DFS(bx,by,visto,n);
	
	if(visto[cx][cy]) cout << "YES\n";
	else cout << "NO\n";
		
	return 0;
}
