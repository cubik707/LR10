#include "Menu.h"

void Menu::showMenu()
{
	while (true)
	{
		cout << left << "Меню: " << endl;
		cout << "1 - Вывод данных" << endl;
		cout << "2 - Добавить данные" << endl;
		cout << "3 - Удалить данные" << endl;
		cout << "4 - Редактировать данные" << endl;
		cout << "0 - Назад" << endl;
		int choice = Validator::getIntVar(0, 6);
		switch (choice) {
		case 1:
			Inventory::printTableFields();
			Inventory::printProducts();
			break;
		case 2:
			add();
			break;
		case 3: {
			//cout << "Введите название продукта: ";
			//string name = Validator::convertName();
			//Inventory::remove(name);
		}
			break;
		case 4: {
			//cout << "Введите название продукта: ";
			//string name = Validator::convertName();
			//Inventory::edit(name);
		}
			break;
		case 0:
			return;
		}
	}
}

void Menu::add()
{
	cout << "Выберите тип продукта:" << endl;
	cout << "1 - Computer" << endl;
	cout << "2 - Laptop" << endl;

	int typeChoice = Validator::getIntVar(1, 2);
	ProductType productType = static_cast<ProductType>(typeChoice - 1);

	Factory* factory = nullptr;
	switch (productType) {
	case ProductType::COMPUTER:
		factory = new ComputerFactory();
		break;
	case ProductType::LAPTOP:
		factory = new LaptopFactory();
		break;
	}

	if (factory) {
		cout << "Введите название продукта: ";
		cin.ignore();
		string name = Validator::convertName();

		cout << "Введите цену продукта: ";
		double price = Validator::getDoubleVar(0, INT_MAX);

		unique_ptr<Product> product = factory->create(name, price);
		Inventory::add(move(product));
		cout << "Продукт успешно добавлен!" << endl;
		delete factory; // Освобождаем ресурсы
	}
}
