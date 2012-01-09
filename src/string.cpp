/*
   FunCPP Library 
   Copyright (C) 2012 by George Vafiadis

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

#include <funcpp/string.h>
using namespace funcpp;

String::String(const String & other)
{
 data = other.data;
}


String::String(const char * str)
{
  data = str;
}

String::String(const std::string & str)
{
  data = str;
}

String::String()
{


}

String::~String()
{

}

int String::size() const
{ return data.size(); }

int String::length() const
{ return data.size(); }

void String::each_char(Block_Char b) const
{
  const int size = data.size();

  for(int i = 0; i < size; ++i)
        b(data[i]);
}

void String::each_byte(Block_Byte b) const
{
  const int size = data.size();

  for(int i = 0; i < size; ++i)
        b((int)data[i]);
}

String & String::operator=(const char * str)
{
  data = str;
  return *this;
}

String & String::operator=(const std::string & str)
{
  data = str;
  return *this;
}


bool String::isEmpty() const
{
  return data.empty();
}

void String::reverse()
{
 const int n = data.size();
 const int nhalf = (n >> 1);

 for(int i = 0; i < nhalf; ++i)
  {
    char & first = data[i];
    char & last  = data[n-i-1];
    char c = first;
    first = last;
    last = c;
  }
}

String String::Reverse() const
{
  std::string rev;
  const int n = data.size();

  for(int i = n-1; i >= 0; --i)
  rev.push_back(data[i]);

  return String(rev);
}

namespace funcpp {
std::ostream & operator<<(std::ostream & output, const funcpp::String & str)
{
  output << str.data;
  return output;
}

std::istream & operator>>(std::istream & input, funcpp::String & str)
{
  input >> str.data;
  return input;
}

};
