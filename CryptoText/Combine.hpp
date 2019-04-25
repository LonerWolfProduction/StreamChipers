#ifndef COMBINE_H
#define COMBINE_H

int combine(int a, int b)
{
	std::stringstream stream;
	stream << a << b;
	int c;
	stream >> c;
	return c;
}

#endif // !COMBINE_H
