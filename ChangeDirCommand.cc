#include "ChangeDirCommand.h"

#include <cstdio>
#include <unistd.h>

void ChangeDirCommand::execute() const {
	if(args.size() == 1) {
		chdir(env.getHomeDir().c_str());
	} else {
		const char* dirName = args[1].c_str();
		if(chdir(dirName) == -1) {
//			cerr << "chdir: " << strerror(errno) << " (" << dirName << ")" << endl;
		}
	}
}

bool ChangeDirCommand::shouldExit() const {
	return false;
}
