#pragma once
#include "Product.h"
#include <vector>
#include <sstream>

class Inventory
{
private:
	static vector<unique_ptr<Product>> products;
public:
	static void addProduct(unique_ptr<Product> product);
	static void printTableFields();
	static void printProducts();
	static void readFromFile();
	static void fillVector(ifstream& file);
	static void writeFromFile();
};

