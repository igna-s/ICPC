//To see the problems

///https://codeforces.com/group/roU9OApnmM/contest/520256



//A - Distinct Numbers

#include <bits/stdc++.h>
using namespace std;



int main() {


  int n;
  cin >> n;
  set<int> cant;

  vector<int> puntaje(n);

  for (int i=0;i<n;i++){
       cin >> puntaje[i];
      cant.insert(puntaje[i] );
  }

  return cant.size();

}


//B - Restaurant Customers	

#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()

using namespace std;

int main() {
    int n, a, b;
    cin >> n;

    map<int, int> changes;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        changes[a]++;
        changes[b]--;
    }

    int current = 0, max_overlap = 0;

    for (auto [pos, delta] : changes) {
        current += delta;
        max_overlap = max(max_overlap, current);
    }

    cout << max_overlap << endl;

    return 0;
}


//C - Sum of Two Values


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> numeros(n);
    map<int, int> encontrado;
    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }
    for (int i = 0; i < n; i++) {
        int requerido = x - numeros[i];
        if (encontrado.find(requerido) != encontrado.end()) {
            cout << encontrado[requerido] + 1 << " " << i + 1 << endl;
            return 0;
        }
        encontrado[numeros[i]] = i;
    }
    cout << -1 << endl;
    return 0;
}


//D - Nearest Smaller Values

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numeros(n);
    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }

    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && numeros[s.top()] >= numeros[i]) {
            s.pop();
        }

        if (s.empty()) {
            cout << 0 << " ";
        } else {
            cout << s.top() + 1 << " ";
        }

        s.push(i);
    }

    cout << "\n";
    return 0;
}



//E - Maximum Subarray Sum



#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;  

    vector<long long> arreglo(n);
    for (int i = 0; i < n; i++) {
        cin >> arreglo[i]; 
    }
    
    long long sumaActual = arreglo[0];
    long long maximoSuma = arreglo[0];
    

    for (int i = 1; i < n; i++) {
        sumaActual = max(arreglo[i], sumaActual + arreglo[i]);
        maximoSuma = max(maximoSuma, sumaActual);
    }
    
    cout << maximoSuma << endl;
    return 0;
}






//F - Room Allocation


#include <bits/stdc++.h>
using namespace std;

struct Cliente {
    int llegada;
    int salida;
    int indice;
};

int main() {
    int n;
    cin >> n;

    vector<Cliente> clientes(n);
    for (int i = 0; i < n; i++) {
        cin >> clientes[i].llegada >> clientes[i].salida;
        clientes[i].indice = i;
    }

    sort(clientes.begin(), clientes.end(), [](const Cliente &a, const Cliente &b) {
        return a.llegada < b.llegada;
    });

    // Cola de prioridad (min-heap) para almacenar pares: (día de salida, número de habitación)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    vector<int> asignacion(n);
    int habitacionesTotales = 0;

    for (auto &c : clientes) {
        // Si existe una habitación que se desocupe antes del día de llegada actual, la reutilizamos
        if (!minHeap.empty() && minHeap.top().first < c.llegada) {
            pair<int, int> top = minHeap.top();
            minHeap.pop();
            int numHabitacion = top.second;
            asignacion[c.indice] = numHabitacion;
            minHeap.push({c.salida, numHabitacion});
        } else {
            // Si no hay habitación disponible, asignamos una nueva habitación
            habitacionesTotales++;
            asignacion[c.indice] = habitacionesTotales;
            minHeap.push({c.salida, habitacionesTotales});
        }
    }

    cout << habitacionesTotales << "\n";
    for (int i = 0; i < n; i++) {
        cout << asignacion[i] << " ";
    }
    cout << "\n";

    return 0;
}



//G - Factory Machines

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long t;
    cin >> n >> t;

    vector<long long> tiempos(n);
    for (int i = 0; i < n; i++) {
        cin >> tiempos[i];
    }


    long long maxi = *max_element(tiempos.begin(), tiempos.end());
    long long low = 0, high = maxi * t;

    while (low < high) {
        long long mid = (low + high) / 2;

        long long total = 0;
        for (int i = 0; i < n; i++) {
            total += mid / tiempos[i];

            if(total >= t) break;
        }

        if(total >= t) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << low << "\n";
    return 0;
}





//H - Subarray Divisibility


#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;


    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<long long> count(n, 0);

    long long suma = 0;
    long long result = 0;


    count[0] = 1;

    for (int i = 0; i < n; i++) {
        suma += arr[i];

        int mod = ((suma % n) + n) % n;

        result += count[mod];

        count[mod]++;
    }

    cout << result << "\n";
    return 0;
}


//I - Array Division

#include <bits/stdc++.h>

using namespace std;

bool esPosible(const vector<long long>& arr, int k, long long limite) {
    int subarreglos = 1;
    long long sumaActual = 0;

    for (long long x : arr) {

        if (sumaActual + x > limite) {
            subarreglos++;
            sumaActual = x;

            if (subarreglos > k)
                return false;
        } else {
            sumaActual += x;
        }
    }
    return true;
}

int main() {
  
    int n, k;
    cin >> n >> k;

    vector<long long> arr(n);
    long long sumaTotal = 0;
    long long maxElemento = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sumaTotal += arr[i];
        maxElemento = max(maxElemento, arr[i]);
    }


    long long low = maxElemento, high = sumaTotal, respuesta = high;

    while (low <= high) {
        long long mid = (low + high) / 2;

        if (esPosible(arr, k, mid)) {
            respuesta = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << respuesta << "\n";
    return 0;
}
