#include "Menu.h"

void Menu::showMenu()
{
	while (true)
	{
		cout << left << "����: " << endl;
		cout << "1 - ����� ������" << endl;
		cout << "2 - �������� ������" << endl;
		cout << "3 - ������� ������" << endl;
		cout << "4 - ������������� ������" << endl;
		cout << "0 - �����" << endl;
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
