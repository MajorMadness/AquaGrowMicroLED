#ifndef structs_h
#define structs_h

#include <WString.h>

typedef struct {
  uint32_t time;
  byte level;  
}LIGHT;

uint32_t get_ts(uint8_t h, uint8_t m, uint8_t s){
  uint32_t t;
  t = h;
  t *= 60;
  t += m;
  t *= 60;
  t += s;
  return t;
}
#endif
