#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

std::string runCaesarCipher( 
    const std::string& inputText, 
    const size_t key,
    const bool encrypt
)
{
    // initialize the alphabet
    const std::vector<char> alphabet{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    const size_t alphabet_size = alphabet.size();

    // initialize the output text
    std::string outputText{""};
    
    char inputChar{'x'};
    int position{0};
    signed int relative_position;

    for (size_t i{0}; i < inputText.size(); ++i) {
        inputChar = std::toupper(inputText[i]);
        // reading the position of the current letter in the alphabet
        auto it = std::find(alphabet.begin(), alphabet.end(), inputChar);
        if (it != alphabet.end()) {
            position = std::distance(alphabet.begin(), it);
        } else {
            std::cerr << "[error] character: " << inputChar << " not found in alphabet" << std::endl;
            break;
        }
        // processes of doing encryption/decrypting
        if (encrypt) {
            relative_position = position+key;
            outputText += alphabet[relative_position%alphabet_size];
        } else {
            relative_position = position - key;
            if (relative_position < 0) {
                outputText += alphabet[(alphabet_size+relative_position)%alphabet_size];
            } else {
                outputText += alphabet[relative_position%alphabet_size];
            }
        }
    }
    return outputText;
}