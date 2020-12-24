#include "MyStack.h"
#include "PrefixToPostfix.h"

#include <iostream>
using namespace std;

void main()
{
	MyStack<int> stack;
	stack.init();

	//char pre[] ="22/(5*2+1)#";
	char exp[100];
	cout << "������ʽ(��׺����#����)��";
	cin >> exp;

	char post[100];
	//cout <<"��׺���ʽΪ��"<< pre << endl;

	int n = 0;			// ���غ�׺���ʽ�ĳ���
	postfix(exp, post, n);
	cout << "��׺���ʽΪ��";
	for (int i = 0; i < n; i++)
		cout << post[i];

	cout << "\n�ɺ�׺���ʽ���������ֵ���:  ";
	cout << postfix_value(post) << endl;

	system("pause");
}

bool isoperator(char op)
{
	switch (op)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return 1;
	default:
		return 0;
	}
}


int priority(char op)
{
	switch (op)
	{
	case '#':
		return -1;
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return -1;
	}
}

//	 ����׺���ʽת��Ϊ��׺���ʽ�����غ�׺���ʽ�ĳ��ȣ������ո�
void postfix(char pre[], char post[], int& n)
{
	int i = 0, j = 0;
	MyStack<char> stack;
	stack.init();		// ��ʼ���洢��������ջ

	stack.push('#');	// ���Ȱѽ�����־��#������ջ��

	while (pre[i] != '#')
	{
		if ((pre[i] >= '0' && pre[i] <= '9') || pre[i] == '.') // �������ֺ�С����ֱ��д���׺���ʽ
		{
			post[j++] = pre[i];
			n++;
		}
		else if (pre[i] == '(')	// �������������ñȽ�ֱ����ջ
			stack.push(pre[i]);
		else if (pre[i] == ')')  // ���������Ž����Ӧ�����ź�Ĳ�������������ջ�еģ�ȫ��д���׺���ʽ
		{
			while (stack.gettop() != '(')
			{
				post[j++] = stack.pop();
				n++;
			}
			stack.pop(); // ����������ջ����׺���ʽ�в���С����
		}
		else if (isoperator(pre[i]))
		{
			post[j++] = ' '; // �ÿո�ֿ�������(
			n++;
			while (priority(pre[i]) <= priority(stack.gettop()))
			{
				// ��ǰ�Ĳ�����С�ڵ���ջ�������������ȼ�ʱ����ջ��������д�뵽��׺���ʽ���ظ��˹���
				post[j++] = stack.pop();
				n++;
			}

			stack.push(pre[i]);	// ��ǰ���������ȼ�����ջ�������������ȼ������ò�������ջ
		}

		i++;
	}
	while (stack.top) // �����еĲ����������׺���ʽ
	{
		post[j++] = stack.pop();
		n++;
	}
}

double read_number(char str[], int* i)
{
	double x = 0.0;
	int k = 0;
	while (str[*i] >= '0' && str[*i] <= '9')  // ������������
	{
		x = x * 10 + (str[*i] - '0');
		(*i)++;
	}

	if (str[*i] == '.') // ����С������
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			x = x * 10 + (str[*i] - '0');
			(*i)++;
			k++;
		}
	}
	while (k != 0)
	{
		x /= 10.0;
		k--;
	}

	return x;
}

double postfix_value(char post[])
{
	MyStack<double> stack;	// ������ջ
	stack.init();

	int i = 0;
	double x1, x2;

	while (post[i] != '#')
	{
		if (post[i] >= '0' && post[i] <= '9')
			stack.push(read_number(post, &i));
		else if (post[i] == ' ')
			i++;
		else if (post[i] == '+')
		{
			x2 = stack.pop();
			x1 = stack.pop();
			stack.push(x1 + x2);
			i++;
		}
		else if (post[i] == '-')
		{
			x2 = stack.pop();
			x1 = stack.pop();
			stack.push(x1 - x2);
			i++;
		}
		else if (post[i] == '*')
		{
			x2 = stack.pop();
			x1 = stack.pop();
			stack.push(x1 * x2);
			i++;
		}
		else if (post[i] == '/')
		{
			x2 = stack.pop();
			x1 = stack.pop();
			stack.push(x1 / x2);
			i++;
		}
	}
	return stack.gettop();
}