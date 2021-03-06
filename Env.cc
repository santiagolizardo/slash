#include "Env.h"

#include <cstdlib> // setenv
#include <unistd.h>

string Env::getUser() const {
	return getenv("USER");
}

string Env::getHostname() const {
	char* hostName = getenv("HOST");
	if(hostName) {
		return hostName;
	}
	char hostNameBuffer[100];
	gethostname(hostNameBuffer, 100);
	return hostNameBuffer;
}

string Env::getHomeDir() const {
	return getenv("HOME");
}

bool Env::hasPrimaryPromptString() const {
	return getenv("PS1") != nullptr;
}

/**
 * Assumes ANSI-C Quoting
 */
string Env::getPrimaryPromptString() const {
	return getenv("PS1");
}

bool Env::hasSecondaryPromptString() const {
	return getenv("PS2") != nullptr;
}

/**
 * Assumes ANSI-C Quoting
 */
string Env::getSecondaryPrompyString() const {
	return getenv("PS2");
}


void Env::setShell(const string& shell) const {
	setenv("SHELL", shell.c_str(), 1);
}
