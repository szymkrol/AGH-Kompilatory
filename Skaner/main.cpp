#include <fstream>
#include <iostream>

#include "Token.h"
#include "Scanner/Scanner.h"
#include "HtmlHighlighter.cpp"
//
// Created by Szymon Król on 12.03.2026.
//
int main() {std::ifstream input_file("../ex.txt");
    std::ifstream input_file_HTML("../exHTML.txt");
    Scanner s = Scanner (input_file);
    Scanner sHTML = Scanner (input_file_HTML);
    HtmlHighlighter::export_to_file(sHTML, "output.html");
    while (true) {
        Token t = s.scan();
        std::cout << t << '\n';
        if (t.get_type() == TokenType::EndOfFile) {
            break;
        }
    }
    input_file.close();
    input_file_HTML.close();
    return 0;
}