#pragma once

#include <iostream>
using namespace std;

template <class ElemType> class MyStack
{
public:
	const static  int MAXSIZE = 100;
	ElemType data[MAXSIZE];
	int top;

public:
	void init();			// ��ʼ��ջ
	bool empty();			// �ж�ջ�Ƿ�Ϊ��
	ElemType gettop();	    // ��ȡջ��Ԫ��(����ջ)
	void push(ElemType x);	// ��ջ
	ElemType pop();			// ��ջ
};


template<class T> void MyStack<T>::init()
{
	this->top = 0;
}

template<class T> bool MyStack<T>::empty()
{
	return this->top == 0 ? true : false;
}

template<class T> T MyStack<T>::gettop()
{
	if (empty())
	{
		cout << "ջΪ�գ�\n";
		exit(1);
	}
	return this->data[this->top - 1];
}

template<class T> void MyStack<T>::push(T x)
{
	if (this->top == MAXSIZE)
	{
		cout << "ջ������\n";
		exit(1);
	}
	this->data[this->top] = x;
	this->top++;
}

template<class T> T MyStack<T>::pop()
{
	if (this->empty())
	{
		cout << "ջΪ��! \n";
		exit(1);
	}

	T e = this->data[this->top - 1];
	this->top--;
	return e;
}