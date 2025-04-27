#include <Async/Context.h>

#include <cassert>

namespace Core::Async
{
    SharedContext::SharedContext(std::atomic<State>* state) : state_(state)
    {
        assert(state_);
    }

    SharedContext::~SharedContext()
    {
        state_ = nullptr;
    }

    _NODISCARD bool SharedContext::IsRunning() const noexcept
    {
        assert(state_);
        State state = State::Running;
        return state_->compare_exchange_strong(state, State::Running, std::memory_order_acquire,
                                               std::memory_order_acquire);
    }

    bool SharedContext::TryCancel() noexcept
    {
        assert(state_);
        state_->store(State::Canceled);
        return true; // Always return true, but dont know realy task was canceled
    }

    void SharedContext::SetState(State state) noexcept
    {
        assert(state_);
        state_->store(state, std::memory_order_release);
    }

    _NODISCARD std::shared_ptr<SharedContext> Context::MakeShared()
    {
        return std::make_shared<SharedContext>(&state_);
    }

    _NODISCARD bool Context::IsRunning() const noexcept
    {
        State state = State::Running;
        return state_.load(std::memory_order_acquire) == State::Running;
    }

    bool Context::TryCancel() noexcept
    {
        state_.store(State::Canceled);
        return true;
    }

    void Context::SetState(State state) noexcept
    {
        state_.store(state, std::memory_order_release);
    }


} // namespace Core::Async
