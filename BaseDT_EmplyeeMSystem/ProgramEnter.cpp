#include<iostream>
#include<string>
#include"SysManager.h"

using namespace std;

void Penter()
{
	//����һ��ϵͳ���������
	SysManager sm;
	while(true)
	{
		sm.ShowManu();	//��ʾ�˵�
		int opt = 0;				//ѡ�����
		cout << "��ѡ����Ҫ���еĲ�����" << endl;
		cin >> opt;

		switch (opt)
		{
		case 0://�˳�ְ��ϵͳ
			sm.exitSystem();
			break; 
		case 1://���ְ����Ϣ
			sm.add_emp();
			break;
		case 2://��ʾְ����Ϣ
			sm.show_emp();
			break;
		case 3://ɾ��ְ����Ϣ
			sm.delete_emp();
			break;
		case 4://�޸�ְ����Ϣ
			sm.alter_rmp();
			break;
		case 5://��ѯְ����Ϣ
			sm.Serach_info();
			break;
		case 6://����ְ����Ϣ
			sm.sort_emp();
			break;
		case 7://���ְ����Ϣ
			sm.clear_emp();
			break;
		default:
			break;
		}

		system("pause");
		system("cls");
	}
	
}

int main()
{
	Penter();

	return 0;
}