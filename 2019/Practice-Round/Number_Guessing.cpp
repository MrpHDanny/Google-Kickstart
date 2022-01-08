#include <iostream>
#include <string>
using namespace std;


int main()
{
	int T; cin >> T;
	for (auto case_num = 1; case_num <= T; ++case_num)
	{
		int a, b, n, g;
		cin >> a >> b >> n;

		a++;	// a is non inclusive so need to increment
		string response;
			
		g = (a + b) / 2;

		for (int i = 0; i < n; i++)
		{
			cout << g << endl;
			cin >> response;
			if (response == "CORRECT")
				break;
			if (response == "TOO_SMALL")
			{
				a = g+1;
				g = (a + b) / 2;
			}
			else
			{
				b = g-1;
				g = (a + b) / 2;
			}

		}
		
	}

	return 0;
}