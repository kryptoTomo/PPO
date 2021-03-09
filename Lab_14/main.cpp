/*
  Celem zadania jest napisanie klasy tablicy dwuwymiarowej.
  Obiekty tej klasy moga wystepowac w dwoch wariantach.
  - albo nie zarzadzaja pamiecia gdy sa stworzone za pomocom funkcji adopt
  - albo nia zarzadzaja gdy sa skonstruowane w zwyczajny sposob.
  UWAGA: przy przypisaniu, i w konstruktorze kopiujacym wytwarzamy obiekty,
  ktore ta pamiecia zarzadzaja.
  Klasa jest wyposarzona w dwa operatory. Pierwszy z nich [] odpowiada za dostep do elementow.
  Zagadka jest co tez powinien operator[] zwrocic zeby mogl na nim zadzialac kolejny operator[]?
  Drugi z nich to operator <<= sluzoacy do wypisywania.
 
 
  Ostateczny program powinien byc przyjazny dla programisty (miec
  czytelny i dobrze napisany kod, a takze dokumentacje).
  
  Pliku main.cpp nie wolno modyfikowac (oczywiście w trakcie pracy można sobie
  komentować fragmenty).

  CMakeLists.txt dolaczony do rozwiazania powinien tworzyc plik wykonywalny
  o nazwie CPPLab (nalezy kopiowac sobie CMakeLists.txt z poprzednich zajec).
  Program nalezy kompilowac z flagami -Wall -g.
  Prosze zadbac o dobre zarzadzanie pamiecia.

  Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
  ani żadnych innych materiałów (w tym własnych wcześniej
  przygotowanych plików)

  Rozwiązanie (archiwum zip) należy przesłać na UPeL do godziny 9:30
  (po 9:30 nie bedzie mozliwosci doslania rozwiazania)

  Program nie będzie oceniany.
 */
#include <iostream>
#include "Arr2D.h"


int main() {

  int data_a[] = { 1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6 };
  Arr2D w_a = Arr2D::adopt( data_a, 4, 4 );
  
  int x = w_a[0][2];
  w_a[0][2] = 0;
  w_a[1][3] = -1;
  w_a[2][3] = -1;
  
  "xxxxxxxx" <<= w_a;
  std::cout << " czy rowne " << (x == w_a[0][2]) << " " << ( w_a[0][2] == 0 )  << "\n";
  
  Arr2D w_b( 3, 3 ); // to tablica, ktora dba o pamiec dla siebie
  w_b[1][0] = 5;
  "==" <<= w_b;

  const Arr2D w_c = w_b;

  w_b = w_a;
    
  "------" <<= w_b;
}
/* output:
xxxxxxxx
1 2 0 4 
5 6 7 -1 
9 0 1 -1 
3 4 5 6 
xxxxxxxx
 czy rowne 0 1
==
0 0 0 
5 0 0 
0 0 0 
==
------
1 2 0 4 
5 6 7 -1 
9 0 1 -1 
3 4 5 6 
------


 */
