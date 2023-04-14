
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
Data& LinearContainer<Data>::Front(){
    if(size!=0)
        return operator[](0);
    else throw std::length_error("Accesso out of bounds negato!");
}

template <typename Data>
Data& LinearContainer<Data>::Back(){
    if(size!=0)
        return operator[](Container::size-1);
    else throw std::length_error("Accesso out of bounds negato!");
}


template <typename Data>
bool LinearContainer<Data>::operator==(const LinearContainer<Data>& lc) const noexcept {
    if(size!=lc.size)
            return false;
    for(int index = 0; index<=size; index++){
        if(operator[](index)!=lc[index])
            return false;
        return true;
    }
}

template <typename Data>
bool LinearContainer<Data>::operator!=(const LinearContainer<Data>& lc) const noexcept {
    return (!*this.operator==);
}

/* ************************************************************************** */

}
