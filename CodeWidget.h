#ifndef CODEWIDGET_H
#define CODEWIDGET_H

#include <QWidget>

class QsciScintilla;

QT_BEGIN_NAMESPACE
namespace Ui {
class CodeWidget;
}
QT_END_NAMESPACE

class CodeWidget : public QWidget {
  Q_OBJECT

 public:
  CodeWidget(QWidget *parent = nullptr);
  ~CodeWidget();

 private:
  Ui::CodeWidget *ui;
  QsciScintilla *editor;
};

#endif  // CODEWIDGET_H
