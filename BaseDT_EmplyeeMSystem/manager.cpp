#include"manager.h"

using namespace std;

//���캯��
Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Did = did;
}

void Manager::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_Id << "     "
		<< "������" << this->m_Name << "     "
		<< "��λ��" << "����" << "     "
		<< "��λְ��" << "����ϰ尲�ŵ�����,���ź������Ĺ���" << endl;
}
