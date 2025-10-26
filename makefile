cc = clang
c_flags = -Wall -Wextra -g
src = bst
target = out

all: $(target)

$(target): $(src)
	$(cc) $(c_flags) $(src).c -o $(target)

run:
	./$(target)

clear:
	rm -f *~ $(target) $(src)

clear_save:
	rm -f *#


