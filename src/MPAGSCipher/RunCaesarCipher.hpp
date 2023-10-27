#ifndef MPAGSCIPHER_RUNCAESARCIPHER
#define MPAGSCIPHER_RUNCAESARCIPHER

#include <string>

std::string runCaesarCipher( 
    const std::string& inputText, 
    const std::string& key,
    const bool encrypt
);

#endif