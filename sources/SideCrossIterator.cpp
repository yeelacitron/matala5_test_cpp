
#include "MagicalContainer.hpp"


using namespace ariel;
using namespace std;
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer continaier){
        
    }
    
    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer::SideCrossIterator& iter){

    }
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const MagicalContainer::SideCrossIterator& other){
        return *this;
    }
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin(){
        return *this;
    }
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end(){
        return *this;
    }
    int MagicalContainer::SideCrossIterator::operator*() const{
        return 0;
    }
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++(){
        return *this;
    }
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator++(int){
        return *this;      
    }
    bool MagicalContainer::SideCrossIterator::operator<(const MagicalContainer::SideCrossIterator& other) const{
        return true;
    }
    bool MagicalContainer::SideCrossIterator::operator>(const MagicalContainer::SideCrossIterator& other) const{
        return true;
    }
    bool MagicalContainer::SideCrossIterator::operator==(const MagicalContainer::SideCrossIterator& other) const{
        return true;
    }
    bool MagicalContainer::SideCrossIterator::operator!=(const MagicalContainer::SideCrossIterator& other) const{
        return false;
    }
