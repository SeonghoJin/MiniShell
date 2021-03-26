#include "strutill.h"
#include <sstream>
#include <algorithm>

std::vector<std::string> split(std::string input, char delimiter) {
    std::vector<std::string> ret;
    std::stringstream ss(input);
    std::string temp;
 
    while (getline(ss, temp, delimiter)) {
        ret.push_back(temp);
    }
 
    return ret;
}

std::string join(std::vector<std::string> input, char insertStr){
    std::stringstream ss;
    size_t inputSz = input.size();
    for(size_t i = 0; i < inputSz; i++){
        ss << input[i];
        if(i != inputSz-1)ss << insertStr;
    }
    return ss.str();
}

std::string trim(std::string input){
    std::stringstream ss;
    size_t inputSz = input.size();
    size_t charStartIndex = -1;
    for(size_t i = 0; i < inputSz; i++){
        if(input[i] != ' '){
            charStartIndex = i;
            break;
        }
    }
    if(charStartIndex == -1)return "";
    else return input.substr(charStartIndex, inputSz);
}