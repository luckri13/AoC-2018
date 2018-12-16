#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

void getSleepTimes(const std::vector<std::string> lines, std::unordered_map<unsigned int, size_t> &sleepTimes){
    unsigned int currentID;
    unsigned int fallTime;
    for (std::string line : lines){
        if(line.find('#') != line.npos){
            currentID = std::stoi(line.substr(line.find('#') + 1, line.find('b') - line.find('#') - 2));
        }
        else if(line.at(19) == 'f'){
            fallTime = std::stoi(line.substr(line.find(':') + 1, 2));
        }
        else{
            sleepTimes[currentID] += std::stoi(line.substr(line.find(':') + 1, 2)) - fallTime;
        }
    }
}

size_t getSleepyMinute(const int id, const std::vector<std::string> &lines){
    std::vector<size_t> minutes;
    for (size_t i = 0; i < 60; ++i){
        minutes.push_back(0);
    }
    int currentID;
    unsigned int fallTime;
    for (std::string line : lines){
        if(line.find('#') != line.npos){
            currentID = std::stoi(line.substr(line.find('#') + 1, line.find('b') - line.find('#') - 2));
        }
        if(currentID == id){
            if(line.at(19) == 'f'){
                std::string time = line.substr(line.find(':') + 1, 2);
                time.erase(0, std::min(time.find_first_not_of('0'), time.size() - 1));
                fallTime = std::stoi(time);
            }
            else if(line.at(19) == 'w'){
                std::string time = line.substr(line.find(':') + 1, 2);
                time.erase(0, std::min(time.find_first_not_of('0'), time.size() - 1));
                for (int i = fallTime; i < std::stoi(time); ++i){
                    minutes.at(i) += 1;
                }
            }
        }
    }
    return distance(std::begin(minutes), max_element(std::begin(minutes), std::end(minutes)));
}

int main(){
    std::vector<std::string> entries;
    std::ifstream infile("in.txt");
    std::string temp;
    while(std::getline(infile, temp)){
        entries.push_back(temp);
    }
    std::sort(entries.begin(), entries.end());
    std::unordered_map<unsigned int, size_t> guardSleepTimes;
    getSleepTimes(entries, guardSleepTimes);
    size_t max = 0;
    int maxID;
    std::unordered_map<unsigned int, size_t>::iterator it;
    for (it = guardSleepTimes.begin(); it != guardSleepTimes.end(); ++it){
        if(it -> second > max){
            max = it -> second;
            maxID = it -> first;
        }
    }
    size_t sleepyMinute = getSleepyMinute(maxID, entries);
    std::cout << maxID * sleepyMinute << std::endl;
}
