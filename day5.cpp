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

//we are using a deque here b/c now we can simulate a stack with pop_front(), since the stack will be reversed when initially parsing input
typedef std::vector<std::deque<char>> sVector;
std::string one(){
    std::string s;
    std::fstream f;
    f.open("input.txt");
    
    sVector stacks(9);
    
    while(std::getline(f,s)){
        if(s[1] == '1'){
            break;
        }
        for(int i = 0; i<s.size(); i+=4){
            int stackIndex = i/4;
            if(s[i] == '['){
                stacks[stackIndex].push_back(s[i+1]);
            }   
        }
    }
    std::getline(f,s);

    while(std::getline(f,s)){
        int move;
        int from;
        int to;

        std::stringstream ss(s);

        std::string temp;
        int count = 0;
        while(ss.good()){
            ss >> temp;
            if(temp[0]>='0' && temp[0]<='9'){
                if(count == 0){
                    move = std::stoi(temp); 
                }
                else if(count == 1){
                    from = std::stoi(temp);
                }
                else{
                    to = std::stoi(temp);
                }
                count++;
            }
        }
        from--;
        to--;
        for(int i = 0; i<move; i++){
            stacks[to].push_front(stacks[from].front());
            stacks[from].pop_front();
        }
    }
    std::string res = "";

    for(int i = 0; i<stacks.size(); i++){
        res+=stacks[i].front();
    }
    return res;
}
std::string two(){
    std::string s;
    std::fstream f;
    f.open("input.txt");
    
    sVector stacks(9);
    
    while(std::getline(f,s)){
        if(s[1] == '1'){
            break;
        }
        for(int i = 0; i<s.size(); i+=4){
            int stackIndex = i/4;
            if(s[i] == '['){
                stacks[stackIndex].push_back(s[i+1]);
            }   
        }
    }
    std::getline(f,s);

    while(std::getline(f,s)){
        int move;
        int from;
        int to;

        std::stringstream ss(s);

        std::string temp;
        int count = 0;
        while(ss.good()){
            ss >> temp;
            if(temp[0]>='0' && temp[0]<='9'){
                if(count == 0){
                    move = std::stoi(temp); 
                }
                else if(count == 1){
                    from = std::stoi(temp);
                }
                else{
                    to = std::stoi(temp);
                }
                count++;
            }
        }
        from--;
        to--;
        std::deque<char> deq;
        for(int i = 0; i<move; i++){
            deq.push_back(stacks[from].front());
            stacks[from].pop_front();
        }
        while(!deq.empty()){
            stacks[to].push_front(deq.back());
            deq.pop_back();
        }
    }
    std::string res = "";

    for(int i = 0; i<stacks.size(); i++){
        res+=stacks[i].front();
    }
    return res;
}
int main () {
    std::cout<<two()<<"\n";
}
