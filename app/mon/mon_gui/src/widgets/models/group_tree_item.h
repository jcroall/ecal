/* ========================= eCAL LICENSE =================================
 *
 * Copyright (C) 2016 - 2019 Continental Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * ========================= eCAL LICENSE =================================
*/

#pragma once

#include "CustomQt/QAbstractTreeItem.h"

#include <QList>

class GroupTreeItem :
  public QAbstractTreeItem
{
public:

  GroupTreeItem(const QVariant& display_role,
                const QVariant& filter_role,
                const QVariant& sort_role,
                const QVariant& font_role,
                const QVariant& group_identifier);

  ~GroupTreeItem();

  QVariant data(int column, Qt::ItemDataRole role = Qt::ItemDataRole::DisplayRole) const;

  int type() const;

  QVariant name() const;
  QVariant identifier() const;

private:
  QVariant display_role_;
  QVariant filter_role_;
  QVariant sort_role_;
  QVariant font_role_;
  QVariant group_identifier_;
};
