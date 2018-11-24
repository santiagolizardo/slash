#pragma once

#include <string>
using std::string;

#include "Env.h"

class Prompt {

	private:
		Env env;

	public:
		Prompt(const Env& env) : env(env) {}
		string get() const;
};
