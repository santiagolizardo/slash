#pragma once

#include "Command.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "Env.h"

class ChangeDirCommand : public Command {
	private:
		Env env;
		vector<string> args;
	public:
		ChangeDirCommand(const Env& env, const vector<string>& args) : env(env), args(args) {}
		virtual void execute() override;
};
