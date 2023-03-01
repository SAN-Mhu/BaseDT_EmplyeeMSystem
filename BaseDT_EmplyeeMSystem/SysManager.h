#pragma once
#include<iostream>
#include<string>
#include"worker.h"
#include<fstream>

#define FILENAME "emp_data.txt"

//����һ��������
class SysManager
{
public:
	//ϵͳ�����๹�캯��
	SysManager();
	
	//ϵͳ��ʼ��
	void Init_sys();
	//����ļ���ְ������
	int get_empNum();
	//ϵͳְ����Ϣ�����ļ�
	void save_sys();
	//�˵���ʾ����
	void ShowManu();
	//�����ּ���Ա��������������
	int find_emp(string f_name);


	//0.�˳�ϵͳ
	void exitSystem();
	//1.���Ա��
	void add_emp();
	//2.��ʾԱ����Ϣ
	void show_emp();
	//3.ɾ����ְԱ��
	void delete_emp();
	//4.�޸�ְ����Ϣ
	void alter_rmp();
	//5.��ѯְ����Ϣ
	void Serach_info();
	//6.����ְ����Ϣ
	void sort_emp();
	//7.���ְ����Ϣ
	void clear_emp();

	
	//ϵͳ��������������
	~SysManager();

public:
	int m_size;
	Worker** m_Marray;
	//�ж�ϵͳ��ְ���Ƿ�Ϊ��
	bool Is_empty;

};