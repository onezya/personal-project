#include<cstdlib>
#include<stdio.h>
#include<ctype.h>
#include<cstring>
#include<fstream>
#include<iostream>
#include "pch.h"
#include"linecount.h"
#include"putout.h"
#include"WordCount.h"

using namespace std;

struct word
{
	char name[30];
	int num;
	struct word *next;
};
class linecount
{
private:
	int linesnum;
public:
	linecount()
	{
		linesnum = 0;
	}
	void put()
	{
		cout << "lines" << ' ' << ':' << linesnum << endl;
	}
	void line(const int f)
	{
		if (f == 1) linesnum++;
	}
};
class wordcount
{
private:
	char ch, temp[30];
	int charnum, wordnum;
	int flag;
	struct word *p;
public:
	int flag1;
	wordcount()
	{
		charnum = 0;
		wordnum = 0;
		flag = 1;
		flag1 = 0;
	}
	void put()
	{
		cout << "characters" << ':' << ' ' << charnum << endl;
		cout << "words" << ':' << ' ' << wordnum << endl;
	}
	void readfile(struct word * &head)
	{
		FILE *fp;
		linecount l;
		if ((fp = fopen("in.txt" ,"r") )== NULL)
		{
			printf("无法打开此文件!\n");
			exit(0);
		}
		while (!feof(fp))
		{
			int i = 0;
			ch = fgetc(fp);
			if (ch != 32 && ch != 10 && ch != 9) flag1 = 1;
			temp[0] = ' ';                                //保证单词的开始一定是有效字符 
			do
			{
				charnum++;                              //统计字符数 
				if (ch >= 'a'&&ch <= 'z' || ch >= 'A'&&ch <= 'Z' || ch >= '0'&&ch <= '9')
				{
					if (ch >= 'A'&&ch <= 'Z')                //大写化小写 
					{
						temp[i] = ch - 32;
						i++;
					}
					else
					{
						temp[i] = ch;
						i++;
					}
					if (i <= 3 && ch >= '0'&&ch <= '9')  flag = 0;   //如果字符序列前四个有数字则不算单词 
				}
				ch = fgetc(fp);
				if (ch != 32 && ch != 10 && ch != 9) flag1 = 1;
				if (ch = 10)
				{
					l.line(flag1);
					flag1 = 0;
				}
				if (feof(fp))
				{
					charnum--;                            //多加了一个EOF 
					break;
				}
			} while (ch >= 'a'&&ch <= 'z' || ch >= 'A'&&ch <= 'Z' || ch >= '0'&&ch <= '9' || temp[0] == ' ');
			charnum++;
			temp[i] = '\0';
			p = head->next;
			while (p)                                  //链表里已经有单词了 
			{
				if (!strcmp(temp, p->name))
				{
					p->num++;
					wordnum++;
					break;
				}
				p = p->next;
			}
			if (!p&&temp[0] != '\0'&&flag == 1)                      //链表存了第一个单词 
			{
				p = new word;
				strcpy_s(p->name, temp);
				p->num = 1;
				wordnum++;
				p->next = head->next;
				head->next = p;
			}
			flag = 1;
		}
	}
};
class putout
{
private:
	int num[10];
	string name[10];
public:
	putout()
	{
		int i;
		for (i = 0; i < 10; i++)
		{
			num[i] = 0;
		}
	}
	void put()
	{
		int j = 0;
		for (j = 0; j < 10; j++)
		{
			printf("%s", name[j]);
			cout << ':' << ' ' << num[j] << endl;
		}
	}
	void sort(struct word*&head)
	{
		struct word *q;
		int i;
		for (i = 0; i < 10; i++)                       //将链表做排序，得出频率最高，字典顺序最靠前的10个 
		{
			q = head;
			while (q != NULL)
			{
				if (q->num > num[i])
				{
					num[i] = q->num;
					name[i] = q->name;
				}
				else
					if (q->name > name[i] && q->num == num[i])
					{
						name[i] = q->name;
					}
				q = q->next;
			}
		}
	}
};
int main()
{
	struct word *head;
	head = new word;
	head->next = NULL;
	wordcount w;
	linecount l;
	putout p;
	w.readfile(head);
	w.put();
	l.put();
	p.sort(head);
	p.put();
	return 0;
}