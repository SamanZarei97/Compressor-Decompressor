#include "huffman.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " <input file> <output file>" << std::endl;
        return 1;
    }

    std::string inputFilename = argv[1];
    std::string outputFilename = argv[2];

    Huffman huff;
    huff.Compress(inputFilename, outputFilename);
    huff.Decompress(outputFilename, "decompressed_" + inputFilename);

    std::cout << "Compression and decompression completed." << std::endl;
    std::cout << "Compressed file: " << outputFilename << std::endl;
    std::cout << "Decompressed file: " << "decompressed_" + inputFilename << std::endl;

    return 0;
}
