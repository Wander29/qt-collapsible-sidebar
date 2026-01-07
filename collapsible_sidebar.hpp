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

#ifndef COLLAPSIBLE_SIDEBAR_HPP
#define COLLAPSIBLE_SIDEBAR_HPP

#include <QFrame>
#include <QGridLayout>
#include <QParallelAnimationGroup>
#include <QScrollArea>
#include <QToolButton>
#include <QWidget>

namespace ui
{
class CollapsibleSidebar : public QWidget
{
  Q_OBJECT

public:
  static const int DEFAULT_DURATION = 150;

  explicit CollapsibleSidebar(const QString& title = "", const int animationDuration = DEFAULT_DURATION, QWidget* parent = 0);

  void setContentLayout(QLayout& contentLayout);
  void setTitle(QString title);
  void updateWidths();

public slots:
  void toggle(bool collapsed);

private:
  QGridLayout* mainLayout;
  QToolButton* toggleButton;
  QParallelAnimationGroup* toggleAnimation;
  QScrollArea* contentArea;
  int animationDuration;
  int collapsedWidth;
  bool isExpanded = false;
  static const int INITIAL_WIDTH=48;
};
}

#endif // COLLAPSIBLE_SIDEBAR_HPP
