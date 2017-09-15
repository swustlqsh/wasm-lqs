//
//  Random.h
//  layout++
//
//  Created by Ma Qi on 8/17/17.
//  Copyright (c) 2017 Ma Qi. All rights reserved.
//

#ifndef layout_Random_h
#define layout_Random_h

//#include <cstdlib>
#include <chrono>

//using namespace std::chrono;

class Random {
  long seed;
public:
  Random(long _seed):seed(_seed) {}
  Random() {
    //seed = duration_cast< milliseconds >(system_clock::now().time_since_epoch()).count();
  }
  double nextDouble() {
    // Robert Jenkins' 32 bit integer hash function.
    seed = ((seed + 0x7ed55d16) + (seed << 12)) & 0xffffffff;
    seed = ((seed ^ 0xc761c23c) ^ (seed >> 19)) & 0xffffffff;
    seed = ((seed + 0x165667b1) + (seed << 5)) & 0xffffffff;
    seed = ((seed + 0xd3a2646c) ^ (seed << 9)) & 0xffffffff;
    seed = ((seed + 0xfd7046c5) + (seed << 3)) & 0xffffffff;
    seed = ((seed ^ 0xb55a4f09) ^ (seed >> 16)) & 0xffffffff;
    return static_cast <double> (seed & 0xfffffff) / static_cast <double> (0x10000000);
  }
  float nextFloat() {
    // Robert Jenkins' 32 bit integer hash function.
    seed = ((seed + 0x7ed55d16) + (seed << 12)) & 0xffffffff;
    seed = ((seed ^ 0xc761c23c) ^ (seed >> 19)) & 0xffffffff;
    seed = ((seed + 0x165667b1) + (seed << 5)) & 0xffffffff;
    seed = ((seed + 0xd3a2646c) ^ (seed << 9)) & 0xffffffff;
    seed = ((seed + 0xfd7046c5) + (seed << 3)) & 0xffffffff;
    seed = ((seed ^ 0xb55a4f09) ^ (seed >> 16)) & 0xffffffff;
    return (float)(static_cast <double> (seed & 0xfffffff) / static_cast <double> (0x10000000));
  }
  double next(double max) {
    return nextDouble() * max;
  }
};

static Random ARandom(42);

#endif
