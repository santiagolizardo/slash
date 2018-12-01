#include "ChangeDirCommand.h"

#include <cstdio>
#include <unistd.h>

#include <unistd.h>
#include <errno.h>

#include "CommandException.h"

#include <sstream>
using std::ostringstream;

void ChangeDirCommand::execute() {
	if(args.size() == 1) {
		chdir(env.getHomeDir().c_str());
	} else {
		const char* dirName = args[1].c_str();
		if(chdir(dirName) == -1) {
			ostringstream oss;
			oss << "chdir: " << strerror(errno) << " (" << dirName << ")";
			throw CommandException(oss.str());
		}
	}
}

