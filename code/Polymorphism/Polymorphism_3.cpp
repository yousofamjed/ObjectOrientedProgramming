#include <iostream>

using namespace std;
/*
Pure virtual function
	The base class can contain its own implementation of the virtual function.
	In C++, It is however possible only to mention virtual functions in a base class without defining it (without implementation). This kind of virtual function is called pure virtual function.
	A base class containing pure virtual functions are called abstract classes
	A pure virtual function declaration is ended by =0 in the base class.

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

	//not pure virtual
	//virtual double area() { return 0.0; }

	//pure virtual
	virtual double area()=0;

};

class CircularShape :public Shape
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
	double area()
	{
		return 3.14*radius_*radius_;
	}
};

class Oval :public Shape
{
private:
	int horizontalRadius_;
	int verticalRadius_;
public:
	Oval(int x, int y, int h, int v) :Shape(x, y)
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
	double area()
	{
		return 3.14*horizontalRadius_*verticalRadius_;
	}
};


double areaAll(Shape *a[], int size)
{
	double totalArea = 0.0;
	for (int i = 0; i < size; i++)
	{
		totalArea = totalArea + a[i]->area();
	}
	return totalArea;
}


int main()
{
	//the array of pointers will be stored in the stack and the objects will be stored in the heap
	//or we can create the array in the same way defined in the previous example
	Shape* shapes[4] = { new CircularShape(10,20,15),
					  new CircularShape(5,6,7),
					  new Oval(7,8,9,10),
					  new Oval(4,5,66,77) };
	
	cout << "The total area is:" << areaAll(shapes, 4);
}
