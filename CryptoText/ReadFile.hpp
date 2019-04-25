#ifndef READFILE_H
#define READFILE_H

void ReadFile(std::string s)
{
	std::ifstream fin;
	fin.open(s);
	if (!fin.is_open())
	{
		std::cout << "File is not open...\n";
	}
	else
	{
		while (!fin.eof())
		{
			char buffer[500];
			fin.getline(buffer, 500);
			char *p = buffer;
			int iS = 0;
			int iW = 0;
			int iG = 0;
			char bufferSymbol[2];
			while (*p)
			{
				if (iG == 3)
				{
					iS++;
					iG = 0;
				}
				if (*p == ' ')
				{
					Data.SecretLineCode[iS][iG] = atoi(bufferSymbol);
					bufferSymbol[0] = '\0';
					bufferSymbol[1] = '\0';
					iW = 0;
					iG++;
					p++;
				}
				else
				{
					bufferSymbol[iW] = *p;
					iW++;
					p++;
				}
			}
			Data.CountSymbol = iS + 1;
		}
	}
}

#endif // !READFILE_H
