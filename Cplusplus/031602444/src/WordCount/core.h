#pragma once
#ifndef _CORE_H
#define _CORE_H    
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<fstream>
#include<string>
#include<vector>
#include<map>

using namespace std;

void CountCharacters(ifstream& filemm);//ͳ���������ַ���
void CountWord(ifstream& filemm, map<string, int>& mapp);//ͳ�ƴ�����Ƶ
void SortWord(map<string, int>& mapp);//��Ƶ����

#endif