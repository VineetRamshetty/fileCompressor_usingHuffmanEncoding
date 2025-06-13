#include "../include/huffman.h"
#include<iostream>
#include<fstream>
#include<sstream>

int main(int argc, char *argv[]){
    
    if(argc!=4){
        std::cerr<<"ERROR: invalid number of arguments"<<std::endl;
        return 1;
    }

    std::string mode=argv[1];
    std::string inputFile=argv[2];
    std::string outputFile=argv[3];

    Huffman huff;

    if(mode=="compress"){
        std::ifstream in;
        in.open(inputFile);

        std::stringstream temp;
        temp<<in.rdbuf();
        std::string text=temp.str();

        std::string encodedText=huff.encode(text);
        huff.saveToFile(encodedText, outputFile);

        std::cout<<"compression is successful"<<std::endl;

        in.close();
    }

    return 0;
}