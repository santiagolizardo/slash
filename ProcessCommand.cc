#include "ProcessCommand.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void ProcessCommand::execute() {
	int status;
	pid_t pid;
	pid = fork();
	if(pid < 0) {
		// error forking
	} else if(pid == 0) {
		system(commandLine.c_str());
		exit(EXIT_SUCCESS);
	} else {
		do {
			waitpid(pid, &status, WUNTRACED);
		} while(!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

