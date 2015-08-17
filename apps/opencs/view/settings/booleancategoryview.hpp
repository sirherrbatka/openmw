#ifndef HIERARCHICALBOOLEANVIEW_H
#define HIERARCHICALBOOLEANVIEW_H

namespace CSVSettings
{
    class Page;

    class BooleanCategoryView : public BaseCategoryView
    {
            Q_OBJECT

        public:
            explicit BooleanCategoryView(CSMSettings::Setting* setting,
                                         Page *parent);

        protected:
            virtual void updateView (bool signalUpdate = true) const;
    };

    class BooleanCategoryView : public QObject, public IViewFactory
    {
            Q_OBJECT

        public:
            explicit BooleanCategoryView(QWidget* parent = 0)
                : QObject (parent)
            {}

            ///Overriden method (from IViewFactory)
            virtual BooleanView* createView(CSMSettings::Setting* setting,
                                            Page* parent);
    };
}

#endif /* HIERARCHICALBOOLEANVIEW_H */
