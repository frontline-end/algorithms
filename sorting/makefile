cc = clang
c_flags = -Wall -Wextra -g
src = bubbleSort
target = out

all: $(target)

$(target): $(src)
	$(cc) $(c_flags) $(src).c -o $(target)

run:
	./$(target)

clear:
	rm -f *c~ $(target) $(src)
