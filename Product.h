#pragma once
#include <memory>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
class Product
{
protected:
	string name;
	double price;
public:
	Product();
	Product(const string& name, double price);

	void display() const;
	virtual unique_ptr<Product> clone() const = 0;
	
};

class Computer : public Product {
public:
	Computer();
	Computer(const string& name, double price);

	unique_ptr<Product> clone() const override;
	friend ostream& operator<<(std::ostream& out, const Computer& computer);
	friend istream& operator>>(std::istream& is, Computer& computer);
};

class Laptop : public Product {
public:
	Laptop();
	Laptop(const string& name, double price);

	unique_ptr<Product> clone() const override;
	friend ostream& operator<<(std::ostream& out, const Laptop& laptop);
	friend istream& operator>>(std::istream& is, Laptop& laptop);
};
