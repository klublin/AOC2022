#include <iostream>
#include <vector> 
#include <fstream>
#include <climits>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <sstream>


bool one(int cycles){
    // if(cycles == 20 || cycles == 60 || cycles == 100 || cycles == 140 || cycles == 180 || cycles == 220){
    //     return true;
    // }
    
    return cycles%40 == 0 ? true : false;
}

char two(int cycles, int x){
    if(cycles == x || cycles == (x-1) || cycles == (x+1)){
        return '#';
    }
    return '.';
}
int main () {
    std::string s;
    std::fstream f;
    f.open("input.txt");

    //int signal = 0;
    int cycles = 1;
    int xRegister = 1;
    while(std::getline(f,s)){
        int increment = 0;
        if(s.find("addx")!=std::string::npos){
            increment = std::stoi(s.substr(s.find(" ") + 1));
            std::cout<<two((cycles - 1)%40, xRegister );  
            cycles++;
            if(one(cycles-1)){
                std::cout<<"\n";
            }
        }
        std::cout<<two((cycles - 1)%40, xRegister);
        cycles++;
        xRegister+=increment;
        if(one(cycles-1)){
            std::cout<<"\n";
        }
        
    }
}