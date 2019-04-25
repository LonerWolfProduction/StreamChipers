#ifndef DATA_H
#define DATA_H

struct DataStruct
{
	int CountSymbol;
	char EnteredLine[80];
	char NameFile[80];
	int SecretLineCode[80][3];
	int DecodeLine[80];
	DataStruct()
	{
		ClMass(EnteredLine);
		ClMass(DecodeLine);
		CountSymbol = 0;
	}
	void SetEnteredLine(const char *p)
	{
		strcpy_s(EnteredLine, p);
	}
	void SetNameFile(std::string s)
	{
		strcpy_s(NameFile, s.c_str());
	}
}Data;

#endif // !DATA_H
