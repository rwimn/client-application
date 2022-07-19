/***********************************************************************************************************************
**
** Copyright (C) 2022 Saratov Free Software Center. <optics@sarfsc.ru>
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
**
***********************************************************************************************************************/

#include "graphmodel.h"

#include <mvvm/interfaces/undostackinterface.h>
#include <mvvm/standarditems/standarditemincludes.h>
#include <mvvm/utils/numericutils.h>
#include <mvvm/widgets/widgetutils.h>

#include <cmath>
#include <stdexcept>

#include <QColor>

namespace
{
constexpr double PI   = 3.14159265358979323846;
constexpr int nPoints = 1000;
constexpr double xMin = 0.0;
constexpr double xMax = 374.46;
constexpr double dx   = (xMax - xMin) / nPoints;

std::vector<double> binValues(double ampFactor = 1.0)
{
    std::vector<double> result;
    for (int i = 0; i < nPoints; ++i)
    {
        double x     = xMin + i * dx;
        double value = ampFactor * 15.0 * std::sin(1.75 * PI * 3 * x)
                       + ampFactor * 7.0 * std::sin(2 * PI * 3.32 * x);
        result.push_back(value);
    }
    return result;
}
} // namespace

using namespace ModelView;

namespace gui
{
GraphModel::GraphModel()
    : SessionModel("GraphModel")
{
    populateModel();
}

void GraphModel::addGraph()
{
    if (undoStack())
    {
        undoStack()->beginMacro("addGraph");
    }

    auto data = insertItem<Data1DItem>(dataContainer());
    data->setAxis<FixedBinAxisItem>(nPoints, xMin, xMax);
    data->setValues(binValues(ModelView::Utils::RandDouble(0.5, 1.0)));

    auto graph = insertItem<GraphItem>(viewport());
    graph->setDataItem(data);
    graph->setNamedColor(ModelView::Utils::RandomNamedColor());

    if (undoStack())
    {
        undoStack()->endMacro();
    }
}

GraphViewportItem *GraphModel::viewport()
{
    return topItem<GraphViewportItem>();
}

ContainerItem *GraphModel::dataContainer()
{
    return topItem<ContainerItem>();
}

void GraphModel::populateModel()
{
    auto container = insertItem<ContainerItem>();
    container->setDisplayName("Data container");

    auto viewport = insertItem<GraphViewportItem>();
    viewport->setDisplayName("Graph container");

    addGraph();
    setUndoRedoEnabled(true);
}

} // namespace gui
