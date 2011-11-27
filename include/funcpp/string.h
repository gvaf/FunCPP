#ifndef FUNCPP_LIBRARY_STRING_H
#define FUNCPP_LIBRRAY_STRING_H

#include <string>

namespace funcpp {

class String
{
 public:
    String(const char * str);
    String(const std::string & str);

    String();   //< Constructor
   ~String();   //< Destructor

  typedef void (*Block_Char)(char c);
  typedef void (*Block_Byte)(int c);

  void each_char(Block_Char b);
  void each_byte(Block_Byte b);

  String & operator=(const char * str);
  String & operator=(const std::string & str);

 private:
   std::string data;
};

}; // end of namespace

#endif // end of FUNCPP_LIBRRAY_STRING_H
