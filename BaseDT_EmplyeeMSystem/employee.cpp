#include"employee.h"

using namespace std;

//���캯��
Employee::Employee(int id,string name,int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Did = did;
}

void Employee::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_Id << "     "
		<< "������" << this->m_Name << "     "
		<< "��λ��" << "Ա��" << "     "
		<< "��λְ��" << "��ɾ����ŵ�����" << endl;
}
