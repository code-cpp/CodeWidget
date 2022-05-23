#include "CodeWidget.h"

#include <Qsci/qsciapis.h>
#include <Qsci/qscilexercpp.h>
#include <Qsci/qscilexercsharp.h>
#include <Qsci/qscilexervb.h>
#include <Qsci/qscilexerverilog.h>
#include <Qsci/qsciscintilla.h>

#include <QHBoxLayout>

#include "ui_CodeWidget.h"

CodeWidget::CodeWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::CodeWidget), editor{new QsciScintilla(this)} {
  ui->setupUi(this);

  //设置编号为0的页边显示行号
  editor->setMarginType(0, QsciScintilla::NumberMargin);
  editor->setMarginLineNumbers(0, true);
  editor->setMarginWidth(0, 35);

  editor->SendScintilla(QsciScintilla::SCI_SETCODEPAGE,
                        QsciScintilla::SC_CP_UTF8);

  QsciLexer *textLexer;
  textLexer = new QsciLexerVB;
  editor->setLexer(textLexer);

  QsciAPIs *apis = new QsciAPIs(textLexer);
  QString filename = ":/keywords/CppWord";
  apis->load(filename);
  apis->prepare();

  //设置自动完成所有项
  editor->setAutoCompletionSource(QsciScintilla::AcsAll);
  //设置大小写敏感
  editor->setAutoCompletionCaseSensitivity(true);
  //每输入1个字符就出现自动完成的提示
  editor->setAutoCompletionThreshold(1);

  //其他设置
  //开启自动缩进
  editor->setAutoIndent(true);
  //设置缩进的显示方式
  editor->setIndentationGuides(QsciScintilla::SC_IV_LOOKBOTH);
  //显示选中的行号
  editor->setCaretLineVisible(true);
  //显示选中行号的背景色
  editor->setCaretLineBackgroundColor(Qt::lightGray);
  //左侧行号显示的背景色
  editor->setMarginsBackgroundColor(Qt::gray);
  //设置括号匹配
  editor->setBraceMatching(QsciScintilla::SloppyBraceMatch);

  //设置左侧行号栏宽度等
  QFont font("Courier", 10, QFont::Normal);
  QFontMetrics fontmetrics = QFontMetrics(font);
  editor->setMarginWidth(0, fontmetrics.horizontalAdvance("000"));
  editor->setMarginLineNumbers(0, true);
  editor->setBraceMatching(QsciScintilla::SloppyBraceMatch);  //括号匹配
  editor->setTabWidth(4);

  QFont margin_font;
  margin_font.setFamily("SimSun");
  margin_font.setPointSize(
      11);  //边栏字体设置px我这里显示不出行号，不知道是怎么回事
  editor->setMarginsFont(margin_font);  //设置页边字体
  editor->setMarginType(
      0, QsciScintilla::NumberMargin);  //设置标号为0的页边显示行号
  // editor->setMarginMarkerMask(0,QsciScintilla::Background);//页边掩码
  // editor->setMarginSensitivity(0,true);//设置是否可以显示断点,注册通知事件，当用户点击边栏时，scintilla会通知我们
  // textEdit->setMarginsBackgroundColor(QColor("#bbfaae"));
  //    editor->setMarginLineNumbers(0,true);//设置第0个边栏为行号边栏，True表示显示
  //    editor->setMarginWidth(0,15);//设置0边栏宽度
  editor->setMarginsBackgroundColor(Qt::gray);  //显示行号背景颜色
  editor->setMarginsForegroundColor(Qt::white);

  editor->setFolding(QsciScintilla::BoxedTreeFoldStyle);  //折叠样式
  editor->setFoldMarginColors(Qt::gray, Qt::lightGray);   //折叠栏颜色

  // auto complete
  // Acs[None|All|Document|APIs]
  //禁用自动补全提示功能|所有可用的资源|当前文档中出现的名称都自动补全提示|使用QsciAPIs类加入的名称都自动补全提示
  editor->setAutoCompletionSource(
      QsciScintilla::AcsAll);  //自动补全。对于所有Ascii字符
  // editor->setAutoCompletionCaseSensitivity(false);//大小写敏感度，设置lexer可能会更改，不过貌似没啥效果
  editor->setAutoCompletionThreshold(
      3);  //设置每输入一个字符就会出现自动补全的提示
  // editor->setAutoCompletionReplaceWord(false);//是否用补全的字符串替代光标右边的字符串

  QHBoxLayout *hly = new QHBoxLayout(this);
  hly->addWidget(editor);
}

CodeWidget::~CodeWidget() { delete ui; }
