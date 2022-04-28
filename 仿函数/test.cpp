#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<functional>
#include<vector>
#include<map>
#include<algorithm>

void Print(int a)
{
	cout << a;
}

class Print2
{
public:
	void operator()(int a)
	{
		cout << a;
	}
};

//int main()
//{
//	/*negate<int> a;
//	cout<<a(10);
//	cout<<a.operator()(5);
//	cout << endl;
//
//	map<int, int,greater<int>> m;
//	m.insert(pair<int,int>(1,10));
//	m.insert(make_pair(2, 20));
//	m.insert(make_pair(3, 30));
//	m.insert(make_pair(4, 40));
//	m.insert(make_pair(5, 50));
//
//	for (map<int, int,greater<int>>::iterator it = m.begin(); it != m.end(); it++)
//	{
//		cout << "key:" << it->first << " " << "value:" << it->second << endl;
//	}*/
//
//	//for_each�㷨
//	vector<int> v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//
//	for_each(v.begin(), v.end(), Print2());
//	cout << endl;
//
//
//	return 0;
//}

class TransData
{
public:
	int operator()(int a)//�������Դ����
	{
		return a + 100;//��������������� transform��Ŀ��������
	}
};

void test1()//transform�㷨
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int> v1;
	v1.resize(v.size());//��Ҫָ��Ŀ��ռ��С ��Ȼת�Ʋ���ȥ

	transform(v.begin(), v.end(), v1.begin(), TransData());

	for_each(v1.begin(), v1.end(), Print);
	
}

void test2()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator pos = find(v.begin(), v.end(), 5);
	if (pos != v.end())
	{
		cout << "�ҵ��ˣ�" << *pos;
	}
	else
	{
		cout << "�Ҳ���";
	}

}

class Person
{
public:
	string name;
	int age;
	int weight;
	Person(string name, int age, int weight)
	{
		this->age = age;
		this->name = name;
		this->weight = weight;
	}

	bool operator== (const Person& p)//�ײ㲻����Զ������͵ıȽ� ������Ҫ�ض���==����
	{
		if (this->age = p.age && this->name == p.name && this->weight == p.weight)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};


void test3()
{
	vector<Person> v;
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		string name = "��";
		name = name + nameSeed[i];
		int age = 22;
		int weight = 150;

		Person p(name, age, weight);

		v.push_back(p);

			
	}

	Person pp("��A", 22, 150);//Ҫ���ҵ���
	vector<Person>::iterator pos = find(v.begin(), v.end(), pp);

	if (pos != v.end())
	{
		cout << "�ҵ��ˣ�" << pos->name;
	}
	else
	{
		cout << "�Ҳ���";
	}


}

class GreaterFive
{
public:
	bool operator()(int a)
	{
		return a > 5;
	}
};


class PersonFind_if
{

};



void test4()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterFive());

	if (pos != v.end())
	{
		cout << "�ҵ���" << *pos;
	}
	else
	{
		cout << "û�ҵ�";
	}
}



int main()
{
	//test1();//transform
	/*test2();*///find�㷨���������Ͳ���
	/*test3();*///find���Զ������Ͳ���
	//test4();//find_if
	char* p;
	int a = 10;
	int b = 20;
	int& c = a;
	a = 30;
	cout << c;
	return 0;
}

