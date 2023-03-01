#include"SysManager.h"
#include"worker.h"
#include"boss.h"
#include"employee.h"
#include"manager.h"

using namespace std;


//ϵͳ�����๹�캯��
SysManager::SysManager()
{
	this->Init_sys();
}

//����ļ���ְ������
int SysManager::get_empNum()
{
	//��������������
	ifstream ifs;
	//���ļ�
	ifs.open(FILENAME, ios::in);
	//�ж��ļ��Ƿ��
	if (!ifs.is_open())
	{
		//cout<<"�ļ���ʧ��"<<endl;
		return 0;
	}
	//��ȡ����
	int id;
	string name;
	int did;

	int data_num=0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		data_num++;
	}
	ifs.close();

	return data_num;
}
//ϵͳ��ʼ��
void SysManager::Init_sys()
{
	//��������������
	ifstream ifs;
	//���ļ�
	ifs.open(FILENAME, ios::in);
	//�ж��ļ��Ƿ��
	//1.�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{//�ļ�������
		//cout << "�ļ�������" << endl;
		this->Is_empty = true;
		this->m_size = 0;
		this->m_Marray = NULL;
		return;
	}
	//�ж��ļ��Ƿ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{//�ļ�Ϊ��
		//cout << "�ļ�Ϊ��" << endl;
		this->Is_empty = true;
		this->m_size = 0;
		this->m_Marray = NULL;
		return;
	}
	ifs.close();
	//�ر����ϴ�
	

	//���ļ������Ҳ�Ϊ��
	//��������������
	ifstream ifs1;
	//���ļ�
	ifs1.open(FILENAME, ios::in);
	
	//����ļ���ְ������
	this->m_size = this->get_empNum();
	//�����¿ռ�
	this->m_Marray = new Worker * [this->m_size];
	//���ļ��ڵ����ݿ�����ȥ
	int n_id;
	string n_name;
	int n_did;
	for (int i = 0; i < this->m_size; i++)
	{
		ifs1 >> n_id;
		ifs1 >> n_name;
		ifs1 >> n_did;
		switch (n_did)
		{
		case 1:
			this->m_Marray[i] = new Employee(n_id, n_name, 1);
			break;
		case 2:
			this->m_Marray[i] = new Manager(n_id, n_name, 2);
			break;
		case 3:
			this->m_Marray[i] = new Boss(n_id, n_name, 3);
			break;
		default:
			break;
		}

	}
	ifs1.close();
	//����δ�ձ�־λ
	this->Is_empty = false;
	
	

}
//ְ����Ϣ����
void SysManager::save_sys()
{
	//�������������
	ofstream ofs;
	//���ļ�
	ofs.open(FILENAME,ios::out);
	//����������
	for (int i = 0; i < this->m_size; i++)
	{
		ofs << this->m_Marray[i]->m_Id << " "
			<< this->m_Marray[i]->m_Name << " "
			<< this->m_Marray[i]->m_Did << endl;
	}
	//�ر��ļ�
	ofs.close();
}
//�˵���ʾ����
void SysManager::ShowManu()
{
	cout << "***********************************************************" << endl;
	cout << "************	��ӭʹ��ְ������ϵͳ	***************" << endl;
	cout << "***************	0.�˳�ϵͳ	***************" << endl;
	cout << "***************	1.���ְ����Ϣ	***************" << endl;
	cout << "***************	2.��ʾְ����Ϣ	***************" << endl;
	cout << "***************	3.ɾ��ְ����Ϣ	***************" << endl;
	cout << "***************	4.�޸�ְ����Ϣ	***************" << endl;
	cout << "***************	5.����ְ����Ϣ	***************" << endl;
	cout << "***************	6.����ְ����Ϣ	***************" << endl;
	cout << "***************	7.���ְ����Ϣ	***************" << endl;
	cout << "*********************************************************" << endl;
	cout << endl;
}
//�����ּ���Ա��������������
int SysManager::find_emp(string f_name)
{
	int f_index = -1;
	if (this->Is_empty)//���ϵͳ������Ϣ���򷵻�
	{ }
	else
	{
		for (int i = 0; i < this->m_size; i++)
		{
			if (this->m_Marray[i]->m_Name == f_name)
			{
				f_index = i;
				break;
			}
		}
	}
	
	return f_index;

}


//0.�˳�ϵͳ
void SysManager::exitSystem()
{
	cout << "��ӭ���´�ʹ�ã�" << endl;
	system("pause");
	exit(0);//�˳�ϵͳ

}
//1.���Ա��
void SysManager::add_emp()
{

	int add_size;
	cout << "������Ҫ���Ա����������" << endl;
	cin >> add_size;

	//����һ���¿ռ���Ա����Ϣ
	int newSize = this->m_size + add_size;
	Worker** newspace = new Worker * [newSize];
	//��ԭ�������ݿ������¿ռ���
	for (int i = 0; i < this->m_size; i++)
	{
		newspace[i] = this->m_Marray[i];
	}

	int n_id;
	string n_name;
	int n_did;
	Worker * n_emp=NULL;
	for (int i = 0; i < add_size; i++)
	{
		
		cout << "�������" << i + 1 << "��ְ����ְ�����:" << endl;
		cin >> n_id;
		cout << "�������" << i + 1 << "��ְ��������:" << endl;
		cin >> n_name;
		do
		{
			cout << "��ѡ���" << i + 1 << "��ְ���ĸ�λ:" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> n_did;
			if (3 < n_did || n_did < 1)
				cout << "��Ч��λ�����������룡" << endl;

		} while (3<n_did || n_did<1);
		switch (n_did)
		{
		case 1:
			n_emp = new Employee(n_id, n_name,1);
			break;
		case 2:
			n_emp = new Manager(n_id, n_name, 2);
			break;
		case 3:
			n_emp = new Boss(n_id, n_name, 3);
			break;
		default:
			break;
		}
		//���³�Ա����ϵͳ
		newspace[this->m_size + i] = n_emp;
	}
	//����ϵͳ����
	this->m_size = newSize;
	//��������ָ��
	this->m_Marray = newspace;
	//��־λ����
	this->Is_empty = false;
	this->save_sys();

	n_emp = NULL;
	newspace = NULL;
	cout << "��ӳɹ���" << endl;

}
//2.��ʾԱ����Ϣ
void SysManager::show_emp()
{
	if (this->Is_empty)
	{
		cout << "ϵͳ������ְ����Ϣ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_size; i++)
		{
			//������Ϣ��ʾ����
			this->m_Marray[i]->ShowInfo();
		}
		cout << "ְ����Ϣ��ʾ��ɣ�" << endl;
	}
}
//3.ɾ����ְԱ��
void SysManager::delete_emp()
{
	if (this->Is_empty)
	{
		cout << "��ǰ����Ϊ�գ��޷�ɾ��" << endl;
		return;
	}
	
	string tager_name;
	cout << "������Ҫɾ����ְ��������" << endl;
	cin >> tager_name;

	//����Ŀ��ְ��������
	int tager_index = this->find_emp(tager_name);
	if(tager_index != -1)
	{
		//�ͷ�Ŀ��ռ�
		delete this->m_Marray[tager_index];
		this->m_Marray[tager_index] = NULL;
		//�����������ǰ����
		for (int i = tager_index; i < this->m_size - 1; i++)
			this->m_Marray[i] = this->m_Marray[i + 1];
		if (this->m_size != 1 && ((this->m_size - 1) == tager_index))
		{
			//�����һ�������ͷ�
			delete this->m_Marray[this->m_size - 1];
			this->m_Marray[this->m_size - 1] = NULL;
		}

		//��������
		this->m_size --;
		//�ж��Ƿ���±�־λ
		if (!this->m_size)
			this->Is_empty = true;
		//����ϵͳ���ļ�
		this->save_sys();
		cout << "ְ����ɾ����" << endl;
	}
	else
	{
		cout << "��Ա�������ڣ�" << endl;
	}
}
//4.�޸�ְ����Ϣ
void SysManager::alter_rmp()
{
	if (this->Is_empty)
	{
		cout << "��ǰְ��Ϊ�գ��޷��޸�" << endl;
		return;
	}

	string tager_name;
	cout << "������Ҫ�޸ĵ�ְ������" << endl;
	cin >> tager_name;
	int a_index = this->find_emp(tager_name);
	if (a_index == -1)
	{
		cout << "���޴��ˣ��޷��޸ģ�" << endl;
		return;
	}

	//�ͷ�ԭ�ж���
	delete this->m_Marray[a_index];
	this->m_Marray[a_index] = NULL;

	int n_id;
	string n_name;
	int n_did;
	cout << "�������޸ĺ��ְ����ţ�" << endl;
	cin >> n_id;
	cout << "�������޸ĺ��ְ��������" << endl;
	cin >> n_name;
	do
	{
		cout << "��ѡ���޸ĺ��ְ����λ:" << endl;
		cout << "1.��ͨԱ��" << endl;
		cout << "2.����" << endl;
		cout << "3.�ϰ�" << endl;
		cin >> n_did;
		if (3 < n_did || n_did < 1)
			cout << "��Ч��λ�����������룡" << endl;

	} while (3 < n_did || n_did < 1);
	switch (n_did)
	{
	case 1:
		this->m_Marray[a_index] = new Employee(n_id, n_name, 1);
		break;
	case 2:
		this->m_Marray[a_index] = new Manager(n_id, n_name, 2);
		break;
	case 3:
		this->m_Marray[a_index] = new Boss(n_id, n_name, 3);
		break;
	default:
		break;
	}
	cout << "�޸ĳɹ���" << endl;
	//������ĵ������ļ�
	this->save_sys();

}
//5.��ѯְ����Ϣ
void SysManager::Serach_info()
{
	if (this->Is_empty)
	{
		cout << "��ǰְ��Ϊ�գ��޷�����" << endl;
		return;
	}

	string tager_name;
	cout << "������Ҫ���ҵ�ְ������" << endl;
	cin >> tager_name;
	int a_index = this->find_emp(tager_name);
	if (a_index == -1)
	{
		cout << "���޴���" << endl;
		return;
	}
	else 
	{
		cout << "���ҳɹ�" << endl;
		this->m_Marray[a_index]->ShowInfo();
	}

}
//6.����ְ����Ϣ
void SysManager::sort_emp()
{
	if (this->Is_empty)
	{
		cout << "��ǰ�б�Ϊ��,�޷�����" << endl;
		return;
	}
	Worker* temp = NULL;;
	for(int i=0;i<this->m_size-1;i++)
		for (int j = i; j < this->m_size; j++)
		{
			if (this->m_Marray[i]->m_Id > this->m_Marray[j]->m_Id)
			{//����ָ��
				temp = this->m_Marray[i];
				this->m_Marray[i] = this->m_Marray[j];
				this->m_Marray[j] = temp;
			}
		}
	cout << "������ɣ�" << endl;
	//��������ϵͳ�ļ�
	this->save_sys();

}
//7.���ְ����Ϣ
void SysManager::clear_emp()
{
	if (this->Is_empty)
	{
		cout << "��ǰϵͳ�Ѿ�Ϊ�գ�" << endl;
		return;
	}
	//��ʼ���
	for (int i = 0; i < this->m_size; i++)
	{
		delete this->m_Marray[i];
		this->m_Marray[i] = NULL;
	}
	delete[] this->m_Marray;
	this->m_Marray = NULL;
	this->m_size=0;
	this->Is_empty = true;

	cout << "�����ְ����Ϣ" << endl;
}

//ϵͳ��������������
SysManager::~SysManager()
{
	cout << "sysManager���캯�����������������ã�" << endl;
	if (this->m_Marray != NULL)
	{
		for (int i = 0; i < this->m_size; i++)
		{
			delete this->m_Marray[i];
			m_Marray[i] = NULL;
		}

		delete[] this->m_Marray;
		this->m_Marray = NULL;
		this->m_size = 0;
	}
}