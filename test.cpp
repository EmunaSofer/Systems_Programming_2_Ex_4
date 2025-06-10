// emuna002@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.hpp"
#include <sstream>

using namespace ariel;

TEST_CASE("Basic addElement/remove/size functionality") {
    MyContainer<int> c;
    CHECK(c.size() == 0);

    c.addElement(5);
    c.addElement(10);
    c.addElement(5);
    CHECK(c.size() == 3);

    c.remove(5);
    CHECK(c.size() == 1);

    CHECK_THROWS_AS(c.remove(100), std::runtime_error);
}

TEST_CASE("AscendingOrder iteration") {
    MyContainer<int> c;
    c.addElement(7); c.addElement(15); c.addElement(6); c.addElement(1); c.addElement(2);

    std::vector<int> expected = {1, 2, 6, 7, 15};
    std::vector<int> result;
    for (auto it = c.begin_ascending_order(); it != c.end_ascending_order(); ++it) {
        result.push_back(*it);
    }
    CHECK(result == expected);
}

TEST_CASE("DescendingOrder iteration") {
    MyContainer<int> c;
    c.addElement(7); c.addElement(15); c.addElement(6); c.addElement(1); c.addElement(2);

    std::vector<int> expected = {15, 7, 6, 2, 1};
    std::vector<int> result;
    for (auto it = c.begin_descending_order(); it != c.end_descending_order(); ++it) {
        result.push_back(*it);
    }
    CHECK(result == expected);
}

TEST_CASE("SideCrossOrder iteration") {
    MyContainer<int> c;
    c.addElement(7); c.addElement(15); c.addElement(6); c.addElement(1); c.addElement(2);

    std::vector<int> expected = {1, 15, 2, 7, 6};
    std::vector<int> result;
    for (auto it = c.begin_side_cross_order(); it != c.end_side_cross_order(); ++it) {
        result.push_back(*it);
    }
    CHECK(result == expected);
}

TEST_CASE("ReverseOrder iteration") {
    MyContainer<int> c;
    c.addElement(7); c.addElement(15); c.addElement(6); c.addElement(1); c.addElement(2);

    std::vector<int> expected = {2, 1, 6, 15, 7};
    std::vector<int> result;
    for (auto it = c.begin_reverse_order(); it != c.end_reverse_order(); ++it) {
        result.push_back(*it);
    }
    CHECK(result == expected);
}

TEST_CASE("Order iteration (insertion)") {
    MyContainer<int> c;
    c.addElement(7); c.addElement(15); c.addElement(6); c.addElement(1); c.addElement(2);

    std::vector<int> expected = {7, 15, 6, 1, 2};
    std::vector<int> result;
    for (auto it = c.begin_order(); it != c.end_order(); ++it) {
        result.push_back(*it);
    }
    CHECK(result == expected);
}

TEST_CASE("MiddleOutOrder iteration") {
    MyContainer<int> c;
    c.addElement(7); c.addElement(15); c.addElement(6); c.addElement(1); c.addElement(2);

    std::vector<int> expected = {6, 15, 1, 7, 2};
    std::vector<int> result;
    for (auto it = c.begin_middle_out_order(); it != c.end_middle_out_order(); ++it) {
        result.push_back(*it);
    }
    CHECK(result == expected);
}

TEST_CASE("operator<< output format") {
    MyContainer<int> c;
    c.addElement(4); c.addElement(7); c.addElement(1);

    std::ostringstream out;
    out << c;

    std::string str = out.str();
    CHECK(str.find("4") != std::string::npos);
    CHECK(str.find("7") != std::string::npos);
    CHECK(str.find("1") != std::string::npos);
    CHECK(str.front() == '{');
    CHECK(str.back() == '}');
}
