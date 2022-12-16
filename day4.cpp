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
    
    while(std::getline(f,s)){
        std::string first = s.substr(0, s.find(","));
        std::string second = s.substr(s.find(",")+1);
        
        int x1 = std::stoi(first.substr(0, first.find("-")));
        int x2 = std::stoi(first.substr(first.find("-")+1));

        int y1 = std::stoi(second.substr(0, second.find("-")));
        int y2 = std::stoi(second.substr(second.find("-")+1));

        //test if this string parse is good lol
        std::cout<<"("<<x1<<","<<x2<<") and ("<<y1<<","<<y2<<")"<<"\n";

        if(x1<=y1 && x2>=y2 || y1<=x1 && y2>=x2){
            total++;
        }
    }

    return total;

}
int two(){
    std::string s;
    std::fstream f;
    f.open("input.txt");
    int total = 0;
    
    while(std::getline(f,s)){
        std::string first = s.substr(0, s.find(","));
        std::string second = s.substr(s.find(",")+1);
        
        int x1 = std::stoi(first.substr(0, first.find("-")));
        int x2 = std::stoi(first.substr(first.find("-")+1));

        int y1 = std::stoi(second.substr(0, second.find("-")));
        int y2 = std::stoi(second.substr(second.find("-")+1));

        if(x2>=y1 && x2<=y2 || y2>=x1 && y2<=x1 || x1>=y1 && x1<=y2 || y1>=x1 && y1<=x2){
            total++;
        }
    }

    return total;

}
int main () {
    std::cout<<two()<<"\n";
    return 0;
}