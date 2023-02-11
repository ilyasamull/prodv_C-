#include <iostream>
#include <chrono>
#include <limits>

template <typename Resolution>
class Timer {
public:
    Timer() = default;
    ~Timer() = default;
public:
    void start();
    void stop();
private:
    std::chrono::steady_clock::time_point start_time;
};

template <typename Resolution>
void Timer<Resolution>::start() {
    start_time = std::chrono::steady_clock::now();
}

template <typename Resolution>
void Timer<Resolution>::stop() {
    std::cout << std::chrono::duration_cast<Resolution>(std::chrono::steady_clock::now() - start_time).count() << std::endl;
}

int main() {
    std::cout << "Time of incrementation" << std::endl;

    std::cout << "signed: ";
    Timer<std::chrono::milliseconds> timer_signed_increment;
    timer_signed_increment.start();
    for (signed int i = std::numeric_limits<signed int>::min(); i != std::numeric_limits<signed int>::max(); ++i) {}
    timer_signed_increment.stop();

    std::cout << "unsigned: ";
    Timer<std::chrono::milliseconds> timer_unsigned_increment;
    timer_unsigned_increment.start();
    for (unsigned int i = std::numeric_limits<unsigned int>::min(); i != std::numeric_limits<unsigned int>::max(); ++i) {}
    timer_unsigned_increment.stop();


    std::cout << "Time of decrementation:" << std::endl;

    std::cout << "signed: ";
    Timer<std::chrono::milliseconds> timer_signed_decrement;
    timer_signed_decrement.start();
    for (signed int i = std::numeric_limits<signed int>::max(); i != std::numeric_limits<signed int>::min(); --i) {}
    timer_signed_decrement.stop();

    std::cout << "unsigned: ";
    Timer<std::chrono::milliseconds> timer_unsigned_decrement;
    timer_unsigned_decrement.start();
    for (unsigned int i = std::numeric_limits<unsigned int>::max(); i != std::numeric_limits<unsigned int>::min(); --i) {}
    timer_unsigned_decrement.stop();


    std::cout << "Time of multiplication:" << std::endl;

    std::cout << "signed: ";
    Timer<std::chrono::milliseconds> timer_signed_multiply;
    timer_signed_multiply.start();
    for (int i = 0; i != 1e8; ++i) {
        for (signed int j = 1; j < 1e8; j *= 3) {}
    }
    timer_signed_multiply.stop();

    std::cout << "unsigned: ";
    Timer<std::chrono::milliseconds> timer_unsigned_multiply;
    timer_unsigned_multiply.start();
    for (int i = 0; i != 1e8; ++i) {
        for (unsigned int j = 1u; j < 1e8; j *= 3) {}
    }
    timer_unsigned_multiply.stop();


    std::cout << "Time of division:" << std::endl;

    std::cout << "signed: ";
    Timer<std::chrono::milliseconds> timer_signed_divide;
    timer_signed_divide.start();
    for (int i = 0; i != 1e8; ++i) {
        for (signed int j = 1e8; j > 0; j /= 3) {}
    }
    timer_signed_divide.stop();

    std::cout << "unsigned: ";
    Timer<std::chrono::milliseconds> timer_unsigned_divide;
    timer_unsigned_divide.start();
    for (int i = 0; i != 1e8; ++i) {
        for (unsigned int j = 1e8; j > 0; j /= 3) {}
    }
    timer_unsigned_divide.stop();
}