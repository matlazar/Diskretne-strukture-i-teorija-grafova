#include <iostream>
using namespace std;
int roditelj[100];
int a, b, u, v, i, j;

int pronadji(int i){
	while(roditelj[i]){
		i = roditelj[i];
	}
	return i;
}

bool relacija(int i, int j){
	if (i != j){
		roditelj[j] = i;
		return true;
	}
	return false;
}

int main(){
	int n;
	int brojVeza = 1;
	int minCijena = 0;
	int min;

	int graf[100][100];
	char vrhovi[100];
	
	cout << "Kruskalovog algoritma" << endl;
	cout << "------------------------------------" << endl;	 
	cout << "Broj vrhova: ";
	cin >> n;
	cout << "------------------------------------" << endl;
	cout << "Oznacite vrhove slovima " << endl;
	cout << "------------------------------------" << endl;
	for (int i = 0; i<n;i++){
		cout<<"Ime" << " " <<  i+1 << ".vrha: ";
		cin >> vrhovi[i];
	}
	
	cout << "------------------------------------" << endl;
	cout << "Unesite matricu vrijednosti: " << endl;
	cout << "------------------------------------" << endl;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			if(i == j){
				graf[i][j] = 0;
			}else{
				cout << "Brid: " << vrhovi[i-1] << "-" << vrhovi[j-1] << ": ";
				cin >> graf[i][j];
			}	
			if (graf[i][j] == 0){
				graf[i][j] = 100;
			}
		}
	}
	
	cout << "------------------------------------" << endl;
	cout << "Ispis matrice" << endl;
	cout << "------------------------------------" << endl;
	for(int i = 0; i < n; i++){
	 if(i == 0) cout << "   " << vrhovi[i] << " ";
	 else if(i == n-1) cout << vrhovi[i] << endl;
	 else cout << vrhovi[i] << " ";
	 }
	for(int i = 1; i <= n; i++){
		cout << vrhovi[i-1] << "|" << " ";
		for(int j = 1; j<=n; j++){
			if(graf[i][j] == 100){
				cout << 0 << " ";
			}else{
				cout << graf[i][j] << " ";
			}
			
			if(j == n){
				cout << endl;
			}
		}
	}
	
	cout << "------------------------------------" << endl;
	cout << "Ispis veza: " << endl;
	cout << "------------------------------------" << endl;
	while(brojVeza < n){
		min = 100;
		for (int i=1; i<=n; i++){
			for (int j=i+1; j<=n; j++){
				if (graf[i][j] < min){
					min = graf[i][j];
					a = u = i;
					b = v = j;
				}
			}
		}
		u=pronadji(u);
		v=pronadji(v);
		if(relacija(u,v)){
			cout << brojVeza << " veza: (" << vrhovi[a-1] << "," << vrhovi[b-1] << ") = " << min << endl;
			brojVeza++;
			minCijena += min;
		}
		graf[a][b] = graf[b][a] = 100;
	}
	cout << "------------------------------------" << endl;
	cout << endl << "Minimalna tezina: " << minCijena << endl;
	cout << "------------------------------------" << endl;
	system("PAUSE");
	return 0;
}
