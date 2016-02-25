#ifndef UNITS_H
#define UNITS_H

#include <QString>

// Для каждой физической величины будем хранить её имя
// и её размер в базовых единицах измерения
struct Units {
  QString name; // Название единицы измерения
  double size; // Размер в базовых единицах
  double offset; // Смещение (нужно для температуры)
};

extern Units weight[];
extern Units length[];
extern Units volume[];
extern Units temperature[];

#endif // UNITS_H
