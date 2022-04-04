#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Problem Link
https://codingcompetitions.withgoogle.com/kickstart/round/0000000000051060/0000000000058b89
*/
int main()
{
	int T; cin >> T;
	for (auto case_num = 1; case_num <= T; ++case_num)
	{
		int ans;
	
		int n;		// Length of next line, but we don't need it
		cin >> n; 

		vector<int> scores;

		string input;
		cin >> input;

		for (char c : input)
		{
			scores.push_back(c-48);
		}

		int bucket_size = 0;
		scores.size() % 2 == 0 ? bucket_size = scores.size() / 2 : bucket_size = scores.size() / 2 + 1;

		int index = 0;
		int largest_sum = -1;
		int current_sum = 0;

		// Calculate sum of first bucket of numbers
		for (int i = 0; i < bucket_size; i++)
			current_sum += scores[i];

		largest_sum = current_sum;

		for (int i = 1; i <= scores.size() - bucket_size; i++)
		{
			current_sum -= scores[i - 1]; // Subtract previous left-most value
			current_sum += scores[i - 1 + bucket_size]; // Add next right-most value

			if (current_sum > largest_sum) largest_sum = current_sum;
		}

		ans = largest_sum;

		cout << "Case #" << case_num << ": " << ans << endl;
	}

	return 0;
}
