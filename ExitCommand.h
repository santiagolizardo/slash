#pragma once

class ExitCommand {
	public:
		void execute() {}
		bool shouldExit() const { return true; }
};
