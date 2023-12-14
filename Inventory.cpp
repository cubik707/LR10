#include "Inventory.h"

vector<unique_ptr<Product>> Inventory::products;

void Inventory::add(unique_ptr<Product> product)
{
	products.push_back(move(product));
}

void Inventory::remove(const string& name)
{
    auto it = std::remove_if(products.begin(), products.end(), [&name](const unique_ptr<Product>& product) {
        return product->getName() == name;
        });

    if (it != products.end()) {
        products.erase(it, products.end());
        cout << "������� ������� ������." << endl;
    }
    else {
        cout << "������� � ����� ��������� �� ������." << endl;
    }
}

void Inventory::edit(const string& name)
{
    auto it = std::find_if(products.begin(), products.end(), [&name](const unique_ptr<Product>& product) {
        return product->getName() == name;
        });

    if (it != products.end()) {
        // ����������� ��������� �������
        cout << "������� ����� �������� ��������: ";
        string newName = Validator::getValidStr();
        (*it)->setName(newName);

        cout << "������� ����� ���� ��������: ";
        double newPrice = Validator::getDoubleVar(0, INT_MAX);
        (*it)->setPrice(newPrice);

        cout << "������� ������� ��������������." << endl;
    }
    else {
        cout << "������� � ����� ��������� �� ������." << endl;
    }
}

void Inventory::printTableFields()
{
    printLine(LINE_LENGTH);
	cout << setw(5) << "| �" << setw(22) << "| ��������";
    cout << setw(15) << "| ����" << "|" << endl;
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

        string type, name;
        double price;
        ss >> type;
        ss.ignore();

        if (type == "Computer|") {
            Computer computer;
            getline(ss, name, '|');
            ss >> price;
            ComputerFactory factory;
            products.push_back(factory.create(name, price));
        }
        else if (type == "Laptop|") {
            Laptop laptop;
            getline(ss, name, '|');
            ss >> price;
            LaptopFactory factory;
            products.push_back(factory.create(name, price));
        }
        else {
            // ����������� ��� ��������
            throw runtime_error("����������� ��� �������� � �����.");
        }
    }
}
