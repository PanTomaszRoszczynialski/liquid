/*
    Copyright (C) 2011 Jocelyn Turcotte <turcotte.j@gmail.com>

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this program; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#ifndef HISTORYITEM_H
#define HISTORYITEM_H

#include <QObject>
#include "tab.h"
#include "location.h"

class HistoryItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QUrl iconSource READ iconSource NOTIFY iconSourceChanged)
    Q_PROPERTY(Location* location READ location CONSTANT)
    Q_PROPERTY(int relativeIndex READ relativeIndex NOTIFY relativeIndexChanged)

public:
    HistoryItem(int qWebHistoryIndex, Tab* tab, QObject* parent = 0);

    Q_INVOKABLE void goTo();
    QUrl iconSource();
    QPixmap icon();
    Location* location() { return &m_location; }
    int relativeIndex() const;

    void checkIcon();
    void checkRelativeIndex();

signals:
    void indexChanged();
    void iconSourceChanged();
    void relativeIndexChanged();

private:
    int m_qWebHistoryIndex;
    Tab* m_tab;
    Location m_location;
};

#endif // HISTORYITEM_H