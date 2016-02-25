#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "units.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

  void convertValue();

  void updateComboBoxes();

  Units* getActiveUnitsList();

 private slots:
  void on_srcComboBox_currentIndexChanged(const QString& arg1);

  void on_dstComboBox_currentIndexChanged(const QString& arg1);

  void on_srcValue_valueChanged(double arg1);

  void on_dstValue_valueChanged(double arg1);

  void on_lengthRadioButton_clicked();

  void on_temperatureRadioButton_clicked();

  void on_volumeRadioButton_clicked();

  void on_weightRadioButton_clicked();

 private:
  Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
