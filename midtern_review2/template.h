//
// Created by Yumeng Zhang on 5/4/23.
//

#ifndef MIDTERN_REVIEW2_TEMPLATE_H
#define MIDTERN_REVIEW2_TEMPLATE_H

#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;


template <typename objectType>
const objectType& GetMax (const objectType& value1, const objectType& value2) {
    if (value1 > value2)
        return value1;
    else
        return value2;
};


template <typename T>
class CMyFirstTemplateClass {

public:

    void SetVariable (const T& newValue) {
        m_Value = newValue;
    };

//    void SetVariable (T newValue) {
//        m_Value = newValue;
//    };

    T& GetValue () {
        return m_Value;
    };

private:
    T m_Value;
};

void use_template();



#endif //MIDTERN_REVIEW2_TEMPLATE_H
