#include<iostream>
using namespace std;

/*
Operators Overloading

The operators + , - , / and  *  perform differently depending on their context in integers, floating point and pointers.
	C++ enables programmers to overload most operator to be sensitive to the context in which they are used.
	Operator overloading is often clearer than using explicit function calls.


a. Definition.It is redefining the meaning of an operator when it is used with objects of a user defined type (class).
b. Why
	Overloading operators enables C++�s operators to work with class objects
	Overloading operators enables the use traditional operators with user-defined objects
c. Remark
	Overloading operators requires great care; when overloading is misused, program difficult to understand


Syntax of operator function
	Write function definition as normal: Header and bodyFunction name is keyword operator followed by the symbol for the operator being overloaded
	Example:
		Operator+ used to overload the addition operator (+)
	Syntax:
		Ftype operatorOP (ListOfParameters)	{

		}

*/

class Fraction
{
	friend ostream& operator<< (ostream &out, Fraction &f1);
	friend istream& operator>> (istream &out, Fraction &f1);
private:
	int num;
	int denom;
public:
	Fraction(int a, int b)
	{
		num = a;
		denom = b;
	}
	void print()
	{
		cout << num << "/" << denom << endl;
	}

	Fraction operator+(Fraction f2)
	{
		int n, d;
		if (denom == f2.denom)
		{
			n = num + f2.num;
			d = denom;
		}
		else
		{
			n = num * f2.denom + f2.num*denom;
			d = denom * f2.denom;
		}
		Fraction result(n, d);
		return result;

		//or
		//return Fraction(n, d);
	}

	Fraction operator-(Fraction f2)
	{
		int n, d;
		if (denom == f2.denom)
		{
			n = num - f2.num;
			d = denom;
		}
		else
		{
			n = num * f2.denom - f2.num*denom;
			d = denom * f2.denom;
		}
		Fraction result(n, d);
		return result;
	}

	Fraction operator*(Fraction f2)
	{
		int n, d;
		n = num * f2.num;
		d = denom * f2.denom;
		Fraction result(n, d);
		return result;
	}

	Fraction operator/(Fraction f2)
	{
		int n, d;
		n = num * f2.denom;
		d = denom * f2.num;
		Fraction result(n, d);
		return result;
	}
	Fraction operator+(int x)
	{
		Fraction f2(x, 1);
		Fraction result = f2 + *this;
		return result;
	}

	bool operator>(Fraction f2)
	{
		double d1, d2;
		d1 = num * 1.0 / denom * 1.0;
		d2 = f2.num *1.0 / f2.denom*1.0;

		return d1 > d2;
	}

	bool operator>=(Fraction f2)
	{
		double d1, d2;
		d1 = num * 1.0 / denom * 1.0;
		d2 = f2.num *1.0 / f2.denom*1.0;

		return d1 >= d2;
	}
	bool operator!=(Fraction f2)
	{
		double d1, d2;
		d1 = num * 1.0 / denom * 1.0;
		d2 = f2.num *1.0 / f2.denom*1.0;

		return d1 != d2;
	}

	bool operator!=(int x)
	{
		double d1;
		d1 = num * 1.0 / denom * 1.0;

		return d1 != x;
	}

	void operator+=(int x)
	{
		Fraction f2(x, 1);
		*this = *this + f2;
	}

	void operator-=(int x)
	{
		Fraction f2(x, 1);
		*this = *this - f2;
	}

	Fraction operator++()//prefix
	{
		*this = *this + 1;
		return *this;
	}

	Fraction operator++(int)//postfix
	{
		Fraction temp(num, denom);
		*this = *this + 1;
		return temp;
	}



};

ostream& operator<< (ostream &out, Fraction &f1)
{
	out << f1.num;
	out << "/";
	out << f1.denom;
	out << endl;
	return out;
}
istream& operator>> (istream &in, Fraction &f1)
{
	in >> f1.num;
	in >> f1.denom;
	return in;
}


int main()
{
	Fraction f1(3, 5);
	Fraction f2(4, 3);

	int x = 3;
	cout << x << endl;
	cout << ++x << endl;
	cout << x << endl;
	cout << x++ << endl;
	cout << x << endl;


	++f1;
	f1.print();

	f1++;
	f1.print();


	cout << f1;

	cin >> f1;
	f1.print();
}
