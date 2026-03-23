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
| **Komentarz liniowy**             | `Comment`              | `//.*`                                       | Komentarz kończący się znakiem nowej linii.     |
| **Komentarz blokowy**             | `CommentBlock`         | `/\*[\s\S]*?\*/`                             | Komentarz wieloliniowy (blokowy).               |
| **Równe**                         | `Equal`                | `==`                                         | Operator porównania (równość).                  |
| **Przypisanie**                   | `Assign`               | `=`                                          | Operator przypisania wartości.                  |
| **Różne**                         | `NotEqual`             | `!=`                                         | Operator porównania (nierówność).               |
| **Logiczne AND**                  | `LogicalAnd`           | `&&`                                         | Operator logiczny koniunkcji.                   |
| **Logiczne OR**                   | `LogicalOr`            | `\|\|`                                       | Operator logiczny alternatywy.                  |
| **Negacja / Wykrzyknik**          | `Exclamation`          | `!`                                          | Operator logiczny negacji.                      |
| **Bitowe AND / Adres**            | `Ampersand`            | `&`                                          | Operator bitowy lub pobrania adresu.            |
| **Bitowe OR**                     | `Pipe`                 | `\|`                                         | Operator bitowy OR.                             |
| **Mniejsze lub równe**            | `LessEqual`            | `<=`                                         | Operator porównania mniejszy-równy.             |
| **Większe lub równe**             | `MoreEqual`            | `>=`                                         | Operator porównania większy-równy.              |
| **Mniejsze niż**                  | `LessThan`             | `<`                                          | Operator porównania mniejszości.                |
| **Większe niż**                   | `MoreThan`             | `>`                                          | Operator porównania większości.                 |
| **Przesunięcie w lewo**           | `ShiftLeft`            | `<<`                                         | Operator przesunięcia bitowego w lewo.          |
| **Przesunięcie w prawo**          | `ShiftRight`           | `>>`                                         | Operator przesunięcia bitowego w prawo.         |
| **Dwukropek**                     | `Colon`                | `:`                                          | Znak dwukropka.                                 |
| **Operator zasięgu**              | `DoubleColon`          | `::`                                         | Operator zasięgu (scope resolution).            |
| **Kropka**                        | `Dot`                  | `.`                                          | Dostęp do składowych (kropka).                  |
| **Wielokropek**                   | `Ellipsis`             | `...`                                        | Operator trzech kropek.                         |
| **Przecinek**                     | `Comma`                | `,`                                          | Separator argumentów lub zmiennych.             |
| **Średnik**                       | `Semicolon`            | `;`                                          | Znak końca instrukcji.                          |
| **Klamra lewa**                   | `LeftBrace`            | `{`                                          | Początek bloku kodu.                            |
| **Klamra prawa**                  | `RightBrace`           | `}`                                          | Koniec bloku kodu.                              |
| **Nawias kwadratowy lewy**        | `LeftBracket`          | `[`                                          | Początek indeksowania lub tablicy.              |
| **Nawias kwadratowy prawy**       | `RightBracket`         | `]`                                          | Koniec indeksowania lub tablicy.                |
| **Słowa kluczowe (Control)**      | `Keyword...`           | `if\|else\|while\|for\|return\|break\|...`   | Instrukcje sterujące przepływem programu.       |
| **Typy danych**                   | `Type...`              | `int\|float\|bool\|void\|string\|char`       | Wbudowane typy danych.                          |
