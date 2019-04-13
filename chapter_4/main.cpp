#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void test_func_1(){
    int my_numbers[5] = {};
//    for(int i = 0;i < 5;i++){
//        cout <<"the number is " << my_numbers + i << endl;
//    }
    cout << "the size of the array is :" << sizeof (my_numbers) << endl;
}

void array_list(){
    const int ARRAY_LIST_SIZE = 5;
    const int BEGIN = 20;
    int array[ARRAY_LIST_SIZE][ARRAY_LIST_SIZE] = {};
    for (int i = 0;i < ARRAY_LIST_SIZE;i++){
        for (int j = 0;j < ARRAY_LIST_SIZE;j++){
            array[i][j] = BEGIN + i;
        }
    }

    for (int i = 0;i < ARRAY_LIST_SIZE;i++){
        for (int j = 0;j < ARRAY_LIST_SIZE;j++){
            cout <<"the size of battery is : " << array[i][j] << endl;
        }
    }
}

int main()
{
//    cout << "Hello World!" << endl;
//    test_func_1();
//    int my_numbers_2[5] = {21,23,39,2304,90};
//    for(int i = 0;i < 5;i++){
//        cout <<"the number is " << my_numbers_2[i] << endl;
//    }
//    array_list();
    char num[10] = {'a','b'};
    cout << strlen(num) << endl;

    return 0;
}

