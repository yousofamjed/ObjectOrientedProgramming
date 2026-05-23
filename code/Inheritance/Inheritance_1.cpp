
#include <iostream>
#include <string>
using namespace std;
/*
An instance of a derived class contains all the members of the base class.
All of those members must be initialized during construction.
The base class�s constructor has to be called by the derived class�s constructor.
Base-class constructor and assignment operators are not inherited by derived classes.
Derived-class constructors and assignment operators can call base-class constructors and assignment operators.
A derived-class constructor always calls the constructor for its base class.
When an object of a derived class is declared, the compiler executes the constructor for the base class first and then executes the constructor for the derived class.
Destructors are called in the reverse order of constructor calls. So a derived-class destructor is called before its base-class destructor.
It is not necessary to call the base-class destructor explicitly from the derived-class destructor.
*/

class User
{
private:
	int id_;
	string name_;

public:
	User()
	{
		cout << "User: Default Constructor Called" << endl;
		id_ = 0;
		name_ = "No Name";
	}
	//parameterized constructor
	User(int id,string name)
	{
		cout << "User: Parameterized Constructor Called" << endl;

		id_ = id;
		name_ = name;
	}
	~User()
	{
		cout << "User: Destructor Called" << endl;
	}
	void setId(int id)
	{
		id_ = id;
	}
	void setName(string name)
	{
		name_ = name;
	}
	
	int getId()
	{
		return id_;
	}
	string getName()
	{
		return name_;
	}	
};

class Student :public User
{
private:
	double gpa_;
	int accHours_;
public:
	Student()
	{
		cout << "Student: Default Constructor Called" << endl;
		gpa_ = 0.0;
		accHours_ = 0;
	}
	
	//parameterized constructor with initializer list
	Student(int id, string name, double gpa, int acc):User(id,name)
	{
		cout << "Student: Parameterized Constructor Called" << endl;
		
		//set the values from child class to set child data members or we can put them in the initializer list
		gpa_ = gpa;
		accHours_ = acc;
	}
	
	~Student()
	{
		cout << "Student: Destructor Called" << endl;
	}
	void setGpa(double gpa)
	{
		gpa_ = gpa;
	}
	void setAccHours(int acc)
	{
		accHours_ = acc;
	}
	double getGpa()
	{
		return gpa_;
	}
	int getAccHours()
	{
		return accHours_;
	}
};

class Instructor :public User
{
private:
	int salary_;
	int experience_;
public:
	Instructor()
	{
		cout << "Instructor: Default Constructor Called" << endl;
		salary_ = 0;
		experience_ = 0;
	}
	
	//parameterized constructor without initializer list
	Instructor(int id,string name,int salary,int exp)
	{
		cout << "Instructor: Parameterized Constructor Called" << endl;
		
		//setters from parent class to set parent data members
		setId(id);
		setName(name);

		//set the values from child class to set child data members
		salary_ = salary;
		experience_ = exp;
	}

	~Instructor()
	{
		cout << "Instructor: Destructor Called" << endl;
	}
	void setSalary(int salary)
	{
		salary_ = salary;
	}
	void setExperience(int experience)
	{
		experience_ = experience;
	}
	int getSalary()
	{
		return salary_;
	}
	int getExperience()
	{
		return experience_;
	}
};

int main()
{	
	Instructor inst;
	inst.setId(1);
	inst.setName("Ahmed");
	inst.setSalary(1000);
	inst.setExperience(10);

	////Test no initializer list
	//Instructor inst2(1, "Ahmed", 1000, 10);

	////Test initializer list
	//Student s(2,"Ali",90.0,50);
	
}
