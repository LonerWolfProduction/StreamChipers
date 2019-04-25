#ifndef DECODE_H
#define DECODE_H

void Decode()
{
	srand(Password.GetPassword());
	int randInt = rand() % 1000;
	char *p = Data.EnteredLine;
	int iS = 0;
	while (*p)
	{
		int Latter = (int)(*p);
		int iD = 0;
		int Rot[3];
		while (randInt)
		{
			int number = randInt % 10;
			Rot[iD] = XOR(number, Data.SecretLineCode[iS][iD]);
			randInt = randInt / 10;
			if (Latter / 10 != 0) Latter = Latter / 10;
			iD++;
		}
		for (int i = 2; i > -1; i--) Data.DecodeLine[iS] = combine(Data.DecodeLine[iS], Rot[i]);
		p++;
		iS++;
		randInt = rand() % 1000;
		while (randInt < 100)
		{
			randInt = rand() % 1000;
		}
	}
}

#endif // !DECODE_H
