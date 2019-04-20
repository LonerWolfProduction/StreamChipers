#ifndef COMMANDENCODE_H
#define COMMANDENCODE_H

void Encode()
{
	char namefile[80];
	std::cout << "Please, put name file: ";
	std::cin.getline(namefile, 80);
	Encoder.SetNameFile(namefile);

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
	Encoder.SetPassword(passwordInt);

	Encoder.Encode();
}

#endif // !COMMANDENCODE_H
