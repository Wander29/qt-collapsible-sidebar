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

#include "mainwindow.h"
#include "collapsible_sidebar.hpp"

#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  m_textEdit(new QTextEdit(this))
{
  // Central widget and layout
  QWidget *central = new QWidget(this);
  QHBoxLayout *layout = new QHBoxLayout(central);

  // Configure text edit (read-only to behave like static text)
  m_textEdit->setReadOnly(true);
  m_textEdit->setPlainText(
    "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
    "Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
    "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. "
    "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. "
    "Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
  );

  layout->addWidget(m_textEdit);
  layout->setContentsMargins(6,6,6,6);

  setCentralWidget(central);
  setWindowTitle(QStringLiteral("Collapsible Sidebar example"));

  // Sidebar
  ui::CollapsibleSidebar* sidebar = new ui::CollapsibleSidebar("Sidebar", 150);

  auto* anyLayout = new QVBoxLayout();
  anyLayout->addWidget(new QLabel("Some Text in Sidebar", sidebar));
  anyLayout->addWidget(new QPushButton("Button in Sidebar", sidebar));

  sidebar->setContentLayout(*anyLayout);
  layout->addWidget(sidebar);
}

QSize MainWindow::sizeHint() const
{
  return QSize(500, 450);
}

MainWindow::~MainWindow() = default;
