Am implementat ambele scenarii ale problemei rucsacului.

Scenariul 1: obiectele pot fi transportate partial (bucati din obiectul initial)
in acest caz fisierul de date are pe prima linie valoarea 1.
Fisierul de test in acest caz este in directorul ./test_scenariu1

Scenariul 2: obiectele nu pot fi transportate partial, adica un obiect care nu mai poate fi transportat in intregime nu va fi luat deloc
In acest caz fisierul de date are prima linie valoarea 0.
Fisierul de test in acest caz este in directorul ./test_scenariu2

Programul pe care l-am implementat foloseste 2 structuri:
- o structura pentru reprezentarea informatiilor despre rucsac 
  - int fractionar -> scenariul folosit
  - int n -> numarul de obiecte
  - float Gmax -> greutatea maxima
  - obiect* v -> vectorul cu obiecte candidate la transport

- o structura pentru reprezentarea informatiilor despre obiecte
   - int k -> numarul de ordine al obiectului (necesar la afisare)
   - float g -> greutatea obiectului
           p -> castigul obtinut prin transportul in intregime al obiectului
           ef -> eficienta la transport, calculata ca fiind p/g
              -> in raport cu aceasta valoare se sorteaza descrescator obiectele

Functia main() contine urmatoarele apeluri:
- citire(FILE *f, rucsac *r) -> citirea datelor din fisierul "greedy.txt"
- qsort(void *v, size_t n, size_t size, int (*ordonare)(const void *a, const void *b)) -> functia din stdlib.h, folosita pentru sortarea eficienta a obiectelor din vector in raport cu eficienta lor
- greedy(rucsac *r) -> functia care implementeaza tehnica Greedy
