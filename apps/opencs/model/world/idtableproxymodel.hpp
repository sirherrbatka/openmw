#ifndef CSM_WOLRD_IDTABLEPROXYMODEL_H
#define CSM_WOLRD_IDTABLEPROXYMODEL_H

#include <string>

#include <boost/shared_ptr.hpp>

#include <map>

#include <QSortFilterProxyModel>

#include "../filter/node.hpp"
#include "../filter/columnfilterbase.hpp"

namespace CSMWorld
{
    class IdTableProxyModel : public QSortFilterProxyModel
    {
            Q_OBJECT

            boost::shared_ptr<CSMFilter::Node> mRowFilter;
            boost::shared_ptr<CSMFilter::ColumnFilterBase> mColumnFilter;
            std::map<int, int> mColumnMap; // column ID, column index in this model (or -1)

        private:

            void updateColumnMap();

        public:

            IdTableProxyModel (QObject *parent = 0);

            virtual QModelIndex getModelIndex (const std::string& id, int column) const;

            void setRowFilter (const boost::shared_ptr<CSMFilter::Node>& filter);
            void setColumnFilter (const boost::shared_ptr<CSMFilter::ColumnFilterBase>& filter);

            void refreshFilter();

        protected:

            bool lessThan(const QModelIndex& left, const QModelIndex& right) const;

            virtual bool filterAcceptsRow (int sourceRow,
                                           const QModelIndex& sourceParent) const;

            virtual bool filterAcceptsColumn (int source_column,
                                              const QModelIndex& sourceParent) const;
    };
}

#endif
