//https://codeforces.com/group/roU9OApnmM/contest/607504/standings/groupmates/true



// Oficial Solutions

// A - Depredador o presa

#include <bits/stdc++.h>
 
using namespace std;
 
#define all(c) (c).begin(),(c).end()
 
int main() {
	
	int n, a, b;
	cin >> n >> a >> b;
	vector <int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	vector <int> todos = v;
	sort(all(todos));
	
	for(int x : v) {
		cout << lower_bound(all(todos),x+b) - lower_bound(all(todos),x+a) << " ";
		cout << upper_bound(all(todos),x-a) - upper_bound(all(todos),x-b) << "\n";
	}
	
	
	return 0;
}


// B - Traductor profesional



#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	
	int n, m;
	cin >> n >> m;
	map <string,string> mapa;
	for(int i = 0; i < n; i++) {
		string pal1, pal2;
		cin >> pal1 >> pal2;
		mapa[pal1] = pal2;
	}
	for(int i = 0; i < m; i++) {
		string pal; cin >> pal;
		cout << mapa[pal] << " ";
	}
	cout << "\n";
	
	
	return 0;
}




// C - Ahorremos electricidad que salta la térmica


#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	
	int t; cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		cout << (n * m + 1) / 2 << "\n";
	}
	return 0;
}




// D - El SuperHiperMegaReContra Cargador


#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define all(c) (c).begin(),(c).end()
 
struct device {
	int a, b;
};
 
int main() {
	
	int n, p;
	cin >> n >> p;
	
	vector <device> v(n);
	for(int i = 0; i < n; i++) cin >> v[i].a >> v[i].b;
	bool infinito = true;
	ll acum = 0;
	for(int i = 0; i < n; i++) {
		if(p < v[i].a) infinito = false;
		acum += v[i].a;
	}
	if(acum > p) infinito = false;
	if(infinito) {
		cout << "-1\n";
		return 0;
	}
	ld l = 0, r = 1e11;
	for(int _ = 0; _ < 64; _++) {
		ld med = (l+r)/2;
		ld total_uso = 0;
		for(int i = 0; i < n; i++) {
			if((ld)v[i].b - med * v[i].a < 0) {
				total_uso += (med * v[i].a - v[i].b) / (ld)p;
			}
		}
		if(total_uso > med) r = med;
		else l = med;
	}
	cout << fixed << setprecision(10) << l << "\n";
	
	
	
	return 0;
}




//E - Los cristales del Turko


#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	
	int n;
	cin >> n;
	for(int i = n/2; i >= 0; i--) {
		int cantD = n - 2*i;
		for(int j = 0; j < i; j++) cout << "*";
		for(int j = 0; j < cantD; j++) cout << "D";
		for(int j = 0; j < i; j++) cout << "*";
		cout << "\n";
	}
	for(int i = 1; i <= n/2; i++) {
		int cantD = n - 2*i;
		for(int j = 0; j < i; j++) cout << "*";
		for(int j = 0; j < cantD; j++) cout << "D";
		for(int j = 0; j < i; j++) cout << "*";
		cout << "\n";
	}
	return 0;
}



// F - Searching Local Minimum

#include <bits/stdc++.h>
 
using namespace std;
 
int query(int n) {
	cout << "? " << n << endl;
	int ans; cin >> ans;
	return ans;
}
 
int main() {
	int n; cin >> n;
	
	int l = 1, r = n;
	while(r-l > 0) {
		int med = (l+r)/2;
		int val = query(med);
		int val2 = query(med+1);
		if(val < val2) r = med;
		else l = med+1;
	}
	cout << "! " << l << endl;
	return 0;
}



// G - MORNAZO


#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	
	string pal; cin >> pal;
	for(int i = 0; i < pal.size(); i++) {
		if(pal[i] == '.') {
			cout << "0";
		} else {
			if(pal[i+1] == '.') {
				cout << "1";
			} else {
				cout << "2";
			}
			i++;
		}
	}
	cout << "\n";
	
	return 0;
}









// My solutions 

// E - Los cristales del Turko

#include <bits/stdc++.h>
using namespace std;

int main() {
    int i,t,n,m;

        char d = 'D';
        cin>>n;
        int  actizq = (n/2) , actder =(n/2) ;
        string s (n,'*');


        for (i=0;i<n;i++){

            s[actizq]=d;
            s[actder]=d;




            actizq--;
            actder++;

            if(actizq<0){
                   actizq=n-1;
                   actder=0;
                   d='*';
            }

            cout << s  << "\n";

}
return 0;}







// B - Traductor profesional

#include <bits/stdc++.h>
using namespace std;

int main() {
    int i,t,n,m;

        cin>>n;
        cin>>m;

        string aux,aux2;
        map<string,string> s;
        string res;

        for (i=0;i<n;i++){
            cin>> aux;
            cin>> aux2;
            s[aux]=aux2;
        }

        for (i=0;i<m-1;i++){
            cin>> aux;
            res+= s[aux];
            res+= ' ';
        }

        cin>> aux;
        res+= s[aux];
        res+= "\n";
        cout << res;
        return 0;
}







// My solutions (With corrections)



// C - Ahorremos electricidad que salta la térmica

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,n,m;
    cin >> t;


    while (t--){

        int n,m;
        cin >> n;
        cin >> m;

        int  tot = (n / 2)*m;

        if (n % 2 != 0) tot+= (m/2);

        if (n%2 != 0 and m % 2 != 0) tot++;



        cout << tot  << "\n";

}
return 0;
}





// G - MORNAZO



#include <bits/stdc++.h>
using namespace std;

int main() {
    string mornazo;
    cin >> mornazo;
    string res;
    res.reserve(mornazo.size());

    for (int i = 0; i < (int)mornazo.size(); i++) {
        if (mornazo[i] == '.') {
            res += '0';
        } else {
            if (i + 1 < (int)mornazo.size() && mornazo[i+1] == '.') {
                res += '1';
            } else {
                res += '2';
            }
            i++;
        }
    }

    cout << res << "\n";
    return 0;
}
