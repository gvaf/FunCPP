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

#include <gtest/gtest.h>
#include <funcpp/string.h>

TEST(StringTest, StringLength) 
{
   funcpp::String s;
   const char * text1 = "Hello this is a test";
   s = text1;
   EXPECT_EQ(strlen(text1), s.size());
   EXPECT_EQ(strlen(text1), s.length());
}

TEST(StringTest, StringMultiply)
{
  const char * text = "Hello";
  funcpp::String s = text;
  char buffer[1000];
  int times = 5;

  buffer[0] = 0;

  for(int i = 0; i < times; ++i)
    strcat(buffer, text);      
  
  s = s * times;
 
  ASSERT_TRUE(strlen(buffer) == s.size());

  for(int i = 0; i < strlen(buffer); ++i)
    EXPECT_EQ(buffer[i], s[i]);
}

TEST(StringTest, StringElementReference)
{
 funcpp::String a;
 const char * s = "hello how are you!!!";

 a = s;

ASSERT_TRUE(strlen(s) == a.size());

for(int i = 0; i < a.size(); ++i)
  EXPECT_EQ(s[i], a[i]); 
}

TEST(StringTest, StringRange)
{
 funcpp::String a    = "My Funny Test";
 funcpp::String sub  = a[funcpp::range(3,7)];
 funcpp::String sub1 = a(3,7);

 for(int i = 3, k = 0; i <= 7; ++i, ++k)
   EXPECT_EQ(a[i], sub[k]);

 ASSERT_TRUE( sub.size() == sub1.size() );

 for(int i = 0; i < sub.size(); ++i)
   EXPECT_EQ(sub[i], sub1[i]);
}

TEST(StringTest, StringConcat)
{
  funcpp::String a;
  funcpp::String b = "Last Section";
  const char * text = "1230 3.14159 Hello Last Section!";

  a << 1230 << " " << 3.14159 << " Hello " << b <<  '!';

  ASSERT_TRUE(strlen(text) == a.size());

  for(int i = 0; i < strlen(text); ++i)
    EXPECT_EQ( a[i], text[i] );
}

TEST(StringTest, StringReverse)
{
 funcpp::String a = "Hello this is an apple";
 funcpp::String r = a.Reverse();

 ASSERT_TRUE(a.size() == r.size());

 for(int i = 0; i < a.size(); ++i)
   EXPECT_EQ( a[i], r[r.size() - i - 1] );

 a = "";
 r = a.Reverse();

 EXPECT_EQ(r.size(), 0);
}

TEST(StringTest, StringReverseInPlace)
{
 const char * text = "Hello this is an apple";
 const int textSize = strlen(text);
 funcpp::String a = text;
 a.reverse();

 ASSERT_TRUE(a.size() == textSize);

 for(int i = 0; i < textSize; ++i)
   EXPECT_EQ( a[i], text[textSize - i - 1] );
}

TEST(StringTest, StringEachChar)
{
  const char * text = "hello how are you";
  char * s = (char *)text;
  funcpp::String a = text;

  a.each_char( [&](char c) {
    EXPECT_EQ( c, *(s++) ); 
  } );

  a = "";

  a.each_char( [](char c) {
   ASSERT_TRUE(false);
  } );
}

TEST(StringTest, StringEachByte) 
{
  const char * text = "hello how are you";
  char * s = (char *)text;
  funcpp::String a = text;

  a.each_char( [&](int c) {
    EXPECT_EQ( c, (int)*(s++) ); 
  } );

  a = "";

  a.each_char( [](int c) {
   ASSERT_TRUE(false);
  } );

}

