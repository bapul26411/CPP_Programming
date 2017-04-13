/*
Simple Single ton design pattern.
@Author: Kulamani Sethi
Date: 13-Apr-2017
*/
#include <iostream>
using namespace std;
class singleTon
{
private:
singleTon(){}
static singleTon *ptr;

public:
static singleTon createInstance(); 
};

singleTon *singleTon :: ptr= NULL;
singleTon singleTon::createInstance()
	{
	if(ptr == NULL)
		{
		ptr= new singleTon();
		cout<<"\nA singleTon instance created..";
		}
	else
		{
		cout<<"\nAlready singleTon instantiated";
		exit(0);
		}
	return *ptr; 
	}
int main()
{
singleTon *s1;
s1->createInstance();

singleTon *s2= singleTon::createInstance();

return 0;
}