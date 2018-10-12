CFLAGS = -g -Wall

all: bank.o event.o customer.o teller.o customerevent.o tellerevent.o tellerqueue.o eventqueue.o
	g++ -Wall bank.o event.o customer.o teller.o customerevent.o tellerevent.o tellerqueue.o eventqueue.o -o qSim
	
bank.o: bank.cpp teller.h customer.h tellerevent.h customerevent.h tellerqueue.h eventqueue.h
	g++ $(CFLAGS) -c bank.cpp
event.o: event.cpp event.h
	g++ $(CFLAGS) -c event.cpp
customer.o: customer.cpp customer.h customerevent.h
	g++ $(CFLAGS) -c customer.cpp
teller.o: teller.cpp teller.h
	g++ $(CFLAGS) -c teller.cpp
customerevent.o: customerevent.cpp customerevent.h customer.h tellerqueue.h
	g++ $(CFLAGS) -c customerevent.cpp
tellerevent.o: tellerevent.cpp tellerevent.h
	g++ $(CFLAGS) -c tellerevent.cpp
tellerqueue.o: tellerqueue.cpp tellerqueue.h
	g++ $(CFLAGS) -c tellerqueue.cpp
eventqueue.o: eventqueue.cpp eventqueue.h customerevent.h
	g++ $(CFLAGS) -c eventqueue.cpp
clean:
	rm -f *.o qSim
	rm -f -r html latex
docs:
	doxygen
