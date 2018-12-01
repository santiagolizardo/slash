#pragma once

#include <exception>
using std::exception;

#include <string>
using std::string;

class CommandException : public exception {
	private:
		string message;
	public:
		CommandException(const string& s) : exception(), message(s) {}
		virtual const char* what() const throw () {
			return message.c_str();
		}
};

