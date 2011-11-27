#include <iostream>
using namespace std;

#include <funcpp/string.h>

void test_each_char()
{
  cout << "\nTest: Testing each_char() method call" << endl;

  funcpp::String a = "hello how are you";

  a.each_char( [](char c) {
     cout << c << "_";
  } );

 cout << endl;
}

void test_each_byte()
{
  cout << "\nTest: Testing each_byte() method call" << endl;

  funcpp::String a = "hello how are you";

  a.each_byte( [](int d) {
   cout << d << ", ";
 });

 cout << endl;
}

int main()
{
  test_each_char();
  test_each_byte();
 return 0;
}
