#include"boss.h"

using namespace std;

//���캯��
Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Did = did;
}

void Boss::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_Id << "     "
		<< "������" << this->m_Name << "     "
		<< "��λ��" << "�ϰ�" << "     "
		<< "��λְ��" << "����˾" << endl;
}
