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

ofstream& operator<<(ofstream& out, const Product& product)
{
	out << product.name << "|" << product.price << endl;
	return out;
}

ifstream& operator>>(ifstream& is, Product& product)
{
	getline(is, product.name, '|');
	is >> product.price;
	return is;
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

std::ostream& operator<<(std::ostream& out, const Computer& computer)
{
	out << "Computer|" << computer.name << "|" << computer.price;
	return out;
}

std::istream& operator>>(std::istream& is, Computer& computer)
{
	is >> computer.name >> computer.price;
	return is;
}

std::ostream& operator<<(std::ostream& out, const Laptop& laptop)
{
	out << "Laptop|" << laptop.name << "|" << laptop.price;
	return out;
}

std::istream& operator>>(std::istream& is, Laptop& laptop)
{
	is >> laptop.name >> laptop.price;
	return is;
}
