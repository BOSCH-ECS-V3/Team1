#ifndef AVERAGESVIEW_HPP
#define AVERAGESVIEW_HPP

#include <gui_generated/averages_screen/AVERAGESViewBase.hpp>
#include <gui/averages_screen/AVERAGESPresenter.hpp>

class AVERAGESView : public AVERAGESViewBase
{
public:
    AVERAGESView();
    virtual ~AVERAGESView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // AVERAGESVIEW_HPP
