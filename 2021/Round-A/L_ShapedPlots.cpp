#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(int X, int Y);

/*
    Passes test set 1 where:
    1 ≤ R ≤ 40.
    1 ≤ C ≤ 40.

    Time limit exceeded for test set 2 where:
    1 ≤ R ≤ 1000 and 1 ≤ C ≤ 1000 for at most 5 test cases.
    For the remaining cases, 1 ≤ R ≤ 40 and 1 ≤ C ≤ 40. 

*/
/* Problem Link
https://codingcompetitions.withgoogle.com/kickstart/round/0000000000436140/000000000068c509
*/
int main()
{
    int T; cin >> T;    // Test cases
    
    for(auto case_num = 1; case_num <= T; ++case_num)
    {
        int R; cin >> R;    // Rows
        int C; cin >> C;    // Columns
        
        string ans = solution(R, C);
        std::cout << "Case #" << case_num << ": " << ans << std::endl;
    }
}

bool isCorrectShape(int h, int w)
{
    if(h * 2 == w || w * 2 == h)
        return true;
    else 
        return false;
}

string solution(int R, int C)
{
    int _shapes = 0;            // Number of L-Shapes
    
    int grid[R][C];

    // Fill grid
    for(auto row = 0; row < R; ++row)
    {
        for(auto col = 0; col < C; ++col)
        {
            cin >> grid[row][col];
        }
    }
    
    for(auto row = 0; row < R; ++row)
    {
        for(auto col = 0; col < C; ++col)
        {
            if(grid[row][col] == 0)     // Skip if 0
                continue;
            
            int dir[2]{1,-1};

            for(int i = 0; i < 2; ++i)  // Grow Up & Down
            {
                int height = 1, width = 1;
                int h_offset = row - height * dir[i];
                while(h_offset >= 0 && h_offset < R && grid[h_offset][col] != 0) // While haven't reached edge or 0
                {
                    height ++;
                    for(int j = 0; j < 2; ++j)  // Branch Left & Right
                    {
                        int w_offset = col - width * dir[j];       
                        while(w_offset >= 0 && w_offset < C && grid[h_offset][w_offset] != 0 && /*optimizations ->*/ width <= height * 2 && ((w_offset+2 >= height) || (R - w_offset + 1))) // While haven't reached edge or 0
                        {
                            width++;
                            isCorrectShape(abs(height), abs(width)) ? _shapes++ : 0;    
                            w_offset = col - width * dir[j]; 
                        }
                        width = 1;            
                    }
                    h_offset = row - height * dir[i];
                }
            } // Grow Up & Down
            
            for(int i = 0; i < 2; ++i) // Grow Left & Right
            {
                int height = 1, width = 1;
                int w_offset = col - width * dir[i];
                while(w_offset >= 0 && w_offset < C && grid[row][w_offset] != 0) // While haven't reached edge or 0
                {
                    width++;
                    for(int j = 0; j < 2; ++j)  // Branch Up & Down
                    {
                        int h_offset = row - height * dir[j];
                        while(h_offset >= 0 && h_offset < R && grid[h_offset][w_offset] != 0 && /*optimizations ->*/ height <= width * 2 && ((h_offset+2 >= width) || (C - h_offset + 1)))  // While haven't reached edge or 0
                        {
                            height++;
                            isCorrectShape(abs(height), abs(width)) ? _shapes++ : 0;
                            h_offset = row - height * dir[j];
                        }
                        height = 1;
                    }
                    w_offset = col - width * dir[i];
                }
            } // Grow Left & Right
        }
    }

    return std::to_string(_shapes / 2);     // Each shape was found twice from each edge, hence divide by 2
}


