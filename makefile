TEST = test

image_test.o:
	g++ image.cpp -o $(TEST)/image_test --std=c++11

test: image_test.o
	$(TEST)/./image_test

clean:
	@rm -f *.o
	@rm -f test/image_test