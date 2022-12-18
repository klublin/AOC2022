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


#define max 70000000
#define needed 30000000
struct Node {
    Node* parent;
    int space; //contains size of all files/sub-directories
    std::unordered_map<std::string, Node*> children;

    Node(Node* _parent) {
        parent = _parent;
        space = 0;
    }
    ~Node(){
        if(parent!=nullptr){
            delete parent;
        }
        for(auto&i : children){
            delete i.second;
        }
    }
};


int one(Node* root){
    int total = 0;
    if(root->space <= 100000){
        total+=root->space;
    }

    for(auto& i : root->children){
        total+=one(i.second);
    }

    return total;
}
int two(Node* root, int spaceNeeded){
    int minDir = INT_MAX;
    if(root->space >= spaceNeeded && root->space < minDir){
        minDir = root->space;
    }

    for(auto& i : root->children){
        minDir = std::min(minDir, two(i.second, spaceNeeded));
    }
    return minDir;
}
int main () {
    std::string s;
    std::fstream f;
    f.open("input.txt");
    Node* root = new Node(nullptr);
    Node* curr = root;
    std::getline(f,s);

    while(std::getline(f,s)){
        if(s.find("$")!=std::string::npos && s.find("cd")!=std::string::npos){
            if(s.find("..")!=std::string::npos){
                curr = curr->parent;
            }
            else{
                std::string child = s.substr(s.find("cd ") + 3, s.size());
                curr = curr->children[child];
            }
        }
        else if(s.find("$") == std::string::npos){
            //we do not have a case for ls, since ls doesn't denote anything
            if(s.find("dir")!=std::string::npos){ 
                std::string dirName = s.substr(4, s.size());
                curr->children[dirName] = new Node(curr);
            }
            else{
                int fileSize = stoi(s.substr(0, s.find(" ")));
                Node* temp = curr;
                while(temp->parent!=nullptr){
                    temp = temp->parent;
                    temp->space+=fileSize;
                }
                curr->space+= fileSize;
            }
        }
    }
    std::cout<<one(root)<<"\n";
    std::cout<<two(root, needed - (max - root->space))<<"\n";

}