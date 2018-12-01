#include "Slash.h"

#include <iostream>
using std::cin;
using std::cerr;
using std::cout;
using std::endl;

#include <cstdlib>
#include <cstdio>

#include <sstream>

#include "Prompt.h"

#include <signal.h>

#include <readline/readline.h>

#include <memory>
using std::unique_ptr;

#include "ChangeDirCommand.h"
#include "ExitCommand.h"
#include "ProcessCommand.h"
#include "CommandException.h"

vector<string> Slash::splitLine(const string& line) {
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(line);
	while (std::getline(tokenStream, token, ' ')) {
		tokens.push_back(token);
	}
	return tokens;
}

Slash::Slash(int argc, char** argv) {
	signal(SIGINT, Slash::signalHandler);

	read_history(HISTORY_PATH);

	env.setShell(argv[0]);
}

void Slash::signalHandler(int number) {
}

int Slash::run() {
	Prompt prompt(env);
	int exitCode = EXIT_SUCCESS;
	bool exitFlag = false;
	while(!exitFlag) {
		string commandLine;
		char* readLineBuffer = readline(prompt.get().c_str());
		if(readLineBuffer) {
			commandLine = readLineBuffer;
			add_history(readLineBuffer);
			free(readLineBuffer);
		}
		if(commandLine.empty()) {
			continue;
		}
		vector<string> arguments = splitLine(commandLine);
		string programName = arguments[0];
		unique_ptr<Command> command;
		if(programName == "exit") {
			command = unique_ptr<Command>(new ExitCommand());
		} else if(programName == "cd") {
			command = unique_ptr<Command>(new ChangeDirCommand(env, arguments));
		} else {
			command = unique_ptr<Command>(new ProcessCommand(commandLine));
		}
		try {
			command->execute();
			exitFlag = command->shouldExit();
		} catch(const CommandException& ce) {
			cerr << "ERROR: " << ce.what() << endl;
		}
	}

	write_history(HISTORY_PATH);

	return exitCode;
}

