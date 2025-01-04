bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir bin
	g++ -o bin/testListArray testListArray.cpp ListArray.h

clean:
	rm -r *.o *.gch bin
