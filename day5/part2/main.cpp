#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

size_t testData(size_t letter, std::vector<char> data){
    data.erase(std::remove(data.begin(), data.end(), letter), data.end());
    data.erase(std::remove(data.begin(), data.end(), letter + 32), data.end());
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
    return data.size();
}

int main(){
    std::vector<char> data;
    std::ifstream infile("in.txt");
    char temp;
    while(infile >> std::noskipws >> temp){
        data.push_back(temp);
    }
    size_t min = data.size();
    for(size_t i = 65; i < 91; ++i){
        if(testData(i, data) < min){
            min = testData(i, data);
        }
    }
    std::cout << min << std::endl;
}