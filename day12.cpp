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


using Point = std::pair<int,int>;
void print(std::vector<std::vector<char>>& grid){
    for(auto& v : grid){
        for(auto& i : v){
            std::cout<<i<<",";
        }
        std::cout<<"\n";
    }
}
void printI(std::vector<std::vector<int>>& grid){
    for(auto& v : grid){
        for(auto& i : v){
            std::cout<<i<<",";
        }
        std::cout<<"\n";
    }
}
int one(std::vector<std::vector<char>>& grid, Point& start, Point& end){
    int m = grid.size();
    int n = grid[0].size();
    std::queue<Point> q;

    std::vector<Point> dirs = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
    std::vector<std::vector<bool>>visited(m, std::vector<bool>(n, false));
    std::vector<std::vector<int>>dist(m, std::vector<int>(n, INT_MAX));

    visited[start.first][start.second] = true;
    dist[start.first][start.second] = 0;
    q.push({start.first, start.second});

    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        if(curr == end){
            printI(dist);
            return dist[curr.first][curr.second];
        }
        for(auto& dir : dirs){
            int x = curr.first + dir.first;
            int y = curr.second + dir.second;
            if(x < m && x >= 0 && y < n && y >= 0 && !visited[x][y]){
                if(grid[curr.first][curr.second] + 1 >= grid[x][y]){
                    q.push({x, y});
                    visited[x][y] = true;

                    //std::cout<<dist[x][y]<<" "<<dist[curr.first][curr.second]<<"\n";
                    dist[x][y] = dist[x][y] < dist[curr.first][curr.second] + 1 ? dist[x][y] : dist[curr.first][curr.second] + 1;  
                    
                }
            }
        }

    }   
    return -1;
}

int main () {
    std::string s;
    std::fstream f;
    f.open("test.txt");

    std::vector<std::vector<char>> grid; 
    std::pair<int,int> start;
    Point end;
    while(std::getline(f,s)){
        std::vector<char> temp;

        for(char c : s){
            if(c == 'S'){
                start.first = grid.size();
                start.second =  temp.size();
                temp.push_back('a');
            }
            else if(c == 'E'){
                end.first = grid.size();
                end.second =  temp.size();
                temp.push_back('z');
            }
            else{
                temp.push_back(c);
            }
        }
        grid.push_back(temp);
        temp.clear();
    }
    std::cout<<one(grid, start, end)<<"\n\n";
    int minDist = INT_MAX;
    for(int i = 0; i<grid.size(); i++){
        for(int j = 0; j<grid[0].size(); j++){
            if(grid[i][j] == 'a'){
                start.first = i;
                start.second = j;
                int temp = one(grid,start,end);
                if(temp!=-1){
                    minDist = std::min(minDist, one(grid, start, end));
                }
            }
            
        }
    }
}