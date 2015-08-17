#include "basecategoryview.h"

CSVSettings::BaseCategoryView::BaseCategoryView(CSMSettings::Setting* setting,
                                                Page* parent)
    : View(setting, parent)
{
    QWidget* widget = createAndConnectCategory(setting);

    addWidget(widget);
}
