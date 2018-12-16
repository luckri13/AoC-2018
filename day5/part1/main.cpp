#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

int main(){
    std::vector<char> data;
    std::ifstream infile("in.txt");
    char temp;
    while(infile >> std::noskipws >> temp){
        data.push_back(temp);
    }
    size_t i = 0;
    while(i < data.size()){
        if(abs(data[i] - data[i+1]) == 32){
            data.erase(data.begin() + i, data.begin() + i + 2);
            i = 0;
        }
        else{
            ++i;
        }
    }
    std::cout << data.size() << std::endl;
}