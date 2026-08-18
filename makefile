build:
	g++ *.cpp -o wayfarer

leak:	
	valgrind --leak-check=full ./wayfarer