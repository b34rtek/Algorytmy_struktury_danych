# Najkrótsza trasa w terenie górzystym

## 📖 Opis zadania

Celem zadania jest znalezienie najkrótszej trasy przez teren podzielony na pola o różnych wysokościach. Każde pole ma wysokość wyrażoną nieujemną liczbą całkowitą. Przejście między polami zależy od różnicy wysokości:

* Przejście na pole o wysokości **A** z pola o wysokości **B** trwa:

  * **A - B + 1** minut, jeśli **A > B**,
  * **1** minutę, jeśli **A ≤ B**.
* Ruch możliwy jest tylko na pola sąsiadujące bokami (maksymalnie 4 kierunki).
* Nie wolno opuścić obszaru zdefiniowanego mapą.

Dodatkowo na mapie mogą znajdować się wyciągi (jednokierunkowe):

* Każdy wyciąg ma punkt startu, punkt docelowy, czas przejazdu i częstotliwość odjazdów (wyciąg kursuje w minutach będących wielokrotnością zdefiniowanej wartości).
* Jeżeli dotrzemy do punktu startowego wyciągu w czasie **t**, a częstotliwość odjazdów to **f**, to czekamy do najbliższego czasu **t'** będącego wielokrotnością **f** (t' ≥ t), a następnie podróż wyciągiem trwa określoną liczbę minut.

Rozwiązanie powinno działać w czasie i pamięci mieszczących się w standardowym typie `int`.

---

## 📝 Wejście

1. Dwie liczby całkowite: szerokość **W** i wysokość **H** mapy.
2. Pozycja startowa: współrzędne kolumny i wiersza (0‐indeksowane).
3. Pozycja docelowa: współrzędne kolumny i wiersza (0‐indeksowane).
4. Liczba wyciągów **N**.
5. Dla każdego wyciągu kolejno:

   * Współrzędne startu (kolumna, wiersz).
   * Współrzędne docelowe (kolumna, wiersz).
   * Czas trwania przejazdu w minutach.
   * Częstotliwość odjazdów (minuty).
6. Macierz wysokości terenu: **H** wierszy po **W** wartości.

Wszystkie wartości są nieujemne.

---

## 📤 Wyjście

Wypisz jedną liczbę całkowitą — minimalny czas (w minutach) potrzebny na dotarcie z pola startowego do docelowego.

---

## 💡 Przykłady

### Przykład 1

**Wejście**

```
9 8
0 0
8 7
0
0 0 0 0 0 0 0 0 8
0 9 9 9 9 9 9 9 0
0 1 0 1 0 0 0 9 0
0 9 0 0 0 1 0 9 0
0 9 1 1 1 1 0 9 0
0 9 0 0 0 0 0 9 0
0 9 9 9 9 1 9 9 0
8 0 0 0 0 0 0 0 0
```

**Wyjście**

```
18
```

---

### Przykład 2

**Wejście**

```
9 9
0 0
8 8
5
0 1 2 0 5 2
0 1 2 0 1 3
2 0 4 0 3 7
4 1 8 8 20 11
4 2 8 8 10 12
0 9 0 9 0 9 0 9 0
0 9 0 9 0 9 0 9 0
0 9 0 9 0 9 0 9 0
0 9 0 9 0 9 0 9 0
0 9 0 9 0 9 0 9 0
0 9 0 9 0 9 0 9 0
0 9 0 9 0 9 0 9 0
0 9 0 9 0 9 0 9 0
0 9 0 9 0 9 0 9 0
```

**Wyjście**

```
22
```

---

## ⚙️ Ograniczenia

* **Testy 0–10:** poprawność (50%)
* **Testy 11–15:** wydajność (30%)
* **Testy 16–19:** obsługa wyciągów (20%)

