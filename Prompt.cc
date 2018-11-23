#include "Prompt.h"

#include <sstream>
using std::ostringstream;

string Prompt::get() const {
	ostringstream iss;
	iss << env.getUser() << "@" << env.getHostname() << "> ";
	return iss.str();
}

