#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
namespace ariel{ 
    class MagicalContainer{
        private:

        public:
            MagicalContainer();
            void addElement(int num);
            int size() const;
            void removeElement(int num);
            class AscendingIterator{
                private:
                public:
                    AscendingIterator(MagicalContainer continaier);
                    ~AscendingIterator()= default;
                    AscendingIterator(const AscendingIterator& iter);
                    AscendingIterator& operator=(const AscendingIterator& other);
                    AscendingIterator begin();
                    AscendingIterator end();
                    int operator*() const;
                    AscendingIterator& operator++();
                    AscendingIterator operator++(int);
                    bool operator<(const AscendingIterator& other) const;
                    bool operator>(const AscendingIterator& other) const;
                    bool operator==(const AscendingIterator& other) const;
                    bool operator!=(const AscendingIterator& other) const;

            };
            class SideCrossIterator{
                private:
                public:
                    SideCrossIterator(MagicalContainer continaier);
                    ~SideCrossIterator()= default;
                    SideCrossIterator(const SideCrossIterator& iter);
                    SideCrossIterator& operator=(const SideCrossIterator& other);
                    SideCrossIterator begin();
                    SideCrossIterator end();
                    int operator*() const;
                    SideCrossIterator& operator++();
                    SideCrossIterator operator++(int);
                    bool operator<(const SideCrossIterator& other) const;
                    bool operator>(const SideCrossIterator& other) const;
                    bool operator==(const SideCrossIterator& other) const;
                    bool operator!=(const SideCrossIterator& other) const;
            };
            class PrimeIterator{
                private:
                public:
                    PrimeIterator(MagicalContainer continaier);
                    ~PrimeIterator()= default;
                    PrimeIterator(const PrimeIterator& iter);
                    PrimeIterator& operator=(const PrimeIterator& other);
                    PrimeIterator begin();
                    PrimeIterator end();
                    int operator*() const;
                    PrimeIterator& operator++();
                    PrimeIterator operator++(int);
                    bool operator<(const PrimeIterator& other) const;
                    bool operator>(const PrimeIterator& other) const;
                    bool operator==(const PrimeIterator& other) const;
                    bool operator!=(const PrimeIterator& other) const;

            };
            

    };
}