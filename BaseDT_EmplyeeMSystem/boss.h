#pragma once
#include"worker.h"

class Boss :public Worker
{
public:
	//���캯��
	Boss(int id, string name, int did);
	//��Ϣ��ʾ���� 
	virtual void ShowInfo();

	//��������
	~Boss();
}; 
