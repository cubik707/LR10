#pragma once
#include "Product.h"

class Factory
{
public:
	virtual unique_ptr<Product> create() const = 0;
};

class ComputerFactory : public Factory {
public:
	unique_ptr<Product> create() const override;
};

class LaptopFactory : public Factory {
public:
	unique_ptr<Product> create() const override;
};
