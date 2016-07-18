#ifndef _LIST_HPP
# define _LIST_HPP

# include <memory>
# include <stdexcept>
# include <Iterator.hpp>
# define CONTAINER_IMPL
# include <Assert.hpp>

namespace ext_cpp_lexi
{
    namespace __impl
    {
        struct List_node_base
        {
            List_node_base * _next;
            List_node_base * _prev;
        };

        template <typename _Type>
        struct List_node : public List_node_base
        {
            List_node(const _Type & data, List_node_base * prev, List_node_base * next) { _data = data; _prev = prev; _next = next; }
            _Type _data;
        };

        template <typename _Type>
        class List_Iterator : public Iterator<_Type, _Type &, _Type *>
        {
        public:
            explicit List_Iterator(List_node_base * node) : _node(node) {}
            ~List_Iterator() {}
            List_Iterator(const List_Iterator & lvalue) : _node(lvalue._node) {}

            typedef List_Iterator<_Type> self;
            typedef _Type value_type;
            typedef _Type & reference;
            typedef _Type * pointer;

            typedef List_node<value_type> _Node;

            reference operator*() const
            { return static_cast<_Node *>(_node)->_data; }
            pointer operator->() const
            { return addressof(static_cast<_Node*>(_node)->_data); }

            self & operator++()
            { _node = _node->_next; return *this; }
            self & operator--()
            { _node = _node->_prev; return *this; }

//            template <typename _Iterator>
//            bool operator==(const Adaptator::Reverse_Iterator<_Iterator> & lvalue) const
//            { return operator==(lvalue.base()); }
//            template <typename _Iterator>
//            bool operator!=(const Adaptator::Reverse_Iterator<_Iterator> & lvalue) const
//            { return !operator==(lvalue.base()); }

//            bool operator==(const self & lvalue) const
//            { return operator*() == *lvalue; }
//            bool operator!=(const self & lvalue) const
//            { return !operator==(lvalue); }

        private:
            List_node_base * _node;
        };

        template <typename _Type>
        class List_Const_Iterator
        {
            public:
            explicit List_Const_Iterator(const List_node_base * node) : _node(node) {}
            ~List_Const_Iterator() {}
            List_Const_Iterator(const List_Const_Iterator & lvalue) : _node(lvalue._node) {}

            typedef List_Const_Iterator<_Type> self;
            typedef _Type value_type;
            typedef const _Type * pointer;
            typedef const _Type & reference;

            typedef const List_node<value_type> _Node;

            reference operator*() const
            { return static_cast<_Node *>(_node)->_data; }
            pointer operator->() const
            { return addressof(static_cast<_Node*>(_node)->_data); }

            self & operator++()
            { _node = _node->_next; return *this; }
            self & operator--()
            { _node = _node->_prev; return *this; }

//            template <typename _Iterator>
//            bool operator==(const Adaptator::Reverse_Iterator<_Iterator> & lvalue) const
//            { return operator==(lvalue.base()); }
//            template <typename _Iterator>
//            bool operator!=(const Adaptator::Reverse_Iterator<_Iterator> & lvalue) const
//            { return !operator==(lvalue.base()); }

//            bool operator==(const self & lvalue) const
//            { return operator*() == *lvalue; }
//            bool operator!=(const self & lvalue) const
//            { return !operator==(lvalue); }

        private:
            const List_node_base * _node;
        };
    }

    namespace Assert
    {
        template <typename _Type>
        struct is_Iterator<__impl::List_Iterator<_Type>>
        { static const bool value = true; };

        template <typename _Type>
        struct is_Iterator<__impl::List_Const_Iterator<_Type>>
        { static const bool value = true; };
    }

    template <typename _Type>
    class List
    {
    public:
        typedef List<_Type> self;
        typedef _Type value_type;
        typedef _Type & reference;
        typedef _Type * pointer;

        typedef __impl::List_node<_Type> _Node;

        typedef __impl::List_Iterator<_Type> Iterator;
        typedef __impl::List_Const_Iterator<_Type> Const_Iterator;
        typedef Adaptator::Reverse_Iterator<Iterator> Reverse_Iterator;
        typedef Adaptator::Reverse_Iterator<Const_Iterator> Const_Reverse_Iterator;

        List(const reference data)
        {
            _Node * begin = new _Node(data, NULL, NULL);
            _first = begin;
            _last = _first;
        }
        ~List() {}

        self & operator+=(const reference & lvalue)
        {
            _Node * node = new _Node(lvalue, NULL, _first);
            _first = node;
            _first->_next->_prev = _first;
            return *this;
        }

        bool operator==(const self & lvalue) const
        {
            Const_Iterator itA = c_begin();
            for (Const_Iterator itB = lvalue.c_begin(); itA != c_end(); ++itB)
            {
                if (*itA != *itB)
                    return false;
                ++itA;
            }
            return true;
        }
        bool operator!=(const self & lvalue) const
        { return !operator==(lvalue); }

        Iterator begin() const { return Iterator(_first); }
        Iterator end() const { return Iterator(_last); }

        Const_Iterator c_begin() const { return Const_Iterator(_first); }
        Const_Iterator c_end() const { return Const_Iterator(_last); }

        Reverse_Iterator r_begin() const { return Reverse_Iterator(end()); }
        Reverse_Iterator r_end() const { return Reverse_Iterator(begin()); }

        Const_Reverse_Iterator cr_begin() const { return Const_Reverse_Iterator(c_end()); }
        Const_Reverse_Iterator cr_end() const { return Const_Reverse_Iterator(c_begin()); }

    private:
        __impl::List_node_base * _first;
        __impl::List_node_base * _last;
    };

    namespace Assert
    {
        template <typename _Type>
        struct is_Container<List<_Type>>
        { static const bool value = true; };
    }
}

#endif /* _LIST_HPP */
