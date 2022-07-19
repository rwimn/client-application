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

#ifndef GRAPH_MODEL_H
#define GRAPH_MODEL_H

#include <mvvm/model/sessionmodel.h>

namespace ModelView
{
class GraphViewportItem;
class ContainerItem;
} // namespace ModelView

namespace gui
{
class GraphModel : public ModelView::SessionModel
{
public:
    GraphModel();

    void addGraph();

private:
    ModelView::GraphViewportItem *viewport();
    ModelView::ContainerItem *dataContainer();

    void populateModel();
};

} // namespace gui

#endif // GRAPH_MODEL_H
