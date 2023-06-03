#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <math.h>
#include "sources/MagicalContainer.hpp"

using namespace std;
using namespace ariel;
TEST_SUITE("MagicalContainer tests")
{
    TEST_CASE("MagicalContainer constractor")
    {
        MagicalContainer container;
        CHECK_NOTHROW(MagicalContainer container);

    }
    TEST_CASE("MagicalContainer addElement()"){
        MagicalContainer container;
        CHECK_NOTHROW(container.addElement(2)); 
        //Adding the same element is allowed
        container.addElement(25);
        CHECK_NOTHROW(container.addElement(25));        
    }
    TEST_CASE("MagicalContainer removeElement()"){
        MagicalContainer container;
        container.addElement(25);
        container.addElement(26);
        container.addElement(27);
        // Can't remove no exiting element
        CHECK_THROWS(container.removeElement(30));
        CHECK_EQ(container.size(),3);
        // Can remove exiting element
        CHECK_NOTHROW(container.removeElement(25));
    }
    TEST_CASE("MagicalContainer size()"){
        MagicalContainer container;
        // Before adding elements
        CHECK_EQ(container.size(),0);
        CHECK_NOTHROW(container.size());
        // Each addition raises the size in one 
        for(int i = 0; i<6;i++){
            container.addElement(i);
            CHECK_EQ(container.size(),i+1);
            CHECK_NOTHROW(container.size());
        }
        // After removing the size is decrease
        container.removeElement(3);
        CHECK_EQ(container.size(),5);
        CHECK_NOTHROW(container.size());

    }
}
TEST_SUITE("AscendingIterator tests")
{
    TEST_CASE("AscendingIterator constractor")
    {
        MagicalContainer container;
        CHECK_NOTHROW(MagicalContainer::AscendingIterator ascIter(container));
        MagicalContainer::AscendingIterator ascIter(container);
        //copy constractor
        CHECK_NOTHROW(MagicalContainer::AscendingIterator ascItercopy(ascIter));
        container.addElement(1);
        container.addElement(2);
        container.addElement(4);
        container.addElement(8);
        container.addElement(16);
    }


    TEST_CASE("AscendingIterator go through the element")
    {
        //Ascending container
            MagicalContainer container;
            container.addElement(1);
            container.addElement(2);
            container.addElement(4);
            container.addElement(8);
            container.addElement(16);
            MagicalContainer::AscendingIterator ascIter(container);
            //At the begining the iterator is at the start
            CHECK(ascIter==ascIter.begin());
            CHECK(*ascIter==1);
            for(int i=1;i<5;i++){
                ++ascIter;
                CHECK(*ascIter== pow(i,2));
            }
            ++ascIter;
            CHECK(ascIter==ascIter.end());
            //Should throw exception if try to advance the pointer after one position past the last element of the container
            CHECK_THROWS(++ascIter);
        //No order container with negitive numbers(-5,-3,1,2,8)
            MagicalContainer container2;
            container2.addElement(1);
            container2.addElement(-3);
            container2.addElement(2);
            container2.addElement(8);
            container2.addElement(-5);
            MagicalContainer::AscendingIterator ascIter2(container2);
            CHECK(*ascIter2.begin()==-5);
            ++ascIter2;
            CHECK(*ascIter2==1);
            ++ascIter2;
            CHECK(*ascIter2==2);
            ++ascIter2;
            CHECK(*ascIter2==8);
            ++ascIter2;
            CHECK(ascIter2==ascIter2.end());
            
    }
    TEST_CASE("AscendingIterator GT,LT.==,!=")
    {
        MagicalContainer container; 
        container.addElement(10);
        container.addElement(2);
        container.addElement(6);
        container.addElement(11);
        container.addElement(9);
        MagicalContainer::AscendingIterator ascIter1(container); //(2,6,9,10,11)
        MagicalContainer::AscendingIterator ascIter2(container); //(2,6,9,10,11)
        //At the begining the iterators is at the start
        CHECK(ascIter1==ascIter2);
        CHECK(*ascIter1==*ascIter2);
        CHECK(ascIter2.begin() < ascIter2.end());
        CHECK_FALSE(ascIter1 < ascIter2);
        CHECK_FALSE(ascIter1 > ascIter2);
        CHECK_FALSE(ascIter1 != ascIter2);
        ++ascIter2;
        CHECK(ascIter1 < ascIter2);
        CHECK(ascIter2 > ascIter1);
        CHECK(*ascIter1 < *ascIter2);
        CHECK(ascIter1 != ascIter2);

        CHECK(ascIter1 < ascIter1.end());
        CHECK(ascIter2.begin() < ascIter2);
        CHECK(ascIter2.begin() != ascIter2);
        CHECK(ascIter2.end() != ascIter2);
        ++ascIter1;//6
        CHECK(ascIter1==ascIter2);
        ++ascIter1;//9
        ++ascIter1;//11
        CHECK(ascIter1 > ascIter2);
        CHECK(ascIter2 < ascIter1);
        CHECK(*ascIter1 > *ascIter2);
    }
    TEST_CASE("AscendingIterator assaignment operator")
    {
        MagicalContainer container;
        container.addElement(10);
        container.addElement(2);
        container.addElement(6);
        container.addElement(11);
        container.addElement(9);
        MagicalContainer::AscendingIterator ascIter(container);
        MagicalContainer::AscendingIterator iter = ascIter;
        CHECK(ascIter==iter);
        CHECK(ascIter.begin()==iter.begin());
        CHECK(ascIter.end()==iter.end());
    }
    TEST_CASE("AscendingIterator empty container")
    {
        MagicalContainer empty;
        MagicalContainer::AscendingIterator ascIter(empty);
        CHECK(ascIter.begin()==ascIter.end());
        CHECK(ascIter==ascIter.end());
        CHECK(ascIter.begin()==ascIter);
        //Should throw exception if try to advance the pointer after one position past the last element of the container
        CHECK_THROWS(++ascIter);
    }
}
TEST_SUITE("SideCrossIterator tests")
{
    TEST_CASE("SideCrossIterator constractor")
    {
        MagicalContainer container;
        CHECK_NOTHROW(MagicalContainer::SideCrossIterator cIter(container));
        MagicalContainer::SideCrossIterator cIter(container);
        //copy constractor
        CHECK_NOTHROW(MagicalContainer::SideCrossIterator cItercopy(cIter));
    }


    TEST_CASE("SideCrossIterator go through the element")
    {

        MagicalContainer container;
        container.addElement(1);
        container.addElement(2);
        container.addElement(4);
        container.addElement(8);
        container.addElement(16);
        MagicalContainer::SideCrossIterator cIter(container);
        //At the begining the iterator is at the start
        CHECK(cIter==cIter.begin());
        CHECK(*cIter==1);
        ++cIter;
        CHECK(*cIter== 16);   
        ++cIter;
        CHECK(*cIter== 2); 
        ++cIter;
        CHECK(*cIter== 8);    
        ++cIter;
        CHECK(*cIter== 4);        
        ++cIter;
        CHECK(cIter==cIter.end());
        //Should throw exception if try to advance the pointer after one position past the last element of the container
        CHECK_THROWS(++cIter);
        
    }
    TEST_CASE("SideCrossIterator GT,LT.==,!=")
    {
        MagicalContainer container; 
        container.addElement(10);
        container.addElement(2);
        container.addElement(6);
        container.addElement(11);
        container.addElement(9);
        MagicalContainer::SideCrossIterator cIter1(container); //(10,9,2,11,6)
        MagicalContainer::SideCrossIterator cIter2(container); //(10,9,2,11,6)
        //At the begining the iterators is at the start
        CHECK(cIter1==cIter2);
        CHECK(*cIter1==*cIter2);
        CHECK(cIter2.begin() < cIter2.end());
        CHECK_FALSE(cIter1 < cIter2);
        CHECK_FALSE(cIter1 > cIter2);
        CHECK_FALSE(cIter1 != cIter2);
        ++cIter2;//9
        CHECK(cIter1 < cIter2);
        CHECK(cIter2 > cIter1);
        CHECK(*cIter1 >*cIter2);// 10>9
        CHECK(cIter1 != cIter2);

        CHECK(cIter1 < cIter1.end());
        CHECK(cIter2.begin() < cIter2);
        CHECK(cIter2.begin() != cIter2);
        CHECK(cIter2.end() != cIter2);
        ++cIter1;//9
        CHECK(cIter1==cIter2);
        ++cIter1;//2
        ++cIter1;//11
        CHECK(cIter1 > cIter2);
        CHECK(cIter2 < cIter1);
        CHECK(*cIter1 > *cIter2); //11>10
    }
    TEST_CASE("SideCrossIterator assaignment operator")
    {
        MagicalContainer container;
        container.addElement(10);
        container.addElement(2);
        container.addElement(6);
        container.addElement(11);
        container.addElement(9);
        MagicalContainer::SideCrossIterator cIter(container);
        MagicalContainer::SideCrossIterator iter = cIter;
        CHECK(cIter==iter);
        CHECK(cIter.begin()==iter.begin());
        CHECK(cIter.end()==iter.end());
    }
    TEST_CASE("SideCrossIterator empty container")
    {
        MagicalContainer empty;
        MagicalContainer::SideCrossIterator cIter(empty);
        CHECK(cIter.begin()==cIter.end());
        CHECK(cIter==cIter.end());
        CHECK(cIter.begin()==cIter);
        //Should throw exception if try to advance the pointer after one position past the last element of the container
        CHECK_THROWS(++cIter);
    }
}
TEST_SUITE("SideCrossIterator tests")
{
    TEST_CASE("SideCrossIterator constractor")
    {
        MagicalContainer container;
        CHECK_NOTHROW(MagicalContainer::SideCrossIterator cIter(container));
        MagicalContainer::SideCrossIterator cIter(container);
        //copy constractor
        CHECK_NOTHROW(MagicalContainer::SideCrossIterator cItercopy(cIter));
    }


    TEST_CASE("PrimeIterator go through the element")
    {

        MagicalContainer container;
        container.addElement(2);
        container.addElement(3);
        container.addElement(4);
        container.addElement(5);
        container.addElement(6);
        MagicalContainer::PrimeIterator pIter(container); //(2,3,5)
        //At the begining the iterator is at the start
        CHECK(pIter==pIter.begin());
        CHECK(*pIter==2);
        ++pIter;
        CHECK(*pIter== 3);   
        ++pIter;
        CHECK(*pIter== 5);
        ++pIter;
        CHECK(pIter==pIter.end());
        //Should throw exception if try to advance the pointer after one position past the last element of the container
        CHECK_THROWS(++pIter);
        
    }
    TEST_CASE("PrimeIterator GT,LT.==,!=")
    {
        MagicalContainer container; 
        container.addElement(2);
        container.addElement(3);
        container.addElement(4);
        container.addElement(5);
        container.addElement(6);
        MagicalContainer::PrimeIterator pIter1(container); //(2,3,5)
        MagicalContainer::PrimeIterator pIter2(container); //(2,3,5)
        //At the begining the iterators is at the start
        CHECK(pIter1==pIter2);
        CHECK(*pIter1==*pIter2);
        CHECK(pIter2.begin() < pIter2.end());
        CHECK_FALSE(pIter1 < pIter2);
        CHECK_FALSE(pIter1 > pIter2);
        CHECK_FALSE(pIter1 != pIter2);
        ++pIter2;//3
        CHECK(pIter1 < pIter2);
        CHECK(pIter2 > pIter1);
        CHECK(*pIter1 <*pIter2);// 2<3
        CHECK(pIter1 != pIter2);

        CHECK(pIter1 < pIter1.end());
        CHECK(pIter2.begin() < pIter2);
        CHECK(pIter2.begin() != pIter2);
        CHECK(pIter2.end() != pIter2);
        ++pIter1;//3
        CHECK(pIter1==pIter2);
        ++pIter1;//5
        CHECK(pIter1 > pIter2);
        CHECK(pIter2 < pIter1);
        CHECK(*pIter1 > *pIter2); //5>3
    }
    TEST_CASE("PrimeIterator assaignment operator")
    {
        MagicalContainer container;
        container.addElement(10);
        container.addElement(2);
        container.addElement(6);
        container.addElement(11);
        container.addElement(9);
        MagicalContainer::PrimeIterator pIter(container);
        MagicalContainer::PrimeIterator iter = pIter;
        CHECK(pIter==iter);
        CHECK(pIter.begin()==iter.begin());
        CHECK(pIter.end()==iter.end());
    }
    TEST_CASE("PrimeIterator empty container")
    {
        MagicalContainer empty;
        MagicalContainer::PrimeIterator pIter(empty);
        CHECK(pIter.begin()==pIter.end());
        CHECK(pIter==pIter.end());
        CHECK(pIter.begin()==pIter);
        //Should throw exception if try to advance the pointer after one position past the last element of the container
        CHECK_THROWS(++pIter);
    }
}
