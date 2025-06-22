//https://cses.fi/problemset/     (Range Queries)


//Repasinho

/*

Estructura                  Uso principal                    Construcción    Consulta       Actualización    Espacio      Notas
--------------------------- -------------------------------- --------------------------------------------     ------------
Prefix Sum Array           Sumas de rango estáticas         O(n)            O(1)           O(n)             O(n)         Muy simple; no dinámico
Sqrt Decomposition         Consultas + updates moderados    O(n)            O(√n)          O(1)             O(n)         Fácil de implementar
Sparse Table               RMQ/min/max estático             O(n·log n)      O(1)           —                O(n·log n)   Sólo idempotentes, sin updates
Segment Tree               Consultas + updates rápidos      O(n)            O(log n)       O(log n)         O(n)         Versátil; admite casi cualquier f(range)


1. Prefix Sum Array (Arreglo de sumas acumuladas)

Uso: Cuando sólo necesitas consultas de rango (por ejemplo, suma de A[l…r]), sin actualizaciones intermedias.
Construcción: Precomputas P[i] = A[0] + … + A[i] en O(n).
Consulta: Suma rango en O(1): sum(l,r) = P[r] - (l>0 ? P[l-1] : 0).
Actualización: No admite bien actualizaciones; si cambias un elemento debes recomputar todo (O(n)).

2. Square Root Decomposition (Descomposición por raíz cuadrada)

Uso: Cuando quieres algo más dinámico que prefix sums, con actualizaciones y consultas, y prefieres implementarlo rápido.
Bloques: Divides en bloques de tamaño ≈√n.
Construcción: Preprocesas sumas parciales por bloque en O(n).
Consulta: O(√n) por combinar bloques completos + extremos parciales.
Actualización: O(1) para actualizar elemento y su bloque, o O(1)–O(√n) según el problema.

3. Sparse Table

Uso: Para consultas idempotentes en arreglos estáticos (RMQ, min, max, gcd…), sin actualizaciones.
Construcción: O(n log n) con DP de potencias de 2.
Consulta: O(1) usando dos superposiciones de intervalos.
Actualización: No admite: si cambias datos debes reconstruir (O(n log n)).

4. Segment Tree (Árbol de segmentos)

Uso: Cuando necesitas consultas y actualizaciones frecuentes en rangos (suma, mínimo, máximo, etc.).
Construcción: O(n)–O(n log n) según implementación.
Consulta: O(log n) por recorrer ramas.
Actualización: O(log n) para modificar hoja y propagar arriba.
Espacio: O(4 n) normalmente.





*/

l





*/
