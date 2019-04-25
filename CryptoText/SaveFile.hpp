#ifndef SAVEFILE_H
#define SAVEFILE_H

void SaveFile(char *p)
{
	std::ofstream fout;
	fout.open(p);
	bool exit = false;
	for (int i = 0; i < Data.CountSymbol && !exit; i++)
		for (int t = 0; t < 3; t++)
		{
			fout << Data.SecretLineCode[i][t] << " ";
		}
	fout.close();
}

void SaveFileDecode(char *p)
{
	std::ofstream fout;
	fout.open(p);
	bool exit = false;
	for (int i = 0; i < Data.CountSymbol && !exit; i++)
	{
		fout << (char)Data.DecodeLine[i];
	}
	fout.close();
}

#endif // !SAVEFILE_H
