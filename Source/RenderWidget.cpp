#include <RenderWidget.h>

#include <Interfaces/IRenderable.h>


#if __has_include(<nvtx3/nvToolsExt.h>)
#include <nvtx3/nvToolsExt.h>
#define NVTX_RANGE_PUSH(__name) nvtxRangePushA(__name)
#define NVTX_RANGE_PUSH_CURRENT() NVTX_RANGE_PUSH(__FUNCTION__)
#define NVTX_RANGE_POP() nvtxRangePop()
#else
#define NVTX_RANGE_PUSH(...)
#define NVTX_RANGE_PUSH_CURRENT()
#define NVTX_RANGE_POP()
#endif


RenderWidget::RenderWidget(QWidget* parent) : QWidget(parent)
{
}

void RenderWidget::UpdateView(std::shared_ptr<Core::Interfaces::IRenderable> renderObject)
{
    object_ = renderObject;
    update();
}

void RenderWidget::paintEvent(QPaintEvent* event)
{
    NVTX_RANGE_PUSH_CURRENT();
    if (object_)
    {
        NVTX_RANGE_PUSH("Render object");
        object_->Draw(event, this);
        NVTX_RANGE_POP();
    }
    NVTX_RANGE_POP();
}
