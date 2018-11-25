#pragma once

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "Env.h"

class Slash {

	private:
		static constexpr char HISTORY_PATH[] = ".slash_history";
		static void signalHandler(int number);
		Env env;
		vector<string> splitLine(const string& line);

	public:
		Slash(int argc, char** argv);
		int run();
};

