#// emuna002@gmail.com
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror
Main = main
TEST = test
HEADERS = MyContainer.hpp

# קובצי המקור
SRC_Main = $(Main).cpp
SRC_TEST = $(TEST).cpp

# קובץ ההרצה של הדמו
Main: $(SRC_Main) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o Main $(SRC_Main)

# קובץ ההרצה של הבדיקות
test: $(SRC_TEST) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o test $(SRC_TEST)
	./test

# בדיקת זליגות זיכרון
valgrind: Main test
	valgrind --leak-check=full --track-origins=yes ./Main
	valgrind --leak-check=full --track-origins=yes ./test

# ניקוי קבצי הפלט
clean:
	rm -f Main test
