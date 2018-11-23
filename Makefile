
sources=Env.cc Slash.cc Main.cc Prompt.cc

all:
	c++ $(sources) -lreadline -std=c++17 -o slash

clean:
	rm -f slash

