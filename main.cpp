#include <iostream>
#include <ShlObj.h>
#include <Windows.h>
#include <tchar.h>
using namespace std;
int about() {
	system("cls");
	cout << "�û������ļ��޸����� UPRT [�汾 0.1 Release]\n" << endl
		<< "(c)2021 ������(Jack He).\n" << endl
		<< "Github:BiliJackHe��\n" << endl
		<< "��Ȩ�� ���������ѧ ʹ�á�\n" << endl;
	system("pause");
	return 0;
}
int info() {
	system("cls");
	cout << "�û������ļ��޸����ߣ�User Profiles Repair Tools,��� UPRT����һ�����ڽ����ɾ�û�Ŀ¼�����С���ߡ�\n" << endl
		 << "ԭ�����ϵͳע����в����û�����(HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\ProfileList)��ʹϵͳ�ٴ�������Ч���á�" << endl << endl;
	system("pause");
	return 0;
}

int DelReg(const TCHAR* lpszSubKey) {
	int ret = RegDeleteKeyW(HKEY_LOCAL_MACHINE, lpszSubKey);
	if (ret == ERROR_SUCCESS) {
		return 0;
	}
	else {
		return 1;
	}
	return 0;
}

int RegFix() {
	system("pause");
	system("cls");
	int nRegFixState = DelReg(_T("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\ProfileList"));
	if (nRegFixState == 1) {
		cout << "�޸�ʧ�ܣ�" << endl;
		exit(-1);
	}
	else {
		system("fix.reg");
		cout << "�޸��ɹ�!" << endl;
		exit(0);
		return 0;
	}
}

int main() {
	system("cls");
	SetConsoleTitleW(_T("�û������ļ��޸�����"));
	int nChoose = 0;
	while (1) {
		system("cls");
		cout << "�û������ļ��޸����� [�汾 0.1 Release]" << endl << endl;
		cout << "[1] �޸�" << endl;
		cout << "[2] ����" << endl;
		cout << "[3] ����" << endl;
		cout << "[4] �˳�" << endl;
		cout << "[5] Windows �����������CMD��" << endl << endl;
		cout << "��ѡ�� [1-5] ���е�����һ��: ";
		nChoose = 0;
		cin >> nChoose;
		if (nChoose == 1) {
			RegFix();
		}
		else if (nChoose == 2) {
			info();
		}
		else if (nChoose == 3) {
			about();
		}
		else if (nChoose == 4)
		{
			exit(0);
		}
		else if (nChoose == 5) {
			system("cmd");
		}
	}
	return 0;
}