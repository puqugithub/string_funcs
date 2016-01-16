/************************************
 * file enc : utf8
************************************/
#ifndef CPPCOMMON_STR_FUNCTS_H
#define CPPCOMMON_STR_FUNCTS_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>
#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>  //读取可变参数的头文件
#include <iconv.h>
#include <memory.h>
#include "typedefs.h"
namespace CPPCOMMON
{
	using namespace std;

	std::string string_format(const std::string fmt, ...) ;

	string JoinStr(const vector<string>& source, const string& connector);

	vector<string> SplitStr(const string& source, const string& pattern = " \t\n");

	void SplitStr(const string& source, vector<string>& out_vec, const string& pattern = " \t\n");

	string UpperStr(const string& str);

	string LowerStr(const string& str);

	string ReplaceStr(const string& strSrc, const string& oldStr, const string& newStr, int count = -1);
	string StripStr(const string& str, const string& patternstr = " \n\t");

	unsigned int CountStrDistance(const string& A, const string& B);

	unsigned int CountStrSimilarity(const string& A, const string& B);

	
}
#endif
