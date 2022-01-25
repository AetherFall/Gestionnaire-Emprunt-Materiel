#include "MyDelegate.h"
#include <QSpinBox>

MyDelegate::MyDelegate(QObject *parent) : QItemDelegate(parent)
{

}

// TableView need to create an Editor
// Create Editor when we construct MyDelegate
// and return the Editor
QWidget* MyDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    return new ElementsItem("CB#01", *new QImage("/res/images/radio.png"), "William Lambert", true, parent);
   /* QSpinBox *editor = new QSpinBox(parent);
    ElementsItem *item = new ElementsItem("CB#01", *new QImage("/res/images/radio.png"), "William Lambert", true, parent);
       editor->setMinimum(0);
       editor->setMaximum(100);
       return editor;*/
}

// Then, we set the Editor
// Gets the data from Model and feeds the data to Editor
void MyDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
    // Get the value via index of the Model
    //int value = index.model()->data(index, Qt::EditRole).toInt();

    // Put the value into the SpinBox
   /* QSpinBox *spinbox = static_cast<QSpinBox*>(editor);
    spinbox->setValue(value);*/

    ElementsItem *elem = static_cast<ElementsItem*>(editor);
}

// When we modify data, this model reflect the change
void MyDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
   /* QSpinBox *spinbox = static_cast<QSpinBox*>(editor);
        spinbox->interpretText();
        int value = spinbox->value();
        model->setData(index, value, Qt::EditRole);*/

    ElementsItem *elem = static_cast<ElementsItem*>(editor);
}

// Give the SpinBox the info on size and location
void MyDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    ElementsItem *elem = static_cast<ElementsItem*>(editor);
}
