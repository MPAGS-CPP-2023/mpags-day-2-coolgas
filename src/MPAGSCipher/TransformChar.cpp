#include "TransformChar.hpp"

#include <string>
#include <cctype>

std::string transformChar(const char in_char)
{
    std::string text;

    if (std::isalpha(in_char)) {
        text += std::toupper(in_char);
        return text;
    }
    
    // Transliterate digits to English words
    switch (in_char) {
        case '0':
            text += "ZERO";
            break;
        case '1':
            text += "ONE";
            break;
        case '2':
            text += "TWO";
            break;
        case '3':
            text += "THREE";
            break;
        case '4':
            text += "FOUR";
            break;
        case '5':
            text += "FIVE";
            break;
        case '6':
            text += "SIX";
            break;
        case '7':
            text += "SEVEN";
            break;
        case '8':
            text += "EIGHT";
            break;
        case '9':
            text += "NINE";
            break;
    }
    return text;
}