#include <iostream>
#include <string.h>
using namespace std;

class shape
{

public:
virtual void draw()=0;
static shape* shapeFactory(string type);
};

class circle: public shape
{
public:
	void draw()
	{
	cout<<"\nCircle drawn.. ! ";
	}
	friend class shape;
};

class rectangle: public shape
{
public:
	void draw()
	{
	cout<<"\nrectangle drawn.. ! ";
	}
	friend class shape;
};
shape* shape::shapeFactory(string type)
	{
	if(type== "circle")
		return new circle();
	else if(type== "rectangle")
		return new rectangle();
	else
		cout<<"\n Sorry, We don't have required shape type..!";
	}
int main()
{
shape  *obj1, *obj2;
obj1= shape::shapeFactory("circle");
obj2= shape::shapeFactory("rectangle");
obj1->draw();
obj2->draw();

return 0;
}

