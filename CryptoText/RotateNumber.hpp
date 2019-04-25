#ifndef ROTATENUMBER_H
#define ROTATENUMBER_H

int RotateNumber(int number) {
	std::ostringstream output_stream;
	int result;

	output_stream << number;
	std::string str_number = output_stream.str();

	std::reverse(str_number.begin(), str_number.end());

	std::istringstream input_stream(str_number, std::istringstream::in);
	input_stream >> result;

	return result;
}

#endif // !ROTATENUMBER_H
