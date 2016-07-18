#ifndef _ITERATOR_HPP
# define _ITERATOR_HPP

/** @file Iterator.hpp
 *  Ceci est un fichier include interne, destiné à une inclusion
 *  au sein d'autres modules. Ne pas essayer de l'utiliser directement.
 *  @headername(Iterator)
 * 
 * Ce fichier implémente Iterator et un adaptateur Reverse_Iterator,
 * les fonctions qui y sont associées et la surcharge de leurs opérateurs.
 */
# include <impl/Iterator_Traits.hpp>
# define ITERATOR_IMPL
# include <Assert.hpp>

namespace ext_cpp_lexi
{
    /** 
     *  @addtogroup Iterators
     *  @{
     */

    // Iterator
    /**
     *  @brief Squelette de base d'un Iterator
     * 
     *  Ceci constitue le squelette d'un Iterator.
     *  Chaque Iterator doit hériter de ce type squelette.
     */
    template <typename _Type, typename _Reference = _Type &, typename _Pointer = _Type *>
    struct Iterator
    {
        typedef _Type value_type;
        typedef _Reference reference;
        typedef _Pointer pointer;
    };
    namespace Adaptator
    {
        template <typename _Iterator>
        class Reverse_Iterator : public Iterator<typename Iterator_Traits<_Iterator>::value_type,
                                                 typename Iterator_Traits<_Iterator>::reference,
                                                 typename Iterator_Traits<_Iterator>::pointer>
        {
        protected:
            _Iterator _nested;

            typedef Iterator_Traits<_Iterator> _Traits;

        public:
            typedef Reverse_Iterator<_Iterator> self;
            typedef _Iterator nested_iterator;
            typedef typename _Traits::value_type value_type;
            typedef typename _Traits::reference reference;
            typedef typename _Traits::pointer pointer;

            Reverse_Iterator() : _nested() {}
            explicit Reverse_Iterator(nested_iterator it) : _nested(it) {}
            Reverse_Iterator(const Reverse_Iterator & it) : _nested(it._nested) {}

            template <typename _It>
            Reverse_Iterator(const Reverse_Iterator<_It> & it) : _nested(it.base()) {}

            nested_iterator base() const
            { return _nested; }

            reference operator*() const
            {
                nested_iterator _tmp = _nested;
                return *_tmp;
            }
            pointer operator->() const
            { return &(operator*()); }

            self & operator++()
            { --_nested; return *this; }
            self & operator--()
            { ++_nested; return *this; }

//            bool operator==(const self & lvalue) const
//            { return operator==(lvalue.base()); }
//            bool operator==(const nested_iterator & lvalue) const
//            { return _nested == lvalue; }
//            bool operator!=(const self & lvalue) const
//            { return !operator==(lvalue.base()); }
//            bool operator!=(const nested_iterator & lvalue) const
//            { return !operator==(lvalue.base()); }
        };
    }

    namespace Assert
    {
        template <typename _Iterator>
        struct is_Iterator<Adaptator::Reverse_Iterator<_Iterator>>
        { static const bool value = true; };
    }
}

#endif /* _ITERATOR_HPP */
