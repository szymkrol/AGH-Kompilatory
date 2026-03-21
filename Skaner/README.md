# Scanner - projekt kompilatory


## Język implementacji
* **Język:** C++

## Zbiór tokenów (specyfikacja)

Skaner rozpoznaje następujące tokeny:

| Nazwa Tokena         | Kod (Enum)      | Regex                      | Opis                                            |
|:---------------------|:----------------|:---------------------------|:------------------------------------------------|
| **Plus**             | `SignPlus`      | `+`                        | Znak dodawania.                                 |
| **Minus**            | `SignMinus`     | `-`                        | Znak odejmowania.                               |
| **Gwiazdka**         | `SignStar`      | `*`                        | Znak mnożenia.                                  |
| **Dzielenie**        | `SignSlash`     | `\`                        | Znak dzielenia.                                 |
| **Nawias lewy**      | `LeftParen`     | `(`                        | Otwarcie nawiasu.                               |
| **Nawias prawy**     | `RightParen`    | `)`                        | Zamknięcie nawiasu.                             |
| **Liczba całkowita** | `NumberInteger` | `[0-9]+`                   | Ciąg cyfr dziesiętnych.                         |
| **Identyfikator**    | `Identifier`    | `[a-zA-Z_-][a-zA-Z0-9_-]*` | Nazwa zaczynająca nie zaczynająca się od cyfry. |
| **Białe znaki**      | `Whitespace`    | `[ \f\n\r\t\v]+`           | Białe znaki                                     |
