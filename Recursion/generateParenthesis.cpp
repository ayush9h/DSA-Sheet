#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100
void solve(int pos, int n, int open, int close)
{
	static char str[MAX_SIZE];

	if (close == n) {
		cout << str << endl;
		return;
	}
	else {
		if (open > close) {
			str[pos] = ')';
			solve(pos + 1, n, open, close + 1);
		}

		if (open < n) {
			str[pos] = '(';
			solve(pos + 1, n, open + 1, close);
		}
	}
}
void printParenthesis(int n)
{
	if (n > 0)
		solve(0, n, 0, 0);
	return;
}

int main()
{
	int n;
	cin>>n;
	printParenthesis(n);
	return 0;
}
