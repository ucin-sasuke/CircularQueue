#include "CircularQueue.h"
#include <iostream>
using namespace std;

void menu()
{
	cout << "�ȴ����﹦�ܲ˵���" << endl;
	cout << "1.�Ŷ�" << endl;
	cout << "2.����" << endl;
	cout << "3.�鿴�Ŷ�" << endl;
	cout << "4.�����Ŷӣ��������ξ���" << endl;
	cout << "5.�°�" << endl;
	cout << "6.�ϰ�" << endl;
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
	test.DispQueue();*/ //����˳����й��ܵĲ���
	char n;
	int num, work = 0;
	bool sign= false;
	CircularQueue<int> test;
	
	do {
		menu();
		if (work == 0)
			cout << "��δ��ʼ�ϰ࣬���봦���ϰ�״̬��������6";
		cin >> n;
		cout << endl;
		switch (n)
		{
		case '1': cout << "�������ŶӲ��˵Ĳ����ţ�";
				  cin >> num; test.EnQueue(num);
				 break;
		case '2':test.DeQueue(num); cout << "��" << num << "�Ų��˾���" << endl; break;
		case '3':cout << "�ŶӶ����еĲ���������Ϊ��"; test.DispQueue(); break;
		case '4':cout << "�ŶӶ����еĲ���������Ϊ��"; test.DispQueue(); sign = false; break;
		case '5':cout << "���ڿ�ʼ�°࣬�޷������������"<<endl; test.DeQueue(num); sign = false; work = 0; break;
		case '6':cout << "�ѿ�ʼ�ϰ�";  cout << "���������蹦����ţ�"; work = 1; sign = true; break;
		default:cout << "�޷�ʶ�����������룺";
		}
	} while (sign);
	cout << "���˳����򣬸�лʹ��"<<endl;
	system("pause");
	return 0;
}