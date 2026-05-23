#include<iostream>
#include<string>

using namespace std;


/*
Types of Inheritance
a. Single inheritance
	A class is derived from one base class.
	A derived class is more specific than its base class and represents a smaller group of objects.
	An object of a derived class may also be treated as an object of the base-class.
b. Multiple inheritance
	A class is derived from multiple base classes.
	Multiple inheritance is more complex than single inheritance.
	This example shows the multiple inheritance
*/
class Person
{
private:
	string name_;
	int natNo_;
	string address_;

public:
	Person()
	{
		cout << "Person Constructor Called" << endl;
		name_ = "No Name";
		natNo_ = 0;
		address_ = "No Address";
	}
	Person(string name, int natNo, string address)
	{
		name_ = name;
		natNo_ = natNo;
		address_ = address;
	}
	void setName(string name)
	{
		name_ = name;
	}
	void setNatNo(int natNo)
	{
		natNo_ = natNo;
	}
	void setAddress(string address)
	{
		address_ = address;
	}
	string getName()
	{
		return name_;
	}
	int getNatNo()
	{
		return natNo_;
	}
	string getAddress()
	{
		return address_;
	}
};

class Employee
{
private:
	int empNo_;
	float salary_;

public:
	Employee()
	{
		cout << "Employee Constructor Called" << endl;
		empNo_ = 0;
		salary_ = 0.0;
	}
	Employee(int empno, float sal)
	{
		empNo_ = empno;
		salary_ = sal;
	}
	void setEmpno(int empno)
	{
		empNo_ = empno;
	}
	void setSalary(float sal)
	{
		salary_ = sal;
	}
	int getEmpno()
	{
		return empNo_;
	}
	float getSalary()
	{
		return salary_;
	}
};

class Lecturer : public Employee, public Person
{
private:
	int semHours_;
	int totalStudents_;
public:
	Lecturer()
	{
		cout << "Lecturer Constructor Called" << endl;
		semHours_ = 0;
		totalStudents_ = 0;
	}
	Lecturer(string name, int natNo, string address, int empno, float sal, int hours, int stds):Person(name,natNo,address),Employee(empno,sal)
	{
		semHours_ = hours;
		totalStudents_ = stds;
	}
	void setSemHours(int hours)
	{
		semHours_ = hours;
	}
	void setTotalStudents(int stds)
	{
		totalStudents_ = stds;
	}
	int getSemHours()
	{
		return semHours_;
	}
	int getTotalStudents()
	{
		return totalStudents_;
	}
};

int main()
{
	Lecturer r("Ahmed",123456,"Amman",1,1000,10,30);
	cout << "Name:" << r.getName()<<endl;
	cout << "NatNo:" << r.getNatNo() << endl;
	cout << "Address:" << r.getAddress() << endl;
	cout << "Empno:" << r.getEmpno() << endl;
	cout << "Salary:" << r.getSalary() << endl;
	cout << "Hours:" << r.getSemHours() << endl;
	cout << "Number of students:" << r.getTotalStudents() << endl;

	Lecturer r2;
}
