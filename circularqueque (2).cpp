#include "CircularQueue.h"
#include <iostream>
using namespace std;

void menu()
{
	cout << "等待就诊功能菜单：" << endl;
	cout << "1.排队" << endl;
	cout << "2.就诊" << endl;
	cout << "3.查看排队" << endl;
	cout << "4.不在排队，余下依次就诊" << endl;
	cout << "5.下班" << endl;
	cout << "6.上班" << endl;
}

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
	char n;
	int num, work = 0;
	bool sign= false;
	CircularQueue<int> test;
	
	do {
		menu();
		if (work == 0)
			cout << "还未开始上班，如须处于上班状态，请输入6";
		cin >> n;
		cout << endl;
		switch (n)
		{
		case '1': cout << "请输入排队病人的病历号：";
				  cin >> num; test.EnQueue(num);
				 break;
		case '2':test.DeQueue(num); cout << "请" << num << "号病人就诊" << endl; break;
		case '3':cout << "排队队伍中的病历号依次为："; test.DispQueue(); break;
		case '4':cout << "排队队伍中的病历号依次为："; test.DispQueue(); sign = false; break;
		case '5':cout << "现在开始下班，无法继续加入队伍"<<endl; test.DeQueue(num); sign = false; work = 0; break;
		case '6':cout << "已开始上班";  cout << "请输入所需功能序号："; work = 1; sign = true; break;
		default:cout << "无法识别，请重新输入：";
		}
	} while (sign);
	cout << "已退出程序，感谢使用"<<endl;
	system("pause");
	return 0;
}