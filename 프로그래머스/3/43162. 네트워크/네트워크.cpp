#include <string>
#include <vector>

using namespace std;
int visited[200];

void chk(int n, int i, vector<vector<int>> computers);
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<n;++i){
        if(visited[i]==0){
            chk(n, i, computers);
            answer++;
        }
    }
    
    return answer;
}
void chk(int n, int i, vector<vector<int>> computers){
    visited[i] = 1;
    
    for(int j=0;j<n;++j){
        if(computers[i][j]&&!visited[j]){
            chk(n, j, computers);
        }
    }
}