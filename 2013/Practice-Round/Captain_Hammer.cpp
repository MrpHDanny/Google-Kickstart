#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;


#define PI 3.141592653589793

int main()
{
	

	int T; cin >> T;
	for (auto case_num = 1; case_num <= T; ++case_num)
	{
		int V, D; cin >> V >> D;
		cin.ignore();

		// Solution
		double ans = 0;

		// Find angle of projectile trajectory given distance and velocity
		ans = 0.5 * asin((9.8 * D) / ((double)V * (double)V)) * 180 / PI;

		cout << "Case #" << case_num << ": " << std::setprecision(7) << std::fixed << ans << endl;
	}
}