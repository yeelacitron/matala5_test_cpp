
#include "MagicalContainer.hpp"


using namespace ariel;
using namespace std;
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer continaier){
        
    }
    
    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer::AscendingIterator& iter){

    }
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const MagicalContainer::AscendingIterator& other){
        return *this;
    }
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin(){
        return *this;
    }
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end(){
        return *this;
    }
    int MagicalContainer::AscendingIterator::operator*() const{
        return 0;
    }
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++(){
        return *this;
    }
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator++(int){
        return *this;      
    }
    bool MagicalContainer::AscendingIterator::operator<(const MagicalContainer::AscendingIterator& other) const{
        return true;
    }
    bool MagicalContainer::AscendingIterator::operator>(const MagicalContainer::AscendingIterator& other) const{
        return true;
    }
    bool MagicalContainer::AscendingIterator::operator==(const MagicalContainer::AscendingIterator& other) const{
        return true;
    }
    bool MagicalContainer::AscendingIterator::operator!=(const MagicalContainer::AscendingIterator& other) const{
        return false;
    }
