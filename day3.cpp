#include <iostream>
#include <vector> 
#include <fstream>
#include <climits>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

int one(){
    std::string s;
    std::fstream f;
    f.open("input.txt");
    int total = 0;
    std::unordered_set<int> set;
    while(std::getline(f,s)){
        int size = s.size();
        for(int i = 0; i<size/2; i++){
            set.insert(s[i]);
        }   
        for(int i = size/2; i<size; i++){
            if(set.find(s[i])!=set.end()){
                if(s[i]>='A' && s[i]<='Z'){
                    total+=(s[i]-'A'+27);
                }
                else{
                    total+=(s[i]-'a'+1);
                }
                break;
            }
        }
        set.clear();

    }

    return total;

}
//A=rock, B= paper, C = scissor. X = LOSE Y = DRAW Z = WIN
void print(std::unordered_map<char,int>& map){
    for(auto& i : map){
        std::cout<<"{"<<i.first<<" "<<i.second<<"}"<<", ";
    }
    std::cout<<"\n";
}
int two(){
    std::string s;
    std::fstream f;
    f.open("input.txt");

    int total = 0;
    std::unordered_map<char,int> map;
    int i = 0;
    while(std::getline(f,s)){
        if(i%3 == 2){
            for(int i = 0;i<s.size(); i++){
                if(map[s[i]] == 2){
                    if(s[i]>='A' && s[i]<='Z'){
                        total+=(s[i]-'A'+27);
                    }
                    else{
                        total+=(s[i]-'a'+1);
                    }
                    break;
                }
            }
            map.clear();
        }
        else if(i%3 == 0){
            for(int i = 0; i<s.size(); i++){
                map[s[i]] = 1;
            }
        }
        else{
            for(int i = 0;i<s.size(); i++){
                if(map[s[i]] == 1){
                    map[s[i]] = 2;
                }
            }
        }
        i++;
    }
    return total;
}
int main () {
    std::cout<<two()<<"\n";
    return 0;
}