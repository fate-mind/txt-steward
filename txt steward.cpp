﻿#include<fstream>
#include <iostream>
#include<iomanip>
#include<string>
#include<stdlib.h>
using namespace std;
void create();
void find();
void del();
void number();
inline void clean();
struct txtinformation
{
	int num;
	string txtname;
	string author;
};
int main()
{
	int choice;
	char again;
	fstream mfile;
	mfile.open("base.txt", ios::out | ios::app);
	mfile.close();
label:
	clean();
	cout << "1.create" << endl;
	cout << "2.find" << endl;
	cout << "3.delete" << endl;
	cout << "4.number" << endl;
	cout << "0.exit" << endl;
	cout << "please input your choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		create();
		break;
	case 2:
		find();
		break;
	case 3:
		del();
		break;
	case 4:
		number();
		break;
	case 0:
		return 0;
		break;
	default:
		cout << "you enter a wrong choice";
	}
	goto label;
}
void create()
{
	clean();
	fstream mfile;
	mfile.open("base.txt", ios::out | ios::app);
	fstream cfile;
	string str;
	string str_1 = ".txt";
	string str_2;
	cout << "please input your txtname:";
	cin >> str_2;
	str = str_2 + str_1;
	if (str == "base.txt")
	{
		cout << "wrong" << endl;
	}
	else
	{
		mfile << str << "/" << endl;
		cfile.open(str, ios::out);
		cout << "create successful" << endl;
		cfile.close();
	}
	system("pause");
}
void find()
{
	clean();
	int num = 0;
	string str_1, str_2, str;
	char find;
	str_2 = ".txt";
	cout << "please input your txtname:";
	cin >> str_1;
	str = str_1 + str_2;
	ifstream ifile(str);
	if (!ifile.fail())
	{
		cout << "what do you want to find:";
		cin >> find;
		while (!ifile.eof())
		{
			char ch;
			int sp = ifile.tellg();
			ifile.get(ch);
			if (ch == find)
			{
				if (ifile.eof())
				{
					break;
				}
				else
				{
					num++;
					cout << "postion:" << sp;
					cout << " is found" << endl;
				}
			}
		}
		cout << num << "results" << endl;
	}
	else
	{
		cout << "not find " << str << endl;
	}
	ifile.close();
	system("pause");
}
void del()
{
	clean();
	int i = 0, j = 0;
	char str_1[72];
	char str_2[] = { '.','t','x','t','\0' };
	cout << "please input the filename you want to delete: ";
	cin >> str_1;
	while (str_1[i] != '\0')
		i++;
	while (str_2[j] != '\0')
		str_1[i++] = str_2[j++];
	str_1[i] = '\0';
	if (strcmp(str_1,"base.txt"))
	{
		if (!remove(str_1))
		{
			cout << "successful" << endl;
		}
		else
		{
			cout << "the file is not find"<<endl;
		}
	}
	else
	{
		cout << "you can not delete this file" << endl;
	}
	system("pause");
}
void number()
{
	clean();
	int num = 0;
	int numl = 0;
	ifstream nfile;
	string str_2 = ".txt", str, str_1;
	cout << "please input your txtname:";
	cin >> str_1;
	str = str_1 + str_2;
	nfile.open(str);
	if (!nfile.fail())
	{
		while (!nfile.eof())
		{
			char ch;
			nfile.get(ch);
			if (nfile.eof())
				break;
			if (ch == 10 || ch == 32)
				continue;
			if (ch < 0)
				numl++;
			else
				num++;
		}
		num = num + numl / 3;
		cout << "it has " << num << " char" << endl;
	}
	else
	{
		cout << "the file is not find";
	}
	nfile.close();
	system("pause");
}
void clean()
{
	system("cls");
}
