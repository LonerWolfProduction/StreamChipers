#ifndef DATA_H
#define DATA_H

struct DataStruct
{
	int CountSymbol;
	int EnteredSymbol;
	char NameFile[64];
	char *EnteredLine;
	int **SecretLineCode;
	int *DecodeLine;
	DataStruct()
	{
		ClMass(NameFile, 64);
		CountSymbol = 0;
		EnteredSymbol = 0;
	}
	void CreateSecretLineCode(int iS)
	{
		SecretLineCode = new int*[iS];
		for (int i = 0; i < iS; i++)
		{
			SecretLineCode[i] = new int[3];
		}
	}
	void SetEnteredLine(const char *p)
	{
		EnteredLine = new char[EnteredSymbol];
		strcpy_s(EnteredLine, EnteredSymbol, p);
		CreateSecretLineCode(EnteredSymbol);
	}
	void CreateDecodeLine()
	{
		DecodeLine = new int[CountSymbol];
		for (int i = 0; i < CountSymbol; i++)
			DecodeLine[i] = 0;
	}
	void SetNameFile(std::string s)
	{
		strcpy_s(NameFile, s.c_str());
	}
}Data;

#endif // !DATA_H
