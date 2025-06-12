#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    string input="a12a";
    unordered_map<char, int> frequency;
    int n=input.size();
    for(int i=0; i<n; i++){
        frequency[input[i]]++;
    }
    for(auto i:frequency){
        cout<<i.first<<" -> "<<i.second<<endl;
    }
    return 0;
}