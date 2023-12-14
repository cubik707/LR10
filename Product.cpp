#include "Product.h"

Product::Product()
	: name ("-"), price(0)
{
}

Product::Product(const string& name, double price)
	: name(name), price(price)
{
}

void Product::display() const
{
	cout.setf(ios::left | ios::fixed | ios::dec);
	cout << "| " << setw(20) << name;
	cout << "| " << setw(13) << price;
	cout.unsetf(ios::left | ios::fixed | ios::dec);
}



Computer::Computer()
{
}

Computer::Computer(const string& name, double price)
	: Product(name, price)
{
}

unique_ptr<Product> Computer::clone() const
{
	return make_unique<Computer>(*this);
}

Laptop::Laptop()
{
}

Laptop::Laptop(const string& name, double price)
	: Product(name, price)
{
}

unique_ptr<Product> Laptop::clone() const
{
	return make_unique<Laptop>(*this);
}


