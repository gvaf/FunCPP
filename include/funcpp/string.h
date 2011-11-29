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
#ifndef FUNCPP_LIBRARY_STRING_H
#define FUNCPP_LIBRRAY_STRING_H

#include <string>
#include <iostream>
#include <regex>

namespace funcpp {

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

  typedef void (*Block_Char)(char c);
  typedef void (*Block_Byte)(int c);

  /// Overload stream operator for output
  friend std::ostream & operator<<(std::ostream & output, const funcpp::String & str);

  /// Overload stream operator for input
  friend std::istream & operator>>(std::istream & input, funcpp::String & str);

  /// Passes each character in str to the given block
  void each_char(Block_Char b) const;

  /// Passes each byte in str to the given block
  void each_byte(Block_Byte b) const;

  /// Returns the number of characters
  int  size() const;
  int  length() const;

  /// Returns true if the string is empty
  bool isEmpty() const;

  /// Assignment operator with C style string
  String & operator=(const char * str);

  /// Assignment operator with standard string
  String & operator=(const std::string & str);

  /// Reverse string in place
  void reverse();

  /// Return a new reversed string
  String get_reverse() const;

 private:
   std::string data;
};

}; // end of namespace


#endif // end of FUNCPP_LIBRRAY_STRING_H
