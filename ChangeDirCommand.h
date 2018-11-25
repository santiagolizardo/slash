#pragma once

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "Env.h"

class ChangeDirCommand {
	private:
		vector<string> args;
		Env env;
	public:
		ChangeDirCommand(const Env& env, const vector<string>& args)
			: env(env), args(args)
			{}
		void execute() const;
		bool shouldExit() const;
};
