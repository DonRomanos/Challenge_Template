#pragma once

#include "Level_0.hpp"
#ifdef BUILD_REFERENCE
    #include "Reference_Level_0.hpp"
#endif
#include "benchmark/benchmark.h"

/***************************************************************/
template <class T> void BM_SomeFunc(benchmark::State& state) 
{
  T toBeBenchmarked;
  for (auto _ : state) 
  {
      toBeBenchmarked.doingSomething();
  }
  state.SetComplexityN(state.range(0));
}

/***************************************************************/
#ifdef BUILD_REFERENCE
    BENCHMARK_TEMPLATE(BM_SomeFunc, reference::SomeClass)->Range(1<<0, 1<<10)->Complexity();
#endif
BENCHMARK_TEMPLATE(BM_SomeFunc, onions::SomeClass)->RangeMultiplier(2)->Range(1<<0, 1<<12)->Complexity();