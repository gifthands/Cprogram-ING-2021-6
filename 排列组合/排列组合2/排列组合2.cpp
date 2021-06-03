#include <iostream>
using namespace std;
int main()
{
	char a[] = "一二三四五六七八九十";
	char *num=a;
	int n;
	cin >> n;
	if (n >= 1 && n <= 10)
		cout << *(num + n - 1);
	else
		cout << "out of range";
}
