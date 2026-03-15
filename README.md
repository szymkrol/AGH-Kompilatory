# Scanner - Projekt Kompilatory


## Język Implementacji
* **Język:** C++20

## Zbiór tokenów (Specyfikacja)

Skaner rozpoznaje następujące tokeny:

| Nazwa Tokena         | Kod (Enum)      | Regex                      | Opis                                            |
|:---------------------|:----------------|:---------------------------|:------------------------------------------------|
| **Plus**             | `SignPlus`      | `+`                        | Znak dodawania.                                 |
| **Minus**            | `SignMinus`     | `-`                        | Znak odejmowania.                               |
| **Gwiazdka**         | `SignStar`      | `*`                        | Znak mnożenia.                                  |
| **Ukośnik wsteczny** | `SignSlash`     | `\`                        | Znak dzielenia.                                 |
| **Nawias lewy**      | `LeftParen`     | `(`                        | Otwarcie nawiasu.                               |
| **Nawias prawy**     | `RightParen`    | `)`                        | Zamknięcie nawiasu.                             |
| **Liczba całkowita** | `NumberInteger` | `[0-9]+`                   | Ciąg cyfr dziesiętnych.                         |
| **Identyfikator**    | `Identifier`    | `[a-zA-Z_-][a-zA-Z0-9_-]*` | Nazwa zaczynająca nie zaczynająca się od cyfry. |