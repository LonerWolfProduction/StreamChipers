#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <string>
#include "ClMass.hpp"
#include "Combine.hpp"
#include "RotateNumber.hpp"
#include "XOR.hpp"
#include "Help.hpp"
#include "Password.hpp"
#include "Data.hpp"
#include "Encode.hpp"
#include "Decode.hpp"
#include "SaveFile.hpp"
#include "ReadFile.hpp"

int main(int argc, char* argv[])
{
	if (argc > 1)
	{
		bool exit = false;
		bool encode = false;
		bool decode = false;
		std::cout << "Encode or Decode file ";
		std::cout << argv[1] << "?\n";
		Data.SetNameFile(argv[1]);
		while (!exit)
		{
			std::string command;
			std::cout << "Enter command: "; std::getline(std::cin, command);
			if (command == "help") Help();
			else if (command == "encode") { exit = true; encode = true; }
			else if (command == "decode") { exit = true; decode = true; }
			else if (command == "exit") { exit = true; }
			else std::cout << "command is not found... Entered - help\n";
		}
		if (encode)
		{
			std::string name;
			std::string password;
			std::string save; bool saveBool = false;
			bool unsaveBool = false;
			std::cout << "Entered password: "; std::getline(std::cin, password);
			Password.Initialization(password);
			ReadFileDecode(Data.NameFile);
			Encode();
			std::cout << "Encode is successfully. Save file? y/n: ";
			while (!saveBool)
			{
				std::getline(std::cin, save);
				if (save == "y")
				{
					std::cout << "Entered name file: "; std::getline(std::cin, name);
					Data.SetNameFile(name);
					SaveFile(Data.NameFile);
					std::cout << "Save is successfully.\n";
					saveBool = true;
				}
				else if (save == "n")
				{
					saveBool = true;
				}
				else
				{
					std::cout << "Please, entered y/n: ";
				}
			}
			if (!unsaveBool)
			{
				bool EnterConsolBool = false;
				std::string EnterConsol;
				std::cout << "Entered in consol? y/n: ";
				while (!EnterConsolBool)
				{
					std::getline(std::cin, EnterConsol);
					if (EnterConsol == "y")
					{
						for (int i = 0; i < Data.CountSymbol; i++)
							for (int t = 0; t < 3; t++)
								std::cout << Data.SecretLineCode[i][t] << " ";
						EnterConsolBool = true;
					}
					else if (EnterConsol == "n")
					{
						EnterConsolBool = true;
					}
					else
					{
						std::cout << "Please, entered y/n: ";
					}
				}
			}
		}
		if (decode)
		{
			std::string name;
			std::string password;
			std::string save; bool saveBool = false;
			bool unsaveBool = false;
			std::cout << "Entered password: "; std::getline(std::cin, password);
			Password.Initialization(password);
			ReadFile(Data.NameFile);
			Decode();
			std::cout << "Decode is successfully. Save file? y/n: ";
			while (!saveBool)
			{
				std::getline(std::cin, save);
				if (save == "y")
				{
					std::cout << "Entered name file: "; std::getline(std::cin, name);
					Data.SetNameFile(name);
					SaveFileDecode(Data.NameFile);
					std::cout << "Save is successfully.\n";
					saveBool = true;
				}
				else if (save == "n")
				{
					saveBool = true;
				}
				else
				{
					std::cout << "Please, entered y/n: ";
				}
			}
			if (!unsaveBool)
			{
				bool EnterConsolBool = false;
				std::string EnterConsol;
				std::cout << "Entered in consol? y/n: ";
				while (!EnterConsolBool)
				{
					std::getline(std::cin, EnterConsol);
					if (EnterConsol == "y")
					{
						for (int i = 0; i < Data.CountSymbol; i++) std::cout << (char)Data.DecodeLine[i];
						std::cout << "\n";
						EnterConsolBool = true;
					}
					else if (EnterConsol == "n")
					{
						EnterConsolBool = true;
					}
					else
					{
						std::cout << "Please, entered y/n: ";
					}
				}
			}
		}
	}
	else
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
			else if (command == "exit") { exit = true; }
			else std::cout << "command is not found... Entered - help\n";
		}

		if (encode)
		{
			std::string name;
			std::string password;
			std::string text;
			std::string save; bool saveBool = false;
			bool unsaveBool = false;
			std::cout << "Entered password: "; std::getline(std::cin, password);
			Password.Initialization(password);
			std::cout << "Entered your text: "; std::getline(std::cin, text);
			Data.EnteredSymbol = (int)text.length() + 1;
			Data.SetEnteredLine(text.c_str());
			Encode();
			std::cout << "Encode is successfully. Save file? y/n: ";
			while (!saveBool)
			{
				std::getline(std::cin, save);
				if (save == "y")
				{
					std::cout << "Entered name file: "; std::getline(std::cin, name);
					Data.SetNameFile(name);
					SaveFile(Data.NameFile);
					std::cout << "Save is successfully.\n";
					saveBool = true;
				}
				else if (save == "n")
				{
					saveBool = true;
				}
				else
				{
					std::cout << "Please, entered y/n: ";
				}
			}
			if (!unsaveBool)
			{
				bool EnterConsolBool = false;
				std::string EnterConsol;
				std::cout << "Entered in consol? y/n: ";
				while (!EnterConsolBool)
				{
					std::getline(std::cin, EnterConsol);
					if (EnterConsol == "y")
					{
						for (int i = 0; i < Data.CountSymbol; i++)
							for (int t = 0; t < 3; t++)
								std::cout << Data.SecretLineCode[i][t] << " ";
						EnterConsolBool = true;
					}
					else if (EnterConsol == "n")
					{
						EnterConsolBool = true;
					}
					else
					{
						std::cout << "Please, entered y/n: ";
					}
				}
			}
		}
		else if (decode)
		{
			std::string name;
			std::string password;
			std::string save; bool saveBool = false;
			bool unsaveBool = false;
			std::cout << "Entered name file: "; std::getline(std::cin, name);

			if (!ReadFile(name.c_str())) { saveBool = true; unsaveBool = true; }
			else 
			{
				std::cout << "Entered password: "; std::getline(std::cin, password);
				Password.Initialization(password);
				Decode(); 
				std::cout << "Decode is successfully. Save file? y/n: "; 
			}
			while (!saveBool)
			{
				std::getline(std::cin, save);
				if (save == "y")
				{
					std::cout << "Entered name file: "; std::getline(std::cin, name);
					Data.SetNameFile(name);
					SaveFileDecode(Data.NameFile);
					std::cout << "Save is successfully.\n";
					saveBool = true;
				}
				else if (save == "n")
				{
					saveBool = true;
				}
				else
				{
					std::cout << "Please, entered y/n: ";
				}
			}
			if (!unsaveBool)
			{
				bool EnterConsolBool = false;
				std::string EnterConsol;
				std::cout << "Entered in consol? y/n: ";
				while (!EnterConsolBool)
				{
					std::getline(std::cin, EnterConsol);
					if (EnterConsol == "y")
					{
						for (int i = 0; i < Data.CountSymbol; i++) std::cout << (char)Data.DecodeLine[i];
						std::cout << "\n";
						EnterConsolBool = true;
					}
					else if (EnterConsol == "n")
					{
						EnterConsolBool = true;
					}
					else
					{
						std::cout << "Please, entered y/n: ";
					}
				}
			}
		}
	}
	system("PAUSE");
	return 0;
}