#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int r;
    int c;

    int rows[4]={-1,0,1,0};
    int cols[4]={0,1,0,-1};
    bool validbfs(int x,int y,int r,int c){
        return x>0&&x<r&& y>0&&y<c;
    }
    void replaceSurrounded(vector<vector<char>> &mat) {
        r = mat.size();
        c = mat[0].size();
        queue<pair<int,int>> q;
        //apply bjs method on border 0's
        //replacre 0's with t
        //first row
        for (int j = 0; j < c;j++){
            if(mat[0][j]=='0'){  //pahali row me traversing ho rhi hh ot caro column
                q.push({0,j});
                mat[0][j]='T';
            }
        }
        //first col
        for (int i = 1; i < r;i++){
            if(mat[i][0]=='0'){
                q.push({i, 0});
                mat[i][0]='T';
            }
        }
        //last row
        for (int k = 1; k < c;k++){
            if(mat[r-1][k]=='0'){
                q.push({r - 1, k});
                mat[r - 1][k]='T';
            }
        }
        //last col
        for (int p = 1; p < r;p++){
            if(mat[p][c-1]=='0'){
                q.push({p, c - 1});
                mat[p][c - 1]='T';
            }
        }
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4;i++){
                int nx=x+rows[i];   
                int ny=y+cols[i];
                if(validbfs(nx,ny,r,c)&&mat[nx][ny]=='0'){
                    mat[nx][ny]='T';  //here we are replacing 0 with t as it is connected to border 0
                    q.push({nx,ny});
                }
            }
        }

        //replace all t with 0 and 0 with x
        for (int i = 0; i < r;i++){
            for (int j = 0; j < c;j++){
                if(mat[i][j]=='0'){
                    mat[i][j]='X';
                }
                if(mat[i][j]=='T'){
                    mat[i][j]='0';
                }
            }
        }
    }
};

int main() {
    vector<vector<char>> mat = {
        {'X','X','X','X'},
        {'X','0','0','X'},
        {'X','X','0','X'},
        {'X','0','X','X'}
    };

    Solution s;
    s.replaceSurrounded(mat);

    cout << "Modified Matrix:\n";
    for (auto &row : mat) {
        for (auto &ch : row)
            cout << ch << " ";
        cout << "\n";
    }

    return 0;
}
