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

void print(std::vector<int>& v){
    for(int i : v){
        std::cout<<i<<",";
    }
    std::cout<<"\n\n";
}
int one(std::string& s){
    std::vector<int> map(26, 0);
    
    int left = 0;
    int right = 0;
    while((right - left) < 4){
        map[s[right] - 'a'] ++;
        right ++;
    }
    right--;
    while(right < s.size()){
        int counter = 0;
        for(int i = 0; i<map.size(); i++){
            if(map[i] == 1){
                counter++;
            }
        }
        if(counter == 4){
            return right + 1;
        }
        else{
            if(map[s[left] - 'a'] != 0){
                map[s[left] - 'a'] --;
            }
            left++;
            right++;
            map[s[right] -'a'] ++;
        }
    }
    return s.size();

}
int two(std::string& s){
    std::vector<int> map(26, 0);
    
    int left = 0;
    int right = 0;
    while((right - left) < 14){
        map[s[right] - 'a'] ++;
        right ++;
    }
    right--;
    while(right < s.size()){
        int counter = 0;
        for(int i = 0; i<map.size(); i++){
            if(map[i] == 1){
                counter++;
            }
        }
        if(counter == 14){
            return right + 1;
        }
        else{
            if(map[s[left] - 'a'] != 0){
                map[s[left] - 'a'] --;
            }
            left++;
            right++;
            map[s[right] -'a'] ++;
        }
    }
    return s.size();
}
int main () {
    std::string s;
    std::fstream f;
    f.open("input.txt");

    while(std::getline(f,s)){
        std::cout<<two(s)<<"\n";
    }
}