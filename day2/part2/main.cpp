#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::string commonLetters(const std::string &word1, const std::string &word2){
    std::string temp;
    for(int i = 0; i < word1.size(); ++i){
        if(word1[i] == word2[i]){
            temp += word1[i];
        }
    }
    return temp;
}

int boxCheck(int box, std::vector<std::string> &boxes){
    for(int i = box + 1; i < boxes.size(); ++i){
        int differences = 0;
        for(int j = 0; j < boxes.at(box).size(); ++j){
            if(boxes.at(box)[j] != boxes.at(i)[j]){
                differences += 1;
            }
        }
        if(differences < 2){
            return i;
        }
    }
    return 0;
}

std::string arrayCheck(std::vector<std::string> &boxes){
    for(int i = 0; i < boxes.size(); ++i){
        if(boxCheck(i, boxes)){
            return commonLetters(boxes.at(i), boxes.at(boxCheck(i, boxes)));
        }
    }
}

int main(void){
    std::vector<std::string> boxes;
    std::ifstream infile("in.txt");
    std::string temp;
    while(infile >> temp){
        boxes.push_back(temp);
    }
    std::cout << arrayCheck(boxes) << std::endl;
    system("pause");
    return 0;
}