#include "Scanner.h"
#include "Token.h"
#include <fstream>
#include <string>

class HtmlHighlighter {
public:
    static void export_to_file(Scanner& scanner, const std::string& filename) {
        std::ofstream file(filename);

        file << "<html><head><meta charset='UTF-8'><style>\n"
             << "body { background: #1e1e1e; color: #d4d4d4; font-family: 'Consolas', monospace; padding: 20px; line-height: 1.2; }\n"
             << ".keyword { color: #c678dd; font-weight: bold; }\n" // Fioletowy
             << ".type    { color: #61afef; }\n"               // Niebieski
             << ".string  { color: #98c379; }\n"               // Zielony
             << ".comment { color: #5c6370; font-style: italic; }\n" // Szary
             << ".literal { color: #d19a66; }\n"               // Pomarańczowy
             << ".ident   { color: #e06c75; }\n"               // Czerwony
             << ".op      { color: #56b6c2; }\n"               // Turkusowy
             << ".error   { background: #f44747; color: white; }\n" // Biały
             << "</style></head><body><pre>\n";

        while (true) {
            Token t = scanner.scan();
            file << wrap_token(t);
            if (t.get_type() == TokenType::EndOfFile) break;
        }

        file << "</pre></body></html>";
        file.close();
    }

private:
    static std::string escape(std::string data) {
        std::string buffer;
        for (size_t pos = 0; pos != data.size(); ++pos) {
            switch (data[pos]) {
                case '&':  buffer.append("&amp;");       break;
                case '\"': buffer.append("&quot;");      break;
                case '\'': buffer.append("&apos;");      break;
                case '<':  buffer.append("&lt;");        break;
                case '>':  buffer.append("&gt;");        break;
                default:   buffer.append(1, data[pos]); break;
            }
        }
        return buffer;
    }

    static std::string wrap_token(const Token& t) {
        std::string css_class = "";
        switch (t.get_type()) {
            case TokenType::KeywordIf: case TokenType::KeywordElse:
            case TokenType::KeywordWhile: case TokenType::KeywordReturn:
            case TokenType::KeywordFor: case TokenType::KeywordBreak:
            case TokenType::KeywordContinue: case TokenType::KeywordSwitch:
            case TokenType::KeywordCase:
                css_class = "keyword"; break;

            case TokenType::TypeInt: case TokenType::TypeFloat:
            case TokenType::TypeBoolean: case TokenType::TypeVoid:
            case TokenType::TypeString:
                css_class = "type"; break;

            case TokenType::NumberIntegerDecimal: case TokenType::NumberIntegerHex:
            case TokenType::NumberIntegerOctal: case TokenType::NumberFloat:
            case TokenType::LiteralBool: case TokenType::LiteralPtr:
                css_class = "literal"; break;

            case TokenType::LiteralString:
            case TokenType::LiteralCharacter:
                css_class = "string"; break;

            case TokenType::Comment:
            case TokenType::CommentBlock:
                css_class = "comment"; break;

            case TokenType::Identifier:
                css_class = "ident"; break;

            case TokenType::Equal: case TokenType::Assign: case TokenType::NotEqual:
            case TokenType::LessEqual: case TokenType::MoreEqual:
            case TokenType::LogicalAnd: case TokenType::LogicalOr:
                css_class = "op"; break;

            case TokenType::Error:
                css_class = "error"; break;

            default: return escape(t.get_value());
        }
        return "<span class=\"" + css_class + "\">" + escape(t.get_value()) + "</span>";
    }
};