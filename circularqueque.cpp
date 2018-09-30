#include "CircularQueue.h"
#include <iostream>
using namespace std;

int main()
{
	/*int e = 0;
	CircularQueue<int> test;
	for (int i = 0; i < 10; i++)
		test.EnQueue(i);
	for (int j = 0; j < 3; j++)
	{
		test.DeQueue(e);
		cout << e << " ";
	}
	cout << endl;
	for (int k = 9; k < 13; k++)
		test.EnQueue(k);
	test.DispQueue();*/ //对于顺序队列功能的测试
	int n,i=0;
	char *t;
	cin >> n;
	CircularQueue<int> test;
	t=test.num(n);
	while (*(t + i) != '\0')
	{
		cout << *(t + i) << " ";
		i++;
	}
	system("pause");
	return 0;
}