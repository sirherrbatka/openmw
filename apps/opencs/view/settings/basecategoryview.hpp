#ifndef BASECATEGORYVIEW_H
#define BASECATEGORYVIEW_H

namespace CSVSettings
{
    class Page;

    class BaseCategoryView : public View
    {
            Q_OBJECT

        public:
            explicit BaseCategoryView(CSMSettings::Setting* setting,
                                      Page* parent);

        protected:
            virtual void updateView(bool signaleUpdate = true) const;

        private:
            virtual QWidget* createAndConnectCategory(CSMSettings::Setting* setting) = 0;
    };
}

#endif /* BASECATEGORYVIEW_H */
