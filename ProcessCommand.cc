#include "ProcessCommand.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ProcessCommand::execute() {
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

