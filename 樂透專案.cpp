#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<map>
#include<ctime>
#include<cstdlib>
using namespace std;
void OptionOne(vector<vector<int> > &nums, int op1);//�M���X���N�y
void OptionTwo(vector<vector<int> > &nums, int op2);//�M���X�����y
void OptionThree(vector<vector<int> > &nums, vector<string>&bufdays, vector<int>&buf, string s);//��J����丹�X
void OptionFour(string day4, vector<string> bufdays, vector<vector<int> > nums);//��Y�~�Y�몺�Ҧ����X
void OptionFive(int op5, vector<vector<int> > nums, vector<string>bufdays);//��J�Ʀr��u�̱`�v�P�L�@�_�X�{�����X
void OptionSix(int op6, vector<vector<int> > nums, vector<string>bufdays);//��J�Ʀr��u�̤��`�v�P�L�@�_�X�{�����X
void OptionSeven(string day7, vector<string> bufdays, vector<vector<int> > nums);//��J����M���X���
void OptionNine(vector<int> &Random, int Test);//�q���︹
void OptionTen(int op10, int opp10, vector<vector<int> > nums, vector<string>bufdays);//��J�Ʀr�M���Ƨ�u��X���̱`�v�P�L�@�_�X�{�����X
void OptionEleven(int op11, int opp11, vector<vector<int> > nums, vector<string>bufdays);//��J�Ʀr�M���Ƨ�u��X���̤��`�v�P�L�@�_�X�{�����X
void OptionTwelve(vector<int> &Random, int Test);//�Y�ްݯ���
void OptionThirteen(vector<string>bufdays);//�߬W�]�P�k
void OptionFourteen(string Test);//�����ɻ�
void OptionFifteen(string Test);//�����z��
void OptionSixteen(vector<string>bufdays);//��7~11�Ӽƥ]�P
int main()
{
	ifstream fin;
	fin.open("C:\\Users\\lin-book\\Documents\\lottery.txt");//���޸��������|
	if (fin.fail())
	{
		cout << "Cannot open file" << endl;
		return 1;
	}
	cout << "�Ĥ@�մ����M�D�W�d" << endl;
	cout << "�ֳz�s�y��" << endl;
	cout << "0.�����ֳz�s�y��" << endl;
	cout << "1.���X�����N�y" << endl;
	cout << "2.���X�������y" << endl;
	cout << "3.��Y�Ӥ�������X(��J����A�丹�X)" << endl;
	cout << "4.��Y�~�A�Y�몺�Ҧ����X (��J�~�B��A�C�X�Ҧ����X)" << endl;
	cout << "5.��J X ���X�A��u�̱`�v�P���@�P�X�{�����X�e 5 �W (��J X ���X)" << endl;
	cout << "6.��J X ���X�A��u�̤��`�v�P���@�P�X�{�����X�e 5 �W (��J X ���X)" << endl;
	cout << "7.��J ����A��J 6 �Ӹ��X�A��X���X�X" << endl;
	cout << "8.�n���G���ˤ@�ո��X" << endl;
	cout << "9.�ոզn���(�@�չq���︹)" << endl;
	cout << "10.�d�߬Y�ӼƦr�u��X���̱`�v�P���@�P�X�{�����X�e 5 �W (��J X ���X)" << endl;
	cout << "11.�d�߬Y�ӼƦr�u��X���̤��`�v�P���@�P�X�{�����X�e 5 �W (��J X ���X)" << endl;
	cout << "12.�Y�ްݯ����A�Я����}�ܸ��X" << endl;
	cout << "13.�߬W�]�P�k" << endl;
	cout << "14.�����ɻ�(��J����6�Ӹ��X)" << endl;
	cout << "15.�����z��(��J�j��6�Ӹ��X)" << endl;
	cout << "16.�� 7~11 �Ӹ��X�]�P(�C�X�Ҧ��զX)" << endl;
	cout << endl;cout << endl;cout << "-------------------------------------------------" << endl;cout << endl;
	vector<vector<int> > nums;//�ƭ�
	vector<int> buf;
	vector<string>bufdays;//���
	string s;
while(fin >> s)
	{
			bufdays.push_back(s);
			for (int k=0; k < 7; k++)
			{
				int v;
				fin >> v;
				buf.push_back(v);
			}
			nums.push_back(buf);
			buf.clear();
	}
int option;
while (true)
{
	cin >> option;
	if (option == 0)
		break;
	else if (option == 1)
	{
		cout << "�аݭn�d�ߪ�X�����N�y" << endl;
		int op1;
		cin >> op1;
		OptionOne(nums, op1);
	}
	else if (option == 2)
	{
		cout << "�аݭn�d�ߪ�X�������y" << endl;
		int op2;
		cin >> op2;
		OptionTwo(nums, op2);
	}
	else if (option == 3)
	{
		cout << "�п�J���(�榡�G2017/05/17)" << endl;
		string day3;
		cin >> day3;
		OptionThree(nums, bufdays, buf, day3);
	}
	else if (option == 4)
	{
		cout << "�п�J�~�B��(�榡�G2017/05)" << endl;
		string day4;
		getline(cin, day4);
		OptionFour(day4, bufdays, nums);
	}
	else if (option == 5)
	{
		cout << "�п�J�@�Ӹ��X�A�ڭ̱N���A��X�u�̱`�v�P�o�Ӹ��X�@�P�X�{�����ӼƦr" << endl;
		int op5;
		cin >> op5;
		OptionFive(op5, nums,bufdays);
	}
	else if (option == 6)
	{
		cout << "�п�J�@�Ӹ��X�A�ڭ̱N���A��X�u�̤��`�v�P�o�Ӹ��X�@�P�X�{�����ӼƦr" << endl;
		int op6;
		cin >> op6;
		OptionSix(op6, nums,bufdays);
	}
	else if (option == 7)
	{
		cout << "�п�J����P6�Ӹ��X�A�ڭ̱N���A�ֹ襤�F�X�Ӹ��X" << endl;
		cout << "(����榡�G2017/05/17)" << endl;
		string day7;
		OptionSeven(day7, bufdays, nums);
	}
	else if (option == 8)
	{
		cout << "���ڬݬݡI�I�o���̱��˧A�����X" << endl;
	}
	else if (option == 9)
	{
		cout << "�H���︹" << endl;
		vector<int> Random;
		int i = 0;
		OptionNine(Random, i);
	}
	else if (option == 10)
	{
		cout << "�ڭ̱N���A��X�u��X���̱`�v�P�o�Ӹ��X�@�P�X�{�����ӼƦr�A�Х���J�Q�j�M��X�����Ʀr�A�A��J���X" << endl;
		int op10,opp10;
		cin >> opp10>>op10;
		OptionTen(op10,opp10, nums, bufdays);
	}
	else if (option == 11)
	{
		cout << "�ڭ̱N���A��X�u��X���̤��`�v�P�o�Ӹ��X�@�P�X�{�����ӼƦr�A�Х���J�Q�j�M��X�����Ʀr�A�A��J���X" << endl;
		int op11, opp11;
		cin >> opp11 >> op11;
		OptionEleven(op11, opp11, nums, bufdays);
	}
	else if (option == 12)
	{
		cout << "���F�I�I" << endl;
		vector<int>Random;
		int i = 0;
		OptionTwelve(Random, i);
	}
	else if (option == 13)
	{
		cout << "�@�B��ܥi��|�X�{�����X�C" << endl;
		cout << "    �m�g�n�� 1~49 �Ӹ��X(�H�j�ֳz����) ����X�Y�z�Ӧb�U���ܦ����|�|�X�{�����X�C" << endl;
		cout << "�G�B��ܥi��|�X�{�����X�C" << endl;
		cout << "    ���۱m�g�|�]�� 6 �ӬW�l�A�ç��X�����X���O�k���줣�P���W�l�W�C�C�ӬW�l�ܤַ|���@�ӼƦr�C" << endl;
		cout << endl;
		cout << "����J�Ʀr�ɽХH�r�I�j�}" << endl;
		OptionThirteen(bufdays);
	}
	else if (option == 14)
	{
		cout << "�п�J�Ʀr(�ݤp��6��)" << endl;
		string op14;
		cin.ignore(1000, '\n');
		getline(cin, op14);
		OptionFourteen(op14);
	}
	else if (option == 15)
	{
		cout << "�п�J�Ʀr(�ݤj��6��)" << endl;
		string op15;
		cin.ignore(1000, '\n');
		getline(cin, op15);
		OptionFifteen(op15);
	}
	else if (option == 16)
	{
		cout << "�п�J�z�Q�]�P��7��11�Ӹ��X" << endl;
		OptionSixteen(bufdays);
	}
}
	/*for (int i = 0; i < bufdays.size(); i++)
	{
		cout << bufdays[i];
		for (int j = 0;j < 7;j++)
		{
			cout << " " << nums[i][j];
		}
		cout << endl;
	}*/
	fin.close();
}
//----------------------------------------------------------------------------
void OptionOne(vector<vector<int>>& nums, int op1)//�M���X���N�y
{
	vector<int> Rank;
	map<int, int> Cold;
	for (int i = 0; i < op1; i++)
	{
		for (int k = 0; k < 7; k++)
		{
			if (Cold.count(nums[i][k]) == 0)
			{
				Cold.insert(make_pair(nums[i][k], 1));
			}
			else
			{
				Cold[nums[i][k]]++;
			}
		}
	}
	for (map<int, int>::iterator iter = Cold.begin(); iter != Cold.end(); iter++)
	{
		Rank.push_back(iter->second);
	}
	sort(Rank.begin(), Rank.end());
	for (map<int, int>::iterator iter = Cold.begin(); iter != Cold.end(); iter++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (Rank[i] == iter->second)
			{
				cout << iter->first << " ";
				Rank[i] = 0;
				i = 5;
			}
		}
	}
	cout << endl;cout << "-----------------------------------------------" << endl;
}
//------------------------------------------------------------------------------
void OptionTwo(vector<vector<int>>& nums, int op2)//�M���X�����y
{
	vector<int> Rank;
	map<int, int> Hot;
	for (int i = 0; i < op2; i++)
	{
		for (int k = 0; k < 7; k++)
		{
			if (Hot.count(nums[i][k]) == 0)
			{
				Hot.insert(make_pair(nums[i][k], 1));
			}
			else
			{
				Hot[nums[i][k]]++;
			}
		}
	}
	for (map<int, int>::iterator iter = Hot.begin(); iter != Hot.end(); iter++)
	{
		Rank.push_back(iter->second);
	}
	sort(Rank.begin(), Rank.end());
	reverse(Rank.begin(), Rank.end());
	for (map<int, int>::iterator iter = Hot.begin(); iter != Hot.end(); iter++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (Rank[i] == iter->second)
			{
				cout << iter->first << " ";
				Rank[i] = 0;
				i = 5;
			}
		}
	}
	cout << endl;
	cout << "-----------------------------------------------" << endl;
}
//----------------------------------------------------------------------------------------------
void OptionThree(vector<vector<int>> &nums, vector<string>&bufdays, vector<int>&buf, string s)//��J����丹�X
{
	int x = 0;
	for (int i = 0; i < bufdays.size(); i++)
	{
		if (bufdays[i] == s)
		{
			x = i;
			break;
		}
	}
	for (int i = 0; i < 7; i++)
	{
		cout << nums[x][i] << " ";
	}
	cout << endl;cout << "-----------------------------------------------" << endl;
}
//---------------------------------------------------------------------------------
void OptionFour(string day4, vector<string> bufdays, vector<vector<int> > nums)//��Y�~�Y�몺�Ҧ����X
{
	int t = 0;
	cin >> day4;
	for (int i = 0; i < 120; i++)
	{
		string k = bufdays[i];
		string kk = "";
		kk = kk + k[0] + k[1] + k[2] + k[3] + k[4] + k[5] + k[6];
		if (day4 == kk)
		{
			cout << bufdays[i] << " ";
			t++;
			for (int j = 0; j < 7; j++)
			{
				if (j == 6)
				{
					cout << nums[i][j] << endl;
				}
				else
					cout << nums[i][j] << " ";
			}
		}
	}
	if (t == 0)
		cout << "�d�L�����" << endl;
	cout << "-----------------------------------------------" << endl;
}
//---------------------------------------------------------------------------------
void OptionFive(int op5, vector<vector<int> > nums, vector<string>bufdays)//��J�Ʀr��u�̱`�v�P�L�@�_�X�{�����X
{
	vector<int>Rank;
	map<int, int>Hot;
	for (int i = 0; i < bufdays.size(); i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (nums[i][j] == op5)
			{
				for (int k = 0;k < 7;k++)
				{
					if (Hot.count(nums[i][k]) == 0)
						Hot.insert(make_pair(nums[i][k], 1));
					else
						Hot[nums[i][k]]++;
				}
			}
		}
	}
	for (map<int, int>::iterator iter = Hot.begin();iter != Hot.end();iter++)
	{
		Rank.push_back(iter->second);
	}
	sort(Rank.begin(), Rank.end());
	reverse(Rank.begin(), Rank.end());
	for (map<int, int>::iterator iter = Hot.begin();iter != Hot.end();iter++)
	{
		for (int i = 1;i < 6;i++)
		{
			if (Rank[i] == iter->second&&i == 5)
			{
				cout << iter->first<<" ";
				Rank[i] = 0;
				i = 6;
			}
			else if (Rank[i] == iter->second)
			{
				cout << iter->first << " ";
				Rank[i] = 0;
				i = 6;
			}
		}
	}
	cout << endl;cout << "-----------------------------------------------" << endl;
}
//-----------------------------------------------------------------------------
void OptionSix(int op6, vector<vector<int> > nums,vector<string>bufdays)//��J�Ʀr��u�̤��`�v�P�L�@�_�X�{�����X
{
	if (op6 <= 49 && op6 >= 0)
	{
		int agb[50] = { 0 };//0-49
		int agb2[50] = { 0 };
		for (int i = 0; i < bufdays.size(); i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (op6 == nums[i][j])
				{
					for (int l = 0; l < 7; l++)
					{
						if (j != l)
						{
							agb[nums[i][l]]++;
							agb2[nums[i][l]]++;
						}
					}
				}
			}
		}
		int t;
		for (int i = 0; i < 50; i++)
		{
			if (agb2[i] == 0)
			{
				agb2[i] = 1000;
			}
		}
		sort(agb2, agb2 + 50);
		int agb3[5];
		agb3[0] = agb2[0];
		agb3[1] = agb2[1];
		agb3[2] = agb2[2];
		agb3[3] = agb2[3];
		agb3[4] = agb2[4];
		int tt = 0;
		int m = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (agb3[i] != 9999)
				{
					if (i != j)
					{
						if (agb3[i] == agb3[j])
						{
							agb3[j] = 9999;
							m++;
						}
					}
				}
			}
		}
		sort(agb3, agb3 + 5);
		for (int k = 0; k < 5 - m; k++)
		{
			for (int i = 0; i < 50; i++)
			{
				if (tt < 5)
				{
					if (agb[i] == agb3[k])
					{
						cout << i << " ";
						tt++;
					}
				}
			}
		}
	}
	else
	{
		cout << "�ֳz�ƭȿ�J���~�A�Э��s����" << endl;	
	}
	cout << endl;
	cout << "-----------------------------------------------" << endl;
}
//------------------------------------------------------------------------------
void OptionSeven(string day7, vector<string> bufdays, vector<vector<int>> nums)//��J����M���X���
{
	cin>>day7;
	int t = 0;
	string k;
	int s = 2;
	for (int i = 0; i < bufdays.size(); i++)
	{
		k = bufdays[i];
		if (day7 == k)
		{
			s = 0;
			int agb[6];
			for (int j = 0; j < 6; j++)
				cin >> agb[j];
			sort(agb, agb + 6);
			for (int j = 0; j < 6; j++)
			{
				for (int l = 0; l < 6; l++)
				{
					if (agb[l] == nums[i][j])
						t++;
				}
			}
			cout << k << " ";
		}
	}
	if (s == 0)
		cout << "����@���F" << t << "�Ӹ��X" << endl;
	else
		cout << "�L�����" << endl;
	cout << "-----------------------------------------------" << endl;
}
//------------------------------------------------------------------------------

void OptionNine(vector<int>& Random, int Test)//�@�չq���︹
{
	srand(time(NULL));
	for (int i = 0; i < 7; i++)
	{
		Random.push_back(rand() % 49 + 1);
		for (int k = 0; k < Random.size(); k++)
		{
			if ((Random[i] == Random[k]) && (i != k))
			{
				Random[k] = 0;
			}
		}
	}
	for (int i = 0; i < Random.size(); i++)
	{
		if (Random[i] == 0)
		{
			Random[i] = rand() % 47 + 2;
		}
	}
	sort(Random.begin(), Random.end());
	for (int i = 0; i < 7; i++)
	{
		cout << Random[i] << " ";
	}
	cout << endl;
	cout << "-----------------------------------------------" << endl;
}
//-----------------------------------------------------------------
void OptionTen(int op10, int opp10, vector<vector<int> > nums, vector<string>bufdays)//��J�Ʀr�M���Ƨ�u��X���̱`�v�P�L�@�_�X�{�����X
{
	vector<int>Rank;
	map<int, int>Hot;
	for (int i = 0; i < opp10; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (nums[i][j] == op10)
			{
				for (int k = 0;k < 7;k++)
				{
					if (Hot.count(nums[i][k]) == 0)
						Hot.insert(make_pair(nums[i][k], 1));
					else
						Hot[nums[i][k]]++;
				}
			}
		}
	}
	for (map<int, int>::iterator iter = Hot.begin();iter != Hot.end();iter++)
	{
		Rank.push_back(iter->second);
	}
	sort(Rank.begin(), Rank.end());
	reverse(Rank.begin(), Rank.end());
	for (map<int, int>::iterator iter = Hot.begin();iter != Hot.end();iter++)
	{
		for (int i = 1;i < 6;i++)
		{
			if (Rank[i] == iter->second&&i == 5&&iter->first!=op10)
			{
				cout << iter->first<<" ";
				Rank[i] = 0;
				i = 6;
			}
			else if (Rank[i] == iter->second&&iter->first != op10)
			{
				cout << iter->first << " ";
				Rank[i] = 0;
				i = 6;
			}
		}
	}
	cout << endl;cout << "-----------------------------------------------" << endl;
}
//------------------------------------------------------------------------------
void OptionEleven(int op11, int opp11, vector<vector<int> > nums, vector<string>bufdays)//��J�Ʀr�M���Ƨ�u��X���̱`�v�P�L�@�_�X�{�����X
{
	vector<int>Rank;
	map<int, int>Hot;
	for (int i = 0; i < opp11; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (nums[i][j] == op11)
			{
				for (int k = 0;k < 7;k++)
				{
					if (Hot.count(nums[i][k]) == 0)
						Hot.insert(make_pair(nums[i][k], 1));
					else
						Hot[nums[i][k]]++;
				}
			}
		}
	}
	for (map<int, int>::iterator iter = Hot.begin();iter != Hot.end();iter++)
	{
		Rank.push_back(iter->second);
	}
	sort(Rank.begin(), Rank.end());
	for (map<int, int>::iterator iter = Hot.begin();iter != Hot.end();iter++)
	{
		for (int i = 1;i < 6;i++)
		{
			if (Rank[i] == iter->second&&i == 5)
			{
				cout << iter->first << " ";
				Rank[i] = 0;
				i = 6;
			}
			else if (Rank[i] == iter->second)
			{
				cout << iter->first << " ";
				Rank[i] = 0;
				i = 6;
			}
		}
	}
	cout << endl;cout << "-----------------------------------------------" << endl;
}
//------------------------------------------------------------------------------
void OptionTwelve(vector<int> &Random, int Test)//�Y�ްݯ���
{
	vector<int>buf;
	srand(time(NULL));
	for (int i = 1; i <= 9; i++)
	{
		buf.push_back(i);
	}
	random_shuffle(buf.begin(), buf.end());
	for (int i = 0; i < 1; i++)
	{
		if (buf[i] == 1)
		{
			cout << "����ҧg" << endl;
			cout << "�Ϩ���G�A��2��3��" << endl;
			cout << "  ����ҧg�S�٬�[���ҧg]�A�۶ǬO�ѤW���妱�P���ƨ�,�OŪ�ѤH���D�_���C" << endl;cout << endl;
			cout << "���˩��B���X�G2�B3" << endl;cout << "-----------------------------------------------" << endl;cout << endl;
		}
		else if (buf[i] == 2)
		{
			cout << "�[�@������" << endl;
			cout << "�Ϩ���G�A��2��19��" << endl;
			cout << "  �b�����\�h�H�H�^�[�@�����ġA�\�h���k�|�b�[�@�����ĥͤ�e�i�}�l�Y���A����ܰ@�ۡC" << endl;cout << endl;
			cout << "���˩��B���X�G2�B19" << endl;cout << "-----------------------------------------------" << endl;cout << endl;
		}
		else if (buf[i] == 3)
		{
			cout << "���W�u�@�̶���" << endl;
			cout << "�Ϩ���G�A��3��23��" << endl;
			cout << "  �����N�O�e�ѤW�t���f�A�@��q�١e�����f�Ρe�����C�f�A�O�j���u���@�a�H�����M�H�^�����C" << endl;cout << endl;
			cout << "���˩��B���X�G3�B23" << endl;cout << "-----------------------------------------------" << endl;cout << endl;
		}
		else if (buf[i] == 4)
		{
			cout << "���A�j��" << endl;
			cout << "�Ϩ���G�A��4��26��" << endl;
			cout << "  �M���ʯ�A����U���į󰵥г��լd��s�A�ҥH�S�Q�٬��y�Ĥ��j�ҡz�C" << endl;cout << endl;
			cout << "���˩��B���X�G4�B26" << endl;cout << "-----------------------------------------------" << endl;cout << endl;
		}
		else if (buf[i] == 5)
		{
			cout << "�ȤѤW��" << endl;
			cout << "�Ϩ���G�A��3��3��" << endl;
			cout << "  �b�����ǻ����ȤѤW�Ҹ}���t�D�G�N�A����C�P�_�C�A�㦳���a�Ѥ̪v���m�����~�q�ت����O�C" << endl;cout << endl;
			cout << "���˩��B���X�G3" << endl;cout << "-----------------------------------------------" << endl;cout << endl;
		}
		else if (buf[i] == 6)
		{
			cout << "���t�ҧg����" << endl;
			cout << "�Ϩ���G�A��6��24��" << endl;
			cout << "  ���t�ҧg�A�T��ɥN���~���j�N���СA�r�����A�����w�A�Z�i���ۡA�P�B�ơB�i�����q�_���A�Y�ҿ׮��T���q�C" << endl;cout << endl;
			cout << "���˩��B���X�G6�B24" << endl;cout << "-----------------------------------------------" << endl;cout << endl;
		}
		else if (buf[i] == 7)
		{
			cout << "�ּw�����g�a��" << endl;
			cout << "�Ϩ���G�A��8��15��" << endl;
			cout << "  ��U�ѤH�A�S�٤�Ѥ��B��ѡA�O�D�Ъ����餧�@�A���x�ިk�k�B�ä����A�۶Ǭ��u�C���v�C" << endl;cout << endl;
			cout << "���˩��B���X�G8�B15" << endl;cout << "-----------------------------------------------" << endl;cout << endl;
		}
		else if (buf[i] == 8)
		{
			cout << "���¤��ӤT�Ӥl" << endl;
			cout << "�Ϩ���G�A��9��9��" << endl;
			cout << "  �������V�B�Y�������B�T���Y�B�E�����B�K�����u�B�f�R�C���C" << endl;cout << endl;
			cout << "���˩��B���X�G9�B9" << endl;cout << "-----------------------------------------------" << endl;cout << endl;
		}
		else if (buf[i] == 9)
		{
			cout << "�C�q" << endl;
			cout << "�Ϩ���G���12��25��" << endl;
			cout << "  ���F������Я�s�x�Q�����A�з|��b12��25��y���C�q���ϥ͡C �������жǹM��ڡA�t�ϸ`���ǲδN�o�ˬy��F�_�ӡC" << endl;cout << endl;
			cout << "���˩��B���X�G12�B25" << endl;cout << "-----------------------------------------------" << endl;cout << endl;
		}
	}
}
//--------------------------------------------------------------
void OptionThirteen(vector<string> bufdays)//�߬W�]�P�k
{
	cin.ignore(1000, '\n');
	vector<string>buf;
	vector<string>bufs1;
	vector<string>bufs2;
	vector<string>bufs3;
	vector<string>bufs4;
	vector<string>bufs5;
	vector<string>bufs6;
	int z = 0;
	string s1, s2, s3, s4, s5, s6;
	cout << "�Ĥ@�ӬW�l" << endl;
	getline(cin, s1);
	cout << "�ĤG�ӬW�l" << endl;
	getline(cin, s2);
	cout << "�ĤT�ӬW�l" << endl;
	getline(cin, s3);
	cout << "�ĥ|�ӬW�l" << endl;
	getline(cin, s4);
	cout << "�Ĥ��ӬW�l" << endl;
	getline(cin, s5);
	cout << "�Ĥ��ӬW�l" << endl;
	getline(cin, s6);
	cout << "�H�U���߬W�]�P�k���Ҧ��զX" << endl;
	string token;
	stringstream ss(s1);
	while (getline(ss, token, ','))
	{
		bufs1.push_back(token);
	}
	stringstream ss2(s2);
	while (getline(ss2, token, ','))
	{
		bufs2.push_back(token);
	}
	stringstream ss3(s3);
	while (getline(ss3, token, ','))
	{
		bufs3.push_back(token);
	}
	stringstream ss4(s4);
	while (getline(ss4, token, ','))
	{
		bufs4.push_back(token);
	}
	stringstream ss5(s5);
	while (getline(ss5, token, ','))
	{
		bufs5.push_back(token);
	}
	stringstream ss6(s6);
	while (getline(ss6, token, ','))
	{
		bufs6.push_back(token);
	}
	for (int a = 0;a < bufs1.size();a++)
	{
		for (int b = 0;b < bufs2.size();b++)
		{
			for (int c = 0;c < bufs3.size();c++)
			{
				for (int d = 0;d < bufs4.size();d++)
				{
					for (int e = 0;e < bufs5.size();e++)
					{
						for (int f = 0;f < bufs6.size();f++)
						{
							buf.push_back(bufs1[a]);
							buf.push_back(bufs2[b]);
							buf.push_back(bufs3[c]);
							buf.push_back(bufs4[d]);
							buf.push_back(bufs5[e]);
							buf.push_back(bufs6[f]);
							for (int g = 0;g < 6;g++)
							{
								if (g == 5)
									cout << buf[g] << endl;
								else
									cout << buf[g] << ",";
							}
							z++;
							buf.clear();
						}
					}
				}
			}
		}
	}
	cout << endl;cout << "�`�@��" << z << "���զX" << endl;cout << endl;cout << "----------------------------------" << endl;
	bufs1.clear();
	bufs2.clear();
	bufs3.clear();
	bufs4.clear();
	bufs5.clear();
	bufs6.clear();
}
//-----------------------------------------------------------------------------------------
void OptionFourteen(string Test)//�����ɻ�
{
	vector<int>Rank;
	stringstream ss(Test);
	string token;
	while (getline(ss, token, ' '))
	{
		int v;
		stringstream st(token);
		st >> v;
		Rank.push_back(v);
	}
	if (Rank.size() < 6)
	{
		srand(time(NULL));
		while (Rank.size() != 6)
		{
			bool r = false;
			int a = (rand() % 100) + 1;
			for (int i = 0; i < Rank.size(); i++)
			{
				if (a == Rank[i] || a > 49)
					r = true;
			}
			if (r == false)
				Rank.push_back(a);
		}
		sort(Rank.begin(), Rank.end());
		for (int i = 0; i < Rank.size(); i++)
		{
			cout << Rank[i] << " ";
		}
	}
	else
		cout << "�A�L���O�S�ݨ�n�p��6�ӶܡI�I" << endl;
	cout << endl << "-----------------------------------------------" << endl; cout << endl;
}
//-------------------------------------------------------------------------------------------
void OptionFifteen(string Test)//�����z��
{
	srand(time(NULL));
	vector<int>random;
	vector<int>Rank;
	stringstream ss(Test);
	string token;
	while (getline(ss, token, ' '))
	{
		int v;
		stringstream st(token);
		st >> v;
		Rank.push_back(v);
	}
	if (Rank.size() > 6 && Rank.size() <= 10)
	{
		while (random.size() != 6)
		{
			bool r = false;
			int a = (rand() % 10) + 1;
			if (a > 0 && a < Rank.size())
			{
				if (random.size() == 0)
				{
					random.push_back(Rank[a - 1]);
				}
				else
				{
					for (int i = 0; i < random.size(); i++)
					{
						if (Rank[a - 1] == random[i])
							r = true;
					}
					if (r == false)
						random.push_back(Rank[a - 1]);
				}
			}
		}
		sort(random.begin(), random.end());
		for (int i = 0; i < random.size(); i++)
		{
			cout << random[i] << " ";
		}
	}
	else if (Rank.size() > 10 && Rank.size() <= 49)
	{
		while (random.size() != 6)
		{
			bool r = false;
			int a = (rand() % 100) + 1;
			if (a > 0 && a < Rank.size())
			{
				if (random.size() == 0)
				{
					random.push_back(Rank[a - 1]);
				}
				else
				{
					for (int i = 0; i < random.size(); i++)
					{
						if (Rank[a - 1] == random[i])
							r = true;
					}
					if (r == false)
						random.push_back(Rank[a - 1]);
				}
			}
		}
		sort(random.begin(), random.end());
		for (int i = 0; i < random.size(); i++)
		{
			cout << random[i] << " ";
		}
	}
	cout << endl << "-----------------------------------------------" << endl; cout << endl;
}
//--------------------------------------------------------------------------------
void OptionSixteen(vector<string> bufdays)//�� 7~11 �Ӹ��X�]�P(�C�X�Ҧ��զX)
{
	cin.ignore(1000,'\n');
	vector<string>buf;
	vector<string>asd;
	string s;
	int q = 0;
	getline(cin, s);
	string token;
	stringstream ss(s);
	while (getline(ss, token, ' '))
	{
		buf.push_back(token);
		asd.push_back(token);
	}
	cout << endl;cout << "�H�U���Ҧ��]�P���զX" << endl;cout << endl;
	if (buf.size() == 7)
	{
		for (int i = 0;i < buf.size();i++)
		{
			asd[i] = "0";
			for (int j = 0;j < buf.size();j++)
			{
				if (asd[j] != "0")
					cout << asd[j] << " ";
			}
			cout << endl;
			q++;
			for (int j = 0;j < buf.size();j++)
				asd[i] = buf[i];
		}
	}
	if (buf.size() == 8)
	{
		for (int i = 0;i < buf.size();i++)
		{
			for (int j = i + 1;j < buf.size();j++)
			{
				asd[i] = "0";
				asd[j] = "0";
				for (int k = 0;k < buf.size();k++)
				{
					if (asd[k] != "0")
						cout << asd[k] << " ";
				}
				cout << endl;
				q++;
				for (int k = 0;k < buf.size();k++)
					asd[k] = buf[k];
			}
		}
	}
	if (buf.size() == 9)
	{
		for (int i = 0;i < buf.size();i++)
		{
			for (int j = i + 1;j < buf.size();j++)
			{
				for (int k = j + 1;k < buf.size();k++)
				{
					asd[i] = "0";
					asd[j] = "0";
					asd[k] = "0";
					for (int l = 0;l < buf.size();l++)
					{
						if (asd[l] != "0")
							cout << asd[l] << " ";
					}
					cout << endl;
					q++;
					for (int l = 0;l < buf.size();l++)
						asd[l] = buf[l];
				}
			}
		}
	}
	if (buf.size() == 10)
	{
		for (int i = 0;i < buf.size();i++)
		{
			for (int j = i + 1;j < buf.size();j++)
			{
				for (int k = j + 1;k < buf.size();k++)
				{
					for (int l = k + 1;l < buf.size();l++)
					{
						asd[i] = "0";
						asd[j] = "0";
						asd[k] = "0";
						asd[l] = "0";
						for (int m = 0;m < buf.size();m++)
						{
							if (asd[m] != "0")
								cout << asd[m] << " ";
						}
						cout << endl;
						q++;
						for (int m = 0;m < buf.size();m++)
							asd[m] = buf[m];
					}
				}
			}
		}
	}
	if (buf.size() == 11)
	{
		for (int i = 0;i < buf.size();i++)
		{
			for (int j = i + 1;j < buf.size();j++)
			{
				for (int k = j + 1;k < buf.size();k++)
				{
					for (int l = k + 1;l < buf.size();l++)
					{
						for (int m = l + 1;m < buf.size();m++)
						{
							asd[i] = "0";
							asd[j] = "0";
							asd[k] = "0";
							asd[l] = "0";
							asd[m] = "0";
							for (int n = 0;n < buf.size();n++)
							{
								if (asd[n] != "0")
									cout << asd[n] << " ";
							}
							cout << endl;
							q++;
							for (int n = 0;n < buf.size();n++)
								asd[n] = buf[n];
						}
					}
				}
			}
		}
	}
	cout << endl;cout << "�`�@��" << q << "���զX" << endl;cout << endl;cout << "----------------------------------" << endl;
	buf.clear();
	asd.clear();
}
