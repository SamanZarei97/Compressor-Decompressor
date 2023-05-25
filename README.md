
# Huffman Compression and Decompression

This project includes an implementation of the Huffman Coding algorithm for file compression and decompression. Huffman coding is a popular algorithm for lossless data compression. The algorithm constructs a variable-length prefix code, which is an optimal way to encode symbols based on their occurrence frequencies.

# Files

The project consists of the following files:

#### huffman.h: 
This header file contains the declaration of the Huffman class, including its public and private methods and data members.

#### huffman.cpp: 
This source file contains the implementation of the Huffman class. It includes methods for building the Huffman tree, generating Huffman codes, compressing and decompressing files, and deleting the Huffman tree.

#### main.cpp:
This file includes the main function. It utilizes the Huffman class to compress and decompress files passed as command-line arguments.

# Usage
You can use the application as follows:

```bash
    ./huffman <input file> <output file>
```
 Where:

    <input file> is the path to the file you want to compress.
    <output file> is the path to the file where the compressed data will be written.
After compressing the input file, the program will also automatically decompress the file to validate that the compression-decompression cycle is lossless. The decompressed file will have the same contents as the original input file and will be named decompressed_<input file>

# Class Huffman
The Huffman class implements the Huffman coding algorithm. It provides methods for compressing and decompressing files.

## Data Members
frequencies: A map from characters to their frequency of occurrence.

huffmanCodes: A map from characters to their corresponding Huffman codes.

huffmanTree: A priority queue representing the Huffman tree.

## Methods

Compress(const std::string& inputFilename, const std::string& outputFilename): Compresses the file at inputFilename and writes the compressed data to outputFilename.

Decompress(const std::string& inputFilename, const std::string& outputFilename): Decompresses the file at inputFilename and writes the decompressed data to outputFilename.

Private utility methods are also included for constructing the Huffman tree, building the Huffman codes, and deleting the Huffman tree.

## Dependencies
This project requires a C++ compiler supporting C++11 or later.

This project uses the standard C++ library, including <map>, <queue>, <vector>, <iostream>, and <fstream>.

## Compilation
To compile the project, use the following command:

    g++ -std=c++11 -o huffman huffman.cpp main.cpp

This will generate the huffman executable which you can run as described above.



