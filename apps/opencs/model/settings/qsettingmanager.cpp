#include "./qsettingmanager.hpp"

#include <QMetaType>
#include <QStringList>

#include <cassert>

CSMSettings::QSettingManager* CSMSettings::QSettingManager::sThisPointer = NULL;

CSMSettings::QSettingManager::QSettingManager(const QString& filePath) :
mSettings(filePath)    //QSETTINGS WILL BE UNABLE TO DEAL WITH NON-QSETTINGS SYNTAX!!!
{
    assert(!sThisPointer);
    sThisPointer = this;
    qRegisterMetaType<CSMSettings::Setting>("SettingStruct");
    qRegisterMetaTypeStreamOperators<CSMSettings::Setting>("SettingStruct");
}

CSMSettings::Setting CSMSettings::QSettingManager::findSetting (const QString& key) const
{
    return mSettings.value(key).value<CSMSettings::Setting>();
}

CSMSettings::QSettingManager* CSMSettings::QSettingManager::getSettingManager()
{
    return sThisPointer;
}

void CSMSettings::QSettingManager::storeSetting (const QString& key, const Setting& setting)
{
    mSettings.setValue(key, QVariant::fromValue(setting));
}

QVariant CSMSettings::QSettingManager::data (const QModelIndex& index, int role)
{
    switch (index.column())
    {
        case 0:
            return QVariant();
        case 2:
            return getKeyFromRow(index.row());
    }
}

int CSMSettings::QSettingManager::rowCount (const QModelIndex& parent) const
{
    if (parent.isValid())
    {
        return -1;
    } else {
        return mSettings.allKeys().size();
    }
}

int CSMSettings::QSettingManager::columnCount (const QModelIndex& parent) const
{
    if (parent.isValid())
    {
        return -1;
    } else {
        return 3;
    }
}

bool CSMSettings::QSettingManager::setData (const QModelIndex& index, const QVariant& value, int role)
{
    if (parent.isValid())
    {
        return false;
    } else {
        switch (index.column())
        {
            case 2:
                setKeyFromRow(index.row(), value);
                break;
        }
    }
}

QModelIndex CSMSettings::QSettingManager::index (int row, int column, const QModelIndex& parent) const
{
    return createIndex(row, column);
}

QVariant CSMSettings::QSettingManager::getKeyFromRow (const int row)
{
    return mSettings.value(mSettings.allKeys().at(row));
}

void CSMSettings::QSettingManager::setKeyFromRow (const int row, const QVariant& value)
{
    mSettings.setValue(mSettings.allKeys().at(row), value);
    return;
}

QVariant CSMSettings::QSettingManager::getGroupFromRow (const int row)
{
    return QVariant(*mSettings.allKeys().at(row).split("/").begin());
}
