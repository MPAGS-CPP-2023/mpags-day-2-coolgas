#include "ProcessCommandLine.hpp"

#include <vector>
#include <string>
#include <iostream>

bool processCommandLine(
    const std::vector<std::string>& args,
    bool& helpRequested,
    bool& versionRequested,
    bool& encrypt,
    std::string& key,
    std::string& inputFileName,
    std::string& outputFileName
)
{
    const std::size_t nCmdLineArgs{args.size()};

    // Return help text if no input given
    if (nCmdLineArgs - 1 == 0) {
        helpRequested = true;
    }

    // Process command line arguments - ignore zeroth element, as we know this
    // to be the program name and don't need to worry about it
    for (std::size_t i{1}; i < nCmdLineArgs; ++i) {
        if (args[i] == "-h" || args[i] == "--help") {
            helpRequested = true;
        } else if (args[i] == "--version") {
            versionRequested = true;
        } else if (args[i] == "-i") {
            // Handle input file option
            // Next element is filename unless "-i" is the last argument
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -i requires a filename argument"
                          << std::endl;
                // exit main with false to indicate failure
                return false;
            } else {
                // Got filename, so assign value and advance past it
                inputFileName = args[i + 1];
                ++i;
            }
        } else if (args[i] == "-o") {
            // Handle output file option
            // Next element is filename unless "-o" is the last argument
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -o requires a filename argument"
                          << std::endl;
                // exit main with false to indicate failure
                return false;
            } else {
                // Got filename, so assign value and advance past it
                outputFileName = args[i + 1];
                ++i;
            }
        } else if (args[i] == "-e") {
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -e requires a filename argument"
                          << std::endl;
                // exit main with false to indicate failure
                return false;
            } else {
                encrypt = true;
                key = args[i + 1];
                ++i;
            }
        } else if (args[i] == "-d") {
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -d requires a filename argument"
                          << std::endl;
                // exit main with false to indicate failure
                return false;
            } else {
                encrypt = false;
                key = args[i + 1];
                ++i;
            }
        } else {
            // Have an unknown flag to output error message and return non-zero
            // exit status to indicate failure
            std::cerr << "[error] unknown argument '" << args[i]
                      << "'\n";
            return false;
        }
    }
    return true;
}