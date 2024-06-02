#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, l, r;
	cin >> n >> l >> r;

	l--;
	r--;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
	}

	for (int i = 0; i <= (r - l) / 2; i++)
	{
		// cout << i << " " << l + i << " " << r - i << endl;
		swap(a[l + i], a[r - i]);
	}

	for (auto e : a)
	{
		cout << e << " ";
	}

	cout << endl;
}