#pragma once
#include"worker.h"

class Employee:public Worker
{
public:
	//���캯��
	Employee(int id, string name, int did);
	//��Ϣ��ʾ���� 
	virtual void ShowInfo();

	//��������
	~Employee();
};