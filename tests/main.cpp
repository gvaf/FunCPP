#include <iostream>
using namespace std;

#include <funcpp/string.h>
#include <regex>

//-----------------------------------------------------------------
void test_string_get_reverse()
{
 cout << "\nTest: testing string get reverse" << endl;

 funcpp::String a = "Hello this is an apple";
 funcpp::String r = a.get_reverse();

 cout << "Reversed = " << r  << endl;
}

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

void test_reg_exp()
{

cout << endl;

}


int main()
{
  test_string_each_char();
  test_string_each_byte();
//  test_string_reverse();
  test_string_get_reverse();
//  test_reg_exp();

 return 0;
}
