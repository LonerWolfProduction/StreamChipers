#ifndef GENERATORCLASS_H
#define GENERATORCLASS_H

class GeneratorClass
{
	char namefile[80];
	int password[80];
	int TextCoding[500];
	void SaveFileCodeText()
	{
		std::ofstream fout;
		fout.open(namefile);
		int *p = TextCoding;
		while (*p)
		{
			fout << *p << " ";
			p++;
		}
		fout.close();
	}
public:
	GeneratorClass()
	{
		ClMass(password);
		ClMass(TextCoding);
		ClMass(namefile);
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
	void CodeMyText(int *text)
	{
		int i = 0;
		int ip = 0;
		while (*text)
		{
			if (!password[ip]) ip = 0;
			srand(password[ip]);
			TextCoding[i] = (*text) + rand();
			text++;
			i++;
			ip++;
		}
		SaveFileCodeText();
	}
}Generator;

#endif // !GENERATORCLASS_H
