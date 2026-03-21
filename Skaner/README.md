# Scanner - projekt kompilatory


## Język implementacji
* **Język:** C++

## Zbiór tokenów (specyfikacja)

Skaner rozpoznaje następujące tokeny:

| Nazwa Tokena                      | Kod (Enum)             | Regex                                        | Opis                                            |
|:----------------------------------|:-----------------------|:---------------------------------------------|:------------------------------------------------|
| **Plus**                          | `SignPlus`             | `+`                                          | Znak dodawania.                                 |
| **Minus**                         | `SignMinus`            | `-`                                          | Znak odejmowania.                               |
| **Gwiazdka**                      | `SignStar`             | `*`                                          | Znak mnożenia.                                  |
| **Dzielenie**                     | `SignSlash`            | `\`                                          | Znak dzielenia.                                 |
| **Nawias lewy**                   | `LeftParen`            | `(`                                          | Otwarcie nawiasu.                               |
| **Nawias prawy**                  | `RightParen`           | `)`                                          | Zamknięcie nawiasu.                             |
| **Liczba całkowita dziesiętna**   | `NumberIntegerDecimal` | `[1-9][0-9]*`                                | Ciąg cyfr dziesiętnych.                         |
| **Liczba całkowita ósemkowa**     | `NumberIntegerOctal`   | `0[0-7]*`                                    | Ciąg cyfr dziesiętnych.                         |
| **Liczba całkowita szesnastkowa** | `NumberIntegerHex`     | `(0x\|0X)[0-9a-fA-F]+`                       | Ciąg cyfr dziesiętnych.                         |
| **Liczba całkowita binarna**      | `NumberIntegerBinary`  | `(0b\|0B)[0-1]+`                             | Ciąg cyfr dziesiętnych.                         |
| **Liczba zmiennoprzecinkowa**     | `NumberFloat`          | `[0-9]+.[0-9]+((e\|E)(-\|+)?[0-9]+)?(f\|F)?` | Liczba zmiennoprzecinkowa.                      |
| **Stała znakowa**                 | `LiteralCharacter`     | `'.*'`                                       | Znak.                                           |
| **String**                        | `LiteralString`        | `".*"`                                       | Słowo.                                          |
| **Stała logiczna**                | `LiteralBool`          | `true \| false`                              | Stała logiczna oznaczająca prawdę lub fałsz     |
| **Stała wskaźnikowa**             | `LiteralPtr`           | `nullptr`                                    | Pusty wskaźnik.                                 |
| **Identyfikator**                 | `Identifier`           | `[a-zA-Z_-][a-zA-Z0-9_-]*`                   | Nazwa zaczynająca nie zaczynająca się od cyfry. |
| **Białe znaki**                   | `Whitespace`           | `[ \f\n\r\t\v]+`                             | Białe znaki                                     |
