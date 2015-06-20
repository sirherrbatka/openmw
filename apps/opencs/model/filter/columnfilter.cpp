#include "columnfilter.hpp"

#include <algorithm>

CSMFilter::ColumnFilter::ColumnFilter (const std::vector<CSMWorld::Columns::ColumnId>& allowedIds)
    : mAllowedIds (allowedIds)
{}

bool CSMFilter::ColumnFilter::test (int column,
                                    const std::map<int, int>& columns) const
{
    std::map<int, int>::const_iterator it(columns.find(column));

    if (it == columns.end())
    {
        throw std::invalid_argument("Can't map column number to the column id");
    }

    CSMWorld::Columns::ColumnId checkedId = static_cast<CSMWorld::Columns::ColumnId> (it->second);
    return (std::find(mAllowedIds.begin(), mAllowedIds.end(), checkedId) != mAllowedIds.end());
}
