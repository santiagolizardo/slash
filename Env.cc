#include "Env.h"

#include <cstdlib>
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

