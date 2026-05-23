#include <iostream>
#include <string>
using namespace std;

class Address
{
	friend class Student;// to make the private data members (city,street,buildingNo) accessable from student class directly without setters and getters
private:
	string city_;
	string street_;
	int buildingNo_;
public:
	Address()
	{
		city_ = "no city";
		street_ = "no street";
		buildingNo_ = 0;
		
	}
	Address(string city, string street, int buildingNo)
	{
		city_ = city;
		street_ = street;
		buildingNo_ = buildingNo;
	}
	void setCity(string city)
	{
		city_ = city;
	}
	void setStreet(string street)
	{
		street_ = street;
	}
	void setBuildingNo(int buildingNo)
	{
		buildingNo_ = buildingNo;
	}
	string getCity()
	{
		return city_;
	}
	string getStreet()
	{
		return street_;
	}
	int getBuildingNo()
	{
		return buildingNo_;
	}
	void printAddress()
	{
		cout << "Address is:" << city_ << "-" << street_ << "-" << buildingNo_ << endl;
	}
};

class Student
{
	friend bool isEqual(const Student &s1, const Student &s2);//to make the private data members (id,name,address) accessable from the isEqual function without using the getters

private:
	int id_;
	string name_;
	Address address_;

public:

	Student()
	{
		id_ = 0;
		name_ = "no name";
		
	}
	Student(int id, string name, string city, string street, int buildingNo)
	{
		id_ = id;
		name_ = name;
		
		address_.setCity(city);
		address_.setStreet(street);
		address_.setBuildingNo(buildingNo);				
	}
		
	void setId(int id)
	{
		id_ = id;
	}
	void setName(string name)
	{
		name_ = name;
	}
	int getId() const
	{
		return id_;
	}
	string getName() const
	{
		return name_;
	}
	void printStudent()
	{
		cout << "Student Id is: " << id_ << endl;
		cout << "Student name is: " << name_ << endl;
		address_.printAddress();
		cout << endl << endl;
	}	
};

bool isEqual(const Student &s1, const Student &s2)
{
	//you have to use getters since the data members are private
	/*
	if (s1.getId() == s2.getId() && s1.getName() == s2.getName())
		return true;
	else
		return false;
	*/

	//if you want to access the private data members directly you have to defind friend function inside the class that has the private data members
	if (s1.id_ == s2.id_ && s1.name_ == s2.name_)
		return true;
	else
		return false;
}

int main()
{
	Student s1(1, "Ali", "Amman", "Ahmed Tarawneh", 4);
	
	Student s2(1, "Ali", "Amman", "Ahmed Tarawneh", 4);
	
	cout<< isEqual(s1, s2);
}
