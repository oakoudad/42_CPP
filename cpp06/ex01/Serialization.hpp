#pragma once

#include <iostream>
#include <sys/_types/_uintptr_t.h>

typedef struct s_data {
  float _float;
  char  _char;
} Data;

class Serializer {
  private:
      Serializer();
      Serializer(const Serializer &obj);
      Serializer &operator=(const Serializer &obj);
      ~Serializer();
  public:
    static uintptr_t  serialize(Data* ptr);
    static Data       *deserialize(uintptr_t raw);
};