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

#include <cstdlib> // setenv

#include "ChangeDirCommand.h"
#include "ExitCommand.h"
#include "ProcessCommand.h"

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

	setenv("SHELL", argv[0], 1);
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
		string command = arguments[0];
		if(command == "exit") {
			ExitCommand command;
			command.execute();
			exitFlag = command.shouldExit();
		} else if(command == "cd") {
			ChangeDirCommand command(env, arguments);
			command.execute();
			exitFlag = command.shouldExit();
		} else {
			ProcessCommand command(commandLine);
			command.execute();
			exitFlag = command.shouldExit();
		}
	}

	write_history(HISTORY_PATH);

	return exitCode;
}

