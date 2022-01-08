#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solve(vector<string> names)
{
	int count = 0;

	for (int i = 0; i < names.size() - 1; i++)
	{
		if (names[i] > names[i + 1])
		{
			count++;
			names[i + 1] = names[i];
		}
	}

	return count;
}



int main()
{
	int T; cin >> T;
	for (auto case_num = 1; case_num <= T; ++case_num)
	{
		int N; cin >> N;
		cin.ignore();

		// Solution
		auto ans = 0;
		vector<string> names;

		for (int j = 0; j < N; j++)
		{
			string name;
			getline(cin, name);

			names.push_back(name);
		}
		ans = solve(names);
		names.clear();

		cout << "Case #" << case_num << ": " << ans << endl;
	}

}