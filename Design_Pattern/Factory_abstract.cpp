#include <iostream>
#include <string>
using namespace std;
class mobile
{
public:
virtual string camera()=0;
virtaul string screen()=0;

void printSpec()
	{
	cout<< camera() <<endl;
	cout<< screen() <<endl;
	}
};

class samsung: public mobile
{
public: 
string camera()
	{
	return "13MP camera.";
	}
string screen()
	{
	return "5 inch screen";
	}
};
class lenova: public mobile
{
public:
	string camera()
	{
	return "16MP camera.";
	}
	string screen()
	{
	return "5.5 inch screen";
	}
};

class mobilefactory
{
public:
mobile* getMobile(string type);
};
mobile* mobilefactory::getMobile(string type)
	{
	if(type == "samsung") return new samsung();
	if(type == "lonova") return new lenova();
	return NULL;
	}


int main()
{
mobilefactory* m= new mobilefactory();
mobile* m1= m->getMobile("samsung");
m1->printSpec();
mobile* m2= m->getMobile("lenova");
m2->printSpec();
return 0;
}