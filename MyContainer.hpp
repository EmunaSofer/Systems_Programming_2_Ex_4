// emuna002@gmail.com
#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <iostream>

namespace ariel {

template<typename T>
class MyContainer {
private:
    std::vector<T> data;

public:
    MyContainer() = default;

    void addElement(const T& element) {
        data.push_back(element);
    }

    void remove(const T& element) {
        bool found = false;
        data.erase(std::remove_if(data.begin(), data.end(), [&](const T& val) {
            if (val == element) {
                found = true;
                return true;
            }
            return false;
        }), data.end());
        if (!found) throw std::runtime_error("Element not found in container");
    }

    size_t size() const {
        return data.size();
    }

    // אופרטור הדפסה
    friend std::ostream& operator<<(std::ostream& os, const MyContainer<T>& container) {
        os << "{";
        for (size_t i = 0; i < container.data.size(); ++i) {
            os << container.data[i];
            if (i != container.data.size() - 1) os << ", ";
        }
        os << "}";
        return os;
    }

    // AscendingOrder Iterator
    class AscendingOrder {
    private:
        MyContainer* container;
        std::vector<T> sorted;
        size_t index;
    public:
        AscendingOrder(MyContainer* c) 
        {
            container = c;
            sorted = c->data;
            std::sort(sorted.begin(), sorted.end());
            index = 0;
        }

        T& operator*() 
        { 
            return sorted[index]; 
        }

        AscendingOrder& operator++() 
        {
             ++index; return *this; 
        }

        bool operator!=(const AscendingOrder& other) const 
        {
             return index != other.index; 
        }

        AscendingOrder begin() 
        {
             return AscendingOrder(container); 
        }

        AscendingOrder end() 
        {
            AscendingOrder it(container);
            it.index = it.sorted.size();
            return it;
        }
    };

    // DescendingOrder Iterator
    class DescendingOrder {
    private:
        MyContainer* container;
        std::vector<T> sorted;
        size_t index;
    public:
       DescendingOrder(MyContainer* c) 
       {
            container = c;
            sorted = c->data;
            std::sort(sorted.begin(), sorted.end(), std::greater<T>());
            index = 0;
        }

        T& operator*() 
        {
             return sorted[index]; 
        }

        DescendingOrder& operator++() 
        {
             ++index; return *this; 
        }

        bool operator!=(const DescendingOrder& other) const 
        {
             return index != other.index; 
        }

        DescendingOrder begin() 
        {
             return DescendingOrder(container); 
        }

        DescendingOrder end() 
        {
            DescendingOrder it(container);
            it.index = it.sorted.size();
            return it;
        }
    };

    // SideCrossOrder Iterator
    class SideCrossOrder {
    private:
        MyContainer* container;// מצביע לקונטיינר שממנו אנחנו שואבים מידע
        std::vector<T> ordered;// ווקטור שמכיל את האובייקטים לפי סדר ספציפי כמבוקש
        size_t index;// כמה אובייקטים יש לי 
    public:
       SideCrossOrder(MyContainer* c) 
       {
            container = c;
            index = 0;
            std::vector<T> sorted = c->data;
            std::sort(sorted.begin(), sorted.end());
            size_t left = 0, right = sorted.size() - 1;
            while (left <= right) {
                ordered.push_back(sorted[left++]);
                if (left <= right) ordered.push_back(sorted[right--]);
            }
        }
        T& operator*() 
        {
             return ordered[index]; 
        }

        SideCrossOrder& operator++() 
        {
             ++index; return *this; 
        }

        bool operator!=(const SideCrossOrder& other) const 
        {
             return index != other.index; 
        }

        SideCrossOrder begin() 
        { 
            return SideCrossOrder(container); 
        }

        SideCrossOrder end() 
        {
            SideCrossOrder it(container);
            it.index = it.ordered.size();
            return it;
        }
    };

    // ReverseOrder Iterator
    class ReverseOrder {
    private:
        MyContainer* container;// מצביע לקונטיינר שממנו אנחנו שואבים מידע
        size_t index;// כמה אובייקטים יש לי 
    public:
        ReverseOrder(MyContainer* c) 
        {
            container = c;
            index = c->data.empty() ? 0 : c->data.size() - 1;
        }
        T& operator*() 
        {
             return container->data[index]; 
        }

        ReverseOrder& operator++() 
        { 
            if (index == 0) index = -1; else --index; return *this; 
        }

        bool operator!=(const ReverseOrder& other) const 
        {
             return index != other.index; 
        }

        ReverseOrder begin() 
        { 
            return ReverseOrder(container); 
        }

        ReverseOrder end() 
        {
            ReverseOrder it(container);
            it.index = static_cast<size_t>(-1);
            return it;
        }
    };

    // Order Iterator (insertion order)
    class Order {
    private:
        MyContainer* container;// מצביע לקונטיינר שממנו אנחנו שואבים מידע
        size_t index;// כמה אובייקטים יש לי 
    public:
       Order(MyContainer* c) 
        {
            container = c;
            index = 0;
        }

        T& operator*() 
        {
             return container->data[index]; 
        }

        Order& operator++() 
        { 
            ++index; return *this; 
        }
        bool operator!=(const Order& other) const 
        {
             return index != other.index; 
        }
        Order begin() 
        {
             return Order(container); 
        }

        Order end() 
        {
            Order it(container);
            it.index = container->data.size();
            return it;
        }
    };

    // MiddleOutOrder Iterator
    class MiddleOutOrder {
    private:
        MyContainer* container;// מצביע לקונטיינר שממנו אנחנו שואבים מידע
        std::vector<T> ordered;// ווקטור שמכיל את האובייקטים לפי סדר ספציפי כמבוקש
        size_t index;// כמה אובייקטים יש לי 
    public:
        MiddleOutOrder(MyContainer* c) {
            container = c;
            index = 0;
            std::vector<T> sorted = c->data;
            std::sort(sorted.begin(), sorted.end());
            size_t n = sorted.size();
            if (n == 0) return;

            size_t mid = n / 2;
            ordered.push_back(sorted[mid]);

            size_t left = 0;
            size_t right = n - 1;

            bool take_from_right = true;
            while (ordered.size() < n) {
                if (take_from_right) {
                    if (right != mid && right < n) {
                        ordered.push_back(sorted[right]);
                        if (right == 0) break;
                        --right;
                    }
                    take_from_right = false;
                } else {
                    if (left != mid && left < n) {
                        ordered.push_back(sorted[left]);
                        if (left == n) break;
                        ++left;
                    }
                    take_from_right = true;
                }
            }
        }

        T& operator*() 
        { 
            return ordered[index]; 
        }

        MiddleOutOrder& operator++() 
        { 
            ++index; return *this; 
        }

        bool operator!=(const MiddleOutOrder& other) const 
        {
             return index != other.index; 
        }

        MiddleOutOrder begin() 
        { 
            return MiddleOutOrder(container); 
        }

        MiddleOutOrder end() 
        {
            MiddleOutOrder it(container);
            it.index = it.ordered.size();
            return it;
        }
    };

    AscendingOrder begin_ascending_order() { return AscendingOrder(this).begin(); }
    AscendingOrder end_ascending_order() { return AscendingOrder(this).end(); }

    DescendingOrder begin_descending_order() { return DescendingOrder(this).begin(); }
    DescendingOrder end_descending_order() { return DescendingOrder(this).end(); }

    SideCrossOrder begin_side_cross_order() { return SideCrossOrder(this).begin(); }
    SideCrossOrder end_side_cross_order() { return SideCrossOrder(this).end(); }

    ReverseOrder begin_reverse_order() { return ReverseOrder(this).begin(); }
    ReverseOrder end_reverse_order() { return ReverseOrder(this).end(); }

    Order begin_order() { return Order(this).begin(); }
    Order end_order() { return Order(this).end(); }

    MiddleOutOrder begin_middle_out_order() { return MiddleOutOrder(this).begin(); }
    MiddleOutOrder end_middle_out_order() { return MiddleOutOrder(this).end(); }
};

} // namespace ariel
