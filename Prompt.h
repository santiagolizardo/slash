#pragma once

#include <string>
using std::string;

#include "Env.h"

class Prompt {

	private:
		Env env;

	public:
		string get() const;
};
