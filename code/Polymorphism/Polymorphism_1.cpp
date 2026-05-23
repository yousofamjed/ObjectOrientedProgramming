
#include <iostream>

using namespace std;
/*
a. What Is the Polymorphism
	 It is the ability for objects of different classes to
	 respond differently to the same function call.
b. Important Use:
	Treating derived class members just like their parent class' members.
c. The polymorphism  in the object-oriented programming theory, is the ability of objects belonging to different types to respond to method calls of the same name, each one according to an appropriate type-specific behavior.

*/
class Shape
{
private:
	int x_;
	int y_;
	
public:
	Shape(int x, int y)
	{
		x_ = x;
		y_ = y;
	}
	int getX()
	{
		return x_;
	}
	int getY()
	{
		return y_;
	}
};

class CircularShape:public Shape
{
private:
	int radius_;
public:
	CircularShape(int x, int y, int r) :Shape(x, y)
	{
		radius_ = r;
	}
	int getRadius()
	{
		return radius_;
	}
	void setRadius(int r)
	{
		radius_ = r;
	}
};

class Oval:public Shape
{
private:
	int horizontalRadius_;
	int verticalRadius_;
public:
	Oval(int x, int y, int h, int v):Shape(x,y)
	{
		horizontalRadius_ = h;
		verticalRadius_ = v;
	}
	int getHorizontalRadius()
	{
		return horizontalRadius_;
	}
	void setHorizontalRadius(int r)
	{
		horizontalRadius_ = r;
	}
	int getVerticalRadius()
	{
		return verticalRadius_;
	}
	void setVerticalRadius(int r)
	{
		verticalRadius_ = r;
	}
};


//The advantage of using polimorphism is to define single function that takes parameter with parent data type to compare any two objects with different types instead of 
//creating many functions that takes each parameter type to compare such as (shape with shape), (shape with oval), (shape with circular),(circular with oval),
//(circular with circular),(oval with oval) ...etc
bool isSamePosition(Shape& s1, Shape& s2)
{
	if (s1.getX() == s2.getX() && s1.getY() == s2.getY())
		return true;
	else
		return false;
}

int main()
{
	//references
	int x = 5;
	int y = 7;

	int &xref1 = x;//create another name for variable x
	int &xref2 = x;//create another name for variable x
	cout << xref1 << endl;//prints the data inside xref1 which is x
	xref2 = 8;//replace the value inside xref2 with value 8, this will change the value of variable x

	//int& ref3; error, you have to put the referenced variable

	xref1 = y;//this will not change the reference from x to y, it will replace the value inside xref1 with the value of y


	int * xptr = &x;//this will create a pointer that points to a location x



	Shape s1(1, 1);
	CircularShape c1(2, 2, 5);
	Oval o1(10, 10, 5, 6);


	Shape& ref1 = s1;
	Shape& ref2 = c1;//circular shape is a shape
	Shape& ref3 = o1;//oval shape is a shape


	cout << s1.getX() << endl;
	cout << ref1.getX() << endl;//the same as the previous line since they are the same variable

	//CircularShape& ref4 = s1; error, s1 is of type shape not circularShape, the shape is not a circular shape

	CircularShape& c2 = c1;

	c2.getRadius();
	//ref2.getRadius(); error, ref2 is of type shape not a cirular shape, so you cant access a member function not inside the shape class


	Shape* ptr1 = &s1;
	Shape* ptr2 = &c1;
	Shape* ptr3 = &o1;

	//CircularShape* cptr = &s1; error, shape is not a circular shape

	cout << ptr2->getX() << endl;
	cout << (*ptr2).getX() << endl;



	bool flag;
	flag = isSamePosition(s1, s1);
	flag = isSamePosition(s1, c1);
	flag = isSamePosition(s1, o1);
	flag = isSamePosition(c1, s1);
	flag = isSamePosition(c1, c1);
	flag = isSamePosition(c1, o1);
	flag = isSamePosition(o1, s1);
	flag = isSamePosition(o1, c1);
	flag = isSamePosition(o1, o1);

}
