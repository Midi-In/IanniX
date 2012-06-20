/*
    IanniX — a graphical real-time open-source sequencer for digital art
    Copyright (C) 2010-2012 — IanniX Association

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef EXTOSCPATTERNEDITOR_H
#define EXTOSCPATTERNEDITOR_H

#include <QWidget>
#include <QPlainTextEdit>
#include "nxobject.h"

namespace Ui {
    class ExtOscPatternEditor;
}

class QPlainTextEditWithFocus : public QPlainTextEdit {
    Q_OBJECT

public:
    QPlainTextEditWithFocus(QWidget *parent = 0):
        QPlainTextEdit(parent) {}

signals:
    void focusOut();
    void focusIn();
protected:
    void focusOutEvent(QFocusEvent *) {    emit(focusOut());   }
    void focusInEvent(QFocusEvent *)  {    emit(focusIn());    }
};

class ExtOscPatternEditor : public QWidget{
    Q_OBJECT

public:
    explicit ExtOscPatternEditor(QWidget *parent = 0);
    ~ExtOscPatternEditor();

private:
    bool textLock, itemLock;
    QList< QPair<QComboBox*,QLabel*> > trees;
    quint16 patternNbValues;

public:
    const QString getPattern() const;
    void setPattern(const QString &pattern, bool refreshText);
    void setPattern(const QVector<QByteArray> &messagePatternItems, bool refreshText);
    void setCurrentItem(QComboBox *combo, QLabel *label, const QString &value, bool forceVisible = true);
    QString getItem(QComboBox *combo, const QString &valDefault, const QString &prefix = "") const;
    QString getItem(QComboBox *combo, qint32 valDefault) const;

signals:
    void actionRouteRemove(ExtOscPatternEditor*);

public slots:
    void currentItemChanged();
    void textPatternChanged();

private:
    Ui::ExtOscPatternEditor *ui;
};

#endif // EXTOSCPATTERNEDITOR_H
