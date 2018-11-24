#include "Slash.h"

#include <iostream>
using std::cin;
using std::cerr;
using std::cout;
using std::endl;

#include <cstdlib>
#include <cstdio>

#include <sstream>

#include <unistd.h>

#include "Prompt.h"

#include <signal.h>

#include <readline/readline.h>

#include <cstdlib> // setenv

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
			exitFlag = true;
		} else if(command == "cd") {
			if(arguments.size() == 1) {
				chdir(env.getHomeDir().c_str());
			} else {
				const char* dirName = arguments[1].c_str();
				if(chdir(dirName) == -1) {
					cerr << "chdir: " << strerror(errno) << " (" << dirName << ")" << endl;
				}
			}
		} else {
			int status;
			pid_t pid, waitPid;
			pid = fork();
			if(pid < 0) {
				// error forking
			} else if(pid == 0) {
				system(commandLine.c_str());
				exit(EXIT_SUCCESS);
			} else {
				do {
				waitPid = waitpid(pid, &status, WUNTRACED);
				} while(!WIFEXITED(status) && !WIFSIGNALED(status));
			}
		}
	}

	write_history(HISTORY_PATH);

	return exitCode;
}

