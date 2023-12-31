#include "RunCaesarCipher.hpp"
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"

#include <cctype>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

int main( int argc, char* argv[] )
{
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};

    // Options that might be set by the command-line arguments
    bool helpRequested{false};
    bool versionRequested{false};
    bool encrypt{false};
    std::string key{""};
    std::string inputFile{""};
    std::string outputFile{""};

    // Process command line arguments - ignore zeroth element, as we know this
    // to be the program name and don't need to worry about it
    const bool processCmdFlag = processCommandLine(cmdLineArgs,
        helpRequested, versionRequested, encrypt,
        key, inputFile, outputFile
    );

    if (processCmdFlag == false) {
        return 1;
    }
    
    // Handle help, if requested
    if (helpRequested) {
        // Line splitting for readability
        std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << "  -e <KEY>          Encrypt the message with KEY steps\n\n"
            << "  -d <KEY>          Decrypt the message with KEY steps\n\n"
            << std::endl;
        // Help requires no further action, so return from main
        // with 0 used to indicate success
        return 0;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) {
        std::cout << "0.1.0" << std::endl;
        return 0;
    }

    // Initialise variables
    char inputChar{'x'};
    std::string inputText;
    std::string outputText;

    // Read in user input from stdin/file
    // Warn that input file option not yet implemented
    if (!inputFile.empty()) {
        std::ifstream in_file {inputFile};
        bool ok_to_read = in_file.good();
        if (!ok_to_read) {
            std::cerr << "[error] failed to open the input file" << std::endl;
            return 1;
        }
        while (in_file >> inputChar) {
            inputText += transformChar(inputChar);
        }
    } else {
        // loop over each character from user input
        while (std::cin >> inputChar) {
            inputText += transformChar(inputChar);
            // If the character isn't alphabetic or numeric, DONT add it
        }
    }

    // run the cipher here
    outputText += runCaesarCipher(inputText, key, encrypt);

    // Warn that output file option not yet implemented
    if (!outputFile.empty()) {
        std::ofstream out_file {outputFile};
        bool ok_to_write = out_file.good();
        if (!ok_to_write) {
            std::cerr << "[error] failed to write to the output file" << std::endl;
        } else {
            out_file << outputText;
        }
    } else {
        std::cout << outputText << std::endl;
    }
    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}