//To see the problems

///https://codeforces.com/group/roU9OApnmM/contest/519743/my


/*
//A - Watermelon

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    if ((n%2==0)&&(n!=2))
    cout << "YES";
    else
    cout << "NO";
}


//B - Way Too Long Words

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string hola;

    for (int i = 0; i < n; i++) {
        cin >> hola;
        int x = hola.size();
        if (x > 10) {
            cout << hola[0] << to_string(x - 2) << hola[x - 1] << "\n";
        } else {
            cout << hola << "\n";
        }
    }
    return 0;
}



//C. Team


#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    int count = 0;

    while(n--) {
        int petya, vasya, tonya;
        cin >> petya >> vasya >> tonya;
        if (petya + vasya + tonya >= 2)
            count++;
    }

    cout << count;
    return 0;
}


//D - Theatre Square

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m, a;
    cin >> n >> m >> a;

    long long tot = n / a;
    if (n % a != 0) tot++;

    long long tot2 = m / a;
    if (m % a != 0) tot2++;

    cout << tot * tot2;
    return 0;
}




//E - Bit++



#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x = 0;
    cin >> n;

    string cadena;
    for (int i = 0; i < n; i++) {
        cin >> cadena;
        if (cadena == "++X" || cadena == "X++")
            x++;
        else
            x--;
    }

    cout << x;
    return 0;
}







//F - Next Round


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> puntaje(n);
    for (int i = 0; i < n; i++) {
        cin >> puntaje[i];
    }

    int corte = puntaje[k - 1];
    int i = 0;

    while ((i < n) && (puntaje[i] >= corte) && (puntaje[i] > 0)) {
        i++;
    }

    cout << i;
    return 0;
}



//G. String Task

#include <bits/stdc++.h>
using namespace std;


bool esVocal(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'|| c == 'y' );
}


int main() {
    string valores;
    cin >> valores;
    string aux;

    for (char c : valores) {
        c = tolower(c);
        if (!esVocal(c)) {
            aux += ".";
            aux += c;
        }
    }

    cout <<aux;
 return 0;
}





//H. IQ test

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> lista(n);

    for (int i = 0; i < n; i++) {
        cin >> lista[i];
    }

    int pares = 0, impares = 0;
    for (int i = 0; i < 3; i++) {
        if (lista[i] % 2 == 0) pares++;
        else impares++;
    }


    bool buscarPar = impares > pares;


    for (int i = 0; i < n; i++) {
        if ((lista[i] % 2 == 0) == buscarPar) {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}

*/
//I. Cut Ribbon

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> dp(n + 1, -1e9);
    dp[0] = 0; 

    for (int i = 1; i <= n; i++){
        if(i >= a)
            dp[i] = max(dp[i], dp[i - a] + 1);
        if(i >= b)
            dp[i] = max(dp[i], dp[i - b] + 1);
        if(i >= c)
            dp[i] = max(dp[i], dp[i - c] + 1);
    }

    cout << dp[n];
    return 0;
}
