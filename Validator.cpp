#include "Validator.h"

int Validator::getIntVar(int minLim, int maxLim)
{
	int resultVar;
	bool is_valid = false;
	do {
		try
		{
			std::cin >> resultVar;
			if (std::cin.fail() || resultVar > maxLim || resultVar < minLim)
			{
				throw std::runtime_error("������ �����!");
			}
			is_valid = true;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "������� ����� �� "
				+ std::to_string(minLim) + " �� " + std::to_string(maxLim) + "." << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}

	} while (!is_valid || std::cin.peek() != '\n');

	return resultVar;
}

double Validator::getDoubleVar(double minLim, double maxLim)
{
	double resultVar;
	bool is_valid = false;
	do {
		try
		{
			std::cin >> resultVar;
			if (std::cin.fail() || resultVar > maxLim || resultVar < minLim)
			{
				throw std::runtime_error("������ �����!");
			}
			is_valid = true;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "������� ����� �� "
				+ std::to_string(minLim) + " �� " + std::to_string(maxLim) + "." << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}

	} while (!is_valid || std::cin.peek() != '\n');

	return resultVar;
}

string Validator::getValidStr()
{
	std::string str;
	bool is_valid = false;

	do {
		try {
			std::getline(std::cin, str);
			if (std::cin.fail() || str.empty()) {
				throw std::runtime_error("������ �����! ������ �����!");
				std::cin.ignore();
			}
			is_valid = true;
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	} while (!is_valid);

	return str;
}

void Validator::convert(std::string& str)
{
	if (!str.empty()) {
		str[0] = toupper(str[0]);
		for (int i = 1; i < str.length(); i++) {
			str[i] = tolower(str[i]);
		}
	}
}

std::string Validator::convertName()
{
	std::string input;
	std::getline(std::cin, input);

	// �������������� ������� ����� � ������
	std::istringstream iss(input);
	std::ostringstream oss;
	std::string word;
	bool firstWord = true;

	while (iss >> word)
	{
		if (!firstWord)
		{
			oss << ' ';  // ��������� ������ ����� ������ ������, ����� �������
		}

		// �������������� ������ ����� � ������� �������, ��������� � ������
		Validator::convert(word);
		oss << word;

		firstWord = false;
	}

	return oss.str();
}

void printLine(int length)
{
	std::cout << "+" << std::setfill('-') << std::setw(length) << "";
	std::cout << std::setfill(' ');
	std::cout << "+" << std::endl;
}
