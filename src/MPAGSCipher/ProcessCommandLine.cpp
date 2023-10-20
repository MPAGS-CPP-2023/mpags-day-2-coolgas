#include <vector>
#include <string>
#include <iostream>

int processCommandLine(
    const std::vector<std::string>& args,
    bool& helpRequested,
    bool& versionRequested,
    bool& encrypt,
    unsigned long& key,
    size_t& cipherTrigger,
    std::string& inputFileName,
    std::string& outputFileName
)
{
    const std::size_t nCmdLineArgs{args.size()};

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
                // exit main with non-zero return to indicate failure
                return 1;
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
                // exit main with non-zero return to indicate failure
                return 1;
            } else {
                // Got filename, so assign value and advance past it
                outputFileName = args[i + 1];
                ++i;
            }
        } else if (args[i].substr(0,2) == "-e") {
            if (args[i].size() > 2) {
                encrypt = true;
                key = std::stoul(args[i].substr(2), nullptr, 10);
                cipherTrigger += 1;
            } else {
                std::cerr << "[error] -e requires a key argument" << std::endl;
                return 1;
            }
        } else if (args[i].substr(0,2) == "-d") {
            if (args[i].size() > 2) {
                encrypt = false;
                key = std::stoul(args[i].substr(2), nullptr, 10);
                cipherTrigger += 1;
            } else {
                std::cerr << "[error] -d requires a key argument" << std::endl;
                return 1;
            }
        } else {
            // Have an unknown flag to output error message and return non-zero
            // exit status to indicate failure
            std::cerr << "[error] unknown argument '" << args[i]
                      << "'\n";
            return 1;
        }
    }
    return 0;
}