#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(nullptr));
	for (int i = 0; i < 10; ++i)
		cout << rand() << endl;
}

