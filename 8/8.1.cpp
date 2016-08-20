//
// 8.1.cpp
// c++1x tutorial
//
// created by changkun at shiyanlou.com
//
// noexcept

#include <iostream>

void may_throw() {
    throw true;
}
auto non_block_throw = []{
    may_throw();
};
void no_throw() noexcept {
    return;
}

auto block_throw = []() noexcept {
    no_throw();
};

int main()
{
    std::cout << std::boolalpha
    << "may_throw() noexcept? " << noexcept(may_throw()) << std::endl
    << "no_throw() noexcept? " << noexcept(no_throw()) << std::endl
    << "lmay_throw() noexcept? " << noexcept(non_block_throw()) << std::endl
    << "lno_throw() noexcept? " << noexcept(block_throw()) << std::endl;
    
    try {
        may_throw();
    } catch (...) {
        std::cout << "捕获异常, 来自 my_throw()" << std::endl;
    }
    
    try {
        non_block_throw();
    } catch (...) {
        std::cout << "捕获异常, 来自 non_block_throw()" << std::endl;
    }
    
    try {
        block_throw();
    } catch (...) {
        std::cout << "捕获异常, 来自 block_throw()" << std::endl;
    }
}
