#include <iostream>
#include <vector> 
#include <fstream>
#include <climits>
#include <algorithm>

//A=rock, B= paper, C = scissor. X=rock, Y=paper, Z=scissor
int one(){
    std::string s;
    std::fstream f;
    f.open("input.txt");
    int opponent;
    int strat;
    int totalPoints = 0;
    while(std::getline(f,s)){
        opponent = s[0];
        strat = s[2];

        int diff = (strat - opponent)%3;
        opponent -= ('A' - 1);
        strat -= ('X' - 1);
        if(diff == 2){
            totalPoints+=(strat+3);
        }
        else if(diff == 1){
            totalPoints+=strat;
        }
        else{
            totalPoints+=(strat+6);
        }
    }

    return totalPoints;

}
//A=rock, B= paper, C = scissor. X = LOSE Y = DRAW Z = WIN
int two(){
    std::string s;
    std::fstream f;
    f.open("input.txt");

    char strat;
    int played;
    int totalPoints = 0;
    int temp = 0;

    while(std::getline(f,s)){
        strat = s[2];
        played = s[0] - 'A';
        if(strat == 'Y'){
            totalPoints+=(played+4);
        }
        else if(strat == 'X'){
            temp = ((played-1)+3)%3 + 1;
            totalPoints+=temp;
        }
        else{
            temp = (played + 1)%3 + 7;
            totalPoints+=temp;
        }
    }
    return totalPoints;
}
int main () {
    std::cout<<two()<<"\n";
    return 0;
}