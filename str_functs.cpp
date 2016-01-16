/************************************
 * file enc : utf8
************************************/
#include "str_functs.h"

namespace CPPCOMMON
{
	std::string string_format(const std::string fmt, ...) 
	{
		int size = 100;
		std::string str;
		va_list ap;
		while (1) {
			str.resize(size);
			va_start(ap, fmt);  //第一个可选参数地址
			int n = vsnprintf((char *)str.c_str(), size, fmt.c_str(), ap);
			va_end(ap);  //让指针无效
			if (n > -1 && n < size) {
				str.resize(n);
				return str;
			}
			if (n > -1)
				size = n + 1;
			else
				size *= 2;
		}
		return str;
	}

	string JoinStr(const vector<string>& src, const string& connectorStr)
	{
		string res = "";
		int len = src.size();
		if(0 == len)
		{
			return "";
		}
		for(int i = 0; i < len - 1; i++)
		{
			res += StripStr(src[i]);
			res += connectorStr;
		}
		res += StripStr(src[len-1]);
		return res;
	}
	vector<string> SplitStr(const string& source, const string& pattern)
	{
		vector<string> res;
		SplitStr(source, res, pattern);
		return res;
	}

	void SplitStr(const string& source, vector<string>& out_vec, const string& pattern)
	{
		if(0 == pattern.size())
		{
			return;
		}
		string s = source + pattern;  //先在字符串最后串联一个pattern
		string::size_type pos;  //和string的大小同样的类型
		uint length = s.size();

		for(uint i = 0; i < length; i++)
		{
			pos = s.find_first_of(pattern, i);  //从i开始查找
			if(pos < length)
			{
				string tmp = StripStr(s.substr(i, pos - i));  //substr
				if("" != tmp)
				{
					out_vec.push_back(tmp);
				}
				if( pattern == " \t\n" )
					i = pos + 1 - 1;
				else
					i = pos + pattern.size() - 1;
			}
		}
	}

	string StripStr(const string& str, const string& patternStr)
	{
		if(str.empty())
		{
			return str;
		}
		string::size_type posL = str.find_first_not_of(patternStr);
		if(string::npos == posL)
		{
			return str;
		}
		string::size_type posR = str.find_last_not_of(patternStr);
		return str.substr(posL, posR - posL + 1);

	}
	

	string UpperStr(const string& strIn)
	{
		string str = strIn;
		//transform函数：http://blog.sina.com.cn/s/blog_8ec0965801012szd.html
		//http://www.cnblogs.com/KeenLeung/archive/2013/03/17/2965192.html
		//功能非常强大，有两种重载的方式，最后一个参数op是可自定义的
		transform(str.begin(), str.end(), str.begin(), (int (*)(int))toupper);
		return str;
	}

	string LowerStr(const string& strIn)
	{
		string str = strIn;
		transform(str.begin(), str.end(), str.begin(), (int (*)(int))tolower);
		return str;
	}

	string ReplaceStr(const string& strSrc, const string& oldStr, const string& newStr, int count)
	{
		string strRet = strSrc;
		size_t pos = 0;
		int l_count = 0;
		if(-1 == count)
			count = strRet.size();
		while((pos = strRet.find(oldStr, pos)) != string::npos)
		{
			strRet.replace(pos, oldStr.size(), newStr);  //替换
			if(++l_count >= count)
			  break;
			pos += newStr.size();
		}
		return strRet;
	}

	unsigned int CountStrDistance(const string& A, const string& B)
	{
		unsigned int lenA = A.size();
		unsigned int lenB = B.size();
		unsigned int len = (lenA < lenB ? lenA : lenB);
		unsigned int res = lenA + lenB - 2 * len;  //距离的len
		for(size_t i = 0; i < len; i++)
		{
			if(A[i] != B[i])  //字符的len
			  res++;
		}
		return res;
	}

	unsigned int CountStrSimilarity(const string& A, const string& B)
	{
		unsigned int lenA = A.size();
		unsigned int lenB = B.size();
		unsigned int len = (lenA < lenB ? lenA : lenB);
		unsigned int res = 0;
		for(size_t i = 0; i < len; i++)
		{
			if(A[i] == B[i])
			  res++;
		}
		return res;
	}

}

#ifdef TEST_STR_FUNCTS
#include <iostream>
using namespace CPPCOMMON;
using namespace std;
int main()
{
	//string s = " \t\n1 a h \n";
	//cout<<"["<<stripStr(s)<<"]"<<endl;
	//cout<<countStrDistance("Aheheh","heheh1212")<<endl;
	//cout<<joinStr(splitStr(s), ",")<<endl;
	//vector<string> vec;
	//splitStr("1 3 4", vec);
	//char * a[] = {"3","jaj","ads"};
	//vector<string> pats(a,a+3);
	//vec.clear();
	//splitStrMultiPattern("1 #3 jajs5 asdf3ads 4", vec, pats);
	//for(int i=0;i<vec.size();i++)
	//{
	//	cout<<vec[i]<<endl;
	//}
	//string s = "1111aaafasfa,asdj.sadhashfhaha";
	//upperStr(s);
	//cout<<s<<endl;
	//
	//s = "ab1ba2ab3";
	//cout<<replaceStr(s,"ab","###")<<endl;
    //ifstream ifile("testdata/dict.txt");
    //string line;
    //while(getline(ifile, line))
    //{
    //    uint16_t strbuf[1024];

    //    size_t unilen = utf8ToUnicode(line.c_str(), line.size(), strbuf);
    //    for(int i = 0; i < unilen; i++)
    //    {
    //        // printf("%x\n", strbuf[i]);
    //    }
    //    char utf8str[512]={0};
    //    unicodeToUtf8(strbuf, unilen, utf8str);
    //    //cout<<strlen(utf8str);
    //    cout<<utf8str<<endl;
    //}
	//cout<<string_format("hehe%s11asd%dasf","[here]",2);
	ifstream ifile("testdata/dict.gbk");
	string line;
	Unicode unicode;
	while(getline(ifile, line))
	{
		cout<<line<<endl;
		utf8ToUnicode(line, unicode);
		printUnicode(unicode);
		cout<<unicodeToUtf8(unicode)<<endl;;
	}
	//vector<string> tmp;
	//tmp.push_back("1");
	////tmp.push_back("2");
	////tmp.clear();
	//cout<<joinStr(tmp, ",")<<endl;
	//ifstream ifile("testdata/dict.gbk");
	//string line;
	//while(getline(ifile, line))
	//{
	//	cout<<line<<endl;
	//	string s = gbkToUtf8(line);
	//	s = utf8ToGbk(s);
	//	cout<<s<<endl;
	//}
	return 0;
}
#endif
