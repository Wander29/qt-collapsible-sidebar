/*
    Wander29/qt-collapsible-sidebar
    (c) 2026 Ludovico Venturi - ludo.venturi@gmail.com
    (c) 2016 Michael A. Voelkel - michael.alexander.voelkel@gmail.com

    This file is part of Wander29/qt-collapsible-sidebar.

    Wander29/qt-collapsible-sidebar is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Wander29/qt-collapsible-sidebar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Wander29/qt-collapsible-sidebar. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QTextEdit;

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

  QSize sizeHint() const override;

private:
  QTextEdit *m_textEdit;
};

#endif // MAINWINDOW_H
