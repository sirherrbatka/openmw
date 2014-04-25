#ifndef CSMSETTINGS_QSETTINGMANAGER_HPP
#define CSMSETTINGS_QSETTINGMANAGER_HPP

#include <QSettings>
#include <QString>
#include <qt4/QtCore/QModelIndex>

#include "./setting.hpp"

namespace CSMSettings
{
    class QSettingManager : public QAbstractItemModel
    {
        QSettings mSettings;
        static QSettingManager* sThisPointer;

    public:
        static QSettingManager* getSettingManager();

        //interface for QAbstractItemModel subclass
        virtual int rowCount(const QModelIndex & parent = QModelIndex()) const;

        virtual int columnCount ( const QModelIndex & parent = QModelIndex() ) const;

        virtual QModelIndex index(int row, int column, const QModelIndex & parent = QModelIndex()) const;

        virtual QModelIndex parent(const QModelIndex & index) const;

        virtual QVariant data(const QModelIndex & index, int role = Qt::DisplayRole);

        virtual bool setData ( const QModelIndex & index, const QVariant & value, int role = Qt::EditRole );

    //remaining functions
        QSettingManager(const QString& filePath);

        Setting findSetting(const QString& key) const;

        void storeSetting(const QString& key, const Setting& setting);

    protected:
        QVariant getKeyFromRow(const int row);

        void setKeyFromRow(const int row, const QVariant& value);

        QVariant getGroupFromRow(const int row);
    };
}
#endif // CSMSETTINGS_QSETTINGMANAGER_HPP
