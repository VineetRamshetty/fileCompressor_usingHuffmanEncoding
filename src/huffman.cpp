#include "../include/huffman.h"
#include<fstream>

void Huffman::buildTree(const std::string &text){
    std::unordered_map<char, int> frequency;
    for(char ch:text){
        frequency[ch]++;
    }
    std::priority_queue<Node*, std::vector<Node*>, compare> pq;
    for(auto i:frequency){
        Node* temp=new Node(i.first, i.second);
        pq.push(temp);
    }
    while(pq.size()>1){
        Node* left=pq.top();
        pq.pop();
        Node* right=pq.top();
        pq.pop();
        Node *temp=new Node('\0', left->freq+right->freq);
        temp->left=left;
        temp->right=right;
        pq.push(temp);
    }
    root=pq.top();
}

void Huffman::generateCode(Node* node, std::string path){
    if(node==NULL){
        return;
    }
    if(node->left==NULL && node->right==NULL){
        code[node->ch]=path;
    }
    generateCode(node->left, path+'0');
    generateCode(node->right, path+'1');
}

std::string Huffman::encode(const std::string &text){
    buildTree(text);
    generateCode(root, "");
    std::string encodedText="";
    for(char ch:text){
        encodedText+=code[ch];
    }
    return encodedText;
}

void Huffman::saveToFile(const std::string &text, const std::string &fileName){
    std::ofstream out;
    out.open(fileName, std::ios::binary);
    out<<text;
    out.close();
}