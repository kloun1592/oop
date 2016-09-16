#include "stdafx.h"

namespace
{

bool isNumber(const std::string & str)
{
	return std::all_of(str.begin(), str.end(), std::isdigit);
}

uint8_t reverseByte(const uint8_t byte)
{
	auto reverseByte = byte;
	reverseByte = ((reverseByte & 0x55) << 1) | ((reverseByte & 0xAA) >> 1);
	reverseByte = ((reverseByte & 0xCC) >> 2) | ((reverseByte & 0x33) << 2);
	reverseByte = (reverseByte >> 4) | (reverseByte << 4);
	return reverseByte;
}

}

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		std::cerr << "Invalid params. Use this:" << std::endl;
		std::cerr << "flipbyte.exe <input byte>" << std::endl;
		std::exit(-1);
	}

	const std::string inputData = argv[1];
	if (!isNumber(inputData))
	{
		std::cerr << "<input byte> must be unsigned integer(0..255)" << std::endl;
		std::exit(-2);
	}

	if (!((atoi(inputData.c_str()) >= 0 && atoi(inputData.c_str()) <= 255)))
	{
		std::cerr << "<input byte> must be 0..255" << std::endl;
		std::exit(-3);
	}

	const uint8_t inputByte = static_cast<uint8_t>(atoi(inputData.c_str()));
	printf("%u\n", reverseByte(inputByte));

	return 0;
}
