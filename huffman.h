#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include <fstream>

class Huffman {
public:
    Huffman() = default;
    ~Huffman() = default;

    void Compress(const std::string& inputFilename, const std::string& outputFilename);
    void Decompress(const std::string& inputFilename, const std::string& outputFilename);

private:
    struct Node {
        char id;
        int freq;
        Node *left, *right;

        Node(char id, int freq, Node* left = nullptr, Node* right = nullptr)
            : id(id), freq(freq), left(left), right(right) {}

        bool operator>(const Node& rhs) const {
            return this->freq > rhs.freq;
        }
    };

    void buildHuffmanTree(const std::string& input);
    void buildHuffmanCodes(Node* root, const std::string& code);
    void writeCompressedFile(const std::string& outputFilename);
    void deleteTree(Node* node);

    std::map<char, int> frequencies;
    std::map<char, std::string> huffmanCodes;
    std::priority_queue<Node*, std::vector<Node*>, std::greater<Node*>> huffmanTree;
};

#endif 


