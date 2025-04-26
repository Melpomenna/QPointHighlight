#include <benchmark/benchmark.h>

static void BM_Test(benchmark::State& state) {
    for (auto _ : state) {
    }
  }


  BENCHMARK(BM_Test);

  BENCHMARK_MAIN();