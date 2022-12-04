#include<fstream>
#include <iostream>
#include<iomanip>
#include<string>
#include<stdlib.h>
using namespace std;
void create();
void find();
void del();
void test();
void number();
inline void clean();
char ascii[127];
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
	mfile.open("base.txt",ios::out|ios::app);
	mfile.close();
	for (int i = 0; i <= 127; i++)
	{
		ascii[i] = i;
	}
label:
	clean();
	cout << "1.create" << endl;
	cout << "2.find" << endl;
	cout << "3.delete" << endl;
	cout << "4.number" << endl;
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
	default:
		cout << "you enter a wrong choice";
	}
	do
	{
		cout << "would you like to use it again(y/n):";
		cin >> again;
	} while (again!='y'&&again!='n');
	if (again == 'y')
		goto label;
	else
		cout << "goodbye";
	return(0);
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
		cout << "wrong"<<endl;
	}
	else
	{
		mfile << str<<"/" << endl;
		cfile.open(str, ios::out);
		cout << "creat successful" << endl;
		cfile.close();
	}
}
void find()
{
	clean();
	int num = 0;
	string str_1, str_2, str;
	char find;
	str_2 =".txt";
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
}
void del()
{
	clean();
	int i = 0, j = 0;
	char str_1[72];
	char str_2[] = { '.','t','x','t','\0' };
	cout << "please input the filename you want to delete:";
	cin >> str_1;
	while (str_1[i] != '\0')
		i++;
	while (str_2[j] != '\0')
		str_1[i++] = str_2[j++];
	str_1[i] = '\0';
	if (!remove(str_1))
	{
		cout << "successful" << endl;
	}
	else
	{
		cout << "the file is not find";
	}
}
void test()
{
	int j = 0;
	ifstream tfile;
	tfile.open("test.txt");
	while (!tfile.eof())
	{
		char ch;
		tfile.get(ch);
		int i = ch;
		if (tfile.eof())
			break;
		if (ch == 10)
			continue;
		cout << ch<< endl;
		j++;
	}
	cout << j;
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
			if (ch == 10||ch==32)
				continue;
			if (ch < 0)
				numl++;
			else
				num++;
		}
		num = num + numl / 3;
		cout << "it has " << num<<" char"<<endl;
	}
	else
	{
		cout << "the file is not find";
	}
	nfile.close();
}
void clean()
{
	system("cls");
}
