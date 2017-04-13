#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Iobserver
{
public:
	virtual void Update(float price) = 0;
};

class Shop: Iobserver
{
string name;
float price;
public:
	Shop (string n) {this->name = n;}
	void Update(float price) 
		{
		this->price= price;
		cout<<"Price at " << name <<"is now: " << price <<endl;
		}
};

class Asubject
{
vector<Shop*> list;
public:
	void Attach(Shop *product);
	void Detach(Shop *product);
	void Notify(float price);
};

void Asubject:: Attach (Shop *shop)
	{
	list.push_back(shop);
	}

void Asubject:: Detach (Shop *shop)
	{
    list.erase(std::remove(list.begin(), list.end(), shop), list.end());   
	cout<< "\n Sope has been removed !"<< endl ;
	}
void Asubject:: Notify(float price)
	{
	for(vector<Shop *>::const_iterator itr= list.begin(); itr != list.end(); ++itr)
		{
		if(*itr != 0)
			{
			(*itr)->Update(price);
			}
		
		}
	
	}
class DummyProduct: public Asubject
	{
	public:
	void Changeprice(float price) 
		{ Notify(price);}
	};
	
int main()
{
DummyProduct product;
Shop shop1("ArinaMarket Shop");
Shop shop2("Vishal mall Shop");

product.Attach(&shop1);
product.Attach(&shop2);
product.Changeprice(100.34f);

//product.Detach(&shop2);

return 0;
}