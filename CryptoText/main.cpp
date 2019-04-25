#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <string>
#include "ClMass.hpp"
#include "Combine.hpp"
#include "RotateNumber.hpp"
#include "XOR.hpp"
#include "Password.hpp"
#include "Data.hpp"
#include "Encode.hpp"
#include "Decode.hpp"

void Help()
{
	std::cout << "This is help\n";
}

void SaveFile(char *p)
{
	std::ofstream fout;
	fout.open(p);
	bool exit = false;
	for (int i = 0; i < 80 && !exit; i++)
		for (int t = 0; t < 3; t++)
		{
			fout << Data.SecretLineCode[i][t] << " ";
		}
			
	fout.close();
}

int main()
{
	std::cout << "CryptoText programm.\n";
	bool exit = false;
	bool encode = false;
	bool decode = false;
	while (!exit)
	{
		std::string command;
		std::cout << "Enter command: "; std::getline(std::cin, command);
		if (command == "help") Help();
		else if (command == "encode") { exit = true; encode = true; }
		else if (command == "decode") { exit = true; decode = true; }
		else std::cout << "command is not found... Entered - help\n";
	}

	if (Encode)
	{
		std::string name;
		std::string password;
		std::string text;
		std::cout << "Entered name file: "; std::getline(std::cin, name);
		Data.SetNameFile(name);
		std::cout << "Entered password: "; std::getline(std::cin, password);
		Password.Initialization(password);
		std::cout << "Entered your text: "; std::getline(std::cin, text);
		Data.SetEnteredLine(text.c_str());
//		std::cout << Data.EnteredLine;
		Encode();
		for (int i = 0; i < 80; i++) for (int t = 0; t < 3; t++) std::cout << Data.SecretLineCode[i][t];
		SaveFile(Data.NameFile);
	}

//	Data.SetEnteredLine("Text is not secret. It's a test.");
//	Password.Initialization();
//	Encode();
//	Decode();

	int *s = Data.DecodeLine;
	while (*s)
	{
		std::cout << (char)(*s);
		s++;
	}

	system("PAUSE");
	return 0;
}