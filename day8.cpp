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


void print(std::vector<std::vector<int>>& graph){
    for(auto& v : graph){
        for(auto& i : v){
            std::cout<<i<<",";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
}

int horizontal(std::vector<std::vector<int>>& graph, int x, int y, int sign, int bound, std::vector<std::vector<bool>>& visible, int currMax){
    //starts at graph[x][y] and moves horizontally to find all the trees visible at row x
    int counter = 0;
    for(int i = y; i!=bound; i+=(sign*1)){
        if(graph[x][i] > currMax){
            counter++;
            visible[x][i] = true;
            currMax = graph[x][i];
        }
    }
    return counter;

}
int vertical(std::vector<std::vector<int>>& graph, int x, int y, int sign, int bound, std::vector<std::vector<bool>>& visible, int currMax){
    //starts at graph[x][y] and moves vertically to find all trees visible at column y

    int counter = 0;
    for(int i = x; i!=bound; i+=(sign*1)){
        if(graph[i][y] > currMax){
            counter++;
            visible[i][y] = true;
            currMax = graph[i][y];
        }
    }
    return counter;
}
int one(std::vector<std::vector<int>>& graph){
    int m = graph.size(); // row size
    int n = graph[0].size(); //# of columns 
    int count = 0;
    std::vector<std::vector<int>>dir{{0,1}, {0,-1}, {1,0}, {-1,0}};
    std::vector<std::vector<bool>> visible(graph.size(), std::vector<bool>(graph[0].size(), false));
    for(int i = 1; i<(m - 1); i++){
        horizontal(graph, i, 1, 1, n-1, visible, graph[i][0]);
        horizontal(graph, i, n-2, -1, 0, visible, graph[i][n-1]);
    }
    for(int i = 0; i<n; i++){
        vertical(graph, 1, i, 1, m - 1, visible, graph[0][i]);
        vertical(graph, m - 2, i, -1, 0, visible, graph[m - 1][i]);
    }

    for(int i = 1; i<(m - 1); i++){
        for(int j = 1; j<(n - 1); j++){
            if(visible[i][j]) count++;
        }
    } 
    return count + 2*m + 2*n - 4;
}
int horizontal2(std::vector<std::vector<int>>& graph, int x, int y, int sign, int bound, int currMax){
    //starts at graph[x][y] and moves horizontally to find all the trees visible at row x
    if(y >= graph[0].size() || y < 0){
        return 0;
    }
    if(y == graph[0].size() - 1 || y == 0){
        return 1;
    }
    //std::cout<<"x = "<<x<<" y = "<<y <<" bound = " << bound <<"\n";
    int counter = 0;
    for(int i = y; i!=bound; i+=(sign*1)){
        //std::cout<<"i = "<<i<<"\n";
        if(graph[x][i] < currMax){
            counter++;
        }
        else{
            counter++;
            break;
        }
    }
    return counter;

}
int vertical2(std::vector<std::vector<int>>& graph, int x, int y, int sign, int bound, int currMax){
    //starts at graph[x][y] and moves vertically to find all trees visible at column y
    if(x < 0 || x>=graph.size()){
        return 0;
    }
    if(x == graph.size() - 1 || x == 0){
        return 1;
    }
    int counter = 0;
    //std::cout<<"I'm observing value: "<<graph[x][y]<<" with currMax = "<<currMax<<" ";
    for(int i = x; i!=bound; i+=(sign*1)){

        if(graph[i][y] < currMax){
            counter++;
        }
        else{
            counter++;
            break;
        }
    }
    return counter;
}
int two(std::vector<std::vector<int>>& graph){
    int m = graph.size();
    int n = graph[0].size();
    int maxScore = 0;

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            // std::cout<<"at coor i = "<<i<<" and j = "<<j <<" "<<vertical2(graph, i - 1, j, -1, 0, graph[i][j])<<"\n";
            int temp = horizontal2(graph, i, j + 1, 1, n, graph[i][j]) * horizontal2(graph, i, j - 1, -1, -1, graph[i][j]) * vertical2(graph, i + 1, j, 1, m, graph[i][j]) * vertical2(graph, i - 1, j, -1, -1, graph[i][j]);
            if(temp > maxScore){
                std::cout<<"i = "<<i <<" and j = " << j<<"\n";
                maxScore = temp;
            }
        }
    }
    // std::cout<<horizontal2(graph, 3, 2+ 1, 1, n, graph[3][2])<<"\n";
    // std::cout<<horizontal2(graph, 3, 2 - 1, -1, -1, graph[3][2])<<"\n";
    // std::cout<<vertical2(graph, 3 + 1, 2, 1, m, graph[3][2])<<"\n";
    // std::cout<<vertical2(graph, 3 - 1, 2, -1, -1, graph[3][2])<<"\n";
    return maxScore;
}
int main () {
    std::string s;
    std::fstream f;
    f.open("input.txt");

    std::vector<std::vector<int>> graph;

    while(std::getline(f,s)){
        std::vector<int> temp;

        for(char c : s){
            temp.push_back(c-'0');
        }

        graph.push_back(temp);

        temp.clear();
    }

    //std::cout<<one(graph)<<"\n";
    std::cout<<two(graph)<<"\n";
}