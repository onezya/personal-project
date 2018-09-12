#include"core.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<fstream>
#include<string>
#include<map>
using namespace std;

int characters = 0;
int lines = 0;
int words = 0;

struct SortByValue {
	bool operator()(const pair<string, int> & a, const pair<string, int> & b) {
		if (a.second == b.second) {
			return a.first < b.first;
		}
		else return a.second > b.second;
	}
};

void CountCharacters(ifstream& filemm)//ͳ���������ַ���
{
	char c;
	char lastline = '\0';

	while (filemm.get(c))
	{
		characters++;
		if (lastline != '\n'&&c == '\n')
		{
			lines++;
		}
		if (lastline == '\n' && (c == '\t' || c == ' '))
		{
			lastline = '\n';
		}
		else
		{
			lastline = c;
		}
	}

	if ((c == '\t' || c == ' ') && (lastline == '\t' || lastline == ' '))
	{
		lastline = c;
	}
	//����ı����һ���ַ��ǻ��з�����ǰһ���ַ��ǻ��з���ǰ�ַ��ǿո�Ҫ��ȥһ��
	else if (c == '\n' || (lastline = '\n' && (c == '\t' || c == ' ')))
	{
		lines--;
	}

	lines++;

}

void CountWord(ifstream& filemm, map<string, int>& mapp)//ͳ�ƴ�����Ƶ
{
	string s;
	vector<int> ans;//��ָ���λ��

	while (filemm >> s) //һ�ζ�ȡһ���ַ�������ȡ�ַ������������кͿո���Ʊ��
	{

		ans.clear();

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= 65 && s[i] <= 90)
			{
				s[i] += 32;
			}
			if (s[i] < 48 || (s[i] > 57 && s[i] < 65) || (s[i] > 90 && s[i] < 97) || s[i]>122)
			{
				ans.push_back(i);
			}
		}

		if (ans.size() == 0)//����ָ����Ŀ����0������ֻ��һ���ַ���
		{
			//����Ӹ÷������ĸ��ַ�������ĸ
			if ((s[0] >= 97 && s[0] <= 122) && (s[1] >= 97 && s[1] <= 122) && (s[2] >= 97 && s[2] <= 122) && (s[3] >= 97 && s[3] <= 122))
			{
				mapp[s]++;
				words++;
			}
			continue;
		}

		//�������һ�����ϵķָ���
		//���жϵ�һ������Ϊ��һ��û�зָ�������ͷ���
		if ((s[0] >= 97 && s[0] <= 122) && (s[1] >= 97 && s[1] <= 122) && (s[2] >= 97 && s[2] <= 122) && (s[3] >= 97 && s[3] <= 122))
		{
			string temp(s.substr(0, ans[0]));//����ǰ�ĸ��ַ�����ĸ����ȡ
			mapp[temp]++;
			words++;
		}

		for (int i = 0; i < ans.size(); i++)
		{
			//����ָ������ĸ��ַ�����ĸ
			if ((s[ans[i] + 1] >= 97 && s[ans[i] + 1] <= 122) && (s[ans[i] + 2] >= 97 && s[ans[i] + 2] <= 122) &&
				(s[ans[i] + 3] >= 97 && s[ans[i] + 3] <= 122) && (s[ans[i] + 4] >= 97 && s[ans[i] + 4] <= 122))
			{
				string temp(s.substr(ans[i] + 1, ans[i + 1] - ans[i] - 1));
				mapp[temp]++;
				words++;
			}
		}
	}
}

void SortWord(map<string, int>& mapp) //��Ƶ����
{
	vector<pair<string, int>> v(mapp.begin(), mapp.end());
	sort(v.begin(), v.end(), SortByValue());
	int vecflag = 0;
	for (vector<pair<string, int>>::iterator vec = v.begin(); vec != v.end(); vec++)
	{
		cout << "<" << vec->first << ">: " << vec->second << endl;
		vecflag++;
		if (vecflag == 10) break;
	}

}