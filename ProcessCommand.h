#pragma once

#include <string>
using std::string;

class ProcessCommand {

	private:
		string commandLine;

	public:
		ProcessCommand(const string& commandLine) : commandLine(commandLine) {}
		void execute();
		bool shouldExit() const { return false; }
};
