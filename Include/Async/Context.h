#pragma once

#include <atomic>
#include <cstdint>
#include <memory>

namespace Core::Async
{

    enum class State : uint8_t
    {
        Running,
        Canceled,
        Inited
    };

    class SharedContext final
    {
    public:
        SharedContext(std::atomic<State>* state);
        ~SharedContext();

        _NODISCARD bool IsRunning() const noexcept;

        bool TryCancel() noexcept;

        void SetState(State) noexcept;

    private:
        std::atomic<State>* state_{nullptr};
    };

    class Context final
    {
    public:
        Context() = default;
        ~Context() = default;

        _NODISCARD std::shared_ptr<SharedContext> MakeShared();

        _NODISCARD bool IsRunning() const noexcept;

        bool TryCancel() noexcept;

        void SetState(State) noexcept;

    private:
        std::atomic<State> state_{State::Inited};
    };
} // namespace Core::Async
