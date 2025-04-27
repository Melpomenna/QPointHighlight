#include <benchmark/benchmark.h>

#include <ArchitectureCore/GeneratePointsModel.h>
#include <ArchitectureCore/GenerateAreaModel.h>
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


static void BM_GenerateAreaModel50(benchmark::State& state)
{
    Core::Data::UIDataInput uiData;
    uiData.generatePointsCount_ = 50;
    uiData.pointsRadius_ = 20;

    auto model = std::make_unique<Core::ArchitectureCore::GeneratePointsModel>(nullptr);
    auto areaModel = std::make_unique<Core::ArchitectureCore::GenerateAreaModel>(model.get(),nullptr);
    Core::Async::Context ctx;
    model->Invoke(uiData, ctx.MakeShared());
    for (auto _ : state)
    {
        areaModel->Invoke(uiData);
    }
}

static void BM_GenerateAreaModel100(benchmark::State& state)
{
    Core::Data::UIDataInput uiData;
    uiData.generatePointsCount_ = 50;
    uiData.pointsRadius_ = 20;

    auto model = std::make_unique<Core::ArchitectureCore::GeneratePointsModel>(nullptr);
    auto areaModel = std::make_unique<Core::ArchitectureCore::GenerateAreaModel>(model.get(),nullptr);
    Core::Async::Context ctx;
    model->Invoke(uiData, ctx.MakeShared());
    for (auto _ : state)
    {
        areaModel->Invoke(uiData);
    }
}


static void BM_GenerateAreaModel250(benchmark::State& state)
{
    Core::Data::UIDataInput uiData;
    uiData.generatePointsCount_ = 50;
    uiData.pointsRadius_ = 20;

    auto model = std::make_unique<Core::ArchitectureCore::GeneratePointsModel>(nullptr);
    auto areaModel = std::make_unique<Core::ArchitectureCore::GenerateAreaModel>(model.get(),nullptr);
    Core::Async::Context ctx;
    model->Invoke(uiData, ctx.MakeShared());
    for (auto _ : state)
    {
        areaModel->Invoke(uiData);
    }
}


static void BM_GenerateAreaModel500(benchmark::State& state)
{
    Core::Data::UIDataInput uiData;
    uiData.generatePointsCount_ = 50;
    uiData.pointsRadius_ = 20;

    auto model = std::make_unique<Core::ArchitectureCore::GeneratePointsModel>(nullptr);
    auto areaModel = std::make_unique<Core::ArchitectureCore::GenerateAreaModel>(model.get(),nullptr);
    Core::Async::Context ctx;
    model->Invoke(uiData, ctx.MakeShared());
    for (auto _ : state)
    {
        areaModel->Invoke(uiData);
    }
}


BENCHMARK(BM_GenerateModel50Points);
BENCHMARK(BM_GenerateModel100Points);
BENCHMARK(BM_GenerateModel250Points);
BENCHMARK(BM_GenerateModel500Points);
BENCHMARK(BM_GenerateAreaModel50);
BENCHMARK(BM_GenerateAreaModel100);
BENCHMARK(BM_GenerateAreaModel250);
BENCHMARK(BM_GenerateAreaModel500);

BENCHMARK_MAIN();
