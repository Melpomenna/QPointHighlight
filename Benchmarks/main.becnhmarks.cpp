#include <benchmark/benchmark.h>

#include <ArchitectureCore/GeneratePointsModel.h>
#include <Async/Context.h>
#include <Domain/UIData.h>

static void BM_GenerateModel50Points(benchmark::State& state)
{
    Core::Data::UIDataInput uiData;
    uiData.generatePointsCount_ = 50;
    uiData.pointsRadius_ = 20;

    auto model = std::make_unique<Core::ArchitectureCore::GeneratePointsModel>(nullptr);
    Core::Async::Context ctx;

    for (auto _ : state)
    {
        model->Invoke(uiData, ctx.MakeShared());
    }
}

static void BM_GenerateModel100Points(benchmark::State& state)
{
    Core::Data::UIDataInput uiData;
    uiData.generatePointsCount_ = 100;
    uiData.pointsRadius_ = 20;

    auto model = std::make_unique<Core::ArchitectureCore::GeneratePointsModel>(nullptr);
    Core::Async::Context ctx;

    for (auto _ : state)
    {
        model->Invoke(uiData, ctx.MakeShared());
    }
}


static void BM_GenerateModel250Points(benchmark::State& state)
{
    Core::Data::UIDataInput uiData;
    uiData.generatePointsCount_ = 250;
    uiData.pointsRadius_ = 20;

    auto model = std::make_unique<Core::ArchitectureCore::GeneratePointsModel>(nullptr);
    Core::Async::Context ctx;

    for (auto _ : state)
    {
        model->Invoke(uiData, ctx.MakeShared());
    }
}


static void BM_GenerateModel500Points(benchmark::State& state)
{
    Core::Data::UIDataInput uiData;
    uiData.generatePointsCount_ = 500;
    uiData.pointsRadius_ = 20;

    auto model = std::make_unique<Core::ArchitectureCore::GeneratePointsModel>(nullptr);
    Core::Async::Context ctx;

    for (auto _ : state)
    {
        model->Invoke(uiData, ctx.MakeShared());
    }
}


BENCHMARK(BM_GenerateModel50Points);
BENCHMARK(BM_GenerateModel100Points);
BENCHMARK(BM_GenerateModel250Points);
BENCHMARK(BM_GenerateModel500Points);

BENCHMARK_MAIN();
