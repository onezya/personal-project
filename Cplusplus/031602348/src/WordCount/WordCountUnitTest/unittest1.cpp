#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/WordCount.h"
#include "../WordCount/putout.h"
#include "../WordCount/linecount.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
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
	void line(const int f)
	{
		if (f == 1) linesnum++;
	}
};
namespace WordCountUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			 linecount  * k;
			 int i;
			k->line(1);
			i = k->linesnum;
			Assert::AreEqual(i, 1); // TODO: 在此输入测试代码
		}

	};
}