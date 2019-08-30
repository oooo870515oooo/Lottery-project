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
void OptionOne(vector<vector<int> > &nums, int op1);//尋找近幾期冷球
void OptionTwo(vector<vector<int> > &nums, int op2);//尋找近幾期熱球
void OptionThree(vector<vector<int> > &nums, vector<string>&bufdays, vector<int>&buf, string s);//輸入日期找號碼
void OptionFour(string day4, vector<string> bufdays, vector<vector<int> > nums);//找某年某月的所有號碼
void OptionFive(int op5, vector<vector<int> > nums, vector<string>bufdays);//輸入數字找「最常」與他一起出現的號碼
void OptionSix(int op6, vector<vector<int> > nums, vector<string>bufdays);//輸入數字找「最不常」與他一起出現的號碼
void OptionSeven(string day7, vector<string> bufdays, vector<vector<int> > nums);//輸入日期和號碼對獎
void OptionNine(vector<int> &Random, int Test);//電腦選號
void OptionTen(int op10, int opp10, vector<vector<int> > nums, vector<string>bufdays);//輸入數字和期數找「近幾期最常」與他一起出現的號碼
void OptionEleven(int op11, int opp11, vector<vector<int> > nums, vector<string>bufdays);//輸入數字和期數找「近幾期最不常」與他一起出現的號碼
void OptionTwelve(vector<int> &Random, int Test);//擲筊問神明
void OptionThirteen(vector<string>bufdays);//立柱包牌法
void OptionFourteen(string Test);//部分補齊
void OptionFifteen(string Test);//部分篩選
void OptionSixteen(vector<string>bufdays);//選7~11個數包牌
int main()
{
	ifstream fin;
	fin.open("C:\\Users\\lin-book\\Documents\\lottery.txt");//雙引號內為路徑
	if (fin.fail())
	{
		cout << "Cannot open file" << endl;
		return 1;
	}
	cout << "第一組期末專題規範" << endl;
	cout << "樂透製造機" << endl;
	cout << "0.關閉樂透製造機" << endl;
	cout << "1.找近幾期的冷球" << endl;
	cout << "2.找近幾期的熱球" << endl;
	cout << "3.找某個日期的號碼(輸入日期，找號碼)" << endl;
	cout << "4.找某年，某月的所有號碼 (輸入年、月，列出所有號碼)" << endl;
	cout << "5.輸入 X 號碼，找「最常」與它一同出現的號碼前 5 名 (輸入 X 號碼)" << endl;
	cout << "6.輸入 X 號碼，找「最不常」與它一同出現的號碼前 5 名 (輸入 X 號碼)" << endl;
	cout << "7.輸入 日期，輸入 6 個號碼，輸出中幾碼" << endl;
	cout << "8.好手氣：推薦一組號碼" << endl;
	cout << "9.試試好手氣(一組電腦選號)" << endl;
	cout << "10.查詢某個數字「近幾期最常」與它一同出現的號碼前 5 名 (輸入 X 號碼)" << endl;
	cout << "11.查詢某個數字「近幾期最不常」與它一同出現的號碼前 5 名 (輸入 X 號碼)" << endl;
	cout << "12.擲筊問神明，請神明開示號碼" << endl;
	cout << "13.立柱包牌法" << endl;
	cout << "14.部分補齊(輸入不足6個號碼)" << endl;
	cout << "15.部分篩選(輸入大於6個號碼)" << endl;
	cout << "16.選 7~11 個號碼包牌(列出所有組合)" << endl;
	cout << endl;cout << endl;cout << "-------------------------------------------------" << endl;cout << endl;
	vector<vector<int> > nums;//數值
	vector<int> buf;
	vector<string>bufdays;//日期
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
		cout << "請問要查詢近幾期的冷球" << endl;
		int op1;
		cin >> op1;
		OptionOne(nums, op1);
	}
	else if (option == 2)
	{
		cout << "請問要查詢近幾期的熱球" << endl;
		int op2;
		cin >> op2;
		OptionTwo(nums, op2);
	}
	else if (option == 3)
	{
		cout << "請輸入日期(格式：2017/05/17)" << endl;
		string day3;
		cin >> day3;
		OptionThree(nums, bufdays, buf, day3);
	}
	else if (option == 4)
	{
		cout << "請輸入年、月(格式：2017/05)" << endl;
		string day4;
		getline(cin, day4);
		OptionFour(day4, bufdays, nums);
	}
	else if (option == 5)
	{
		cout << "請輸入一個號碼，我們將幫你找出「最常」與這個號碼一同出現的五個數字" << endl;
		int op5;
		cin >> op5;
		OptionFive(op5, nums,bufdays);
	}
	else if (option == 6)
	{
		cout << "請輸入一個號碼，我們將幫你找出「最不常」與這個號碼一同出現的五個數字" << endl;
		int op6;
		cin >> op6;
		OptionSix(op6, nums,bufdays);
	}
	else if (option == 7)
	{
		cout << "請輸入日期與6個號碼，我們將幫你核對中了幾個號碼" << endl;
		cout << "(日期格式：2017/05/17)" << endl;
		string day7;
		OptionSeven(day7, bufdays, nums);
	}
	else if (option == 8)
	{
		cout << "讓我看看！！這期最推薦你的號碼" << endl;
	}
	else if (option == 9)
	{
		cout << "隨機選號" << endl;
		vector<int> Random;
		int i = 0;
		OptionNine(Random, i);
	}
	else if (option == 10)
	{
		cout << "我們將幫你找出「近幾期最常」與這個號碼一同出現的五個數字，請先輸入想搜尋近幾期的數字，再輸入號碼" << endl;
		int op10,opp10;
		cin >> opp10>>op10;
		OptionTen(op10,opp10, nums, bufdays);
	}
	else if (option == 11)
	{
		cout << "我們將幫你找出「近幾期最不常」與這個號碼一同出現的五個數字，請先輸入想搜尋近幾期的數字，再輸入號碼" << endl;
		int op11, opp11;
		cin >> opp11 >> op11;
		OptionEleven(op11, opp11, nums, bufdays);
	}
	else if (option == 12)
	{
		cout << "顯靈！！" << endl;
		vector<int>Random;
		int i = 0;
		OptionTwelve(Random, i);
	}
	else if (option == 13)
	{
		cout << "一、選擇可能會出現的號碼。" << endl;
		cout << "    彩迷要由 1~49 個號碼(以大樂透為例) 中選出若干個在下期很有機會會出現的號碼。" << endl;
		cout << "二、選擇可能會出現的號碼。" << endl;
		cout << "    接著彩迷會設立 6 個柱子，並把選出的號碼分別歸類到不同的柱子上。每個柱子至少會有一個數字。" << endl;
		cout << endl;
		cout << "※輸入數字時請以逗點隔開" << endl;
		OptionThirteen(bufdays);
	}
	else if (option == 14)
	{
		cout << "請輸入數字(需小於6個)" << endl;
		string op14;
		cin.ignore(1000, '\n');
		getline(cin, op14);
		OptionFourteen(op14);
	}
	else if (option == 15)
	{
		cout << "請輸入數字(需大於6個)" << endl;
		string op15;
		cin.ignore(1000, '\n');
		getline(cin, op15);
		OptionFifteen(op15);
	}
	else if (option == 16)
	{
		cout << "請輸入您想包牌的7到11個號碼" << endl;
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
void OptionOne(vector<vector<int>>& nums, int op1)//尋找近幾期冷球
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
void OptionTwo(vector<vector<int>>& nums, int op2)//尋找近幾期熱球
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
void OptionThree(vector<vector<int>> &nums, vector<string>&bufdays, vector<int>&buf, string s)//輸入日期找號碼
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
void OptionFour(string day4, vector<string> bufdays, vector<vector<int> > nums)//找某年某月的所有號碼
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
		cout << "查無此資料" << endl;
	cout << "-----------------------------------------------" << endl;
}
//---------------------------------------------------------------------------------
void OptionFive(int op5, vector<vector<int> > nums, vector<string>bufdays)//輸入數字找「最常」與他一起出現的號碼
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
void OptionSix(int op6, vector<vector<int> > nums,vector<string>bufdays)//輸入數字找「最不常」與他一起出現的號碼
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
		cout << "樂透數值輸入錯誤，請重新嘗試" << endl;	
	}
	cout << endl;
	cout << "-----------------------------------------------" << endl;
}
//------------------------------------------------------------------------------
void OptionSeven(string day7, vector<string> bufdays, vector<vector<int>> nums)//輸入日期和號碼對獎
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
		cout << "當期共中了" << t << "個號碼" << endl;
	else
		cout << "無此資料" << endl;
	cout << "-----------------------------------------------" << endl;
}
//------------------------------------------------------------------------------

void OptionNine(vector<int>& Random, int Test)//一組電腦選號
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
void OptionTen(int op10, int opp10, vector<vector<int> > nums, vector<string>bufdays)//輸入數字和期數找「近幾期最常」與他一起出現的號碼
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
void OptionEleven(int op11, int opp11, vector<vector<int> > nums, vector<string>bufdays)//輸入數字和期數找「近幾期最常」與他一起出現的號碼
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
void OptionTwelve(vector<int> &Random, int Test)//擲筊問神明
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
			cout << "文昌帝君" << endl;
			cout << "誕辰日：農曆2月3日" << endl;
			cout << "  文昌帝君又稱為[梓潼帝君]，相傳是天上的文曲星的化身,是讀書人的主宰神。" << endl;cout << endl;
			cout << "推薦幸運號碼：2、3" << endl;cout << "-----------------------------------------------" << endl;cout << endl;
		}
		else if (buf[i] == 2)
		{
			cout << "觀世音菩薩" << endl;
			cout << "誕辰日：農曆2月19日" << endl;
			cout << "  在民間許多人信奉觀世音菩薩，許多婦女會在觀世音菩薩生日前夕開始吃素，為表示虔誠。" << endl;cout << endl;
			cout << "推薦幸運號碼：2、19" << endl;cout << "-----------------------------------------------" << endl;cout << endl;
		}
		else if (buf[i] == 3)
		{
			cout << "海上守護者媽祖" << endl;
			cout << "誕辰日：農曆3月23日" << endl;
			cout << "  媽祖就是〔天上聖母〕，一般通稱〔媽祖〕或〔媽祖婆〕，是大陸沿海一帶人民普遍信奉的神。" << endl;cout << endl;
			cout << "推薦幸運號碼：3、23" << endl;cout << "-----------------------------------------------" << endl;cout << endl;
		}
		else if (buf[i] == 4)
		{
			cout << "神農大帝" << endl;
			cout << "誕辰日：農曆4月26日" << endl;
			cout << "  遍嘗百草，普對各種藥草做田野調查研究，所以又被稱為『藥王大帝』。" << endl;cout << endl;
			cout << "推薦幸運號碼：4、26" << endl;cout << "-----------------------------------------------" << endl;cout << endl;
		}
		else if (buf[i] == 5)
		{
			cout << "玄天上帝" << endl;
			cout << "誕辰日：農曆3月3日" << endl;
			cout << "  在民間傳說中玄天上帝腳踏龜蛇二將，手持七星寶劍，具有消災解厄治水禦火延年益壽的神力。" << endl;cout << endl;
			cout << "推薦幸運號碼：3" << endl;cout << "-----------------------------------------------" << endl;cout << endl;
		}
		else if (buf[i] == 6)
		{
			cout << "關聖帝君關公" << endl;
			cout << "誕辰日：農曆6月24日" << endl;
			cout << "  關聖帝君，三國時代蜀漢的大將關羽，字云長，美須髯，武勇絕倫，與劉備、張飛結義于桃園，即所謂桃園三結義。" << endl;cout << endl;
			cout << "推薦幸運號碼：6、24" << endl;cout << "-----------------------------------------------" << endl;cout << endl;
		}
		else if (buf[i] == 7)
		{
			cout << "福德正神土地公" << endl;
			cout << "誕辰日：農曆8月15日" << endl;
			cout << "  月下老人，又稱月老公、月老，是道教的神祇之一，為掌管男女婚姻之神，相傳為「媒神」。" << endl;cout << endl;
			cout << "推薦幸運號碼：8、15" << endl;cout << "-----------------------------------------------" << endl;cout << endl;
		}
		else if (buf[i] == 8)
		{
			cout << "中壇元帥三太子" << endl;
			cout << "誕辰日：農曆9月9日" << endl;
			cout << "  身長六丈、頭戴金輪、三個頭、九隻眼、八條手臂、口吐青雲。" << endl;cout << endl;
			cout << "推薦幸運號碼：9、9" << endl;cout << "-----------------------------------------------" << endl;cout << endl;
		}
		else if (buf[i] == 9)
		{
			cout << "耶穌" << endl;
			cout << "誕辰日：國曆12月25日" << endl;
			cout << "  為了讓基督教能廣泛被接受，教會選在12月25日慶祝耶穌的誕生。 之後基督教傳遍西歐，聖誕節的傳統就這樣流行了起來。" << endl;cout << endl;
			cout << "推薦幸運號碼：12、25" << endl;cout << "-----------------------------------------------" << endl;cout << endl;
		}
	}
}
//--------------------------------------------------------------
void OptionThirteen(vector<string> bufdays)//立柱包牌法
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
	cout << "第一個柱子" << endl;
	getline(cin, s1);
	cout << "第二個柱子" << endl;
	getline(cin, s2);
	cout << "第三個柱子" << endl;
	getline(cin, s3);
	cout << "第四個柱子" << endl;
	getline(cin, s4);
	cout << "第五個柱子" << endl;
	getline(cin, s5);
	cout << "第六個柱子" << endl;
	getline(cin, s6);
	cout << "以下為立柱包牌法的所有組合" << endl;
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
	cout << endl;cout << "總共有" << z << "筆組合" << endl;cout << endl;cout << "----------------------------------" << endl;
	bufs1.clear();
	bufs2.clear();
	bufs3.clear();
	bufs4.clear();
	bufs5.clear();
	bufs6.clear();
}
//-----------------------------------------------------------------------------------------
void OptionFourteen(string Test)//部分補齊
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
		cout << "你他媽是沒看到要小於6個嗎！！" << endl;
	cout << endl << "-----------------------------------------------" << endl; cout << endl;
}
//-------------------------------------------------------------------------------------------
void OptionFifteen(string Test)//部分篩選
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
void OptionSixteen(vector<string> bufdays)//選 7~11 個號碼包牌(列出所有組合)
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
	cout << endl;cout << "以下為所有包牌的組合" << endl;cout << endl;
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
	cout << endl;cout << "總共有" << q << "筆組合" << endl;cout << endl;cout << "----------------------------------" << endl;
	buf.clear();
	asd.clear();
}
