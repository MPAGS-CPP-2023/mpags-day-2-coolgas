#ifndef MPAGSCIPHER_RUNCAESARCIPHER
#define MPAGSCIPHER_RUNCAESARCIPHER

#include <string>

std::string runCaesarCipher( 
    const std::string& inputText, 
    const size_t key,
    const bool encrpt
);

#endif