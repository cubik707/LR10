#include <iostream>
#include "Inventory.h"
#include "Menu.h"
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	Inventory::readFromFile();
	Menu::showMenu();
	Inventory::writeToFile();
}
