#ifndef SAVEFILE_H
#define SAVEFILE_H
#include <bitset>

void SaveFile(char *p)
{
	std::string s;
	for (int i = 0; i < Data.CountSymbol; i++)
		for (int t = 0; t < 3; t++)
		{
			char buffer[10];
			for (int i = 0; i < 10; i++) buffer[i] = '\0';
			_itoa_s(Data.SecretLineCode[i][t], buffer, 10);
			s = s + buffer + ' ';
			
		}
	
	std::ofstream fout;
	fout.open(p, std::ios_base::binary);
	for (int i = 0; i < (int)s.length(); i++)
	{
		std::bitset<sizeof s[i] * 8> bitset(s[i]);
		fout << bitset.to_string();
	}
	fout.close();
}

void SaveFileDecode(char *p)
{
	std::ofstream fout;
	fout.open(p, std::ios_base::binary);
	for (int i = 0; i < Data.CountSymbol; i++)
	{
		fout << (char)Data.DecodeLine[i];
	}
	fout.close();
}

#endif // !SAVEFILE_H
