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

#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <memory>

#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class QDataWidgetMapper;

namespace ModelView
{
class ViewModel;
class ViewModelDelegate;
class SessionItem;
} // namespace ModelView

namespace gui
{
class GraphModel;

class MainWindow : public QMainWindow
{
public:
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    MainWindow(const MainWindow &) = delete;            // copy ctor
    MainWindow(MainWindow &&)      = delete;            // move ctor
    MainWindow &operator=(const MainWindow &) = delete; // copy assignment
    MainWindow &operator=(MainWindow &&) = delete;      // move assignment

private:
    Ui::MainWindow *ui{nullptr};

private:
    std::unique_ptr<GraphModel> model;
};

} // namespace gui

#endif //MAIN_WINDOW_H
