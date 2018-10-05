#pragma once
#ifndef CircularQueue_h
#define CiraulareQueue_h
#include<iostream>
#define Status int
#define QUEUE_INIT_SIZE 10
#define FULL 0
#define EMPTY 0
#define NOT_EMPTY 1
#define OK 1
template <class T>
class CircularQueue
{
private:
	T *base;
	int front;
	int rear;
	int queuesize;
public:
	CircularQueue();
	~CircularQueue();
	Status EnQueue(T e);//���
	Status DeQueue(T &e);//����
	int QueueLength();
	Status IsEmpty();
	Status ClearQueue();//��ն���
	void DispQueue();//չʾ����
	char* num(int n);//����1��2����������1�ĳ��ӣ�����2�ĵ��������Ҷ�
};
template <class T>
CircularQueue<T>::CircularQueue()
{
	base = new T[QUEUE_INIT_SIZE];
	if (!base) exit(OVERFLOW);
	front = rear = 0;
	queuesize = QUEUE_INIT_SIZE;
}
template <class T>
CircularQueue<T>::~CircularQueue()
{
	delete[] base;
}
template <class T>
Status CircularQueue<T>::EnQueue(T e)
{
	if ((rear + 1) % QUEUE_INIT_SIZE == front) return FULL;
	base[rear] = e;
	rear = (rear + 1) % QUEUE_INIT_SIZE;
	return OK;
}
template <class T>
Status CircularQueue<T>::DeQueue(T &e)
{
	if (rear == front) return EMPTY;
	e = base[front];
	front = (front + 1) % QUEUE_INIT_SIZE;
	return OK;
}
template <class T>
int CircularQueue<T>::QueueLength()
{
	if (rear >= front) return rear - front;
	else
		return QUEUE_INIT_SIZE - (front - rear);
}
template <class T>
Status CircularQueue<T>::IsEmpty()
{
	if (rear == front) return EMPTY;
	else return NOT_EMPTY;
}
template <class T>
Status CircularQueue<T>::ClearQueue()
{
	T e;
	while (IsEmpty != EMPTY)
		DeQueue(e);
}
template <class T>
void CircularQueue<T>::DispQueue()
{
	int i = front;
	if (rear == front)
		cout << "��ǰ����Ϊ��"<<endl;
	else if (rear > front)
	{
		for (; i < rear; i++)
			cout << base[i] << " ";
		cout << endl;
	}
	else
	{
		for (; i < QUEUE_INIT_SIZE; i++)
			cout << base[i] << " ";
		for(int j=0;j<rear;j++)
			cout << base[j] << " ";
		cout << endl;
	}
}
template<class T>
char* CircularQueue<T>::num(int n)
{
	char *result = new char;
	CircularQueue<int> p;
	int i,e;
	for (i = 1; i <= n; i++)
		p.EnQueue(i);
	i = 0;
	while (p.IsEmpty() != EMPTY)
	{
		p.DeQueue(e); *(result + i++) = e + 48;
		if (p.IsEmpty() != EMPTY)
		{
			p.DeQueue(e); p.EnQueue(e);
		}
	}
	*(result + i) = '\0';
	return result;
}
#endif // !CircularQueue_h
