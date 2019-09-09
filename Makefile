# build an executable named unitConverter
all: unitConverter.c tempConverter.c
	gcc -g -o unitConverter unitConverter.c tempConverter.c

clean:
	$(RM) unitConverter
