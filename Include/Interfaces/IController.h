#pragma once

#include <QObject>

#include <Domain/UIData.h>

namespace Core::Interfaces
{
    class IRenderable;

    class IController : public QObject
    {
        Q_OBJECT
    public:
        explicit IController(QObject* parent = nullptr) : QObject(parent)
        {
        }

        ~IController() override = default;

    
    signals:
        void OnFinished(std::shared_ptr<IRenderable>);

    public slots:
        virtual void OnControl(Core::Data::UIDataInput) = 0;
    };
} // namespace Core::Interfaces
