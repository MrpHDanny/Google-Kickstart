#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(int N, int K);

int main()
{
    int T; cin >> T;    // Test cases
    
    for(auto case_num = 1; case_num <= T; ++case_num)
    {
        int N; cin >> N;    // String length
        int K; cin >> K;    // Target goodness score
        
       /// std::cout << "T: " << T << " N: " << N << " K: " << K << std::endl; // Confirm input is correct

        string ans = solution(N, K);
        std::cout << "Case #" << case_num << ": " << ans << std::endl;
    }
}

string solution(int N, int K)
{
    string input; cin >> input; // Input string
    int _K = 0;                 // Current goodness score

    int l_ptr = 0, r_ptr = N-1;
    
    while(l_ptr < r_ptr)
    {
        if(input[l_ptr] != input[r_ptr])
            _K ++;
        
        l_ptr++;
        r_ptr--;
    }

    return std::to_string(abs(_K - K));
}
