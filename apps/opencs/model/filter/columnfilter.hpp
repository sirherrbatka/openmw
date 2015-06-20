#ifndef CSM_FILTER_COLUMNFILTER_H
#define CSM_FILTER_COLUMNFILTER_H

#include "columnfilterbase.hpp"

#include "../world/columns.hpp" //for ColumnId

#include <vector>
#include <map>

namespace CSMFilter
{
    class ColumnFilter : public ColumnFilterBase
    {
            std::vector<CSMWorld::Columns::ColumnId> mAllowedIds;

        public:
            virtual ~ColumnFilter () {};
            ColumnFilter (const std::vector<CSMWorld::Columns::ColumnId>& allowedIds);

            virtual bool test (int column,
                               const std::map<int, int>& columns) const;
    };
}

#endif
