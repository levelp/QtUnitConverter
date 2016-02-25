#include "units.h"

// Каждую физическую величину удобно выразить в наиболее привычных
// и удобных для рассчётов базовых единицах

// Вес и массу удобно выражать в килограммах
Units weight[] = {
  {"килограмм", 1.0, 0.0},
  {"грамм", 0.001, 0.0},
  {"центнер", 100.0, 0.0},
  {"тонна", 1000.0, 0.0},
  {"фунт", 0.45359237, 0.0},
  {"унция", 0.028349523, 0.0},
  {"драхма", 0.0017718452, 0.0},
  {"гран", 0.000064798911, 0.0},
  // Последняя строка в каждой таблице заполнена нулями
  {NULL, 0.0, 0.0}
};

// Расстояния и длины удобно выражать в метрах
Units length[] = {
  {"метр", 1.0, 0.0},
  {"километр", 1000.0, 0.0},
  {"фут", 0.3048, 0.0},
  {NULL, 0.0, 0.0}
};

// Объём, вместимость - в литрах
Units volume[] = {
  {"литр", 1.0, 0.0},
  {"кубический метр", 1000.0, 0.0},
  {NULL, 0.0, 0.0}
};

// Температуру - в градусах Цельсия
// Тут ещё понадобятся смещения
Units temperature[] = {
  {"градусы Цельсия", 1.0, 0.0},
  {"кельвин", 1.0, 273.15},
  {NULL, 0.0, 0.0}
};