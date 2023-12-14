#include "Inventory.h"

vector<unique_ptr<Product>> Inventory::products;

void Inventory::addProduct(unique_ptr<Product> product)
{
	products.push_back(move(product));
}

void Inventory::printTableFields()
{
    printLine(LINE_LENGTH);
	cout << setw(5) << "| №" << setw(22) << "| Название";
    cout << setw(15) << "| Цена" << "|" << endl;
    printLine(LINE_LENGTH);
}

void Inventory::printProducts()
{
	int i = 1;
	for (const auto& product : products) {
		cout << left << setw(5) << "| " + to_string(i++);
		product->display();
        printLine(LINE_LENGTH);
	}
}

void Inventory::readFromFile()
{

    ifstream file;
    try
    {
        file.open("inventory.txt");

        if (file.bad())
        {
            throw runtime_error("Ошибка в открытии файла.");
        }
        if (file.good())
        {
            fillVector(file);
        }

        file.close();
    }
    catch (const runtime_error& e)
    {
        cout << e.what() << endl;
        exit(0);
    }
}

void Inventory::fillVector(ifstream& file)
{
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        unique_ptr<Product> product;

        string type, name;
        double price;
        ss >> type;

        if (type == "Computer|") {
            Computer computer;
            getline(ss, name, '|');
            ss >> price;
            products.push_back(make_unique<Computer>(name, price));
        }
        else if (type == "Laptop|") {
            Laptop laptop;
            getline(ss, name, '|');
            ss >> price;
            products.push_back(make_unique<Laptop>(name, price));
        }
        else {
            // Неизвестный тип продукта
            throw runtime_error("Неизвестный тип продукта в файле.");
        }
    }
}
