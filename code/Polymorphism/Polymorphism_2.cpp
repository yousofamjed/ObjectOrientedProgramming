#include <iostream>

using namespace std;
/*
Virtual member function
	The default behavior of the activation of a member function via a pointer is that the type of the pointer determines the function (static binding).
	The dynamic binding is achieved with the virtual functions
	A function is virtual when its declaration starts with the keyword virtual.
	Once a function is declared virtual in a base class, its definition remains virtual in all derived classes.

	Syntax:
		virtual Ftype Fname(List_parameters);
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
	virtual void print()
	{
		cout << "X is " << x_ << " Y is " << y_ << endl;
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
	void print()
	{
		cout << "Radius is " << radius_ << endl;
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
	void print()
	{
		cout << "Vertical Radius is " << verticalRadius_<<" horizontal Radius is " << horizontalRadius_ << endl;
	}
};

void printAll(Shape *a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		//if virtual not used on print function inside the shape class then it will call the print from shape (parent) class
		//if virtual used on print function inside the shape class then it will call the print from each object class
		a[i]->print();
	}
}

int main()
{
	Shape s1(1, 1);
	CircularShape c1(2, 2, 5);
	Oval o1(10, 10, 5, 6);


	c1.print();//this will call the print from the circular shape class
	c1.Shape::print(); // this will call the print from the shape class

	Shape &ref2 = c1;
	Shape *ptr = &c1;

	//if the print function inside the shape (parent) calss not is defined as virtual then
	ref2.print();//this will call the print from the shape class since the ref2 is of type shape
	ptr->print();//this will call the print from the shape class since the ptr is of type shape

	//if the print function inside the shape (parent) calss is defined as virtual then
	ref2.print();//this will call the print from the CircularShape (child) class since the ref2 is of type shape
	ptr->print();//this will call the print from the CircularShape (child) class since the ptr is of type shape


	Shape* shapes[3] = { &s1,&c1,&o1 };
	printAll(shapes, 3);

}
