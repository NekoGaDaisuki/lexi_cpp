#include <iostream>
#include <List.hpp>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestList
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(ListCTORS)
{
//    using namespace ext_cpp_lexi;
    int array[] = { 7, 1, 2, 3, 4 };
    ext_cpp_lexi::List<int> mylist(array[0]);
    mylist += array[2];
    ext_cpp_lexi::List<int>::Reverse_Iterator itA = mylist.r_begin();
    int i = 10;
    i = *itA;
    std::cout << "i : '" << i << "'" << std::endl;
    ++itA;
    i = *itA;
    std::cout << "i : '" << i << "'" << std::endl;
    static_assert(ext_cpp_lexi::Assert::is_Iterator<ext_cpp_lexi::List<int>::Reverse_Iterator>::value, "Reverse_Iterator wasn't recognized as an Iterator");
    static_assert(ext_cpp_lexi::Assert::is_Iterator<ext_cpp_lexi::List<int>::Iterator>::value, "Iterator wasn't recognized as an Iterator");
}
