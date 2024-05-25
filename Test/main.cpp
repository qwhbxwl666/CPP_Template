#include <iostream>
#include <string>
#include "person.hpp"
#include "MyArray.hpp"

using namespace std;


//函数模板——交换两个数
template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//函数模板——模板必须要确定出T的数据类型，才可以使用
template<class T>
void func()
{
	cout << "func 调用" << endl;
}

//数组排序 大到小
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

//打印数组
template<typename T>
void printArray(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//Person类
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

//普通函数模板——比较两个值是否相等
template<typename T>
bool myCompare(T& a, T& b)
{
	return a == b;
}

//利用具体化Person的版本实现代码，集体化优先调用
template<> bool myCompare(Person& p1, Person& p2)
{
	return (p1.name == p2.name && p1.age == p2.age);

}

//类模板
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

//类模板——默认参数
//1.指定传入的类型
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

//类模板中成员函数的创建时机
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
	//类模板中的成员函数，并不是一开始就创建的，而是在模板调用时再生成
	void func1()
	{
		obj.showPerson1();
	}
	void func2()
	{
		obj.showPerson2();
	}
};

//2.参数模板化
template<typename T1, typename T2>
void printAnimal2(Animal<T1, T2>& p)
{
	cout << "T1的类型为： " << typeid(T1).name() << endl;
	cout << "T2的类型为： " << typeid(T2).name() << endl;
	p.showAnimal();
}

//3.整个类模板化
template<typename T>
void printAnimal3(T& p)
{
	cout << "T的类型为： " << typeid(T).name() << endl;
	p.showAnimal();
}

//类模板与继承
template<typename T>
class Base
{
	T m;
};

//class Son1 :public Base; //错误，C++编译需要给子类分配内存，必须知道父类中T的类型才可以向下继承
class Son1 :public Base<int> //必须指定一个类型
{
public:
	Son1()
	{
		cout << "Son1继承成功" << endl;
	}
};

//类模板继承类模板，可以用T2指定父类中的T类型
template<typename T1, typename T2>
class Son2 :public Base<T2>
{
public:
	Son2()
	{
		cout << "Son2继承成功" << endl;

		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
};


//类模板中成员函数类外实现
template<typename T1, typename T2>
class Person3
{
public:
	T1 name;
	T2 age;
public:
	//成员函数类内声明
	Person3(T1 name, T2 age);
	void showPerson();
};

//构造函数 类外实现
template<typename T1, typename T2>
Person3<T1, T2>::Person3(T1 name, T2 age)
{
	this->name = name;
	this->age = age;
}

//成员函数 类外实现
template<typename T1, typename T2>
void Person3<T1, T2>::showPerson()
{
	cout << "姓名: " << this->name << "  年龄: " << this->age << endl;
}

//类模板分文件编写
//解决方式1，包含cpp源文件
//#include "person.h"
//#include "person.cpp"
//解决方式2，将声明和实现写到一起，文件后缀名改为.hpp
//void test15(){}

//类模板与友元
//2.全局函数配合友元 类外实现 - 先做函数模板声明，下方再做函数模板定义，再做友元
template<typename T1, typename T2> class Person5;

//如何声明了函数模板，可以将实现写到后面，否则需要将实现体写到类的前面让编译器提前看到
template<typename T1, typename T2> void printPerson2(Person5<T1, T2>& p);
template<typename T1, typename T2>
void printPerson2(Person5<T1, T2>& p)
{
	cout << "类外实现 --- 姓名： " << p.name << "  年龄： " << p.age << endl;
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

	//1.全局函数配合友元，类内实现
	friend void printPerson(Person5<T1, T2>& p)
	{
		cout << "姓名： " << p.name << "年龄： " << p.age << endl;
	}

	//全局函数配合友元 类外实现
	friend void printPerson2<>(Person5<T1, T2>& p);
};

//类模板案例
//打印数组
void printIntArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//测试自定义数据类型
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
		cout << "姓名： " << personArr[i].name << "   年龄： " << personArr[i].age << endl;
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
	//func(); //错误，模板不能独立使用，必须确定出T的类型
	func<int>(); //利用显示指定类型的方式，给T一个类型，才可以使用该模板
}

void test03()
{
	//测试char数组
	char charArr[] = "fbdaceg";
	int num = sizeof(charArr) / sizeof(char);
	mySort(charArr, num);
	printArray(charArr, num);
}

void test04()
{
	//测试int数组
	int intArr[] = { 5,7,3,6,4,8,9,1,2 };
	int num = sizeof(intArr) / sizeof(int);
	mySort(intArr, num);
	printArray(intArr, num);
}

void test05()
{
	int a = 10;
	int b = 20;
	//内置数据类型可以直接使用通用的函数模板
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
	//自定义数据类型，不会调用普通的函数模板
	//可以创建具体化的Person数据类型的模板，用于特殊处理这个类型
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
	//指定NameType为string类型，AgeType为int类型
	Student<string, int> s1("蔡徐坤", 66);
	s1.showStudent();
}

void test08()
{
	//类模板在模板参数列表中可以有默认参数
	Animal<string> a("dog", 2); //类模板中的模板参数列表，可以指定默认参数
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
	Animal <string, int> p("魅力猫", 6);
	printAnimal2(p);
}

void test11()
{
	Animal <string, int> p("梅素汁", 8);
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
	//1.全局函数在类内实现
	Person5<string, int> p("Tom", 20);
	printPerson(p);
}

void test17()
{
	//全局函数在类外实现
	Person5<string, int> p("Jerry", 30);
	printPerson2(p);
}

//测试内置()
//数据类型
void test18()
{
	MyArray<int> array1(10);
	for (int i = 0; i < 10; i++)
	{
		array1.pushBack(i);
	}
	cout << "array1打印输出： " << endl;
	printIntArray(array1);
	cout << "array1的大小： " << array1.getSize() << endl;
	cout << "array1的容量： " << array1.getCapacity() << endl;

	cout << "--------------------------------------------" << endl;

	MyArray<int> array2(array1);
	array2.popBack();
	cout << "array2打印输出： " << endl;
	printIntArray(array2);
	cout << "array2的大小： " << array2.getSize() << endl;
	cout << "array2的容量： " << array2.getCapacity() << endl;
}

//测试自定义数据类型
void test19()
{
	//创建数组
	MyArray<Person6> personArray(10);
	Person6 p1("韩信", 11);
	Person6 p2("猴子", 22);
	Person6 p3("李白", 33);
	Person6 p4("妲己", 44);
	Person6 p5("安琪拉", 55);

	//插入数据
	personArray.pushBack(p1);
	personArray.pushBack(p2);
	personArray.pushBack(p3);
	personArray.pushBack(p4);
	personArray.pushBack(p5);

	printPersonArray(personArray);

	cout << "personArray的大小： " << personArray.getSize() << endl;
	cout << "personArray的容量： " << personArray.getCapacity() << endl;
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