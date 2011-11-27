#include <funcpp/string.h>
using namespace funcpp;

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


void String::each_char(Block_Char b)
{
  const int size = data.size();

  for(int i = 0; i < size; ++i)
        b(data[i]);
}

void String::each_byte(Block_Byte b)
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


