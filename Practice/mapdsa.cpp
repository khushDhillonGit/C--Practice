#include <iostream>
#include <map>
#include <cassert>
#include <limits>
template <typename K, typename V>
class interval_map
{
    friend void IntervalMapTest();
    V m_valBegin;

public:
    std::map<K, V> m_map;
    // constructor associates whole range of K with val
    interval_map(V const &val)
        : m_valBegin(val)
    {
    }

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign(K const &keyBegin, K const &keyEnd, V const &val)
    {

        //check valid case
        if (!(keyBegin < keyEnd))
            return;

        auto itUpperKeyEnd = m_map.upper_bound(keyEnd);

        // map is empty
        if (itUpperKeyEnd == m_map.begin())
        {
            //check if value inserting is not same as m_valBegin
            if (val == m_valBegin)
                return;

            //insert starting pair
            m_map[keyBegin] = val;

            //insert end pair
            m_map[keyEnd] = m_valBegin;
        }
        // map is not empty
        else
        {
            auto itLowerKeyBegin = m_map.lower_bound(keyBegin);

            // here we want to go back then the lower bound of key begin and check what previous pair is so not to insert duplicates
            itLowerKeyBegin = itLowerKeyBegin != m_map.begin() ? std::prev(itLowerKeyBegin):m_map.end();
            //same for upperBound for keyEnd
            itUpperKeyEnd = itUpperKeyEnd != m_map.begin()? std::prev(itUpperKeyEnd):m_map.end();

            //check if we need to insert the value or not, because in cases where previous value is same as val we dont want to insert
            if(itUpperKeyEnd == m_map.end() || (itUpperKeyEnd != m_map.end() && itUpperKeyEnd->second != val))
            {
                //insert the keyEnd
                m_map[keyEnd] = m_map[(itUpperKeyEnd)->first];
                //calculate the itUpperKeyEnd but this time lower_bound as when erasing the upper limit is not erased [lower,upper)
                itUpperKeyEnd = m_map.lower_bound(keyEnd);
            }
            else
            {
                //itUpperKeyEnd is not at map end, so we definitely decreased it above when assigning so we need to increase it to 
                ++itUpperKeyEnd;
            }
            
            //same goes for inserting for keyBegin
            if(itLowerKeyBegin == m_map.end() || (itLowerKeyBegin != m_map.end() && itLowerKeyBegin->second != val))
            {
                m_map[keyBegin] = val;
                itLowerKeyBegin = m_map.upper_bound(keyBegin);
            }else
            {
                ++itLowerKeyBegin;
            }

            //erase the values which are in between
            if(itLowerKeyBegin != m_map.end())
            {
                if (itLowerKeyBegin != itUpperKeyEnd)
                {
                    m_map.erase(itLowerKeyBegin, itUpperKeyEnd);
                }
            }
        }
    }

    // look-up of the value associated with key
    V const &operator[](K const &key) const
    {
        auto it = m_map.upper_bound(key);
        if (it == m_map.begin())
        {
            return m_valBegin;
        }
        else
        {
            return (--it)->second;
        }
    }
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.
// Function to test the interval_map implementation
void IntervalMapTest()
{
    // Test Case 1
    interval_map<int, char> myMap1('A');
    myMap1.assign(1, 3, 'B');
    assert(myMap1[0] == 'A');
    assert(myMap1[1] == 'B');
    assert(myMap1[2] == 'B');
    assert(myMap1[3] == 'A');
    std::cout << "Test Case 1 Passed!" << std::endl;

    // Add more test cases as needed...
}

void SecondTest()
{
    interval_map<int, char> m('A');
    m.assign(3, 6, 'B');
    m.assign(2, 5, 'C');
    m.assign(4, 7, 'A');

    assert(m[1] == 'A');
    assert(m[2] == 'C');
    assert(m[3] == 'C');
    assert(m[4] == 'A');
    assert(m[5] == 'A');
    assert(m[6] == 'A');
    assert(m[7] == 'A');
    std::cout << "Test Case 2 Passed!" << std::endl;
}

void ThirdTest()
{
    interval_map<int, char> m('A');
    m.assign(1, 5, 'B');
    m.assign(4, 6, 'A');
    assert(m[0] == 'A');
    assert(m[1] == 'B');
    assert(m[2] == 'B');
    assert(m[3] == 'B');
    assert(m[4] == 'A');
    assert(m[5] == 'A');
    std::cout << "Test Case 3 Passed!" << std::endl;
}
using TestKeyType = int;
using TestValueType = char;
using TestFloatKeyType = float;

void EmptyRangeTest()
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(3, 3, 'B');
    assert(m.m_map.count(3) == 0);
    m.assign(3, 2, 'B');
    assert(m.m_map.count(2) == 0);
    assert(m.m_map.count(3) == 0);
    std::cout << "Test Case 4 Passed!" << std::endl;
}

void TrivialRangeTest()
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(1, 10, 'B');
    assert(m[0] == 'A');
    for (int i = 1; i < 10; i++)
    {
        assert(m[i] == 'B');
    }
    assert(m[10] == 'A');
    std::cout << "Test Case 5 Passed!" << std::endl;
}

void TrivialTwoRangeTest()
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(1, 3, 'B');
    m.assign(6, 8, 'C');
    assert(m[0] == 'A');
    assert(m[1] == 'B');
    assert(m[2] == 'B');
    assert(m[3] == 'A');
    assert(m[4] == 'A');
    assert(m[5] == 'A');
    assert(m[6] == 'C');
    assert(m[7] == 'C');
    assert(m[8] == 'A');
    std::cout << "Test Case 6 Passed!" << std::endl;
}

void OverwriteLowestTest()
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(std::numeric_limits<TestKeyType>::lowest(), 10000, 'B');
    assert(m[0] == 'B');
    assert(m[9999] == 'B');
    assert(m[10000] == 'A');
    std::cout << "Test Case 7 Passed!" << std::endl;
}

void MergeTest()
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(std::numeric_limits<TestKeyType>::lowest(), 10, 'B');
    m.assign(10, 20, 'B');
    assert(m[0] == 'B');
    assert(m[10] == 'B');
    assert(m[19] == 'B');
    assert(m[20] == 'A');
    std::cout << "Test Case 8 Passed!" << std::endl;
}

void FloatKeyTest()
{
    interval_map<TestFloatKeyType, TestValueType> m('A');
    m.assign(1.f, 5.f, 'B');
    assert(m[0.f] == 'A');
    assert(m[.999999999f] == 'B');
    assert(m[1.f] == 'B');
    assert(m[4.999f] == 'B');
    assert(m[5.f] == 'A');
    std::cout << "Test Case 9 Passed!" << std::endl;
}

void OverlappingRangeCompleteTest()
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(3, 5, 'B');
    m.assign(1, 6, 'C');
    assert(m[0] == 'A');
    assert(m[1] == 'C');
    assert(m[2] == 'C');
    assert(m[3] == 'C');
    assert(m[4] == 'C');
    assert(m[5] == 'C');
    assert(m[6] == 'A');
    std::cout << "Test Case 10 Passed!" << std::endl;
}

void OverlappingRangeInnerTest()
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(1, 6, 'C');
    m.assign(3, 5, 'B');
    assert(m[0] == 'A');
    assert(m[1] == 'C');
    assert(m[2] == 'C');
    assert(m[3] == 'B');
    assert(m[4] == 'B');
    assert(m[5] == 'C');
    assert(m[6] == 'A');
    std::cout << "Test Case 11 Passed!" << std::endl;
}

void OverlappingRangeSmallToLargeTest()
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(1, 5, 'B');
    m.assign(3, 6, 'C');
    assert(m[0] == 'A');
    assert(m[1] == 'B');
    assert(m[2] == 'B');
    assert(m[3] == 'C');
    assert(m[4] == 'C');
    assert(m[5] == 'C');
    assert(m[6] == 'A');
    std::cout << "Test Case 12 Passed!" << std::endl;
}

void OverlappingRangeLargeToSmallTest()
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(3, 6, 'C');
    m.assign(1, 5, 'B');
    assert(m[0] == 'A');
    assert(m[1] == 'B');
    assert(m[2] == 'B');
    assert(m[3] == 'B');
    assert(m[4] == 'B');
    assert(m[5] == 'C');
    assert(m[6] == 'A');
    std::cout << "Test Case 13 Passed!" << std::endl;
}

void ExtendingRangeBeginTest()
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(3, 5, 'B');
    m.assign(1, 4, 'B');
    assert(m[0] == 'A');
    assert(m[1] == 'B');
    assert(m[2] == 'B');
    assert(m[3] == 'B');
    assert(m[4] == 'B');
    assert(m[5] == 'A');
    std::cout << "Test Case 14 Passed!" << std::endl;
}

void ExtendingRangeEndTest()
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(1, 5, 'B');
    m.assign(3, 6, 'B');
    assert(m[0] == 'A');
    assert(m[1] == 'B');
    assert(m[2] == 'B');
    assert(m[3] == 'B');
    assert(m[4] == 'B');
    assert(m[5] == 'B');
    assert(m[6] == 'A');
    std::cout << "Test Case Passed!" << std::endl;
}

void ExtendingRangeBothBeginEndTest()
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(2, 3, 'B');
    m.assign(1, 5, 'B');
    assert(m[0] == 'A');
    assert(m[1] == 'B');
    assert(m[2] == 'B');
    assert(m[3] == 'B');
    assert(m[4] == 'B');
    assert(m[5] == 'A');
    std::cout << "Test Case Passed!" << std::endl;
}

void OverwriteEndValueSafetyTest()
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(2, 5, 'B');
    m.assign(5, 8, 'C');
    m.assign(4, 5, 'A');
    std::cout << "Test Case Passed!" << std::endl;
}

void ReusingExistingRangeBothBeginEndTest()
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(1, 5, 'B');
    m.assign(2, 3, 'B');
    assert(m[0] == 'A');
    assert(m[1] == 'B');
    assert(m[2] == 'B');
    assert(m[3] == 'B');
    assert(m[4] == 'B');
    assert(m[5] == 'A');
    std::cout << "Test Case Passed!" << std::endl;
}

void ReusingEndTest()
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(1, 5, 'B');
    m.assign(4, 6, 'A');
    assert(m[0] == 'A');
    assert(m[1] == 'B');
    assert(m[2] == 'B');
    assert(m[3] == 'B');
    assert(m[4] == 'A');
    assert(m[5] == 'A');
    std::cout << "Test Case Passed!" << std::endl;
}

void RestoringInitialTest()
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(1, 5, 'B');
    m.assign(1, 5, 'A');
    assert(m[0] == 'A');
    assert(m[1] == 'A');
    assert(m[2] == 'A');
    assert(m[3] == 'A');
    assert(m[4] == 'A');
    assert(m[5] == 'A');
    std::cout << "Test Case Passed!" << std::endl;
}

void RestoringInitial2Test()
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(1, 5, 'B');
    m.assign(0, 7, 'A');
    assert(m[0] == 'A');
    assert(m[1] == 'A');
    assert(m[2] == 'A');
    assert(m[3] == 'A');
    assert(m[4] == 'A');
    assert(m[5] == 'A');
    std::cout << "Test Case Passed!" << std::endl;
}

int main()
{
    IntervalMapTest();
    SecondTest();
    ThirdTest();
    EmptyRangeTest();
    TrivialRangeTest();
    TrivialTwoRangeTest();
    OverwriteLowestTest();
    MergeTest();
    FloatKeyTest();
    OverlappingRangeCompleteTest();
    OverlappingRangeInnerTest();
    OverlappingRangeSmallToLargeTest();
    OverlappingRangeLargeToSmallTest();
    ExtendingRangeBeginTest();
    ExtendingRangeEndTest();
    ExtendingRangeBothBeginEndTest();
    OverwriteEndValueSafetyTest();
    ReusingExistingRangeBothBeginEndTest();
    ReusingEndTest();
    RestoringInitialTest();
    RestoringInitial2Test();

    return 0;
}
