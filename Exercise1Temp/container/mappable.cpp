
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */
//Fold

template <typename Data>
void MappableContainer<Data>::Fold(FoldFunctor fun, void* pointer){
    Map( //MapFunctor anonimo
        [&fun, &pointer](const Data& dat){
            fun(&dat, pointer); //FoldFunctor
        }
    );
};

template <typename Data>
void PreOrderMappableContainer<Data>::PreOrderFold(FoldFunctor fun, void* pointer){
    PreOrderMap( //MapFunctor anonimo
        [&fun, &pointer](const Data& dat){
            fun(&dat, pointer); //FoldFunctor
        }
    );
};


template <typename Data>
void PostOrderMappableContainer<Data>::PostOrderFold(FoldFunctor fun, void* pointer){
    PostOrderMap( //MapFunctor anonimo
        [&fun, &pointer](const Data& dat){
            fun(&dat, pointer); //FoldFunctor
        }
    );
};


//Da implementare le altre
/* ************************************************************************** */

}
