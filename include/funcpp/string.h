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
#ifndef FUNCPP_LIBRARY_STRING_H
#define FUNCPP_LIBRRAY_STRING_H

#include <string>
#include <sstream>
#include <iostream>
#include <regex>

namespace funcpp {

struct range
{
  range(int from = 0, int to = 0) 
   :  from(from), to(to)
  {}

  int from;
  int to;
};

class String
{
 public:

   /// Constructor set a C style string
   String(const char * str);

   /// Constructor set a standard string
   String(const std::string & str);

  /// Default Constructor
  String();

  /// Destructor
  ~String();

  /// Copy Constructor
  String(const String & other);

  /// Overload stream operator for output
  friend std::ostream & operator<<(std::ostream & output, const funcpp::String & str);

  /// Overload stream operator for input
  friend std::istream & operator>>(std::istream & input, funcpp::String & str);

  /// Concatenates the given value to str
  template <class T> String & operator<<(const T & value);
  template <class T> String & concat(const T & value);
  template <class T> String & operator+(const T & value);

  /// Element Reference
  char & operator[](int index);
  const char & operator[](int index) const;
  String operator()(int from, int to) const;
  const char & operator()(int index) const;
  String operator[](const range & r) const;

  /// Multiply string
  String operator*(int value) const;

  /// Compare Operator equality
  inline bool operator==(const funcpp::String & str) const;
  inline bool operator==(const std::string & str) const;
  inline bool operator==(const char * str) const;
  inline bool equals(const std::string & str) const;
  inline bool eql(const std::string & str) const;

  /// Passes each character in str to the given block
  void each_char(std::function<void (char)> block) const;

  /// Passes each byte in str to the given block
  void each_byte(std::function<void (int)> block) const;

  /// Returns the number of characters
  int size() const;
  int length() const;

  /// Returns true if the string is empty
  bool isEmpty() const;

  /// Assignment operator with C style string
  String & operator=(const char * str);

  /// Assignment operator with standard string
  String & operator=(const std::string & str);

  /// Reverse string in place
  void reverse();

  /// Return a new reversed string
  String Reverse() const;

 private:
   std::string data;
};


template <class T>
String & String::operator<<(const T & value)
{
  return concat(value);
}

template <class T>
String & String::concat(const T & value)
{
 std::stringstream s;

 s << value;

 this->data.append(s.str());

 return *this;
}

template <class T>
String & String::operator+(const T & value)
{
 return concat<T>(value);
}

}; // end of namespace


#endif // end of FUNCPP_LIBRRAY_STRING_H
