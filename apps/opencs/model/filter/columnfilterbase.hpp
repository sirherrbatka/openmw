#ifndef CSM_FILTER_COLUMNFILTERBASE_H
#define CSM_FILTER_COLUMNFILTERBASE_H

#include <string>
#include <map>

#include <boost/shared_ptr.hpp>

#include <QMetaType>

namespace CSMFilter
{
    class ColumnFilterBase
    {
        public:
            virtual ~ColumnFilterBase ();

            ///< \return Can the specified table column pass through to filter?
            /// \param columns column ID to column index mapping
            virtual bool test (int column,
                               const std::map<int, int>& columns) const = 0;
    };
}

Q_DECLARE_METATYPE (boost::shared_ptr<CSMFilter::ColumnFilterBase>)

#endif
