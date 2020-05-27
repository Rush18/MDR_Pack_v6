#ifndef MDR_1923KX029_M2_TABLES_CTRL_H
#define MDR_1923KX029_M2_TABLES_CTRL_H

#include <MDR_1923KX028_TableMAC.h>
#include <MDR_1923KX028_TableVLAN.h>
#include <MDR_1923KX028_Config.h>

//  Инициализация таблиц
__STATIC_INLINE void MDR_KX028_M2_InitTables(uint32_t waitCyclesMax)
{
  MDR_KX028_MAC_TableInit(waitCyclesMax);
  MDR_KX028_VLAN_TableInit(waitCyclesMax);
}

//  Обработка старения пакетов
//    framesToProcessMax - сколько фреймов обработать за вызов функции
void MDR_KX028_M2_ProcessTablesAgeing(uint32_t framesToProcessMax, uint32_t waitCyclesMax);

//  Обучение таблиц маршрутизации, 
//    framesToProcessMax - сколько фреймов обработать за вызов функции
//    возвращает количество обработанных фреймов
uint32_t MDR_KX028_M2_ProcessTablesLearning(uint32_t framesToProcessMax, uint32_t waitCyclesMax);


#endif  //MDR_1923KX029_M2_TABLES_CTRL_H
