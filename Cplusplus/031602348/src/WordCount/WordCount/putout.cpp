#include<cstdlib>
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
			cout << "name[j]" << ':' << ' ' << num[j] << endl;
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