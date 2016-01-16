#include "str_functs.h"
#include <iostream>
#include <string>
#include <string.h>
using namespace CPPCOMMON;

void PrintVec( vector<string> vec );

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
	

	//Split		划分字符串	vector<string> SplitStr(const string& source, const string& pattern)
	vec.clear();
	str = "nanjing\tyangzhou\tshanghai";
	vec = SplitStr( str, "\t" );
	//vec = SplitStr( str );  //默认为" ", "\t", "\n"其中一个，而且只能默认一个
	cout << "SplitStr()的结果为:" << endl;
	PrintVec( vec );
	cout << endl;


	//UpperStr	字母大写	string UpperStr(const string& strIn)
	str = "nanjing";
	cout << "UpperStr()之后的结果为：" << UpperStr( str ) << endl;
	cout << endl;


	//LowerStr	字母小写	string LowerStr(const string& strIn)
	str = "NanJing";
	cout << "LowerStr()之后的结果为：" << LowerStr( str ) << endl;
	cout << endl;


	//ReplaceStr	替换前几个字符串	string ReplaceStr(const string& strSrc, const string& oldStr, const string& newStr, int count)
	str = "beijingbeijingnanjingbeijing";
	string oldStr = "bei";
	string newStr = "nan";
	int count = 2;
	res = ReplaceStr( str, oldStr,newStr, 2 );  //只替换前2个"bei"
	cout << "ReplaceStr替换str之前：" << str << endl;
	cout << "replaceStr替换str之后：" << res << endl;
	cout << endl;


	//CountStrDistance	计算两个字符串间的距离		unsigned int CountStrDistance(const string& A, const string& B)
	string strA = "beijing";
	string strB = "nanjing";
	string strC = "yangzhou";
	cout << "CountStrDistance( nanjing => beijing ): " <<CountStrDistance( strA, strB ) << endl;
	cout << "CountStrDistance( nanjing => 'yangzhou ): " <<CountStrDistance( strC, strB ) << endl;
	cout << endl;


	//CountStrSimilarity		计算两个字符串间的相似个数	unsigned int CountStrSimilarity(const string& A, const string& B)
	cout << "CountStrSimilarity( nanjing => beijing ): " <<CountStrSimilarity( strA, strB ) << endl;
	cout << "CountStrSimialrity( nanjing => 'yangzhou ): " <<CountStrSimilarity( strC, strB ) << endl;
	cout << endl;

	
	return 0;
}




void PrintVec( vector<string> vec )
{
	vector< string >::iterator iter = vec.begin();
	for( ; iter != vec.end(); iter++ )
	{
		cout << *iter << endl;
	}
}
