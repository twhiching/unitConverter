# build an executable named unitConverter
all: unitConverter.c tempConverter.c timeConverter.c massConverter.c distanceConverter.c
	gcc -g -o unitConverter unitConverter.c tempConverter.c timeConverter.c massConverter.c distanceConverter.c -lm

clean:
	$(RM) unitConverter
