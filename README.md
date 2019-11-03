# godzinki
Little project to calculate work hours

--PL--

Projekt ma na celu wyliczenie godizin pracy.

Plik godzinki_save odpowiada za zapisywanie podanych przez użytkownika godzin do pliku txt:
  1. Program prosi o podanie miesiąca (wylicza ile dni ma miesiąc)
  2. Program podaje kolejno dni danego miesiąca, do których użytkownik wpisuje godziny pracy.
  3. Po zakończeniu wpisywania całego miesiąca program nie przyjmuje więcej dat i godzin.
  4. Program zapisuje plik w postaci "nr_miesiaca.txt"

Plik godzinki_load odpowiada za wczytanie wypełnionego pliku txt, wyliczenie godzin pracy każdego dnia i miesięczną sumę
  1. Program prosi o podanie nr miesiąca
  2. Program wczytuje odpowiedni plik
  3. Program wylicza każdy dzień osobno, sumę godzin z całego miesiąca i dni pracy w mesiącu, po czym wyświetla je użytkownikowi
  
 
pomysły, sugestie i todo:
  - poproś użytkownika o podanie stawki brutto/h i wylicz miesięczną pensję
  - przerobić program na oop
  - poprawka dla nocnej zmiany, gdzie czas pracy przekracza granicę północy

