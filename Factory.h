#pragma once
#include "Product.h"

class Factory
{
public:
	virtual unique_ptr<Product> create() const = 0;
	virtual unique_ptr<Product> create(const string& name, double price) const = 0;
};

class ComputerFactory : public Factory {
public:
	unique_ptr<Product> create() const override;
	unique_ptr<Product> create(const string& name, double price) const override;

};

class LaptopFactory : public Factory {
public:
	unique_ptr<Product> create() const override;
	unique_ptr<Product> create(const string& name, double price) const override;
};
