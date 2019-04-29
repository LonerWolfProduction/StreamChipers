#ifndef ENCODE_H
#define ENCODE_H

void Encode()
{
	srand(Password.GetPassword());
	int randInt = rand() % 1000;
	while (randInt < 100) randInt = rand() % 1000;
	char *p = Data.EnteredLine;
	int iS = 0;
	int iteration = 0;
	while (*p)
	{
		int Latter = (int)(*p);
		int iD = 0;
		while (randInt)
		{
			int number = randInt % 10;
			int number2 = Latter % 10;
			
			Data.SecretLineCode[iS][iD] = XOR(number, number2);
			randInt = randInt / 10;
			Latter = Latter / 10;
			iD++;
		}
		p++;
		iS++;
		randInt = rand() % 1000;
		while (randInt < 100)
		{
			randInt = rand() % 1000;
		}
		iteration++;
	}
	Data.CountSymbol = iteration;
}

#endif // !ENCODE_H
