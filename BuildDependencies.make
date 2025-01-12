MainEshop: main.o StatisticsReporting.o InitialiseCatalog.o
	cc main.o StatisticsReporting.o InitialiseCatalog.o -o MainEshop

main.o: main.c func.h
	cc -c main.c

StatisticsReporting.o: StatisticsReporting.c func.h
	cc -c StatisticsReporting.c -o StatisticsReporting.o

InitialiseCatalog.o: InitialiseCatalog.c func.h
	cc -c InitialiseCatalog.c -o InitialiseCatalog.o 

