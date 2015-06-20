
#include "idtableproxymodel.hpp"

#include <vector>

#include "idtablebase.hpp"

void CSMWorld::IdTableProxyModel::updateColumnMap()
{
    mColumnMap.clear();

    if (mRowFilter)
    {
        std::vector<int> columns(mRowFilter->getReferencedColumns());

        const IdTableBase& table = dynamic_cast<const IdTableBase&> (*sourceModel());

        for (std::vector<int>::const_iterator iter (columns.begin()); iter!=columns.end(); ++iter)
            mColumnMap.insert (std::make_pair (*iter,
                table.searchColumnIndex (static_cast<CSMWorld::Columns::ColumnId> (*iter))));
    }
}

bool CSMWorld::IdTableProxyModel::filterAcceptsRow (int sourceRow,
                                                    const QModelIndex& sourceParent) const
{
    // It is not possible to use filterAcceptsColumn() and check for
    // sourceModel()->headerData (sourceColumn, Qt::Horizontal, CSMWorld::ColumnBase::Role_Flags)
    // because the sourceColumn parameter excludes the hidden columns, i.e. wrong columns can
    // be rejected.  Workaround by disallowing tree branches (nested columns), which are not meant
    // to be visible, from the filter.
    if (sourceParent.isValid())
        return false;

    if (!mRowFilter)
        return true;

    return mRowFilter->test (
        dynamic_cast<IdTableBase&> (*sourceModel()), sourceRow, mColumnMap);
}

bool CSMWorld::IdTableProxyModel::filterAcceptsColumn (int sourceColumn, const QModelIndex& sourceParent) const
{
    if (sourceParent.isValid())
        return false;

    return (!mColumnFilter || mColumnFilter->test(sourceColumn, mColumnMap));
}

CSMWorld::IdTableProxyModel::IdTableProxyModel (QObject *parent)
    : QSortFilterProxyModel (parent)
{
    setSortCaseSensitivity (Qt::CaseInsensitive);
}

QModelIndex CSMWorld::IdTableProxyModel::getModelIndex (const std::string& id, int column) const
{
    return mapFromSource (dynamic_cast<IdTableBase&> (*sourceModel()).getModelIndex (id, column));
}

void CSMWorld::IdTableProxyModel::setRowFilter (const boost::shared_ptr<CSMFilter::Node>& filter)
{
    beginResetModel();
    mRowFilter = filter;
    updateColumnMap();
    endResetModel();
}

void CSMWorld::IdTableProxyModel::setColumnFilter (const boost::shared_ptr<CSMFilter::ColumnFilterBase>& filter)
{
    beginResetModel();
    mColumnFilter = filter;
    updateColumnMap();
    endResetModel();
}

bool CSMWorld::IdTableProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
    return QSortFilterProxyModel::lessThan(left, right);
}

void CSMWorld::IdTableProxyModel::refreshFilter()
{
    updateColumnMap();
    invalidateFilter();
}
