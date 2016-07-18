/** @file Assert.hpp
 *  Ceci est un fichier include utilisateur destiné à fournir
 *  des assertions.
 *  @headername(Assert)
 * 
 *  Ce fichier implémente diverses assertions statiques permettant
 *  à l'utilisateur de valider l'usage des composants de la bibliothèque
 *  à la compilation.
 */

namespace ext_cpp_lexi
{
    namespace Assert
    {
# if defined CONTAINER_IMPL && !defined CONTAINER_ASSERT
#  define CONTAINER_ASSERT
        /** @var is_Container
         * 
         */
        template <typename _Type>
        struct is_Container
        { static const bool value = false; };
# endif /* CONTAINER_ASSERT */

# if defined ITERATOR_IMPL && !defined ITERATOR_ASSERT
#  define ITERATOR_ASSERT
        template <typename _Type>
        struct is_Iterator
        { static const bool value = false; };
# endif /* ITERATOR_ASSERT */
    }
}
