#include <iostream>
#include <assert.h>
//#include "opencv2/core.hpp"
//#include "pcl/pcl_config.h"

//using namespace std;
//using namespace cv;


int main() {
    
    int i = 1;
    int *j = &i; //pointer, is a variable that stores the memory address as its value.
    int &k = i; //reference, reference operator (&)
    int **l = &j; //pointer to pointer
    int &&m = i + k; //rvalue reference c++11

    // * is used in declaration (string *ptr, string* ptr), it creates a pointer variable.
    // * not used in declaration, it act as a dereference operator.

    std::cout << "sizeof(int*) = " << sizeof(int*) << std::endl;
    std::cout << "sizeof(int) = " << sizeof(int)  << std::endl;

    //std::cout << "OpenCV Version " << cv::getVersionString() << std::endl;
    //std::cout << "PCL Version " << PCL_VERSION << std::endl;
    
    std::cout << "i = " << i << " &i = " << &i << std::endl;
    std::cout << "j = " << j << " &j = " << &j << " *j = " << *j << std::endl;
    std::cout << "k = " << k << " &k = " << &k << std::endl;
    std::cout << "l = " << l << " &l = " << &l << " *l = " << *l << " **l = " << **l << std::endl;
    std::cout << "m = " << m << " &m = " << std::endl;

    assert(j == &i);
    assert(*j == i);
    assert(k == i);
    assert(&k == &i);
    assert(l == &j);
    assert(*l == &i);
    assert(**l == i);
    assert(m == i + k);
}
/*

sizeof(int*) = 8
sizeof(int) = 4

OpenCV Version 4.6.0
PCL Version 101300

int i = 1;          i = 1 &i = 0x9e231ffd1c
int *j = &i;        j = 0x9e231ffd1c &j = 0x9e231ffd10 *j = 1
int &k = i;         k = 1 &k = 0x9e231ffd1c
int **l = &j;       l = 0x9e231ffd10 &l = 0x9e231ffd08 *l = 0x9e231ffd1c **l = 1
int &&m = i + k;    m = 2 &m =

*/
