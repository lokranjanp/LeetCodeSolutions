class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int row = 0;
        int col = 0;
        for(int i=0;i<commands.size();i++){
            if(commands[i]== "DOWN")
                row++;
            else if(commands[i] == "UP")
                row--;
            else if(commands[i] == "RIGHT")
                col++;
            else 
                col--;
        }
        return row*n+col;
    }
};