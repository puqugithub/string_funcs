#include "str_functs.h"
#include <iostream>
#include <string>
#include <string.h>
using namespace CPPCOMMON;

int main()
{
	cout << "\n#===========Demo===========#\n" << endl;

	//string_format		格式化string类型
	string str = "nanjing";
	cout << "string_format()的结果：" << string_format( "This is [%s].\n", str.c_str() ) << endl;
	cout << endl;

	//StripStr	删除首部和尾部的'\n'和'\t'	string StripStr(const string& str, const string& patternstr = " \n\t");
	str = "nanjing    ";
	cout << "StripStr( str )之前：" << str << "$" << endl;
	cout << "StripStr( str )之后：" << StripStr( str ) << "$" << endl;
	cout << endl;


	//JoinStr	把vec中的字符串用指定的连接符串起来	string JoinStr(const vector<string>& source, const string& connector);
	vector< string > vec;
	vec.push_back( "nanjing" );
	vec.push_back( "yangzhou" );
	vec.push_back( "hangzhou" );
	
	string res = JoinStr( vec, "-" );
	cout << "JoinStr( vec, connector )的结果：" << res << endl;
	cout << endl;
	

	
	return 0;
}
