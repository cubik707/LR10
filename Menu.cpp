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
			
			break;
		case 3:
			
			break;
		case 4:
			
			break;

		case 0:
			return;
		}
	}
}
