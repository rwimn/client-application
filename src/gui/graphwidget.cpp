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

#include "graphwidget.h"
#include "ui_graphwidget.h"

#include "graphmodel.h"

#include <mvvm/plotting/graphcanvas.h>
#include <mvvm/standarditems/graphviewportitem.h>

#include <QAction>
#include <QBoxLayout>
#include <QToolBar>
#include <QToolButton>

#include <QDebug>

using namespace ModelView;

namespace gui
{
GraphWidget::GraphWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GraphWidget())
{
    ui->setupUi(this);

    initActions();
}

void GraphWidget::setModel(GraphModel *model)
{
    if (!model)
    {
        return;
    }

    this->model = model;

    ui->graphCanvas->setItem(this->model->topItem<GraphViewportItem>());
}

void GraphWidget::initActions()
{
    // TODO: Implement.
}

GraphWidget::~GraphWidget()
{
    delete ui;
}

} // namespace gui
