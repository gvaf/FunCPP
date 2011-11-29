#include <iostream>
using namespace std;

#include <funcpp/string.h>


//-----------------------------------------------------------------

void test_string_reverse()
{
 cout << "\nTest: testing string reverse in place" << endl;

 funcpp::String a;

 cout << "Enter string = ";
 cin >> a;

 a.reverse();

 cout << "Reversed string : " << a << endl;

}

//-----------------------------------------------------------------

void test_string_each_char()
{
  cout << "\nTest: Testing each_char() method call" << endl;

  funcpp::String a = "hello how are you";

  a.each_char( [](char c) {
     cout << c << "_";
  } );

 cout << endl;
}

//-----------------------------------------------------------------

void test_string_each_byte()
{
  cout << "\nTest: Testing each_byte() method call" << endl;

  funcpp::String a = "hello how are you";

  a.each_byte( [](int d) {
   cout << d << ", ";
 });

 cout << endl;
}

//-----------------------------------------------------------------


int main()
{
  test_string_each_char();
  test_string_each_byte();
  test_string_reverse();


 return 0;
}
