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
	
	string getName() const { return name; };
	double getPrice() const { return price; };
	void setName(const string& name) { this->name = name; };
	void setPrice(double price) { this->price = price; };

	void display() const;
	virtual unique_ptr<Product> clone() const = 0;
	
};

class Computer : public Product {
public:
	Computer();
	Computer(const string& name, double price);

	unique_ptr<Product> clone() const override;
};

class Laptop : public Product {
public:
	Laptop();
	Laptop(const string& name, double price);

	unique_ptr<Product> clone() const override;
};
