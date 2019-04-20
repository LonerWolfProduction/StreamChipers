#include <iostream>
#include <fstream>
#include "ClMass.hpp"
#include "GeneratorClass.hpp"
#include "EncodingClass.hpp"
#include "CommandCode.hpp"
#include "CommandEncode.hpp"
#include "CommandHelp.hpp"

int main()
{
	std::cout << "CryptoStreamText programm\n";

	std::cout << "Put command: ";

	char command[80]; ClMass(command);
	std::cin.getline(command, 80);

	if (!strcmp(command, "exit")) return 0;
	else if (!strcmp(command, "code")) Code();
	else if (!strcmp(command, "encode")) Encode();
	else if (!strcmp(command, "help")) Help();
	else std::cout << "\nCommand is not find...n\n";
	
	system("PAUSE");
	return 0;
}

/*

/*
int a = 55;
int key = 32;
int b = XOR(a, key);

std::cout << "A: " << a << "\n";
std::cout << "Key: " << key << "\n";
std::cout << "Code: " << b << "\n";
std::cout << "Encode: " << XOR(b, key) << "\n";

//	SB.XOR(a, key);
//	SB.BoolSystem(SB.XORI(16, 20));

int key = 23;
int Code = 123456789;
int Pass[30];
int Iteration = 0;

while (Code != 0)
{
	if (Code > 100) Pass[Iteration] = Code % 100;
	else Pass[Iteration] = Code;
	Code /= 100;
	Iteration++;
}

int PassCode[30];

for (int i = 0; i < Iteration; i++)
{
	BoolSystem(Pass[i]);
	std::cout << " ";
}
std::cout << "\n";
for (int i = 0; i < Iteration; i++)
{
	XOR(Pass[i], 26);
	std::cout << " ";
}

//	std::cout << Iteration << "\n";

//	for (int i = 0; i < 30; i++) std::cout << Pass[i] << "\n";

/*
SB.BoolSystem(45);
std::cout << "\n";
SB.BoolSystem(52);
std::cout << "\n";
SB.XOR(45, 52);
std::cout << "\n";


*/

/*

time_t t;
struct tm tm;
long int tRange;

t = time(NULL);
localtime_s(&tm, &t);
tRange = (tm.tm_sec * tm.tm_min * tm.tm_hour) + (tm.tm_yday * tm.tm_wday * tm.tm_mon * tm.tm_mday * tm.tm_year * tm.tm_isdst);

*/