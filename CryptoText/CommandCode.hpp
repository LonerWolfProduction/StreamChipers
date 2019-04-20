#ifndef COMMANDCODE_H
#define COMMANDCODE_H

void Code()
{
	char namefile[80];
	std::cout << "Please, put name file: ";
	std::cin.getline(namefile, 80);
	Generator.SetNameFile(namefile);

	char password[80]; ClMass(password);
	std::cout << "Please, put password: ";
	std::cin.getline(password, 80);

	int passwordInt[80]; ClMass(passwordInt);
	char *p = password;
	int i = 0;
	while (*p)
	{
		passwordInt[i] = password[i];
		i++;
		p++;
	}
	Generator.SetPassword(passwordInt);

	char Text[500]; ClMass(Text);
	std::cout << "Put text: ";
	std::cin.getline(Text, 500);

	p = Text;
	int TextInt[500]; ClMass(TextInt);
	i = 0;
	while (*p)
	{
		TextInt[i] = Text[i];
		i++;
		p++;
	}
	Generator.CodeMyText(TextInt);
}

#endif // !COMMANDCODE_H
