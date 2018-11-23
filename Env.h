#pragma once

#include <string>
using std::string;

class Env {

	public:

		string getUser() const;
		string getHostname() const;
};
