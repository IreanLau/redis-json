#include"my_json.h"


int main()
{
	Json::Value _val;
	string _str_out;
	_val["nick_name"]="fly pig";
	_val["school"]="XATU";
	_val["msg"]="nihao";
	my_json::_serialize(_val, _str_out);
	cout<<_str_out<<endl;
	return 0;
}

