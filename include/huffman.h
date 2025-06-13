#ifndef HUFFMAN_H
#define HUFFMAN_H

#include<string>
#include<unordered_map>
#include<queue>
#include<vector>

struct Node{
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char character, int frequency){
        ch=character;
        freq=frequency;
        left=NULL;
        right=NULL;
    }
};

class compare{
    public:
        bool operator()(Node* a, Node* b){
            return a->freq>b->freq;
        }
};

class Huffman{
    private:
        Node* root=NULL;
        std::unordered_map<char, std::string> code;
        void buildTree(const std::string &text);
        void generateCode(Node* node, std::string path);
    public:
        std::string encode(const std::string &text);
        void saveToFile(const std::string &text, const std::string &fileName);
};

#endif