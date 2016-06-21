#include "redisclient.h"
#include "anet.h" 
#include"my_json.h"
#include <iostream>  
#include<string>
#include <boost/date_time.hpp>  
using namespace boost;  
using namespace std;  
shared_ptr<redis::client> connect_client();  


int main()  
{
	shared_ptr<redis::client> c = connect_client();
//	c->rpush("setval","hello");
//	redis::client::string_vector vals;
//	long num=c->get_list("setval",vals);

//	for(int i=0;i<vals.size();++i)
//		cout<<vals[i]<<endl;

	Json::Value _val;
	string _out;
	
	_val["nick_name"]="fly pig";
	_val["school"]="XATU";
	_val["msg"]="niaho";

	my_json::_serialize(_val,_out);
	cout<<"after serialize:> "<<_out<<endl;
	
	int id=0;
	string idPrefix="set";
	char suffix[20];

	sprintf(suffix,"%d",id);
	//cout<<"~~~~~~~~~~~~"<<suffix<<endl;
	idPrefix+=suffix;
	//cout<<"____________"<<idPrefix<<endl;
	c->set(idPrefix,_out);
	string s = c->get(idPrefix);
	cout<<"get idInfo form redis:> "<<s<<endl;
	
	Json::Value _val_out;
	my_json::_deserialize(s,_val_out);
	cout<<"after _deserialize"<<endl;
	cout<<_val_out["nick_name"]<<endl;
	cout<<_val_out["school"]<<endl;
	cout<<_val_out["msg"]<<endl;

	return 0;
}

shared_ptr<redis::client> connect_client()
{
	const char* c_host = getenv("REDIS_HOST");
	string host = "localhost";
	if(c_host)
		host = c_host;

	return boost::shared_ptr<redis::client>(new redis::client(host));
}
