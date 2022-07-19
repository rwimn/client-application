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

#ifndef STATUS_BAR_WIDGET_H
#define STATUS_BAR_WIDGET_H

#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui
{
class StatusBarWidget;
}
QT_END_NAMESPACE

class QDataWidgetMapper;

namespace ModelView
{
class ViewModel;
class ViewModelDelegate;
} // namespace ModelView

namespace gui
{
class StatusBarWidget : public QWidget
{
public:
    Q_OBJECT

public:
    explicit StatusBarWidget(QWidget *parent = nullptr);
    ~StatusBarWidget() override;

private:
    StatusBarWidget(const StatusBarWidget &) = delete;            // copy ctor
    StatusBarWidget(StatusBarWidget &&)      = delete;            // move ctor
    StatusBarWidget &operator=(const StatusBarWidget &) = delete; // copy assignment
    StatusBarWidget &operator=(StatusBarWidget &&) = delete;      // move assignment

private:
    std::unique_ptr<ModelView::ViewModel> view_model;
    std::unique_ptr<ModelView::ViewModelDelegate> delegate;
    std::unique_ptr<QDataWidgetMapper> mapper;

private:
    Ui::StatusBarWidget *ui{nullptr};
};

} // namespace gui

#endif //STATUS_BAR_WIDGET_H
