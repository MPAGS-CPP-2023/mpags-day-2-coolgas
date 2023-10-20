#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE
#define MPAGSCIPHER_PROCESSCOMMANDLINE

#include <vector>
#include <string>

int processCommandLine(
    const std::vector<std::string>& args,
    bool& helpRequested,
    bool& versionRequested,
    std::string& inputFileName,
    std::string& outputFileName );

#endif
