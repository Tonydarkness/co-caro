#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>

using namespace std;

void TaoMang(int*& a, int n)
{
	a = new int[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100 + 1;
	}
}

int main()
{
	int* a;
	int n;
	cout << "Nhap n: ";
	cin >> n;
	a = new int[100];
	for (int i = 0; i < 100; i++)
	{
		a[i] = i + 1;
	}
	int* copy = a;
	int* bo;
	bo = new int[n];
	return 0;
}