CC	=	gcc
CXX	=	g++
RM	=	rm -f

CXXFLAGS	=	-std=c++11

#Generates regression_using_gradient_descent exectuble file main function object codes
regression_using_gradient_descent: regression_using_gradient_descent.o
	$(CXX) regression_using_gradient_descent.o -o bin/regression_using_gradient_descent.exe

#Generates KNN (main function) object code
regression_using_gradient_descent.o: src/regression_using_gradient_descent.cc
	$(CXX) -c $(CXXFLAGS) src/regression_using_gradient_descent.cc

# #Generates Instance (class) object code
# Instance.o: src/Instance.cpp inc/Instance.hpp
# 	$(CXX) -c src/Instance.cpp

clean:
	$(RM) *.o regression_using_gradient_descent
