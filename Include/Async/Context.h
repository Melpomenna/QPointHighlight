#pragma once

#include <atomic>
#include <cstdint>
#include <memory>

namespace Core::Async
{

    /**
     * @brief Represents the state of an asynchronous operation.
     */
    enum class State : uint8_t
    {
        Running, /**< The operation is currently running. */
        Canceled, /**< The operation has been canceled. */
        Inited /**< The operation is initialized but not yet started. */
    };

    /**
     * @brief A shared context for managing the state of an asynchronous operation.
     */
    class SharedContext
    {
    public:
        /**
         * @brief Constructs a SharedContext with a given state.
         * @param state A pointer to the atomic state to manage.
         */
        SharedContext(std::atomic<State>* state);

        /**
         * @brief Destructor for SharedContext.
         */
        ~SharedContext();

        /**
         * @brief Checks if the operation is currently running.
         * @return True if the operation is running, false otherwise.
         */
        _NODISCARD bool IsRunning() const noexcept;

        /**
         * @brief Attempts to cancel the operation.
         * @return True if the operation was successfully canceled, false otherwise.
         */
        bool TryCancel() noexcept;

        /**
         * @brief Sets the state of the operation.
         * @param state The new state to set.
         */
        void SetState(State state) noexcept;

    private:
        std::atomic<State>* state_{nullptr}; /**< Pointer to the atomic state being managed. */
    };

    /**
     * @brief A context for managing the state of an asynchronous operation.
     */
    class Context final
    {
    public:
        /**
         * @brief Default constructor for Context.
         */
        Context() = default;

        /**
         * @brief Default destructor for Context.
         */
        ~Context() = default;

        /**
         * @brief Creates a shared context from this context.
         * @return A shared pointer to a SharedContext.
         */
        _NODISCARD std::shared_ptr<SharedContext> MakeShared();

        /**
         * @brief Checks if the operation is currently running.
         * @return True if the operation is running, false otherwise.
         */
        _NODISCARD bool IsRunning() const noexcept;

        /**
         * @brief Attempts to cancel the operation.
         * @return True if the operation was successfully canceled, false otherwise.
         */
        bool TryCancel() noexcept;

        /**
         * @brief Sets the state of the operation.
         * @param state The new state to set.
         */
        void SetState(State state) noexcept;

    private:
        std::atomic<State> state_{State::Inited}; /**< The atomic state being managed. */
    };

} // namespace Core::Async
