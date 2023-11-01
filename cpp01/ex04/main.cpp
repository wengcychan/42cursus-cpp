#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sys/stat.h>

static void	copyAndReplaceLine( char **argv, std::ifstream &ifs, std::ofstream &ofs ) {

	std::string		line;
	std::size_t		s1Pos;

	std::string s1 = argv[2];
	std::string s2 = argv[3];

	while (getline(ifs, line)) {
	
		while (1)
		{
			if (s1 == s2) {
				ofs << line;
				break;
			}
			s1Pos = line.find(s1);
			ofs << line.substr(0, s1Pos);
			if (s1Pos == std::string::npos)
				break;
			ofs << s2;
			line = line.substr(s1Pos + s1.length());
		}

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

	if (ofs)
		copyAndReplaceLine(argv, ifs, ofs);
	else
		std::cout << "Invalid ofstream" << std::endl;

	ifs.close();
	ofs.close();

	return 0;

}
