//https://codeforces.com/group/roU9OApnmM/contest/617048

// B - The Game (Perdiste)

#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
int main(){
    FIN;
    
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
 
    if(n1>n2)
        cout << "First" << "\n";
    else
        cout << "Second" << "\n";
 
    return 0;
}



// H - Uli elige la silla


#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
int main(){
    FIN;
    
    long long n, m, k, col, fil;
    string puesto = "L";
    
    cin >> n >> m >> k;
    
    col = (k-1) / (m*2) +1;
    fil = (k-(col-1)*m*2 -1) / 2 +1;
    if (k % 2 == 0)
        puesto = "R";
    
    cout << col << " " << fil << " " << puesto;
 
    return 0;
}





// I - Zort



#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
int main(){
    FIN;
    
    int n, aux;
    list<int> a;
    cin >> n;
    vector<int> respuesta(n);
    
    for(int i=0; i<n; i++){
        cin >> aux;
        a.push_back(aux);
    }
    
    a.sort();
    
    // for(int x : a){
    //     cout << x;
    // }
    
    for(int i=0; i<n; i++){
        if(i % 2 == 0){
            respuesta[i]= a.front();
            a.pop_front();
        }
        else{
            respuesta[i] = a.back();
            a.pop_back();
        }
    }
    
    // for(int i=0; i<n; i++){
    //     cout << respuesta[i];
    // }
    
    bool ordenable = true;
    int ant = 1e10;
    for(int i=0; i<n; i++){
        // cout << ant << respuesta[i] << "\n";
        if(i % 2 != 0){ //si es par debe ser mayor o igual al anterior. Tener en cuenta que si i es impar entonce ai es par
            if(respuesta[i] < ant){
                ordenable = false;
                break;
            }
        }
        else{ //si es impar entonces debe ser menor o igual al anterior
            if(respuesta[i] > ant){
                ordenable = false;
                break;
            }
        }
        
        ant = respuesta[i];
    }
    
    if(ordenable){
        for(int i=0; i<n; i++){
            cout << respuesta[i] << " ";
        }
    }
    else{
        cout << "Imposible";
    }
}




///With problems

//  C - Rodo y el mecanismo (Time limit exceeded on test 9)
#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cin.tie(0)
 
int main() {
    FIN;
    int n,t,i,val,cant,j;
    bool listo;
    string aux,aux2;
    cin >> n;
    cin >> t;
    vector<string> muestras (n);
    for (i=0;i<n;i++) cin >>muestras[i];
 
    while (t--){
 
     cin >>aux;
     listo=false;
     for (i=0;i<n;i++){
        val= aux.size();
        if (muestras[i].size()==val){
            cant=0;
            aux2=muestras[i];
            for (j=0;j<val;j++){
                    if(aux2[j]!= aux[j])
                        cant++;
                    if (cant>2)break;
            }
            if (cant==1){listo = true;
                        break;
                        }
 
        }
    }
    if (!(listo) )cout << "NO" << endl;
    else cout << "YES" << endl;
}
 
 
    return 0;
}



//D - Mortal Kombat (Wrong answer on test 2)


#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cin.tie(0)
 
int main() {
    FIN;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
 
        int i = 0, res = 0;
        bool amigo = true;
 
        while (i < n) {
            if (amigo) {
                if ((i < n)&&(a[i] == 1)) {res++;i++;}
                if ((i < n)&&(a[i] == 0)) i++;
                }
            else {
                if (i < n) i++;
                if ((i < n)&&(a[i] == 1)) i++;
                }
 
            amigo = !amigo;
        }
        cout << res << '\n';
    }
    return 0;
}



//E - Joaco el ordenador de cartas (Time limit exceeded on test 9)


#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, aux, cant=0;
    cin >> n;
    int minimo = 1;
    queue<int> q;
    multiset<int> s;
 
    for (int i = 0; i < n; i++) {
        cin >> aux;
        q.push(aux);
        s.insert(aux);
        }
 
    minimo = *s.begin();
    while (!q.empty()){
        aux = q.front();
        q.pop();
        if ((aux!= minimo)){
            q.push(aux);
        }
        else {
            if (s.count(minimo) == 1)
                s.erase(s.begin());
            else
                s.erase(s.find(minimo));
            minimo = *s.begin();
            }
        cant++;
    }
    cout << cant << endl;
    return 0;
}




// G - Reemplazo idoneo (Wrong answer on test 5)




#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
int main(){
    FIN;
    
    string s, t;
    map<char, int> mp;
    list<char> aux;
    int j=0;
    
    cin >> s >> t;
    
    for (char c: s)
        mp[c]++;
    for (char c: t)
        mp[c]--;
    
    for (auto it = mp.begin(); it != mp.end(); ++it){
        //it->first es la Key
        //it->second es el value
        while(it->second < 0){
            aux.push_back(it->first);
            it->second ++;
        }
    }
    
    // cout << s << "\n";
    
    for(int i=0; i<s.size(); i++){
        if(s[i]=='?'){
            if (aux.size() > 0){
                s[i] = aux.front();
                aux.pop_front();
            }
            else{
                if(mp[t[j]]>=0){
                    mp[t[j]]--;
                    i--;
                }
                else{
                    s[i] = t[j];
                }
                
                j++;
                if(j==t.size())
                    j=0;
            }
        }
    }
    
    cout << s << "\n";
 
    return 0;
}



