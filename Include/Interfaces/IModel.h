#pragma once

#include <Domain/UIData.h>
#include <QObject>

namespace Core::Interfaces
{
    class IRenderable;
}

namespace Core::Async
{
    class SharedContext;
}

namespace Core::Interfaces
{
    class IModel : public QObject
    {
        Q_OBJECT;

    public:
        explicit IModel(QObject* parent = nullptr) : QObject(parent)
        {
        }

    public slots:
        virtual void Invoke(Core::Data::UIDataInput, std::shared_ptr<Async::SharedContext> context) = 0;

    signals:
        void OnFinished(std::shared_ptr<Core::Interfaces::IRenderable>);
    };
} // namespace Core::Interfaces
