#include <iostream>
#include <fstream>

int main(void){
    int sum = 0;
    int temp;
    std::ifstream infile("in.txt");
    while(infile >> temp){
        sum +=temp;
    }
    std::cout << sum << std::endl;
    system("pause");
    return 0;
}