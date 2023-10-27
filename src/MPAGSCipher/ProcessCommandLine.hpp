#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE
#define MPAGSCIPHER_PROCESSCOMMANDLINE

#include <vector>
#include <string>

bool processCommandLine(
    const std::vector<std::string>& args,
    bool& helpRequested,
    bool& versionRequested,
    bool& encrpt,
    std::string& key,
    std::string& inputFileName,
    std::string& outputFileName
);

#endif