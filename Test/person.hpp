#pragma once
#include <iostream>
#include <string>

using namespace std;

template<typename T1, typename T2>
class Person4
{
public:
	T1 name;
	T2 age;
public:
	Person4(T1 name, T2 age);
	void showPerson();
};

//构造函数 类外实现
template<typename T1, typename T2>
Person4<T1, T2>::Person4(T1 name, T2 age)
{
	this->name = name;
	this->age = age;
}

//成员函数 类外实现
template<typename T1, typename T2>
void Person4<T1, T2>::showPerson()
{
	cout << "姓名： " << this->name << "  年龄： " << this->age << endl;
}