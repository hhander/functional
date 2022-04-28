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
//	//for_each算法
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
	int operator()(int a)//这里接受源数据
	{
		return a + 100;//在里面进行运算再 transform到目标容器中
	}
};

void test1()//transform算法
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int> v1;
	v1.resize(v.size());//先要指定目标空间大小 不然转移不过去

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
		cout << "找到了：" << *pos;
	}
	else
	{
		cout << "找不到";
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

	bool operator== (const Person& p)//底层不会对自定义类型的比较 ，所以要重定义==符号
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
		string name = "人";
		name = name + nameSeed[i];
		int age = 22;
		int weight = 150;

		Person p(name, age, weight);

		v.push_back(p);

			
	}

	Person pp("人A", 22, 150);//要查找的人
	vector<Person>::iterator pos = find(v.begin(), v.end(), pp);

	if (pos != v.end())
	{
		cout << "找到了：" << pos->name;
	}
	else
	{
		cout << "找不到";
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
		cout << "找到了" << *pos;
	}
	else
	{
		cout << "没找到";
	}
}



int main()
{
	//test1();//transform
	/*test2();*///find算法的内置类型查找
	/*test3();*///find的自定义类型查找
	//test4();//find_if
	char* p;
	int a = 10;
	int b = 20;
	int& c = a;
	a = 30;
	cout << c;
	return 0;
}

