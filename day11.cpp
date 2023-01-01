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

typedef enum op {mult, divi, add, sub} op;

struct monkey
{
    std::vector<long long int> items;
    std::pair<op, std::string> operation; 
    long long int test;
    int prime;
    int alt;
    int inspection;

    void print(){
        std::cout<<"items = [";
        for(int i : items){
            std::cout<<i<<",";
        }
        std::cout<<'\b'<<"]\n";
        std::cout<<"\tinspections = "<<inspection<<"\n";
    }
};

long long int calc(std::pair<op, std::string>& operation, long long int old){
    #define helpCalc(sign, a, b) return operation.first == mult ? a*b : operation.first == add ? a + b : operation.first == sub ? a - b : a/b;
    
    if(operation.second.find("old")!=std::string::npos){
        helpCalc(operation.first, old, old);
    }
    long long int incr = std::stoll(operation.second);
    helpCalc(operation.first, old, incr);
    
}
long long int one(std::vector<monkey>& monkeys){
    int D = 1;
    for(monkey m : monkeys){
        D*=m.test;
    }
    for(int round = 1; round!=10001; round++){
        
        for(int i = 0; i<monkeys.size(); i++){
            for(long long int item : monkeys[i].items){
                monkeys[i].inspection ++;
                long long int temp = calc(monkeys[i].operation, item)%D;
                temp%monkeys[i].test == 0 ? monkeys[monkeys[i].prime].items.push_back(temp) : monkeys[monkeys[i].alt].items.push_back(temp);
            }
            monkeys[i].items.clear();
        }
        // std::cout<<"after round "<<round<<"\n\n";
        // for(int i = 0; i<monkeys.size(); i++){
        //     std::cout<<"monkey "<<i<<": \n\t";
        //     monkeys[i].print();
        //     std::cout<<"\n";
        // }
    }
    long long int max1 = INT_MIN;
    long long int max2= INT_MIN;
    for(int i = 0; i<monkeys.size(); i++){
        std::cout<<monkeys[i].inspection<<"\n";
        if(monkeys[i].inspection > max1){
            max2 = max1;
            max1 = monkeys[i].inspection;
        }
        else if(monkeys[i].inspection > max2){
            max2 = monkeys[i].inspection;
        }
    }
    return max1*max2;
}

int main () {
    std::string s;
    std::fstream f;
    f.open("input.txt");

    std::vector<monkey> monkeys;

    while(std::getline(f,s)){
        monkey create;

        while(s!= ""){
            std::getline(f,s);
            if(s.find("Starting items")!=std::string::npos){
                std::stringstream ss(s.substr(s.find(":")+1));
                while(ss.good()){
                    std::string temp;
                    ss >> temp;
                    create.items.push_back(std::stoll(temp));
                }
            }
            else if(s.find("Operation")!=std::string::npos){
                if(s.find("+")!=std::string::npos){
                    std::string increment = (s.substr(s.find("+")+2));

                    create.operation.first = add;
                    create.operation.second = increment; 
                }
                else if(s.find("*")!=std::string::npos){
                    std::string increment = s.substr(s.find("*")+2);
                    
                    create.operation.first = mult;
                    create.operation.second = increment; 
                }
                else if(s.find("-")!=std::string::npos){
                    std::string increment = s.substr(s.find("-")+2);
                    
                    create.operation.first = sub;
                    create.operation.second = increment; 
                }
                else{
                    std::string increment = s.substr(s.find("/") + 2);

                    create.operation.first = divi;
                    create.operation.second = increment;
                }
            }
            else if(s.find("Test")!=std::string::npos){
                int divisor = std::stoll(s.substr(s.find("y") + 2));
                create.test = divisor;
            }
            else if(s.find("If true:")!=std::string::npos){
                int to = std::stoll(s.substr(s.find("y") + 2));
                create.prime = to;
            }
            else if(s.find("If false:")!=std::string::npos){
                int to = std::stoll(s.substr(s.find("y")+ 2));
                create.alt = to;
            }
        }
        create.inspection = 0;
        monkeys.push_back(create);

        create.items.clear();
    }
    std::cout<<one(monkeys)<<"\n";
}