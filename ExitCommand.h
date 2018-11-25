#pragma once

#include "Command.h"

class ExitCommand : public Command {
	public:
		virtual void execute() override {}
		virtual bool shouldExit() override { return true; }
};
