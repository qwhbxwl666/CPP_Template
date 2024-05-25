#pragma once
#include <iostream>
using namespace std;

template<typename T>
class MyArray
{
private:
	T* address; //ָ��һ���ѿռ䣬����ռ�洢����������
	int capacity; //����
	int size; //��С

public:
	//���캯��
	MyArray(int capacity)
	{
		this->capacity = capacity;
		this->size = 0;
		address = new T[this->capacity];
	}

	//��������
	MyArray(const MyArray& arr)
	{
		this->capacity = arr.capacity;
		this->size = arr.size;
		this->address = new T[this->capacity];
		for (int i = 0; i < this->size; i++)
		{
			//���TΪ���󣬶��һ�����ָ�룬������Ҫ����=����������Ϊ����ȺŲ��ǹ�����Ǹ�ֵ
			//��ͨ���Ϳ���ֱ��=������ָ��������Ҫ���
			this->address[i] = arr.address[i];
		}
	}

	//����=������ ��ֹǳ��������
	MyArray& operator = (const MyArray& myarray)
	{
		if (this->address != NULL)
		{
			delete[] this->address;
			this->capacity = 0;
			this->size = 0;
		}
		this->capacity = myarray.capacity;
		this->size = myarray.size;
		this->address = new T[this->capacity];
		for (int i = 0; i < this->size; i++)
		{
			this->address[i] = myarray[i];
		}
		return *this;
	}

	//����[]������ arr[0]
	T& operator[] (int index)
	{
		return this->address[index]; //������Խ�磬�û��Լ�ȥ����
	}

	//β�巨
	void pushBack(const T& val)
	{
		if (this->capacity == this->size)
		{
			return;
		}
		this->address[this->size] = val;
		this->size++;
	}

	//βɾ��
	void popBack()
	{
		if (this->size == 0)
		{
			return;
		}
		this->size--;
	}

	//��ȡ��������
	int getCapacity()
	{
		return this->capacity;
	}

	//��ȡ�����С
	int getSize()
	{
		return this->size;
	}


	//����
	~MyArray()
	{
		if (this->address != NULL)
		{
			delete[] this->address;
			this->address = NULL;
			this->capacity = 0;
			this->size = 0;
		}
	}
};