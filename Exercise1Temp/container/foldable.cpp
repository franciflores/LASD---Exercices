
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */


template <typename Data>
bool FoldableContainer<Data>::Exists(const Data& valoreComparare) const noexcept {
    bool valoreBool = false;
    Fold({ //Funzione anonima
            [this, &valoreComparare](const Data& valoreAttuale, void* esisteBool){
                if(valoreAttuale==valoreComparare){
                    (bool*)esisteBool=true;
                }
            }
        }, &valoreBool); 
    return valoreBool;
}
/* ************************************************************************** */

}
