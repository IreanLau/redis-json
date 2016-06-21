#pragma once

#include<iostream>
#include<string>
#include<json/json.h>


using namespace std;

#define G_BLOCK_SZIE 1024

class my_json{
	public:
		my_json();
		~my_json();
		static int _serialize(Json::Value &_in_val,std::string& str_out);
		static int _deserialize(string &_in_val,Json::Value& _val_out);
};

my_json::my_json()
{

}
my_json::~my_json()
{

}

int my_json::_serialize(Json::Value &_in_val,std::string& str_out)
{
#ifdef _STYLE_
	Json::StyleWriter _write;
#else
	Json::FastWriter _write;
#endif

	str_out = _write.write(_in_val);
	return 0;
}

int my_json::_deserialize(std::string&_in_val,Json::Value& _val_out)
{
	Json::Reader _reader;
	if(_reader.parse(_in_val,_val_out,false) )
		return 0;
	else
		return 1;
}

