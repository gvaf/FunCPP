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

void String::each_char(std::function<void (char)> block) const
{
 const int size = data.size();

  for(int i = 0; i < size; ++i)
        block(data[i]);
}

void String::each_byte(std::function<void (int)> block) const
{
  const int size = data.size();

  for(int i = 0; i < size; ++i)
        block( (int)data[i] );
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

bool String::operator==(const funcpp::String & str) const
{
 return equals(str.data);
}

bool String::operator==(const std::string & str) const
{
 return equals(str);
}

bool String::operator==(const char * str) const
{
  return equals(std::string(str));
}

bool String::equals(const std::string & str) const
{
  return (this->data == str);
}

bool String::eql(const std::string & str) const
{
  return equals(str);
}

char & String::operator[](int index)
{
 if(index >= 0)
  return this->data[index];
 else
  return this->data[this->data.size() - 1 - index];
}

const char & String::operator[](int index) const
{
 if(index >= 0)
  return this->data[index];
 else
  return this->data[this->data.size() - 1 - index];
}

String String::operator()(int from, int to) const
{
  const int & size = data.size();

  if( from < 0 || to < 0 || from >= size || to >= size || from > to)
      return "";  
  
  return data.substr(from, to - from + 1);
}

const char & String::operator()(int index) const
{
  return operator[](index);
}

String String::operator[](const range & r) const
{
 return operator()(r.from, r.to);
}

String String::operator*(int value) const
{
 std::string s;

 for(int i = 0 ; i < value; ++i)
   s.append(data);

 return String(s);
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

