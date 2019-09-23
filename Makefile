# build an executable named unitConverter
all: unitConverter.c tempConverter.c timeConverter.c massConverter.c
	gcc -g -o unitConverter unitConverter.c tempConverter.c timeConverter.c massConverter.c -lm

clean:
	$(RM) unitConverter
