#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

void initializeGuards(const std::vector<std::string> lines, std::unordered_map<size_t, std::vector<size_t>> &guards){
    std::vector<size_t> ids;
    for (std::string line : lines){
        if(line.find('#') != line.npos){
            size_t currentID;
            currentID = std::stoi(line.substr(line.find('#') + 1, line.find('b') - line.find('#') - 2));
            if(!(std::find(ids.begin(), ids.end(), currentID) != ids.end())){
                ids.push_back(currentID);
            }
        }
    }
    std::vector<size_t> temp;
    for(size_t j = 0; j < 60; ++j){
        temp.push_back(0);
    }
    for(size_t i = 0; i < ids.size(); ++i){
        guards[ids.at(i)] = temp;
    }
}

void setGuards(const std::vector<std::string> lines, std::unordered_map<size_t, std::vector<size_t>> &guards){
    int currentID;
    unsigned int fallTime;
    for (std::string line : lines){
        
        if(line.find('#') != line.npos){
            currentID = std::stoi(line.substr(line.find('#') + 1, line.find('b') - line.find('#') - 2));
        }
        if(line.at(19) == 'f'){
            std::string time = line.substr(line.find(':') + 1, 2);
            time.erase(0, std::min(time.find_first_not_of('0'), time.size() - 1));
            fallTime = std::stoi(time);
        }
        else if(line.at(19) == 'w'){
            std::string time = line.substr(line.find(':') + 1, 2);
            time.erase(0, std::min(time.find_first_not_of('0'), time.size() - 1));
            for (int i = fallTime; i < std::stoi(time); ++i){
                guards[currentID].at(i) += 1;
            }
        }
    }
}

size_t getSleepyGuard(const std::unordered_map<size_t, std::vector<size_t>> guards){
    size_t maxID;
    size_t maxValue = 0;
    for (const auto &id : guards){
        for(size_t i = 0; i < 60; ++i){
            if(id.second[i] > maxValue){
                maxID = id.first;
                maxValue = id.second[i];
            }
        }
    }
    return maxID;
}

size_t getSleepyMinute(const std::unordered_map<size_t, std::vector<size_t>> guards, const size_t sleepyGuard){
    auto iDVector = guards.find(sleepyGuard);
    return distance(std::begin(iDVector -> second), max_element(std::begin(iDVector -> second), std::end(iDVector -> second)));
}

int main(){
    std::unordered_map<size_t, std::vector<size_t>> guards;
    std::vector<std::string> entries;
    std::ifstream infile("in.txt");
    std::string temp;
    while(std::getline(infile, temp)){
        entries.push_back(temp);
    }
    std::sort(entries.begin(), entries.end());
    initializeGuards(entries, guards);
    setGuards(entries, guards);
    size_t sleepyGuard = getSleepyGuard(guards);
    size_t sleepMinute = getSleepyMinute(guards, sleepyGuard);
    std::cout << sleepyGuard * sleepMinute << std::endl;
}