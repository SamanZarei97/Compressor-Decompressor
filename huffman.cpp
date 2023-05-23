// huffman.cpp
#include "huffman.h"

void Huffman::Compress(const std::string& inputFilename, const std::string& outputFilename) {
    buildHuffmanTree(inputFilename);
    writeCompressedFile(outputFilename);
    deleteTree(huffmanTree.top());
}

void Huffman::Decompress(const std::string& inputFilename, const std::string& outputFilename) {
    // Open file
    std::ifstream inputFile(inputFilename, std::ios::binary);

    // Read frequencies from file
    int freqSize;
    inputFile.read((char*)&freqSize, sizeof(freqSize));

    for (int i = 0; i < freqSize; i++) {
        char id;
        int freq;
        inputFile.read(&id, sizeof(id));
        inputFile.read((char*)&freq, sizeof(freq));
        frequencies[id] = freq;
    }

    // Reconstruct Huffman tree
    for (auto pair : frequencies) {
        huffmanTree.push(new Node(pair.first, pair.second));
    }

    while (huffmanTree.size() > 1) {
        Node* left = huffmanTree.top(); huffmanTree.pop();
        Node* right = huffmanTree.top(); huffmanTree.pop();

        huffmanTree.push(new Node('\0', left->freq + right->freq, left, right));
    }

    buildHuffmanCodes(huffmanTree.top(), "");

    // Read encoded data
    std::string encodedData;
    inputFile >> encodedData;

    // Decode data
    std::ofstream outputFile(outputFilename, std::ios::binary);
    Node* currNode = huffmanTree.top();
    for (char bit : encodedData) {
        if (bit == '0') currNode = currNode->left;
        else currNode = currNode->right;

        if (!currNode->left && !currNode->right) {
            outputFile.put(currNode->id);
            currNode = huffmanTree.top();
        }
    }

    // Clean up
    deleteTree(huffmanTree.top());
}

void Huffman::buildHuffmanTree(const std::string& inputFilename) {
    if (!inputFilename.empty()) {
        std::ifstream inputFile(inputFilename, std::ios::binary);

        char ch;
        while (inputFile.get(ch)) {
            frequencies[ch]++;
        }
    }

    for (auto pair : frequencies) {
        huffmanTree.push(new Node(pair.first, pair.second));
    }

    while (huffmanTree.size() > 1) {
        Node* left = huffmanTree.top(); huffmanTree.pop();
        Node* right = huffmanTree.top(); huffmanTree.pop();

        huffmanTree.push(new Node('\0', left->freq + right->freq, left, right));
    }

    buildHuffmanCodes(huffmanTree.top(), "");
}

void Huffman::buildHuffmanCodes(Node* root, const std::string& code) {
    if (!root) {
        return;
    }

    if (root->id != '\0') {
        huffmanCodes[root->id] = code;
    }

    buildHuffmanCodes(root->left, code + "0");
    buildHuffmanCodes(root->right, code + "1");
}

void Huffman::writeCompressedFile(const std::string& outputFilename) {
    // Open output file
    std::ofstream outputFile(outputFilename, std::ios::binary);

    // Write frequencies to file
    int freqSize = frequencies.size();
    outputFile.write((char*)&freqSize, sizeof(freqSize));

    for (auto pair : frequencies) {
        outputFile.write(&pair.first, sizeof(pair.first));
        outputFile.write((char*)&pair.second, sizeof(pair.second));
    }

    // Write encoded data
    std::ifstream inputFile(outputFilename);
    char ch;
    while (inputFile.get(ch)) {
        std::string huffCode = huffmanCodes[ch];
        for (char bit : huffCode) {
            outputFile.put(bit);
        }
    }
}

void Huffman::deleteTree(Node* node) {
    if (!node) {
        return;
    }

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}
