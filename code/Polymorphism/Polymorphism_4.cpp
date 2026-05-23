#include <iostream>

using namespace std;
/*
Virtual Distructor
*/
class Shape
{
private:
	int x_;
	int y_;

public:
	
	Shape()
	{
		cout << "Shape Constructor Called\n";
	}
	virtual ~Shape()
	{
		cout << "Shape Distructor Called\n";
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

class CircularShape :public Shape
{
private:
	int radius_;
	int * ptr_;

public:
	CircularShape()
	{
		cout << "CircularShape Constructor Called\n";
		ptr_ = new int[3];
	}
	~CircularShape()
	{
		cout << "CircularShape Distructor Called\n";

		delete[] ptr_;
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

class Oval :public Shape
{
private:
	int horizontalRadius_;
	int verticalRadius_;
public:
	Oval()
	{
		cout << "Oval Constructor Called\n";
	}
	~Oval()
	{
		cout << "Oval Distructor Called\n";
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




int main()
{
	//CircularShape c1;
		
	//Shape& s1 = c1;//this line will not call any constructors since the object already defind and already in the memory
	//Shape* ptr = &c1;//this line will not call any constructors since the object already defind and already in the memory


	cout << endl << endl;


	{
		//this will create an object in the static memory, it will call the default constructor of shape then the default constructor of circularshape as we took before in the inheretance
		CircularShape c2;
		Shape* ptr1 = &c2;
	}
	//this will delete the circular shape then the shape the opposit way they defined




	cout << endl << endl;


	{
		//this will create pointer inside the static memory that points to object inside the heap (DMA) since it uses the "new" keyword 
		Shape* ptr1 = new CircularShape();

		delete ptr1;//you need to delete the pointer explicitly since you are working as DMA, this will call the distructor of shape only because the type of ptr1 is Shape, 
		//if you need to call both distructors you can convert the distructor of shape to virtual distructor
	}
	
}
