# EURObiznes
<p align="justify">
Elektroniczna wersja ekonomicznej gry planszowej. Projekt został wykonany jako praca zaliczeniowa w ramach przedmiotu Programowanie w języku C++. Projekt 
miał na celu wykonanie aplikacji, która obrazuje wykorzystanie głównych założeń paradygmatu programowania obiektowego, m. in. tworzenie własnych klas, 
stosowanie dziedziczenia, polimorfizmu, wykorzystanie podstawowych zależności pomiędzy obiektami poszczególnych klas takich, jak agregacja, kompozycja.
</p>

## Podział projektu
<p align="justify">
Projekt składa się z dwóch zasadniczych części: logicznej i graficznej. W praktyce obie części wchodzą ze sobą w interakcję tylko poprzez wymianę 
potrzebnych danych. Logika odpowiada za wirtualny przebieg rozgrywki, a grafika służy do komunikacji z graczem.
</p>

## Część logiczna
<p align="justify">
Zawiera w sobie implementację wszystkich klas, metod, struktur danych potrzebnych do przeprowadzenia wirtualnej rozgrywki. 
Główne klasy wchodzące w skład logiki:
<ul>
  <li>CGame - bezpośrednio lub pośrednio zarządza wszystkimi obiektami związanymi z grą</li>
  <li>CPlansza - zarządza polami i kartami</li>
  <li>CGracz - klasa reprezentująca pojedynczego uczestnika rozgrywki</li>
  <li>CPole - klasa odpowiadająca polom planszy, różne rodzaje pól wprowadzone poprzez mechanizm dziedziczenia</li>
  <li>CKarta - karty losowane przez gracza, różne rodzaje także wprowadzone poprzez dziedziczenie</li>
</ul>

Domyślnie dane o bazowych obiektach rozgrywki (pola, karty) są pobierane z pliku tekstowego. Do odpowiedniego parsowania danych z pliku zostały zaimplementowane metody statyczne zawarte w plikach źródłowych klasy CPlansza. Możliwe jest również utworzenie przez gracza własnych obiektów pól w trakcie działania aplikacji. 

Zależności między klasami logicznymi zostały ukazane na diagramie UML w folderze <i>doc</i>.
</p>

## Część graficzna
<p align="justify">
  Zawiera implementację klas, których instancje są rysowane na ekranie. Wykorzystane zostały tu klasy biblioteki środowiska Qt. Wszystkie dziedziczą bezpośrednio lub pośrednio po klasie <i>QGraphicsItem</i>. Klasami tworzącymi obiekty rysunków są formularze: 
  <ul>
    <li>NGGracze - okno dodawania nowych graczy</li>
    <li>NGPlansza - okno dodawania własnych pól planszy</li>
    <li>Rozgrywka - okno, w którym jest prowadzona właściwa rozgrywka</li>
    <li>Wlasnosci - okno do przeglądu własności, które posiada gracz</li>
  </ul>
  
  Oprócz powyższych klas, zastosowany został również mechanizm slotów i sygnałów Qt. Umożliwia on zastosowanie odpowiednich akcji dla poszczególnych obiektów, np. wyświetlenie komunikatu z treścią wylosowanej karty, gdy gracz staje na polu "Szansa". 
  
  Zależności pomiędzy klasami grafiki również zostały pokazane na diagramie UML w folderze <i>doc</i>.
</p>
  
