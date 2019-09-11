# build an executable named unitConverter
all: unitConverter.c tempConverter.c timeConverter.c
	gcc -g -o unitConverter unitConverter.c tempConverter.c timeConverter.c

clean:
	$(RM) unitConverter
