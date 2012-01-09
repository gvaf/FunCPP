#include <iostream>
using namespace std;

#include <funcpp/string.h>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <pcre.h>
#include <pcrecpp.h>

//-----------------------------------------------------------------
void test_string_get_reverse()
{
 cout << "\nTest: testing string get reverse" << endl;

 funcpp::String a = "Hello this is an apple";
 funcpp::String r = a.Reverse();

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

#define OVECCOUNT 30  /* should be a multiple of 3 */

void test_reg_exp()
{
 pcre *re;
 const char *error;
 int erroffset;
 int ovector[OVECCOUNT];
 int rc;

 char *regex = "^From: ([^@]+)@([^\r]+)";
 char *data = "From: gvaf@example.com\r\n";

 re = pcre_compile(
  regex,     // the pattern
  0,           // default options
  &error,      // for error message
  &erroffset,  // error offset
  NULL);      // Default character table

 cout << endl;

 if (! re)
 {
   cout << "PCRE compilation failed at expression " <<  erroffset << ": " <<  error << endl;;
    return;
 }

 rc = pcre_exec(
  re,               // the compiled pattern
  NULL,            // no extra data
  data,           // the subject string
  strlen(data),    // the length of the subject
  0,               // start offset 0 in the subject
  0,               // default options
  ovector,         // output vector for substring information
  OVECCOUNT);        // number of elements in the output


 if(rc < 0)
  {
    switch(rc)
     {
        case PCRE_ERROR_NOMATCH:
             printf("No match found in text\n");
             break;
        default:
             printf("Match error %d\n", rc);
             break;
             return;
     };
  }


 if(rc < 3)
  {
     printf("Match did not catch all the groups\n");
     return;
  }

 /*ovector[0]..ovector[1] are the entire matched string*/
 char *name_start = data + ovector[2];
 int name_length = ovector[3] - ovector[2];
 char *domain_start = data + ovector[4];
 int domain_length = ovector[5] - ovector[4];

 /* Finally, print the match */
 printf("Mail from: %.*s domain: %.*s\n", name_length, name_start, domain_length, domain_start);

}


int main()
{
  test_string_each_char();
  test_string_each_byte();
//  test_string_reverse();
  test_string_get_reverse();
  test_reg_exp();


  //http://www.mushclient.com/pcre/pcrecpp.html
  // ndex(substring [, offset]) → fixnum or nil
  // index(regexp [, offset]) → fixnum or nil
  pcrecpp::RE re("h.*o");
  re.FullMatch("hello");

 return 0;
}
