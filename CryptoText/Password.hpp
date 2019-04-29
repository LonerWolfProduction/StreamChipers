#ifndef PASSWORD_H
#define PASSWORD_H

class PasswordClass
{
	char Password[64];
	int CodePassword;
	void Generation()
	{
		char *pPass = Password;
		while (*pPass)
		{
			CodePassword = (CodePassword * (*pPass)) % 1000000000;
			pPass++;
		}
	}
public:
	PasswordClass()
	{
		ClMass(Password, 64);
		strcpy_s(Password, "defaultpassword");
		CodePassword = 1;
	}
	void Initialization(std::string s)
	{
		strcpy_s(Password, s.c_str());
		Generation();
	}
	int GetPassword()
	{
		return CodePassword;
	}
}Password;

#endif // !PASSWORD_H
