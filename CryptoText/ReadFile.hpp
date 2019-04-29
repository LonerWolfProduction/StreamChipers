#ifndef READFILE_H
#define READFILE_H

bool ReadFile(std::string s)
{
	std::ifstream fin;
	fin.open(s);
	if (!fin.is_open())
	{
		std::cout << "File is not open...\n";
		return false;
	}
	else
	{
		std::ifstream fin;
		fin.open(s, std::ios_base::binary);
		std::string s;
		int f = 0;
		int i = 0;
		while (!fin.eof())
		{
			char buffer[9];
			fin.get(buffer, 9);
			int a = 0;
			for (int t = 0; t < 8; t++)
			{
				if (buffer[7 - t] == 49) a |= (1 << t);
			}
			s += (char)a;
			f = 0;
		}
		Data.CreateSecretLineCode((int)s.length());
		int iS = 0;
		int iW = 0;
		int iG = 0;
		char bufferSymbol[3];
		for (int i = 0; i < (int)s.length();)
		{
			if (iG == 3)
			{
				iS++;
				iG = 0;
			}
			if (s[i] == ' ')
			{
				Data.SecretLineCode[iS][iG] = atoi(bufferSymbol);
				bufferSymbol[0] = '\0';
				bufferSymbol[1] = '\0';
				bufferSymbol[2] = '\0';
				iW = 0;
				iG++;
				i++;
			}
			else
			{
				bufferSymbol[iW] = s[i];
				iW++;
				i++;
			}
		}
		Data.CountSymbol = iS;
		Data.CreateDecodeLine();
		return true;
	}
}

bool ReadFileDecode(std::string s)
{
	std::ifstream fin;
	fin.open(s);
	int symbol = 0;
	while (!fin.eof())
	{
		fin.get();
		symbol++;
	}
	fin.close();
	fin.open(s);
	char *str = new char[symbol];
	if (fin.is_open())
	{
		fin.getline(str, symbol);
		Data.EnteredSymbol = symbol;
		Data.SetEnteredLine(str);
		return true;
	}
	else
	{
		std::cout << "File is not open...\n";
		return false;
	}
}

#endif // !READFILE_H
