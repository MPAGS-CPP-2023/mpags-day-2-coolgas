# mpags-cipher
A simple command line tool for encrypting/decrypting text using classical ciphers

## Authors
Thomas Latham, Ben Morgan, Mark Slater, Matt Williams, Luke Kreczko

## Building `mpags-cipher`
Compilation of `mpags-cipher` requires a  C++11 compatible compiler
(GCC 8 or better, Clang 8 or better are recommended) on a UNIX operating
system.
Windows platforms with Visual Studio 2015 or better are also expected to
work, but not tested.

To build from a clone of this repository, open a terminal window
and change to directory build. Then runs:
```
$ cmake ../src
$ make
```

If no input file is supplied, `mpags-cipher` will wait for user input
from the keyboard until RETURN followed by CTRL-D are pressed.
To ensure the input text can be used with the character sets known to
classical ciphers, it is transliterated using the following rules:

- Alphabetical characters are converted to uppercase
- Digits are translated to their English equivalent words (e.g. '0' -> "ZERO")
- All other characters (punctuation) are discarded

To encrypt with Caesar cipher with certain `<KEY>`. After `mpags-cipher` is successfully
built, open a terminal window in build directory. Then runs:
```
$ mpags-cipher -e <KEY>
``` 
Likewise, to decrypt with certain `<KEY>`, apply `-d <KEY>` flag.

The results of this transliteration are output after CTRL-D.

## Source code layout
```
.
├── LICENSE             License file, in our case MIT
├── mpags-cipher.cpp    Main program C++ source file
└── README.md           This file, describes the project
```

## Copying
`mpags-cipher` is licensed under the terms of the MIT License.
Please see the file [`LICENSE`](LICENSE) for full details.