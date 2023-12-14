#include "Inventory.h"

void Inventory::addProduct(unique_ptr<Product> product)
{
	products.push_back(move(product));
}

void Inventory::printTableFields()
{
	cout << setw(5) << "| �" << setw(40) << "| ��������";
	cout << setw(15) << "| ����";
}

void Inventory::printProducts()
{
	int i = 1;
	for (const auto& product : products) {
		cout << left << setw(5) << "| " + to_string(i++);
		product->display();
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
            throw runtime_error("������ � �������� �����.");
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

        string type;
        ss >> type;

        if (type == "Computer|") {
            Computer computer;
            ss >> computer;  // ���������� ���������������� �������� >>
            products.push_back(make_unique<Computer>(computer));
        }
        else if (type == "Laptop|") {
            Laptop laptop;
            ss >> laptop;  // ���������� ���������������� �������� >>
            products.push_back(make_unique<Laptop>(laptop));
        }
        else {
            // ����������� ��� ��������
            throw runtime_error("����������� ��� �������� � �����.");
        }
    }
}
