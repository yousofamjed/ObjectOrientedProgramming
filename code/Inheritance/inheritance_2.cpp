#include <iostream>
#include <string>
using namespace std;

/*
Protected:
A data member or a member function may be declared as protected member.
The protected keyword specifies that those members are accessible only from member functions and friends of the class and its derived classes. 
This applies to all members declared up to the next access specifier or the end of the class


Overriding:
To override a base-class member function, we can, In the derived class, supply a new version of that function with the same signature
( same function name, different definition)
When the function is then mentioned by name in the derived class, the derived version of that function is automatically called
The scope-resolution operator may be used to access the base class version from the derived class.
*/
class User
{
protected:
	int id_;
	string name_;

public:
	User()
	{
		id_ = 0;
		name_ = "No Name";
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

	//member function with the same name with a member function in the derived classes
	void print() 
	{
		cout << "Id: " << id_ << endl << "Name: " << name_ << endl << endl;
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
		gpa_ = 0.0;
		accHours_ = 0;
	}

	Student(int id, string name, double gpa, int acc)
	{
		//since the user data member is protected access modifier then the child class can access the user data member directly without the need of setters
		id_ = id;
		name_ = name;

		//setId(id);
		//setName(name);

		gpa_ = gpa;
		accHours_ = acc;
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

	//member function with the same name with a member function in the parent class
	void print() 
	{
		User::print();
		cout << "Gpa is: " << gpa_ << endl << "hours: " << accHours_ << endl;
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
		salary_ = 0;
		experience_ = 0;
	}
	
	Instructor(int id,string name,int salary,int exp)
	{
		//since the user data member is protected access modifier then the child class can access the user data member directly without the need of setters
		id_ = id;
		name_ = name;

		//setters from parent class to set parent data members
		//setId(id);
		//setName(name);

		//set the values from child class to set child data members
		salary_ = salary;
		experience_ = exp;
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
	//member function with the same name with a member function in the parent class
	void print()
	{
		User::print();//overriding
		cout << "Salary is: " << salary_ << endl << "Experience: " << experience_<<endl;		
	}
};

int main()
{	
	Student s1;
	s1.setId(1);
	s1.setName("Ali");
	s1.setGpa(90);
	s1.setAccHours(120);

	s1.print();//will call the print from student class (member function inside the same object)
	cout << endl;
	s1.User::print();//will call the print from user class (member function inside the parent class) //overriding

	User u1;
	u1.setId(2);
	u1.setName("Sara");
	u1.print();//will call the print from user class (member function inside the same object)
}
