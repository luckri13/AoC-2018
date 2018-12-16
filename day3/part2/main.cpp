#include <vector>
#include <iostream>
#include <fstream>
#include <string>

void parser(std::string &claim, std::vector<std::vector<size_t>> &fabric){
    size_t x, y, w, l;
    x = std::stoi(claim.substr(claim.find("@") + 1, claim.find(",") - claim.find("@") + 1));
    y = std::stoi(claim.substr(claim.find(",") + 1, claim.find(":") - claim.find(",") + 1));
    w = std::stoi(claim.substr(claim.find(":") + 1, claim.find("x") - claim.find(":") + 1));
    l = std::stoi(claim.substr(claim.find("x") + 1, claim.size() - claim.find("x") + 1));
    for (size_t i = x; i < x + w; ++i){
        for (size_t j = y; j < y + l; ++j){
            ++fabric[i][j];
        }
    }
}

size_t getIntact(std::string &claim, std::vector<std::vector<size_t>> &fabric){
    size_t id, x, y, w, l;
    id = std::stoi(claim.substr(claim.find("#") + 1, claim.find("@") - claim.find("#") - 1));
    x = std::stoi(claim.substr(claim.find("@") + 1, claim.find(",") - claim.find("@") + 1));
    y = std::stoi(claim.substr(claim.find(",") + 1, claim.find(":") - claim.find(",") + 1));
    w = std::stoi(claim.substr(claim.find(":") + 1, claim.find("x") - claim.find(":") + 1));
    l = std::stoi(claim.substr(claim.find("x") + 1, claim.size() - claim.find("x") + 1));
    for (size_t i = x; i < x + w; ++i){
        for (size_t j = y; j < y + l; ++j){
            if(fabric[i][j] > 1){
                return 0;
            }
        }
    }
    return id;
}

int main(){
    std::vector<std::string> claims;
    std::ifstream infile("in.txt");
    std::string temp [4];    
    while(infile >> temp[0] >> temp[1] >> temp[2] >> temp[3]){
        claims.push_back(temp[0] + temp[1] + temp[2] + temp[3]);
    }
    std::vector<std::vector<size_t>> fabric(1000, std::vector<size_t>(1000));
    for (size_t i = 0; i < claims.size(); ++i){
        parser(claims.at(i), fabric);
    }
    size_t amount = 0;
    for (size_t i = 0; i < 1000; ++i){
        for (size_t j = 0; j < 1000; ++j){
            if(fabric[i][j] > 1){
                ++amount;
            }
        }
    }
    size_t intactId;
    for (size_t i = 0; i < claims.size(); ++i){
        if(getIntact(claims.at(i), fabric) > 0){
            intactId = getIntact(claims.at(i), fabric);
            break;
        }
    }
    std::cout << "Amount with two and up: " << amount << std::endl;
    std::cout << "Intact ID: " << intactId << std::endl;
}