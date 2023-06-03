
#include "MagicalContainer.hpp"


using namespace ariel;
using namespace std;
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer continaier){
        
    }
    
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer::PrimeIterator& iter){

    }
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const MagicalContainer::PrimeIterator& other){
        return *this;
    }
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin(){
        return *this;
    }
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end(){
        return *this;
    }
    int MagicalContainer::PrimeIterator::operator*() const{
        return 0;
    }
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++(){
        return *this;
    }
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator++(int){
        return *this;      
    }
    bool MagicalContainer::PrimeIterator::operator<(const MagicalContainer::PrimeIterator& other) const {
        return true;
    }
    bool MagicalContainer::PrimeIterator::operator>(const MagicalContainer::PrimeIterator& other) const{
        return true;
    }
    bool MagicalContainer::PrimeIterator::operator==(const MagicalContainer::PrimeIterator& other) const{
        return true;
    }
    bool MagicalContainer::PrimeIterator::operator!=(const MagicalContainer::PrimeIterator& other) const{
        return false;
    }
