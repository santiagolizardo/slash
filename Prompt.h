#pragma once

#include <string>
using std::string;

#include "Env.h"

class Prompt {

	private:
		static constexpr char DefaultPrompt[] = "\033[1;31muser\033[0m@machine";

		string evaluate(const string& prompt) const;
		Env env;

	public:
		Prompt(const Env& env) : env(env) {}
		string get() const;
};
