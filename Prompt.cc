#include "Prompt.h"

#include <sstream>
using std::ostringstream;

#include <iostream>
using std::cout;

string Prompt::get() const {
	string prompt = env.hasPrimaryPromptString() ? env.getPrimaryPromptString() : DefaultPrompt;
	ostringstream oss;
	oss << evaluate(prompt) << std::endl;
	return oss.str();
}

string Prompt::evaluate(const string& prompt) const {
	return prompt;
}

