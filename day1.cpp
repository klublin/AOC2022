#include <iostream>
#include <vector> 
#include <fstream>
#include <climits>
#include <algorithm>

int one(){
    std::string s;
    std::fstream f;
    f.open("input.txt");
    int maxCal = INT_MIN;
    int currElf = 0;
    while(f){
        std::getline(f,s);
        if(s=="\r"){
            maxCal = std::max(maxCal, currElf);
            currElf = 0;
        }
        else{
            currElf += std::stoi(s);
        }
    }

    return maxCal;
}
int two(){
    std::string s;
    std::fstream f;
    f.open("input.txt");
    std::vector<int> cal;
    int currElf = 0;

    while(f){
        std::getline(f,s);
        if(s=="\r"){
            cal.push_back(currElf);
            currElf = 0;
        }
        else{
            currElf += std::stoi(s);
        }
    }

    std::sort(cal.begin(), cal.end(), std::greater<int>());
    return cal[0]+cal[1]+cal[2];
}

int main () {
    std::cout<<two()<<"\n";
    return 0;
}