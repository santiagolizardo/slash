#pragma once

#include <vector>
using std::vector;

#include <string>
using std::string;

class Slash {

	private:
		static void signalHandler(int number);

		vector<string> splitLine(const string& line);

		static constexpr char HISTORY_PATH[] = ".slash_history";

	public:
		Slash(int argc, char** argv);
		int run();
};

