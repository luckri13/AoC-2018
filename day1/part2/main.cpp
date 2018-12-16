#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

bool checkFrequency(std::vector<long> &freqV, std::vector<long> &seqV, long &sum){
    for(long i = 0; i < seqV.size(); ++i){
        freqV.push_back(sum);
        sum += seqV.at(i);
        if(std::find(freqV.begin(), freqV.end(), sum) != freqV.end()){
            return true;
        }
    }
    return false;
}

int main(void){
    long sum = 0;
    std::vector<long> frequencyVector;
    std::vector<long> sequenceVector;
    long temp;
    std::ifstream infile("in.txt");
    while(infile >> temp){
            sequenceVector.push_back(temp);
    }
    while(checkFrequency(frequencyVector, sequenceVector, sum) != true);
    std::cout << sum << std::endl;
    system("pause");
    return 0;
}