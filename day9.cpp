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
#define prime 1381



void move(std::pair<int,int>& head, std::pair<int,int>& tail){
    if(head.first!= tail.first && head.second!= tail.second && (std::abs(head.first - tail.first) == 2 || std::abs(head.second - tail.second) == 2)){
        if(tail.first < head.first && tail.second < head.second){
            tail.first++;
            tail.second++;
        }
        else if(tail.first > head.first && tail.second < head.second){
            tail.first--;
            tail.second++;
        }
        else if(tail.first > head.first && tail.second > head.second){
            tail.first--;
            tail.second--;
        }
        else{
            tail.first++;
            tail.second--;
        }
    }
    else if(head.second == tail.second && (std::abs(head.first - tail.first) == 2)){
        if(tail.first < head.first){
            tail.first++;
        }
        else{
            tail.first--;
        }
    }
    else if(head.first == tail.first && std::abs(head.second - tail.second) == 2){
        if(tail.second < head.second){
            tail.second++;
        }
        else{
            tail.second--;
        }
    }
}

int main () {
    std::string s;
    std::fstream f;
    f.open("test.txt");

    std::unordered_set<std::string> pairs;

    std::pair<int,int> head{0,0};   
    std::vector<std::pair<int,int>> tails(9, {0,0});

    int lineno = 0;
    while(std::getline(f,s)){
        char direction = s[0];
        int dist = std::stoi(s.substr(2));
        for(int i = 0; i<dist; i++){
            if(direction == 'R'){
                head.first++;
            }
            else if(direction == 'L'){
                head.first--;
            }
            else if(direction == 'U'){
                head.second++;
            }
            else{
                head.second--;
            }
            std::pair<int,int> newHead = head;
            for(int i = 0; i<tails.size(); i++){
                move(newHead, tails[i]);
                newHead = tails[i];
            }
            std::string temp = std::to_string(tails[tails.size()-1].first) + " " + std::to_string(tails[tails.size()-1].second);
            pairs.insert(temp);
        }
    }
    std::cout<< pairs.size() <<"\n";
}