#pragma once
#include "Product.h"
#include <vector>
#include <sstream>
#include "Validator.h"
#include "Factory.h"

#define LINE_LENGTH 41

class Inventory
{
private:
	static vector<unique_ptr<Product>> products;
public:
	static void add(unique_ptr<Product> product);
	static void remove(const string& name);
	static void edit(const string& name);

	static void printTableFields();
	static void printProducts();

	static void readFromFile();
	static void fillVector(ifstream& file);
	static void writeToFile();
};

