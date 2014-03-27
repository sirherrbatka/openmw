#ifndef CSVSETTINGS_SETTINGWINDOW_HPP
#define CSVSETTINGS_SETTINGWINDOW_HPP

#include <QMainWindow>
#include <QList>

#include "support.hpp"
#include "../../model/settings/settingmanager.hpp"

namespace CSMSettings { class Selector; }

namespace CSVSettings {

    class Page;

    typedef QList <Page *> PageList;

    class SettingWindow : public QMainWindow
    {
        Q_OBJECT

        PageList mPages;
        CSMSettings::SettingManager *mModel;

    public:
        explicit SettingWindow(QWidget *parent = 0);

        CSMSettings::Selector *selector(const QString &pageName,
                                        const QString &settingName);

        void setModel (CSMSettings::SettingManager &model)  { mModel = &model; }

    protected:

        virtual void closeEvent (QCloseEvent *event);

        void createPages();

        const PageList &pages() const     { return mPages; }
    };
}

#endif // CSVSETTINGS_SETTINGWINDOW_HPP
