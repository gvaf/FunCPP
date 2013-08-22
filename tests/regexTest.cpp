/*
   FunCPP Library
   Developer: George Vafiadis

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
   THE SOFTWARE.
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#include <boost/regex.hpp>
#include <gtest/gtest.h>

TEST(REGEX_BOOST, MatchInteger)
{
  boost::regex re("(\\+|-)?[[:digit:]]+");

  ASSERT_TRUE( regex_match("12", re) );
  ASSERT_TRUE( regex_match("+421321", re) );
  ASSERT_TRUE( regex_match("-1232", re) );
  ASSERT_FALSE( regex_match("-13432d", re) );
}


TEST(REGEX_BOOST, MatchFloat)
{
  boost::regex re("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?((e|E)((\\+|-)?)[[:digit:]]+)?");

  ASSERT_FALSE( regex_match("", re) );
  ASSERT_TRUE ( regex_match("123", re) );
  ASSERT_TRUE ( regex_match("123.34343e+10", re) );
  ASSERT_FALSE( regex_match("-13432d", re) );
}

TEST(REGEX_BOOST, MatchCharacters)
{ 
 boost::regex re( "[a-zA-Z0-9]+" ); 

 ASSERT_TRUE ( regex_match("asdsadasd0120", re) );
 ASSERT_FALSE( regex_match("hello how are you", re) );
 ASSERT_FALSE( regex_match("sdsd$dfdfd", re) );
}


// TODO: http://www.boost.org/doc/libs/1_46_1/libs/regex/doc/html/boost_regex/ref.html

