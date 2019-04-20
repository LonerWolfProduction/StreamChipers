#ifndef ENCODINGCLASS_H
#define ENCODINGCLASS_H

class EncodingClass
{
	char namefile[80];
	int password[80];
	char TextCodingChar[500];
	int TextCoding[500];
public:
	EncodingClass()
	{
		ClMass(namefile);
		ClMass(password);
		ClMass(TextCoding, 500);
		ClMass(TextCodingChar, 500);
	}
	void SetNameFile(char *str)
	{
		strcpy_s(namefile, str);
	}
	void SetPassword(int *pass)
	{
		int *p = pass;
		int i = 0;
		while (*p)
		{
			password[i] = *p;
			i++;
			p++;
		}
	}
	void Encode()
	{
		bool Saving = false;
		std::cout << "Save in file? y/n: ";

		char command[80]; ClMass(command);
		std::cin.getline(command, 80);

		if (!strcmp(command, "y")) Saving = true;
		else if (!strcmp(command, "n")) Saving = false;

		std::ifstream fin;
		fin.open(namefile);
		if (!fin.is_open())
		{
			std::cout << "Error. File destruction or is not found...\n";
		}
		else
		{
			fin.getline(TextCodingChar, 500);
			char *t = TextCodingChar;
			char buffer[10]; ClMass(buffer, 10);
			int i = 0;
			int ic = 0;
			while (*t)
			{
				if (*t == ' ')
				{
					TextCoding[i] = atoi(buffer);
					i++;
					ClMass(buffer, 10);
					t++;
					ic = 0;
				}
				buffer[ic] = (*t);
				ic++;
				t++;
			}
			int *p = TextCoding;
			i = 0;
			int ip = 0;

			std::ofstream fout;
			if (Saving)
			{
				strcat_s(namefile, ".encode.txt");
				fout.open(namefile);
			}
			while (*p)
			{
				if (!password[ip]) ip = 0;
				srand(password[ip]);
				int r = rand();
				if (Saving) fout << (char)(*p - r);
				std::cout << (char)(*p - r);
				p++;
				i++;
				ip++;
			}
			std::cout << "\n";
		}
	}
}Encoder;

#endif // !ENCODINGCLASS_H
