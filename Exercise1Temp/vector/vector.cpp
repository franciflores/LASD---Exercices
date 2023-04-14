#include "vector.hpp"

namespace lasd {

/* ************************************************************************** */

// Costruttori Specifici
template <typename Data>
Vector<Data>::Vector(ulong size){
    VectorImplementato = new Data[size] = {}; //Instanziamo un vettore standard (anonimo)
    dimensione = size;                             //dimensione del vettore
}

template <typename Data>
Vector<Data>::Vector(MappableContainer<Data>& MapCont){
    dimensione = MapCont.size;                             //dimensione del vettore
    VectorImplementato = new Data[dimensione] = {}; //Instanziamo un vettore standard (anonimo)
    ulong index = 0;
    MapCont.Map(//MapFunctor
        [this,&index](const Data& dat){
            VectorImplementato[index++] = dat;
        }
    );
}

template <typename Data>
Vector<Data>::Vector(MutableMappableContainer<Data>& MapCont){
    dimensione = MapCont.size;
    VectorImplementato = new Data[dimensione] = {};
    ulong index = 0;
    MapCont.Map(
        [this, &index](Data& dat){
            VectorImplementato[index++] = std::move(dat);
        }
    );
}


/* *************************************************************************** */
//Costruttori Copy e Move
template <typename Data>
Vector<Data>::Vector(const Vector<Data>& vet){
    dimensione = vet.size;
    VectorImplementato = new Data[dimensione];
    //copy(puntatore primo posto, puntatore ultimo posto, dove copiare)
    std::copy(vet, vet+vet.size, VectorImplementato);    
}

template <typename Data>
Vector<Data>::Vector(Vector<Data> && vet)noexcept{
    //move
    std::swap(VectorImplementato, vet.VectorImplementato);
    std::swap(dimensione, vet.dimensione);
}

/* *************************************************************************** */
//Operatori
template <typename Data>
Data& Vector<Data>::operator[](const ulong index){
    if(index<=size)
        return VectorImplementato[index];
    else 
        throw std::out_of_range("Out of Bounds!");
}

template <typename Data>
Data& Vector<Data>::operator[](const ulong index) const{
    if(index<=size)
        return VectorImplementato[index];
    else 
        throw std::out_of_range("Out of Bounds!");
}

template <typename Data>
Data& Vector<Data>::Front() const {
    LinearContainer<Data>::Front();
}

template <typename Data>
Data& Vector<Data>::Front(){
    LinearContainer<Data>::Front();
}

template <typename Data>
Data& Vector<Data>::Back() const {
    LinearContainer<Data>::Back();
}

template <typename Data>
Data& Vector<Data>::Back() {
    LinearContainer<Data>::Back();
}

/* ************************************************************************** */

template <typename Data>
bool Vector<Data>::operator==(const Vector<Data>& vet) const noexcept {
    if(size!=vet.size)
            return false;
    for(int index = 0; index<=size; index++){
        if(VectorImplementato[index]!=vet.VectorImplementato[index])
            return false;
        return true;
    }
}

template <typename Data>
bool Vector<Data>::operator!=(const Vector<Data>& vet) const noexcept {
    if(size!=vet.size)
        return true;
    for(int index; index<=size; index++){
        if(VectorImplementato[index]!=vet.VectorImplementato[index])
            return true;
        return false;
    }
}

//Copy e Move assignments
template <typename Data> //Copy
Vector<Data>& Vector<Data>::operator=(const Vector<Data>& vet){
    //Istanziamo un vettore e usiamo il costruttore con i MappableContainer
    Vector<Data>* vetDiScambio = new Vector<Data>(vet);
    std::swap(vetDiScambio, *this);
    delete vetDiScambio;
    return *this;  
}

template <typename Data>
Vector<Data>& Vector<Data>::operator=(Vector<Data>&& vet) noexcept {
    //Swappiamo il contenuto della classe
    std::swap(VectorImplementato, vet.VectorImplementato);
    std::swap(dimensione, vet.dimensione);
    return *this;
}

/* ************************************************************************** */
//Distruttore

template <typename Data>
Vector<Data>::~Vector(){
    delete[] VectorImplementato;
}
/* ************************************************************************** */
//Funzioni specifiche
template <typename Data>
void Vector<Data>::Clear(){
    for(int index; index<=size; index++){
        VectorImplementato[index] = 0;
    }
    size = 0;
}

template <typename Data>
void Vector<Data>::Resize(ulong newSize){
    if(newSize>size){
        Vector<Data>* vetDiScambio = new Vector<Data>(newSize);
        for(int index = 0; index<=size; index++){
            vetDiScambio[index]=VectorImplementato[index];
        }
        std::swap(vetDiScambio,VectorImplementato);
        delete vetDiScambio;
    }
    else if(newSize<size){
        Vector<Data>* vetDiScambio = new Vector<Data>(newSize);
        for(int index = 0; index<=newSize; index++){
            vetDiScambio[index]=VectorImplementato[index];
        }
        std::swap(vetDiScambio,VectorImplementato);
        delete vetDiScambio;
    }
}

template <typename Data>
void Vector<Data>::Sort(){ //Faremo bubble sort
    for(int i=0; i<(size-1); i++){
        for(int j=0; j<(size-1-i); j++){
            if(VectorImplementato[j+1]<VectorImplementato[j]){
                int temp=VectorImplementato[j+1];
                VectorImplementato[j+1]=VectorImplementato[j];
                VectorImplementato[j]=temp;
            }
        }
    }
}
/* ************************************************************************** */

}
