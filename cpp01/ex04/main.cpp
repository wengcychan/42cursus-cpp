#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sys/stat.h>

static void copyAndReplaceLine(const std::string& s1, const std::string& s2, std::ifstream& ifs, std::ofstream& ofs) {

	std::string line;
	while (std::getline(ifs, line)) {
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
				line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
				pos += s2.length();
		}
		ofs << line;
		if (!ifs.eof())
			ofs << std::endl;
	}
}

int	main ( int argc, char **argv ) {

	if (argc != 4 || !std::strcmp(argv[2], "") ) {
		std::cout << "Invalid Input" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::ifstream	ifs(filename);
  struct stat		info;
	stat(filename.c_str(), &info);
	if (!ifs || (info.st_mode & S_IFDIR)) {
		std::cout << "Invalid ifstream" << std::endl;
		ifs.close();
		return 1;
	}

	std::ofstream	ofs(filename + ".replace");
	if (!ofs)
	{
		std::cout << "Invalid ofstream" << std::endl;
		ifs.close();
		ofs.close();
		return 1;	
	}

	copyAndReplaceLine(argv[2], argv[3], ifs, ofs);
	ifs.close();
	ofs.close();

	return 0;
}
