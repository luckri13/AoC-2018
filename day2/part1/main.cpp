#include <fstream>
#include <vector>
#include <string>
#include <iostream>

bool checkDoubles(const std::string &box){
    for(int i = 0; i < box.length(); ++i){
        int instances = 0;
        for(int j = 0; j < box.length(); ++j){
            if(box[i] == box[j]){
                instances += 1;
            }
        }
        if(instances > 1 && instances < 3){
            return true;
        }
    }
    return false;
}

bool checkTriples(const std::string &box){
    for(int i = 0; i < box.length(); ++i){
        int instances = 0;
        for(int j = 0; j < box.length(); ++j){
            if(box[i] == box[j]){
                instances += 1;
            }
        }
        if(instances > 2 && instances < 4){
            return true;
        }
    }
    return false;
}

int main(void){
    std::vector<std::string> boxes;
    std::ifstream infile("in.txt");
    std::string temp;
    while(infile >> temp){
        boxes.push_back(temp);
    }
    int doubles = 0, triples = 0;
    for(int i = 0; i < boxes.size(); ++i){
        doubles += checkDoubles(boxes.at(i));
        triples += checkTriples(boxes.at(i));
    }
    std::cout << doubles * triples << std::endl;
    system("pause");
    return 0;
}