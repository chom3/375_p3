submission: submission.cpp 

%: %.cpp
	g++ -std=c++11 $< -o $@ -g

%: %.c
	gcc $< -o $@

clean:
	rm -f *.o $(EXECUTABLE)