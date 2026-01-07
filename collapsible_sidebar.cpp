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

#include "collapsible_sidebar.hpp"

#include <QPropertyAnimation>
#include <QDebug>

namespace ui
{
CollapsibleSidebar::CollapsibleSidebar(const QString& title, const int animationDuration, QWidget* parent)
    : QWidget(parent), animationDuration(animationDuration)
{
  toggleButton = new QToolButton(this);
  toggleAnimation = new QParallelAnimationGroup(this);
  contentArea = new QScrollArea(this);
  mainLayout = new QGridLayout(this);

  toggleButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
  toggleButton->setArrowType(Qt::ArrowType::LeftArrow);
  toggleButton->setText(title);
  toggleButton->setCheckable(true);
  toggleButton->setChecked(false);

  contentArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

  // start out collapsed
  contentArea->setMaximumWidth(0);
  contentArea->setMinimumWidth(0);

  // let the entire widget grow and shrink with its content
  toggleAnimation->addAnimation(new QPropertyAnimation(this, "maximumWidth"));
  toggleAnimation->addAnimation(new QPropertyAnimation(this, "minimumWidth"));
  toggleAnimation->addAnimation(new QPropertyAnimation(contentArea, "maximumWidth"));

  mainLayout->setContentsMargins(0, 0, 0, 0);

  int row = 0;
  mainLayout->addWidget(toggleButton, row++, 0, 1, 1, Qt::AlignLeft|Qt::AlignTop);
  mainLayout->addWidget(contentArea, row, 0, 1, 3);
  setLayout(mainLayout);

  connect(toggleButton, &QToolButton::toggled, this, &CollapsibleSidebar::toggle);
}

void CollapsibleSidebar::toggle(bool expanded)
{
  toggleButton->setArrowType(expanded ? Qt::ArrowType::RightArrow : Qt::ArrowType::LeftArrow);
  toggleAnimation->setDirection(expanded ? QAbstractAnimation::Forward : QAbstractAnimation::Backward);
  toggleAnimation->start();
  this->isExpanded = expanded;
}

void CollapsibleSidebar::setContentLayout(QLayout& contentLayout)
{
  delete contentArea->layout();
  contentArea->setLayout(&contentLayout);
  collapsedWidth = INITIAL_WIDTH;

  updateWidths();
}

void CollapsibleSidebar::setTitle(QString title)
{
  toggleButton->setText(std::move(title));
}

void CollapsibleSidebar::updateWidths()
{
  int contentWidth = contentArea->layout()->sizeHint().width();

  for (int i = 0; i < toggleAnimation->animationCount() - 1; ++i)
  {
    QPropertyAnimation* SectionAnimation = static_cast<QPropertyAnimation *>(toggleAnimation->animationAt(i));
    SectionAnimation->setDuration(animationDuration);
    SectionAnimation->setStartValue(collapsedWidth);
    SectionAnimation->setEndValue(collapsedWidth + contentWidth);
  }

  QPropertyAnimation* contentAnimation = static_cast<QPropertyAnimation *>(toggleAnimation->animationAt(toggleAnimation->animationCount() - 1));
  contentAnimation->setDuration(animationDuration);
  contentAnimation->setStartValue(0);
  contentAnimation->setEndValue(contentWidth);

  toggleAnimation->setDirection(isExpanded ? QAbstractAnimation::Forward : QAbstractAnimation::Backward);
  toggleAnimation->start();
}
}
