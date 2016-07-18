#ifndef _ITERATOR_TRAITS_HPP
# define _ITERATOR_TRAITS_HPP

namespace ext_cpp_lexi
{
    namespace __impl
    {
        template <typename...> using _void_typename = void;

        template <typename _Iterator, typename = _void_typename<>>
        struct _Iterator_Traits {};

        template <typename _Iterator>
        struct _Iterator_Traits<_Iterator,
                                _void_typename<typename _Iterator::value_type,
                                               typename _Iterator::reference,
                                               typename _Iterator::pointer>>
        {
            typedef typename _Iterator::value_type value_type;
            typedef typename _Iterator::reference reference;
            typedef typename _Iterator::pointer pointer;
        };
    }
    template <typename _Iterator>
    struct Iterator_Traits : public __impl::_Iterator_Traits<_Iterator>
    {};
}

#endif /* _ITERATOR_TRAITS_HPP */
