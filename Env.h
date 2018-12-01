#pragma once

#include <string>
using std::string;

class Env {

	public:

		string getUser() const;
		string getHostname() const;
		string getHomeDir() const;
		bool hasPrimaryPromptString() const;
		string getPrimaryPromptString() const;
		bool hasSecondaryPromptString() const;
		string getSecondaryPrompyString() const;
		void setShell(const string& shell) const;
};
