#include <iostream>
#include <string>
#include "person.hpp"
#include "MyArray.hpp"

using namespace std;


//����ģ�塪������������
template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//����ģ�塪��ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
template<class T>
void func()
{
	cout << "func ����" << endl;
}

//�������� ��С
template<typename T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			mySwap(arr[max], arr[i]);
		}
	}

}

//��ӡ����
template<typename T>
void printArray(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//Person��
class Person
{
public:
	string name;
	int age;
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
};

//��ͨ����ģ�塪���Ƚ�����ֵ�Ƿ����
template<typename T>
bool myCompare(T& a, T& b)
{
	return a == b;
}

//���þ��廯Person�İ汾ʵ�ִ��룬���廯���ȵ���
template<> bool myCompare(Person& p1, Person& p2)
{
	return (p1.name == p2.name && p1.age == p2.age);

}

//��ģ��
template<class NameType, typename AgeType>
class Student
{
public:
	NameType name;
	AgeType age;
public:
	Student(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}
	void showStudent()
	{
		cout << "name: " << this->name << "  age: " << this->age << endl;
	}
};

//��ģ�塪��Ĭ�ϲ���
//1.ָ�����������
template<typename NameType, typename AgeType = int>
class Animal
{
public:
	NameType name;
	AgeType age;
public:
	Animal(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}
	void showAnimal()
	{
		cout << "name: " << this->name << "  age: " << this->age << endl;
	}
};

//��ģ���г�Ա�����Ĵ���ʱ��
class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};

template<typename T>
class MyClass
{
public:
	T obj;
	//��ģ���еĳ�Ա������������һ��ʼ�ʹ����ģ�������ģ�����ʱ������
	void func1()
	{
		obj.showPerson1();
	}
	void func2()
	{
		obj.showPerson2();
	}
};

//2.����ģ�廯
template<typename T1, typename T2>
void printAnimal2(Animal<T1, T2>& p)
{
	cout << "T1������Ϊ�� " << typeid(T1).name() << endl;
	cout << "T2������Ϊ�� " << typeid(T2).name() << endl;
	p.showAnimal();
}

//3.������ģ�廯
template<typename T>
void printAnimal3(T& p)
{
	cout << "T������Ϊ�� " << typeid(T).name() << endl;
	p.showAnimal();
}

//��ģ����̳�
template<typename T>
class Base
{
	T m;
};

//class Son1 :public Base; //����C++������Ҫ����������ڴ棬����֪��������T�����Ͳſ������¼̳�
class Son1 :public Base<int> //����ָ��һ������
{
public:
	Son1()
	{
		cout << "Son1�̳гɹ�" << endl;
	}
};

//��ģ��̳���ģ�壬������T2ָ�������е�T����
template<typename T1, typename T2>
class Son2 :public Base<T2>
{
public:
	Son2()
	{
		cout << "Son2�̳гɹ�" << endl;

		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
};


//��ģ���г�Ա��������ʵ��
template<typename T1, typename T2>
class Person3
{
public:
	T1 name;
	T2 age;
public:
	//��Ա������������
	Person3(T1 name, T2 age);
	void showPerson();
};

//���캯�� ����ʵ��
template<typename T1, typename T2>
Person3<T1, T2>::Person3(T1 name, T2 age)
{
	this->name = name;
	this->age = age;
}

//��Ա���� ����ʵ��
template<typename T1, typename T2>
void Person3<T1, T2>::showPerson()
{
	cout << "����: " << this->name << "  ����: " << this->age << endl;
}

//��ģ����ļ���д
//�����ʽ1������cppԴ�ļ�
//#include "person.h"
//#include "person.cpp"
//�����ʽ2����������ʵ��д��һ���ļ���׺����Ϊ.hpp
//void test15(){}

//��ģ������Ԫ
//2.ȫ�ֺ��������Ԫ ����ʵ�� - ��������ģ���������·���������ģ�嶨�壬������Ԫ
template<typename T1, typename T2> class Person5;

//��������˺���ģ�壬���Խ�ʵ��д�����棬������Ҫ��ʵ����д�����ǰ���ñ�������ǰ����
template<typename T1, typename T2> void printPerson2(Person5<T1, T2>& p);
template<typename T1, typename T2>
void printPerson2(Person5<T1, T2>& p)
{
	cout << "����ʵ�� --- ������ " << p.name << "  ���䣺 " << p.age << endl;
}

template<typename T1, typename T2>
class Person5
{
private:
	T1 name;
	T2 age;
public:
	Person5(T1 name, T2 age)
	{
		this->name = name;
		this->age = age;
	}

	//1.ȫ�ֺ��������Ԫ������ʵ��
	friend void printPerson(Person5<T1, T2>& p)
	{
		cout << "������ " << p.name << "���䣺 " << p.age << endl;
	}

	//ȫ�ֺ��������Ԫ ����ʵ��
	friend void printPerson2<>(Person5<T1, T2>& p);
};

//��ģ�尸��
//��ӡ����
void printIntArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//�����Զ�����������
class Person6
{
public:
	string name;
	int age;

public:
	Person6() {}
	Person6(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
};

void printPersonArray(MyArray<Person6>& personArr)
{
	for (int i = 0; i < personArr.getSize(); i++)
	{
		cout << "������ " << personArr[i].name << "   ���䣺 " << personArr[i].age << endl;
	}
}

void test01()
{
	int a = 10;
	int b = 20;
	//mySwap(a, b);
	mySwap<int>(a, b);
	cout << "a = " << a << " " << "b = " << b << endl;

	double c = 1.1;
	double d = 2.2;
	//mySwap(c, d);
	mySwap<double>(c, d);
	cout << "c = " << c << " " << "d = " << d << endl;
}

void test02()
{
	//func(); //����ģ�岻�ܶ���ʹ�ã�����ȷ����T������
	func<int>(); //������ʾָ�����͵ķ�ʽ����Tһ�����ͣ��ſ���ʹ�ø�ģ��
}

void test03()
{
	//����char����
	char charArr[] = "fbdaceg";
	int num = sizeof(charArr) / sizeof(char);
	mySort(charArr, num);
	printArray(charArr, num);
}

void test04()
{
	//����int����
	int intArr[] = { 5,7,3,6,4,8,9,1,2 };
	int num = sizeof(intArr) / sizeof(int);
	mySort(intArr, num);
	printArray(intArr, num);
}

void test05()
{
	int a = 10;
	int b = 20;
	//�����������Ϳ���ֱ��ʹ��ͨ�õĺ���ģ��
	bool ret = myCompare(a, b);
	if (ret)
	{
		cout << "a == b" << endl;
	}
	else
	{
		cout << "a != b" << endl;
	}
}

void test06()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);
	//�Զ����������ͣ����������ͨ�ĺ���ģ��
	//���Դ������廯��Person�������͵�ģ�壬�������⴦���������
	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << "p1 == p2" << endl;
	}
	else
	{
		cout << "p1 != p2" << endl;
	}
}

void test07()
{
	//ָ��NameTypeΪstring���ͣ�AgeTypeΪint����
	Student<string, int> s1("������", 66);
	s1.showStudent();
}

void test08()
{
	//��ģ����ģ������б��п�����Ĭ�ϲ���
	Animal<string> a("dog", 2); //��ģ���е�ģ������б�����ָ��Ĭ�ϲ���
	a.showAnimal();
}

void test09()
{
	MyClass<Person2> m;
	//m.func1();
	m.func2();

}

void test10()
{
	Animal <string, int> p("����è", 6);
	printAnimal2(p);
}

void test11()
{
	Animal <string, int> p("÷��֭", 8);
	printAnimal3(p);
}

void test12()
{
	Son1 s1;
}

void test13()
{
	Son2<int, char> s2;
}

void test14()
{
	Person3<string, int> p("cxk", 18);
	p.showPerson();
}

void test15()
{
	Person4<string, int> p("Tom", 10);
	p.showPerson();
}

void test16()
{
	//1.ȫ�ֺ���������ʵ��
	Person5<string, int> p("Tom", 20);
	printPerson(p);
}

void test17()
{
	//ȫ�ֺ���������ʵ��
	Person5<string, int> p("Jerry", 30);
	printPerson2(p);
}

//��������()
//��������
void test18()
{
	MyArray<int> array1(10);
	for (int i = 0; i < 10; i++)
	{
		array1.pushBack(i);
	}
	cout << "array1��ӡ����� " << endl;
	printIntArray(array1);
	cout << "array1�Ĵ�С�� " << array1.getSize() << endl;
	cout << "array1�������� " << array1.getCapacity() << endl;

	cout << "--------------------------------------------" << endl;

	MyArray<int> array2(array1);
	array2.popBack();
	cout << "array2��ӡ����� " << endl;
	printIntArray(array2);
	cout << "array2�Ĵ�С�� " << array2.getSize() << endl;
	cout << "array2�������� " << array2.getCapacity() << endl;
}

//�����Զ�����������
void test19()
{
	//��������
	MyArray<Person6> personArray(10);
	Person6 p1("����", 11);
	Person6 p2("����", 22);
	Person6 p3("���", 33);
	Person6 p4("槼�", 44);
	Person6 p5("������", 55);

	//��������
	personArray.pushBack(p1);
	personArray.pushBack(p2);
	personArray.pushBack(p3);
	personArray.pushBack(p4);
	personArray.pushBack(p5);

	printPersonArray(personArray);

	cout << "personArray�Ĵ�С�� " << personArray.getSize() << endl;
	cout << "personArray�������� " << personArray.getCapacity() << endl;
}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	//test09();
	//test10();
	//test11();
	//test12();
	//test13();
	//test14();
	//test15();
	//test16();
	//test17();
	//test18();
	test19();

	return 0;
}