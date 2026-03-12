//
// Created by Szymon Król on 12.03.2026.
//

#ifndef AGH_KOMPILATORY_SCANNER_H
#define AGH_KOMPILATORY_SCANNER_H
#include <iosfwd>
enum class Token;

class Scanner {

    static Token scan(std::iostream str);

};


#endif //AGH_KOMPILATORY_SCANNER_H