#pragma once

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "Env.h"

class Slash {

	private:
		static void signalHandler(int number);

		vector<string> splitLine(const string& line);

		static constexpr char HISTORY_PATH[] = ".slash_history";

		Env env;

	public:
		Slash(int argc, char** argv);
		int run();
};

