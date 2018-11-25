#pragma once

#include "Command.h"

#include <string>
using std::string;

class ProcessCommand : public Command {

	private:
		string commandLine;

	public:
		ProcessCommand(const string& commandLine) : commandLine(commandLine) {}
		virtual void execute() override;
};
