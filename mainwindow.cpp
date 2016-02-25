#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::convertValue() {
  // Конвертируем одну величину в другую
  Units* active = getActiveUnitsList();
  // Исходная единица измерения в базовых единицах измерения
  Units from = active[ui->srcComboBox->currentData().toInt()];
  // Конечная единица измерения в базовых единицах измерения
  Units to = active[ui->dstComboBox->currentData().toInt()];
  // Умножаем исходное значение на отношение единиц измерения
  ui->dstValue->setValue( (ui->srcValue->value() - from.offset) * (from.size  / to.size) + to.offset);
}

Units* MainWindow::getActiveUnitsList() {
  if(ui->weightRadioButton->isChecked())
    return weight;
  if(ui->lengthRadioButton->isChecked())
    return length;
  if(ui->volumeRadioButton->isChecked())
    return volume;
  if(ui->temperatureRadioButton->isChecked())
    return temperature;
  // По-умолчанию
  return weight;
}

void MainWindow::updateComboBoxes() {
  // Выбираем активный список единиц измерения
  Units* active = getActiveUnitsList();

  // Добавляем все величины из активного списка в оба ComboBox'а
  ui->srcComboBox->clear();
  ui->dstComboBox->clear();
  for(int i = 0; active[i].name != NULL; i++) {
    // Чтобы понимать какая величина выбрана, добавляем её индекс в список
    ui->srcComboBox->addItem(active[i].name, QVariant(i));
    ui->dstComboBox->addItem(active[i].name, QVariant(i));
  }
  // Выбираем в первом первую величину
  ui->srcComboBox->setCurrentIndex(0);
  // А во втором => вторую
  ui->dstComboBox->setCurrentIndex(1);
}

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // Добавляем все величины из активного списка в оба ComboBox'а
  updateComboBoxes();
  // Сразу конвертируем значение (чтобы показать что всё работает)
  convertValue();
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_srcComboBox_currentIndexChanged(const QString& arg1) {
  convertValue();
}

void MainWindow::on_dstComboBox_currentIndexChanged(const QString& arg1) {
  convertValue();
}

void MainWindow::on_srcValue_valueChanged(double arg1) {
  convertValue();
}

void MainWindow::on_dstValue_valueChanged(double arg1) {
  convertValue();
}

void MainWindow::on_weightRadioButton_clicked() {
  updateComboBoxes();
}

void MainWindow::on_lengthRadioButton_clicked() {
  updateComboBoxes();
}

void MainWindow::on_temperatureRadioButton_clicked() {
  updateComboBoxes();
}

void MainWindow::on_volumeRadioButton_clicked() {
  updateComboBoxes();
}
