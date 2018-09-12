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
class linecount
{

public:
	int linesnum;
	linecount()
	{
		linesnum = 0;
	}
	void put()
	{
		cout << "lines" << ' ' << ':' << linesnum << endl;
	}
	int line(const int f)
	{
		if (f == 1) linesnum++;
		return linesnum;
	}
};