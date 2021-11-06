#include <iostream>
#include <ShlObj.h>
#include <Windows.h>
#include <tchar.h>
using namespace std;
int about() {
	system("cls");
	cout << "用户配置文件修复工具 UPRT [版本 0.1 Release]\n" << endl
		<< "(c)2021 贺禧冠(Jack He).\n" << endl
		<< "Github:BiliJackHe。\n" << endl
		<< "授权于 昆明滇池中学 使用。\n" << endl;
	system("pause");
	return 0;
}
int info() {
	system("cls");
	cout << "用户配置文件修复工具（User Profiles Repair Tools,简称 UPRT）是一个用于解决误删用户目录问题的小工具。\n" << endl
		 << "原理：清除系统注册表中残余用户配置(HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\ProfileList)，使系统再次生成有效配置。" << endl << endl;
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
		cout << "修复失败！" << endl;
		exit(-1);
	}
	else {
		system("fix.reg");
		cout << "修复成功!" << endl;
		exit(0);
		return 0;
	}
}

int main() {
	system("cls");
	SetConsoleTitleW(_T("用户配置文件修复工具"));
	int nChoose = 0;
	while (1) {
		system("cls");
		cout << "用户配置文件修复工具 [版本 0.1 Release]" << endl << endl;
		cout << "[1] 修复" << endl;
		cout << "[2] 介绍" << endl;
		cout << "[3] 关于" << endl;
		cout << "[4] 退出" << endl;
		cout << "[5] Windows 命令解释器（CMD）" << endl << endl;
		cout << "请选择 [1-5] 项中的其中一项: ";
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