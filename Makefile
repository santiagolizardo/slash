
compiler := c++
program_name := slash
src_dir := .
obj_dir := .

sources = $(wildcard $(src_dir)/*.cc)
objects = $(patsubst $(src_dir)/%.cc, $(obj_dir)/%.o, $(sources))

$(program_name): $(objects)
	$(compiler) $^ -lreadline -o $@

$(obj_dir)/%.o: $(src_dir)/%.cc
	$(compiler) -std=c++17 -c $< -o $@

clean:
	rm -f *.o
	rm -f $(program_name)

