/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* recur(vector<vector<int>>&grid,int sr, int er,int sc, int ec){
        if(sr>er or sc>ec) return nullptr;
        int val=grid[sr][sc];
        bool flag=true;
        for(int i=sr;i<=er;i++){
            for(int j=sc;j<=ec;j++){
                if(val!=grid[i][j]){
                    flag=false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) return new Node(val,true);
        int mr=(sr+er)/2,mc=(sc+ec)/2;
        Node* topleft=recur(grid,sr,mr,sc,mc);
        Node* topright=recur(grid,sr,mr,mc+1,ec);
        Node* bottomleft=recur(grid,mr+1,er,sc,mc);
        Node* bottomright=recur(grid,mr+1,er,mc+1,ec);
        return new Node(0,false,topleft,topright,bottomleft,bottomright);
    }
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        return recur(grid,0,n-1,0,n-1);
    }
};