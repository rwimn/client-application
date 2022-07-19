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

#ifndef GRAPH_WIDGET_H
#define GRAPH_WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui
{
class GraphWidget;
}
QT_END_NAMESPACE

namespace ModelView
{
class ItemsTreeView;
class GraphCanvas;
} // namespace ModelView

namespace gui
{
class GraphModel;

class GraphWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GraphWidget(QWidget *parent = nullptr);
    ~GraphWidget();

    void setModel(GraphModel *model);

private:
    void initActions();

private:
    GraphWidget(const GraphWidget &) = delete;            // copy ctor
    GraphWidget(GraphWidget &&)      = delete;            // move ctor
    GraphWidget &operator=(const GraphWidget &) = delete; // copy assignment
    GraphWidget &operator=(GraphWidget &&) = delete;      // move assignment

private:
    GraphModel *model{nullptr};

private:
    Ui::GraphWidget *ui{nullptr};
};

} // namespace gui

#endif // GRAPH_WIDGET_H
