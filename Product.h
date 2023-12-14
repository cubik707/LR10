#pragma once
#include <memory>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


enum class ProductType {
	COMPUTER,
	LAPTOP
};

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

	virtual ProductType getType() const = 0;

	void display() const;
	virtual unique_ptr<Product> clone() const = 0;
	
};

class Computer : public Product {
public:
	Computer();
	Computer(const string& name, double price);

	unique_ptr<Product> clone() const override;
	ProductType getType() const override { return ProductType::COMPUTER; }
};

class Laptop : public Product {
public:
	Laptop();
	Laptop(const string& name, double price);

	unique_ptr<Product> clone() const override;
	ProductType getType() const override { return ProductType::LAPTOP; }
};
