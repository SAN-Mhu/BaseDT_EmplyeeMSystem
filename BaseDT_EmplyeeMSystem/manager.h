#pragma once
#include"worker.h"

class Manager :public Worker
{
public:
	//���캯��
	Manager(int id, string name, int did);
	//��Ϣ��ʾ���� 
	virtual void ShowInfo();

	//��������
	~Manager();
};